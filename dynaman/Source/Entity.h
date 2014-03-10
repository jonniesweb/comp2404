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

#ifndef ENTITY_H
#define ENTITY_H

#include "Types.h"
#include "Point.h"
#include "World.h"



//----------------------------------------------------------------------------//
// Classes                                                                    //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////
/// <summary> Represents an abstract entity in the game world. </summary>

class Entity
{
public:
	////////////////////////////////////////////////////////////////////////////////
	/// <summary> Represents all the types of entities in the game. </summary>

	enum Kind
	{
		eNone,

		// Actors
		ePlayer,
		eHatch,
		eDynamite,
		eFire,

		eBush,
		eTree,
		eBoar,
		eGrunt,
		eSmoke,

		// Items
		eGunpowder,
		eHealthpack,
		eArmor,
		eJetpack
	};

public:
	// Constructors
	Entity			(World* world, const Point& pos);
	Entity			(World* world, int32 x, int32 y);
	virtual ~Entity	(void);

public:
	// Functions
	virtual Kind	GetType			(void) const = 0;

	char			GetIcon			(void) const;
	int8			GetColor		(void) const;

	int32			GetX			(void) const;
	int32			GetY			(void) const;
	Point			GetPosition		(void) const;

	void			SetPosition		(const Point& pos);
	void			SetPosition		(int32 x, int32 y);

	virtual bool	IsAlive			(void) const;
	virtual int8	GetLives		(void) const;
	virtual void	SetLives		(int8 lives);
	virtual void	AddLives		(int8 lives);
	virtual void	Damage			(void);

	virtual void	Update			(uint32 elapsed);

protected:
	// Fields
	World*			mWorld;			// World pointer
	Point			mPosition;		// Entity position
	int32			mImmune;		// Immunity time

	int8			mColor;			// Entity color
	char			mIcon;			// Entity icon
	int8			mLives;			// Entity lives
};

#endif // ENTITY_H
