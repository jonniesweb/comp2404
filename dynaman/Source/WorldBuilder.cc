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

#include "Point.h"
#include "World.h"
#include "Random.h"
#include "Entity.h"

#include "Wall.h"
#include "Item.h"
#include "Boar.h"
#include "Grunt.h"
#include "Smoke.h"
#include "Player.h"
#include "Hatch.h"

#include "WorldBuilder.h"



//----------------------------------------------------------------------------//
// Macros                                                        WorldBuilder //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////

#define ADD_ENEMY( kind ) \
	world->GetEnemies()->AddBack (new kind (world, FindEmptySpot (world)));



//----------------------------------------------------------------------------//
// Functions                                                     WorldBuilder //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////

void WorldBuilder::CreateWorld (World* world, uint8 stage)
{
	// Check the world pointer
	if (world == NULL) return;

	// Create a default world
	uint32 width  = 23;
	uint32 height = 15;
	world->Create (width, height);

	// Fill the world with tree actors
	for (uint32 x = 0; x < width; ++x)
		for (uint32 y = 0; y < height; ++y)
		{
			// Around the entire world
			if (x == 0 || x == width  - 1 ||
				y == 0 || y == height - 1)
				world->SetStatic (x, y, new Wall (world, false));

			// Every even row and column
			elif ((x & 1) == 0 && (y & 1) == 0)
				world->SetStatic (x, y, new Wall (world, false));

			// Randomly generated
			elif (Random::Instance()->NextReal() < 0.45)
			{
				// Avoid player start area
				if ((x != 1 || y != 1) &&
					(x != 1 || y != 2) &&
					(x != 2 || y != 1))
					world->SetStatic (x, y, new Wall (world, true));
			}
		}

	// Add an item to hide in the world
	Wall* wall = FindEmptyBush (world);

	switch (stage)
	{
		case 0 : wall->SetItem (Entity::eHealthpack); break;
		case 1 : wall->SetItem (Entity::eGunpowder); break;
		case 2 : wall->SetItem (Entity::eArmor    ); break;
		case 3 : wall->SetItem (Entity::eGunpowder); break;
		case 4 : wall->SetItem (Entity::eGunpowder); break;
		case 5 : wall->SetItem (Entity::eJetpack  ); break;

		default:
			double value = Random::Instance()->NextReal();
			  if (value > 0.10) wall->SetItem (Entity::eHealthpack);
			elif (value > 0.55) wall->SetItem (Entity::eArmor     );
			else                wall->SetItem (Entity::eGunpowder ); break;
	}

	// Add a hatch to the world
	FindEmptyBush (world)->SetItem (Entity::eHatch);

	// Make sure player is completely cut off
	if (world->GetStatic (1, 3) == NULL)
		world->SetStatic (1, 3, new Wall (world, true));
	if (world->GetStatic (3, 1) == NULL)
		world->SetStatic (3, 1, new Wall (world, true));

	// Add enemies to the world
	switch (stage)
	{
		// There is absolutely a better way of doing this. For instance, each stage
		// can be stored in a file (or buffer) that is read by the world builder.
		// That way you can minimize writing so much repetitive code. That method,
		// however, is out of the scope of this project.

		case 0:
			ADD_ENEMY (Grunt);
			ADD_ENEMY (Grunt);
			ADD_ENEMY (Grunt); break;

		case 1:
			ADD_ENEMY (Grunt);
			ADD_ENEMY (Grunt);
			ADD_ENEMY (Boar ); break;

		case 2:
			ADD_ENEMY (Grunt);
			ADD_ENEMY (Grunt);
			ADD_ENEMY (Boar );
			ADD_ENEMY (Boar ); break;

		case 3:
			ADD_ENEMY (Grunt);
			ADD_ENEMY (Grunt);
			ADD_ENEMY (Boar );
			ADD_ENEMY (Boar );
			ADD_ENEMY (Boar ); break;

		case 4:
			ADD_ENEMY (Grunt);
			ADD_ENEMY (Grunt);
			ADD_ENEMY (Grunt);
			ADD_ENEMY (Boar );
			ADD_ENEMY (Boar );
			ADD_ENEMY (Boar ); break;

		case 5:
			ADD_ENEMY (Grunt);
			ADD_ENEMY (Grunt);
			ADD_ENEMY (Grunt);
			ADD_ENEMY (Boar );
			ADD_ENEMY (Boar );
			ADD_ENEMY (Boar );
			ADD_ENEMY (Smoke); break;

		case 9:
			ADD_ENEMY (Smoke);
			ADD_ENEMY (Smoke);
			ADD_ENEMY (Smoke);
			ADD_ENEMY (Smoke);
			ADD_ENEMY (Smoke);
			ADD_ENEMY (Smoke);
			ADD_ENEMY (Smoke); break;

		default:
			ADD_ENEMY (Grunt);
			ADD_ENEMY (Grunt);
			ADD_ENEMY (Grunt);
			ADD_ENEMY (Boar );
			ADD_ENEMY (Boar );
			ADD_ENEMY (Boar );
			ADD_ENEMY (Smoke);
			ADD_ENEMY (Smoke); break;
	}

	// Add the player character
	world->GetPlayer()->SetPosition (1, 1);
}

////////////////////////////////////////////////////////////////////////////////

void WorldBuilder::AddSmoke (World* world, uint8 count)
{
	while (count-- != 0)
		world->GetEnemies()->AddBack (new Smoke (world, FindEmptySpot (world)));
}



//----------------------------------------------------------------------------//
// Internal                                                      WorldBuilder //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////

Point WorldBuilder::FindEmptySpot (const World* world)
{
	Point result;

	for (bool keepGoing = true; keepGoing; )
	{
		// Select a new random position
		result.X = Random::Instance()->NextInt (world->GetWidth () - 3) + 2;
		result.Y = Random::Instance()->NextInt (world->GetHeight() - 3) + 2;

		// Check the static entity array
		if (world->GetStatic (result) == NULL)
		{
			keepGoing = false;

			// Check the dynamic entity list
			EntityList::Node* node =
				world->GetEnemies()->Front();

			for (; node != NULL; node = node->Next())
				if (node->Value->GetPosition() == result)
				{
					keepGoing = true; break;
				}
		}
	}

	return result;
}

////////////////////////////////////////////////////////////////////////////////

Wall* WorldBuilder::FindEmptyBush (const World* world)
{
	Point result;

	while (true)
	{
		// Select a new random position
		result.X = Random::Instance()->NextInt (world->GetWidth () - 3) + 2;
		result.Y = Random::Instance()->NextInt (world->GetHeight() - 3) + 2;

		// Check the static entity array
		Entity* entity = world->GetStatic (result);

		// Check if entity is an empty bush
		if (entity != NULL &&
			entity->GetType() == Entity::eBush)
		{
			Wall* bush = static_cast<Wall*> (entity);
			if (bush->GetItem() == Entity::eNone)
				return bush;
		}
	}

	return NULL;
}
