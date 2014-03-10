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

#ifndef ENEMY_BOAR_H
#define ENEMY_BOAR_H

#include "Enemy.h"



//----------------------------------------------------------------------------//
// Classes                                                                    //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////

class Boar : public Enemy
{
public:
	//----------------------------------------------------------------------------//
	// Constructors                                                               //
	//----------------------------------------------------------------------------//

	////////////////////////////////////////////////////////////////////////////////

	Boar (World* world, const Point& pos) : Enemy (world, pos)
	{
		mIcon  = 'B';
		mSpeed = Random::Instance()->NextInt (200) + 600;
	}

	////////////////////////////////////////////////////////////////////////////////

	Boar (World* world, int32 x, int32 y) : Enemy (world, x, y)
	{
		mIcon   = 'B';
		mSpeed  = Random::Instance()->NextInt (200) + 600;
	}



public:
	//----------------------------------------------------------------------------//
	// Functions                                                                  //
	//----------------------------------------------------------------------------//

	////////////////////////////////////////////////////////////////////////////////

	Kind GetType (void) const
	{
		return Entity::eBoar;
	}

	////////////////////////////////////////////////////////////////////////////////

	void Simulate (void)
	{
		// Get the position of the player
		Point player = mWorld->GetPlayer()->GetPosition();

		// Is standing on top of player
		if (mPosition == player)
		{
			mIsIdle    = false;
			mDirection = Point::Zero;
		}

		// Look for player on x axis
		elif (mPosition.X == player.X)
		{
			mIsIdle = false;

			if (mPosition.Y - player.Y > 0)
				mDirection = Point (0, -1);
			else
				mDirection = Point (0,  1);
		}

		// Look for player on y axis
		elif (mPosition.Y == player.Y)
		{
			mIsIdle = false;

			if (mPosition.X - player.X > 0)
				mDirection = Point (-1, 0);
			else
				mDirection = Point ( 1, 0);
		}

		// Stop charging
		elif (!mIsIdle)
		{
			mIsIdle = true;
			mSpeed  = Random::Instance()->NextInt (200) + 600;
			mDirection = Point::Zero;
		}

		// Charge the player
		if (!mIsIdle)
		{
			mSpeed = 400;

			// Attempt to move to player position
			if (mWorld->GetStatic (mPosition + mDirection) == NULL)
				mPosition += mDirection;
		}
	}
};

#endif // ENEMY_BOAR_H
