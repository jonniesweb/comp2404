////////////////////////////////////////////////////////////////////////////////
// -------------------------------------------------------------------------- //
//                                                                            //
//   Authors: David Krutsko                                                   //
//   Project: COMP 2404 W13                                                   //
//                                                                            //
// -------------------------------------------------------------------------- //
////////////////////////////////////////////////////////////////////////////////

//----------------------------------------------------------------------------//
// Prefaces                                                                   //
//----------------------------------------------------------------------------//

#ifndef ACTOR_WALL_H
#define ACTOR_WALL_H

#include "Item.h"
#include "Hatch.h"
#include "Entity.h"
#include "Random.h"



//----------------------------------------------------------------------------//
// Classes                                                                    //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////

class Wall : public Entity
{
public:
	//----------------------------------------------------------------------------//
	// Constructors                                                               //
	//----------------------------------------------------------------------------//

	////////////////////////////////////////////////////////////////////////////////

	Wall (World* world, bool isBush) : Entity (world, 0, 0)
	{
		if (isBush)
		{
			mType  = Entity::eBush;
			mColor = 19;
		}

		else
		{
			mType  = Entity::eTree;
			mColor = 64;
		}

		mHasRevealed = false;
		mItem  = Entity::eNone;
		mTimer = 0;
	}



public:
	//----------------------------------------------------------------------------//
	// Functions                                                                  //
	//----------------------------------------------------------------------------//

	////////////////////////////////////////////////////////////////////////////////

	Kind GetType (void) const
	{
		return mType;
	}

	////////////////////////////////////////////////////////////////////////////////

	Kind GetItem (void) const
	{
		return mItem;
	}

	////////////////////////////////////////////////////////////////////////////////

	void SetItem (Kind item)
	{
		mItem = item;
	}

	////////////////////////////////////////////////////////////////////////////////

	void Damage (void)
	{
		if (mType == Entity::eBush)
		{
			// Remove the bush
			mLives = 0;

			// Drop item if needed
			if (mItem != Entity::eNone)
			{
				// WARNING: Handle with extreme care!!
				// Since the static entity array in the World can only have one entity
				// per position, we are forced to "delete this" in order to have the
				// dropped item replace this wall. This means that once SetStatic is
				// called, this instance of Wall will no longer exist, therefore, don't
				// interact with this classes' members after this operation.
				// More Info: http://www.parashift.com/c++-faq-lite/delete-this.html

				if (mItem == Entity::eHatch)
					mWorld->SetStatic (mPosition, new Hatch (mWorld, mPosition));
				else
					mWorld->SetStatic (mPosition, new Item  (mWorld, mPosition, mItem));
			}
		}
	}

	////////////////////////////////////////////////////////////////////////////////

	void Update (uint32 elapsed)
	{
		// Update the entity itself
		Entity::Update (elapsed);

		// Check if should reveal self
		mTimer += elapsed;
		if (mTimer > 400)
		{
			// Reset timer
			mTimer = 0;

			if (mHasRevealed ||
				(mItem != Entity::eNone  &&
				 mItem != Entity::eHatch &&
				 mWorld->GetEnemies()->IsEmpty()))
			{
				mHasRevealed = true;
				if (mColor == 19)
					mColor = 28;
				else
					mColor = 19;
			}
		}
	}



private:
	//----------------------------------------------------------------------------//
	// Fields                                                                     //
	//----------------------------------------------------------------------------//

	Kind	mType;			// Entity Kind of wall
	Kind	mItem;			// Item to drop when destroyed
	int32	mTimer;			// Generic elapsed timer
	bool	mHasRevealed;	// Whether already revealed
};

#endif // ACTOR_WALL_H
