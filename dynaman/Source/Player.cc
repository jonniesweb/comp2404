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

#include <curses.h>

#include "Player.h"
#include "Dynamite.h"



//----------------------------------------------------------------------------//
// Constructors                                                        Player //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////

Player::Player (World* world) : Entity (world, 0, 0)
{
	mColor  = 49;
	mIcon   = 'P';
	mImmune = 0;
	mTimer  = 0;
	Reset();
}



//----------------------------------------------------------------------------//
// Functions                                                           Player //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////

Entity::Kind Player::GetType (void) const
{
	return Entity::ePlayer;
}

////////////////////////////////////////////////////////////////////////////////

int32 Player::GetScore (void) const
{
	return mScore;
}

////////////////////////////////////////////////////////////////////////////////

void Player::SetScore (int32 score)
{
	mScore = score;
}

////////////////////////////////////////////////////////////////////////////////

void Player::AddScore (int32 score)
{
	mScore += score;
}

////////////////////////////////////////////////////////////////////////////////

int8 Player::GetHealthpacks (void) const
{
	return mHealthpacks;
}

////////////////////////////////////////////////////////////////////////////////

void Player::SetHealthpacks (int8 healthpacks)
{
	if (healthpacks < 0)
		mHealthpacks = 0;

	elif (healthpacks > 9)
		mHealthpacks = 9;

	else
		mHealthpacks = healthpacks;
}

////////////////////////////////////////////////////////////////////////////////

void Player::AddHealthpacks (int8 healthpacks)
{
	SetHealthpacks (mHealthpacks + healthpacks);
}

////////////////////////////////////////////////////////////////////////////////

int8 Player::GetGunpowder (void) const
{
	return mGunpowder;
}

////////////////////////////////////////////////////////////////////////////////

void Player::SetGunpowder (int8 gunpowder)
{
	if (gunpowder < 1)
		mGunpowder = 1;

	elif (gunpowder > 7)
		mGunpowder = 7;

	else
		mGunpowder = gunpowder;
}

////////////////////////////////////////////////////////////////////////////////

void Player::AddGunpowder (int8 gunpowder)
{
	SetGunpowder (mGunpowder + gunpowder);
}

////////////////////////////////////////////////////////////////////////////////

bool Player::HasJetpack (void) const
{
	return mJetpack;
}

////////////////////////////////////////////////////////////////////////////////

void Player::SetJetpack (bool jetpack)
{
	mJetpack = jetpack;
}

////////////////////////////////////////////////////////////////////////////////

void Player::AddJetpack (void)
{
	mJetpack = true;
}

////////////////////////////////////////////////////////////////////////////////

bool Player::IsHatchFound (void)
{
	return mHatchFound;
}

////////////////////////////////////////////////////////////////////////////////

void Player::HatchFound (void)
{
	mHatchFound = true;
}

////////////////////////////////////////////////////////////////////////////////

void Player::HatchReset (void)
{
	mHatchFound = false;
}

////////////////////////////////////////////////////////////////////////////////

void Player::Reset (void)
{
	mLives		= 1;
	mHealthpacks= 3;
	mScore		= 0;

	mGunpowder	= 2;
	mJetpack	= false;

	mHatchFound	= false;
}

////////////////////////////////////////////////////////////////////////////////

void Player::Update (uint32 elapsed)
{
	// Update the entity itself
	Entity::Update (elapsed);

	mTimer += elapsed;
	if (mTimer > 100)
	{
		// Reset timer
		mTimer = 0;

		// Whether entity should blink
		if (mImmune > 0)
		{
			if (mColor == 49)
				mColor = 1;
			else
				mColor = 49;
		}

		else mColor = 49;
	}
}

////////////////////////////////////////////////////////////////////////////////

void Player::KeyPress (int32 key)
{
	// Check if the world if valid
	if (!mWorld->IsValid()) return;

	// Handle keyboard movement
	Point pos = mPosition;

	  if (key == KEY_UP   ) pos.Y -= 1;
	elif (key == KEY_LEFT ) pos.X -= 1;
	elif (key == KEY_DOWN ) pos.Y += 1;
	elif (key == KEY_RIGHT) pos.X += 1;

	// Check if there is an entity at position
	Entity* entity = mWorld->GetStatic (pos);

	// Make sure the entity is valid
	if (entity == NULL)
	{
		mPosition = pos;

		// Check for bomb placement
		if ((key | 32) == 'd')
		{
			Dynamite* dynamite = new Dynamite
				(mWorld, this, mGunpowder);

			mWorld->SetStatic (mPosition, dynamite);
		}
	}

	// Check for a bush in your way
	elif (entity->GetType() == Entity::eBush)
	{
		// Check if you can fly over it
		if (mJetpack) mPosition = pos;
	}

	// Check for something you can walk over
	elif (entity->GetType() != Entity::eTree &&
		  entity->GetType() != Entity::eDynamite)
	{
		mPosition = pos;
	}
}
