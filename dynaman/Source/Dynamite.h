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

#ifndef ACTOR_DYNAMITE_H
#define ACTOR_DYNAMITE_H

#include "Fire.h"
#include "Player.h"



//----------------------------------------------------------------------------//
// Classes                                                                    //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////

class Dynamite : public Entity
{
public:
	//----------------------------------------------------------------------------//
	// Constructors                                                               //
	//----------------------------------------------------------------------------//

	////////////////////////////////////////////////////////////////////////////////

	Dynamite (World* world, Player* player, uint8 gunpowder) : Entity (world, 0, 0)
	{
		mColor		= 8;
		mIcon		= 'o';

		mGunpowder	= gunpowder;
		mCountdown	= 2000;

		mTimer		= 0;
		mCurrRange	= 0;

		mCanGoN		= true;
		mCanGoE		= true;
		mCanGoS		= true;
		mCanGoW		= true;

		mPlayer		= player;
	}



public:
	//----------------------------------------------------------------------------//
	// Functions                                                                  //
	//----------------------------------------------------------------------------//

	////////////////////////////////////////////////////////////////////////////////

	Kind GetType (void) const
	{
		return Entity::eDynamite;
	}

	////////////////////////////////////////////////////////////////////////////////

	void Damage (void)
	{
		mCountdown = 0;
	}

	////////////////////////////////////////////////////////////////////////////////

	void Update (uint32 elapsed)
	{
		mTimer     += elapsed;
		mCountdown -= elapsed;

		if (mCountdown <= 0 && mTimer > 50)
		{
			mIcon  = ' ';
			mTimer = 0;

			// Compute position in all directions
			Point n = mPosition - Point (0, mCurrRange);
			Point s = mPosition + Point (0, mCurrRange);
			Point w = mPosition - Point (mCurrRange, 0);
			Point e = mPosition + Point (mCurrRange, 0);

			// Explode at dynamite position
			if (mCurrRange == 0)
				mWorld->GetDynamic()->AddBack (new Fire (mWorld, mPosition));

			else
			{
				// Get entities in all directions
				Entity* en = mWorld->GetStatic (n);
				Entity* es = mWorld->GetStatic (s);
				Entity* ew = mWorld->GetStatic (w);
				Entity* ee = mWorld->GetStatic (e);

				// Stop radiating if a tree was hit
				if (en != NULL && en->GetType() == Entity::eTree) mCanGoN = false;
				if (es != NULL && es->GetType() == Entity::eTree) mCanGoS = false;
				if (ew != NULL && ew->GetType() == Entity::eTree) mCanGoW = false;
				if (ee != NULL && ee->GetType() == Entity::eTree) mCanGoE = false;

				// Radiate explosion in all directions
				if (mCanGoN) mWorld->GetDynamic()->AddBack (new Fire (mWorld, n));
				if (mCanGoS) mWorld->GetDynamic()->AddBack (new Fire (mWorld, s));
				if (mCanGoW) mWorld->GetDynamic()->AddBack (new Fire (mWorld, w));
				if (mCanGoE) mWorld->GetDynamic()->AddBack (new Fire (mWorld, e));

				// Stop radiating if anything was hit
				if (en != NULL) mCanGoN = false;
				if (es != NULL) mCanGoS = false;
				if (ew != NULL) mCanGoW = false;
				if (ee != NULL) mCanGoE = false;
			}

			// Destroy when range has been reached
			if (++mCurrRange > mGunpowder || (!mCanGoN && !mCanGoS && !mCanGoW && !mCanGoE))
				mLives = 0;
		}

		// Alternate icon
		elif (mTimer > 500)
		{
			if (mIcon == 'o')
				 mIcon = 'O';
			else
				mIcon = 'o';

			mTimer = 0;
		}
	}



private:
	//----------------------------------------------------------------------------//
	// Fields                                                                     //
	//----------------------------------------------------------------------------//

	uint8 mGunpowder;	// Total detonating range
	int32 mCountdown;	// Countdown until detonation

	int32 mTimer;		// Generic elapsed timer
	uint8 mCurrRange;	// Current detonating range

	bool mCanGoN;		// Can continue detonating north
	bool mCanGoE;		// Can continue detonating east
	bool mCanGoS;		// Can continue detonating south
	bool mCanGoW;		// Can continue detonating west

	Player* mPlayer;	// Player who planted dynamite
};

#endif // ACTOR_DYNAMITE_H
