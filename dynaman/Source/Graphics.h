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

#ifndef GRAPHICS_H
#define GRAPHICS_H

class Game;
class Entity;
class World;

#include "Types.h"



//----------------------------------------------------------------------------//
// Classes                                                                    //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////
/// <summary> Represents the graphics subsystem for the game. </summary>

class Graphics
{
public:
	// Functions
	static void Init		(void);

	static void Clear		(void);
	static void Refresh		(void);

	static void Draw		(const World*  world );
	static void Draw		(const Entity* entity);
	static void DrawTest	(void);
};

#endif // GRAPHICS_H
