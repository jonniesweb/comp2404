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
#include "Graphics.h"

#include "Game.h"
#include "World.h"
#include "Entity.h"
#include "Player.h"



//----------------------------------------------------------------------------//
// Functions                                                         Graphics //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////
/// <summary> Prepares all possible curses color combinations. </summary>
/// <remarks> See Colors.png for a reference or call "DrawTest". </remarks>

void Graphics::Init (void)
{
	for (short background = 0, i = 1; background < 8; ++background)
		for (short foreground = 0; foreground < 8; ++foreground, ++i)
			init_pair (i, foreground, background);
}

////////////////////////////////////////////////////////////////////////////////
/// <summary> Clears everything on screen and in the curses buffer. </summary>

void Graphics::Clear (void)
{
	clear();
}

////////////////////////////////////////////////////////////////////////////////
/// <summary> Forces everything in the buffer to be displayed on screen. </summary>

void Graphics::Refresh (void)
{
	refresh();
}

////////////////////////////////////////////////////////////////////////////////
/// <summary> Draws the specified world to the curses buffer. </summary>

void Graphics::Draw (const World* world)
{
	// Make sure that the specified world is valid
	if (world == NULL || !world->IsValid()) return;

	// Draw all the static entities
	for (uint32 y = 0, yy = 0; y < world->mHeight; ++y, yy += 3)
		for (uint32 x = 0, xx = 0; x < world->mWidth; ++x, xx += 5)
		{
			// Get information about entity
			int8 color = 1; char icon  = ' ';
			if (world->mStatic[x][y] != NULL)
			{
				color = world->mStatic[x][y]->GetColor();
				icon  = world->mStatic[x][y]->GetIcon();
			}

			// Draw the entity
			attron (COLOR_PAIR (color));
			mvprintw (yy+0, xx, "     ");
			mvprintw (yy+1, xx, "  %c  ", icon);
			mvprintw (yy+2, xx, "     ");
			attroff (COLOR_PAIR (color));
		}

	// Draw all dynamic entities
	EntityList::Node* node;

	node = world->mDynamic->Front();
	while (node != NULL)
	{
		Draw (node->Value);
		node = node->Next();
	}

	// Draw all the enemies entities
	node = world->mEnemies->Front();
	while (node != NULL)
	{
		Draw (node->Value);
		node = node->Next();
	}

	// Draw the main player
	Draw (world->mPlayer);
}

////////////////////////////////////////////////////////////////////////////////
/// <summary> Draws the specified entity to the curses buffer. </summary>

void Graphics::Draw (const Entity* entity)
{
	// Make sure the entity is valid
	if (entity == NULL) return;

	int32 x = entity->GetX() * 5;
	int32 y = entity->GetY() * 3;

	attron (COLOR_PAIR (entity->GetColor()));
	mvprintw (y++, x, "     ");
	mvprintw (y++, x, "  %c  ", entity->GetIcon());
	mvprintw (y  , x, "     ");
	attroff (COLOR_PAIR (entity->GetColor()));
}

////////////////////////////////////////////////////////////////////////////////
/// <summary> Draws a reference table displaying all possible colors. </summary>

void Graphics::DrawTest (void)
{
	int32 x = 4;
	int32 y = 3;

	for (short i = 1; i < 33; ++i)
	{
		mvprintw (y, x, "%2hd = ", i);
		attron (COLOR_PAIR (i));
		mvprintw (y++, x + 5, "  TEST  ");
		attroff (COLOR_PAIR (i));
		if (i % 8 == 0) ++y;
	}

	x = 20;
	y = 3;

	for (short i = 33; i < 65; ++i)
	{
		mvprintw (y, x, "%2hd = ", i);
		attron (COLOR_PAIR (i));
		mvprintw (y++, x + 5, "  TEST  ");
		attroff (COLOR_PAIR (i));
		if (i % 8 == 0) ++y;
	}

	refresh();
	getch();
}
