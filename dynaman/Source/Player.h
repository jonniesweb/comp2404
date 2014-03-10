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

#ifndef ACTOR_PLAYER_H
#define ACTOR_PLAYER_H

class Dynamite;

#include "Entity.h"



//----------------------------------------------------------------------------//
// Classes                                                                    //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////

class Player : public Entity
{
public:
	// Constructors
	Player	(World* world);

public:
	// Functions
	Kind	GetType				(void) const;

	int32	GetScore			(void) const;
	void	SetScore			(int32 score);
	void	AddScore			(int32 score);

	int8	GetHealthpacks		(void) const;
	void	SetHealthpacks		(int8 healthpacks);
	void	AddHealthpacks		(int8 healthpacks);

	int8	GetGunpowder		(void) const;
	void	SetGunpowder		(int8 gunpowder);
	void	AddGunpowder		(int8 gunpowder);

	bool	HasJetpack			(void) const;
	void	SetJetpack			(bool jetpack);
	void	AddJetpack			(void);

	bool	IsHatchFound		(void);
	void	HatchFound			(void);
	void	HatchReset			(void);

	void	Reset				(void);
	void	Update				(uint32 elapsed);
	void	KeyPress			(int32 key);

private:
	// Fields
	int32	mTimer;				// Generic elapsed timer
	int32	mScore;				// Total player score

	int8	mGunpowder;			// Dynamite explosion range
	int8	mHealthpacks;		// Number of health packs
	bool	mJetpack;			// Ability to fly over bushes

	bool	mHatchFound;		// Whether player found portal
};

#endif // ACTOR_PLAYER_H
