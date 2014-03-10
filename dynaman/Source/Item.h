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

#ifndef ACTOR_ITEM_H
#define ACTOR_ITEM_H

#include "Entity.h"
#include "Random.h"
#include "Player.h"

#include "Boar.h"
#include "Grunt.h"



//----------------------------------------------------------------------------//
// Classes                                                                    //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////

class Item : public Entity
{
public:
	//----------------------------------------------------------------------------//
	// Constructors                                                               //
	//----------------------------------------------------------------------------//

	////////////////////////////////////////////////////////////////////////////////

	Item (World* world, const Point& pos, Kind kind) : Entity (world, pos)
	{
		mColor  = 3;
		mType   = kind;
		mImmune = 1000;

		switch (mType)
		{
			case Entity::eArmor		: mIcon = 'A'; break;
			case Entity::eJetpack	: mIcon = 'J'; break;
			case Entity::eHealthpack: mIcon = 'H'; break;
			default					: mIcon = 'G'; break;
		}
	}

	////////////////////////////////////////////////////////////////////////////////

	Item (World* world, int32 x, int32 y, Kind kind) : Entity (world, x, y)
	{
		mColor  = 3;
		mType   = kind;
		mImmune = 1000;

		switch (mType)
		{
			case Entity::eArmor		: mIcon = 'A'; break;
			case Entity::eJetpack	: mIcon = 'J'; break;
			case Entity::eHealthpack: mIcon = 'H'; break;
			default					: mIcon = 'G'; break;
		}
	}



public:
	//----------------------------------------------------------------------------//
	// Functions                                                                  //
	//----------------------------------------------------------------------------//

	////////////////////////////////////////////////////////////////////////////////

	Kind GetType (void) const
	{
		return Entity::eGrunt;
	}

	////////////////////////////////////////////////////////////////////////////////

	void Damage (void)
	{
		if (mImmune <= 0)
		{
			mLives = 0;
			switch (Random::Instance()->NextInt (3))
			{
				case 0: mWorld->GetEnemies()->AddBack (new Grunt (mWorld, mPosition)); break;
				case 1: mWorld->GetEnemies()->AddBack (new Boar  (mWorld, mPosition)); break;
			}
		}
	}

	////////////////////////////////////////////////////////////////////////////////

	void Update (uint32 elapsed)
	{
		// Update the entity itself
		Entity::Update (elapsed);

		// Find the player in the world
		Player* player = mWorld->GetPlayer();

		// Check if player is standing over item
		if (player->GetPosition() == mPosition)
		{
			// Give player item
			switch (mType)
			{
				case Entity::eArmor		: player->AddLives		(1); break;
				case Entity::eJetpack	: player->AddJetpack	( ); break;
				case Entity::eHealthpack: player->AddHealthpacks(1); break;
				default					: player->AddGunpowder	(1); break;
			}

			// Remove item
			mLives = 0;
		}
	}



private:
	//----------------------------------------------------------------------------//
	// Fields                                                                     //
	//----------------------------------------------------------------------------//

	int32 mType; // Type of item
};

#endif // ACTOR_ITEM_H
