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

#ifndef WORLD_H
#define WORLD_H

class Point;
class Entity;
class Player;

#include "EntityList.h"



//----------------------------------------------------------------------------//
// Classes                                                                    //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////
/// <summary> Represents a single world in the game. </summary>

class World
{
	friend class Graphics;

public:
	// Constructors
	 World			(void);
	~World			(void);

public:
	// Functions
	void			Create			(uint32 width, uint32 height);

	void			Destroy			(void);
	bool			IsValid			(void) const;

	uint32			GetWidth		(void) const;
	uint32			GetHeight		(void) const;

	int32			GetTime			(void) const;
	void			SetTime			(int32 time);
	void			AddTime			(int32 time);

	Player*			GetPlayer		(void) const;
	void			SetPlayer		(Player* player);

	Entity*			GetStatic		(const Point& pos) const;
	Entity*			GetStatic		(int32 x, int32 y) const;
	bool			SetStatic		(const Point& pos, Entity* entity);
	bool			SetStatic		(int32 x, int32 y, Entity* entity);

	EntityList*		GetDynamic		(void) const;
	EntityList*		GetEnemies		(void) const;

	bool			CheckBounds		(const Point& pos) const;
	bool			CheckBounds		(int32 x, int32 y) const;

	void			Update			(uint32 elapsed);

private:
	// Fields
	uint32			mWidth;			// Width  of the world
	uint32			mHeight;		// Height of the world

	bool			mDoomed;		// Whether doom unleashed
	int32			mTime;			// Current time left (ms)

	Player*			mPlayer;		// Pointer to the player
	Entity***		mStatic;		// Static entities in the world
									// Layout: [X][Y][Entity*]

	EntityList*		mDynamic;		// Dynamic actors in the world
	EntityList*		mEnemies;		// Enemy   actors in the world
};

#endif // WORLD_H
