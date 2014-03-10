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

#ifndef ACTOR_FIRE_H
#define ACTOR_FIRE_H

#include "Entity.h"



//----------------------------------------------------------------------------//
// Classes                                                                    //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////

class Fire : public Entity
{
public:
	//----------------------------------------------------------------------------//
	// Constructors                                                               //
	//----------------------------------------------------------------------------//

	////////////////////////////////////////////////////////////////////////////////

	Fire (World* world, const Point& pos) : Entity (world, pos)
	{
		mColor = 10;
		mTimer = 200;
	}

	////////////////////////////////////////////////////////////////////////////////

	Fire (World* world, int32 x, int32 y) : Entity (world, x, y)
	{
		mColor = 10;
		mTimer = 200;
	}



public:
	//----------------------------------------------------------------------------//
	// Functions                                                                  //
	//----------------------------------------------------------------------------//

	////////////////////////////////////////////////////////////////////////////////

	Kind GetType (void) const
	{
		return Entity::eFire;
	}

	////////////////////////////////////////////////////////////////////////////////

	void Damage (void)
	{
		// We don't want fire taking damage
	}

	////////////////////////////////////////////////////////////////////////////////

	void Update (uint32 elapsed)
	{
		// Update duration
		mTimer -= elapsed;

		// Fire going out
		if (mTimer < 0)
			mLives = 0;

		// Get the static entity at current position
		Entity* entity = mWorld->GetStatic (mPosition);

		// Damage the entity
		if (entity != NULL)
			entity->Damage();

		// Get enemy entities at current position
		EntityList::Node* node =
			mWorld->GetEnemies()->Front();

		for (; node != NULL; node = node->Next())
			if (node->Value->GetPosition() == mPosition)
				node->Value->Damage();

		// Damage the player
		Entity* player = (Entity*) mWorld->GetPlayer();
		if (player->GetPosition() == mPosition)
			player->Damage();
	}



private:
	//----------------------------------------------------------------------------//
	// Fields                                                                     //
	//----------------------------------------------------------------------------//

	int32 mTimer; // Duration of fire
};

#endif // ACTOR_FIRE_H
