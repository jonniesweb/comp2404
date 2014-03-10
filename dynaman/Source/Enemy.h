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

#ifndef ACTOR_ENEMY_H
#define ACTOR_ENEMY_H

#include "Entity.h"
#include "Random.h"



//----------------------------------------------------------------------------//
// Classes                                                                    //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////

class Enemy : public Entity
{
public:
	//----------------------------------------------------------------------------//
	// Constructors                                                               //
	//----------------------------------------------------------------------------//

	////////////////////////////////////////////////////////////////////////////////

	Enemy (World* world, const Point& pos) : Entity (world, pos)
	{
		mColor		= 16;
		mIcon		= 'G';

		mTimer		= 0;
		mImmune		= 1000;
		mSpeed		= 500;

		mIsIdle		= true;
		mJetpack	= false;
	}

	////////////////////////////////////////////////////////////////////////////////

	Enemy (World* world, int32 x, int32 y) : Entity (world, x, y)
	{
		mColor		= 16;
		mIcon		= 'G';

		mTimer		= 0;
		mImmune		= 1000;
		mSpeed		= 500;

		mIsIdle		= true;
		mJetpack	= false;
	}



public:
	//----------------------------------------------------------------------------//
	// Functions                                                                  //
	//----------------------------------------------------------------------------//

	////////////////////////////////////////////////////////////////////////////////

	virtual void Simulate (void)
	{
	}

	////////////////////////////////////////////////////////////////////////////////

	void Update (uint32 elapsed)
	{
		// Update the entity itself
		Entity::Update (elapsed);

		// Update timer
		mTimer += elapsed;
		if (mTimer > mSpeed)
		{
			// Reset timer
			mTimer = 0;

			// Simulate
			Simulate();

			// Move if idle
			if (mIsIdle)
			{
				// Small chance of changing directions randomly
				if (Random::Instance()->NextReal() < 0.10)
					mDirection = Point::Zero;

				// Locate static entities at new position
				Entity* entity = mWorld->GetStatic (mPosition + mDirection);

				// Check if a new direction needs to be computed
				if (mDirection == Point::Zero || (entity != NULL &&
					!(mJetpack && entity->GetType() == Entity::eBush)))
				{
					Point pts[4];

					// Create possible directions
					pts[0] = Point ( 0, -1);
					pts[1] = Point (-1,  0);
					pts[2] = Point ( 0,  1);
					pts[3] = Point ( 1,  0);

					// Pick one at random
					uint32 p = Random::Instance()->NextInt (4);
					for (uint32 i = 0; i < 4; ++i)
					{
						// Select next possible point
						mDirection = pts[++p % 4];

						// Check the new direction
						entity = mWorld->GetStatic
							(mPosition + mDirection);

						if (entity == NULL || (mJetpack &&
							entity->GetType() == Entity::eBush))
							break;

						else mDirection = Point::Zero;
					}
				}

				// Move to new position
				mPosition += mDirection;
			}

			// Damage the player
			Entity* player = (Entity*) mWorld->GetPlayer();
			if (player->GetPosition() == mPosition)
				player->Damage();
		}
	}



private:
	//----------------------------------------------------------------------------//
	// Fields                                                                     //
	//----------------------------------------------------------------------------//

	int32	mTimer;			// Generic elapsed timer

protected:
	int32	mSpeed;			// Current update speed
	Point	mDirection;		// Current moving direction

	bool	mIsIdle;		// Enemy is currently idling
	bool	mJetpack;		// Ability to fly over bushes
};

#endif // ACTOR_ENEMY_H
