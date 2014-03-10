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

#ifndef ACTOR_HATCH_H
#define ACTOR_HATCH_H

#include "Entity.h"
#include "Random.h"
#include "Player.h"

#include "Boar.h"
#include "Grunt.h"



//----------------------------------------------------------------------------//
// Classes                                                                    //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////
// "Engraved on the side of the hatch are six numbers: 4 8 15 16 23 42".

class Hatch : public Entity
{
public:
	//----------------------------------------------------------------------------//
	// Constructors                                                               //
	//----------------------------------------------------------------------------//

	////////////////////////////////////////////////////////////////////////////////

	Hatch (World* world, const Point& pos) : Entity (world, pos)
	{
		mColor  = 41;
		mImmune = 1000;
		mTimer  = 0;
	}

	////////////////////////////////////////////////////////////////////////////////

	Hatch (World* world, int32 x, int32 y) : Entity (world, x, y)
	{
		mColor  = 41;
		mImmune = 1000;
		mTimer  = 0;
	}



public:
	//----------------------------------------------------------------------------//
	// Functions                                                                  //
	//----------------------------------------------------------------------------//

	////////////////////////////////////////////////////////////////////////////////

	Kind GetType (void) const
	{
		return Entity::eHatch;
	}

	////////////////////////////////////////////////////////////////////////////////

	void Damage (void)
	{
		if (mImmune <= 0)
		{
			mImmune = 3000;

			// Punish the player for damaging the hatch
			Point points[4];
			points[0] = mPosition - Point (0, 1);
			points[1] = mPosition + Point (0, 1);
			points[2] = mPosition - Point (1, 0);
			points[3] = mPosition + Point (1, 0);

			for (int i = 0; i < 4; ++i)
				if (mWorld->GetStatic (points[i]) == NULL)
					switch (Random::Instance()->NextInt (3))
					{
						case 0: mWorld->GetEnemies()->AddBack (new Grunt (mWorld, points[i])); break;
						case 1: mWorld->GetEnemies()->AddBack (new Boar  (mWorld, points[i])); break;
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
		if (player->GetPosition() == mPosition &&
			mWorld->GetEnemies()->IsEmpty())
			player->HatchFound();

		// Check if should blink
		mTimer += elapsed;
		if (mTimer > 300)
		{
			// Reset timer
			mTimer = 0;

			if (mWorld->GetEnemies()->IsEmpty())
			{
				if (mColor == 41)
					mColor = 10;
				else
					mColor = 41;
			}
		}
	}



private:
	//----------------------------------------------------------------------------//
	// Fields                                                                     //
	//----------------------------------------------------------------------------//

	int32 mTimer; // Generic elapsed timer
};

#endif // ACTOR_HATCH_H
