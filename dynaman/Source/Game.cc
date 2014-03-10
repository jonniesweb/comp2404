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

#include <ctime>
#include <curses.h>

#include "Menu.h"
#include "Game.h"
#include "Graphics.h"

#include "World.h"
#include "Player.h"
#include "Random.h"

#include "WorldBuilder.h"



//----------------------------------------------------------------------------//
// Functions                                                             Game //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////
/// <summary> Displays the game menu and waits for user selection. </summary>

void Game::Menu (void)
{
	while (true)
	{
		// Draw menu
		Menu::Draw();

		// Wait for user selection
		switch (Menu::GetOption())
		{
			case Menu::eNormal	: NormalGame(); break;
			case Menu::eExit	: return;
		}
	}
}

////////////////////////////////////////////////////////////////////////////////
/// <summary> A normal single player game against an AI. </summary>

void Game::NormalGame (void)
{
	//----------------------------------------------------------------------------//
	// Startup                                                                    //
	//----------------------------------------------------------------------------//

	// Don't block getch
	timeout (0);

	// Clear the screen
	Graphics::Clear();

	// Reset timings
	mPressed    = 0;
	mElapsed    = 0;
	mLastUpdate = 0;

	// Reset game stage
	mStage		= 0;

	// Create the player and world
	mWorld  = new World();
	mPlayer = new Player (mWorld);
	mWorld->SetPlayer (mPlayer);

	WorldBuilder::CreateWorld (mWorld, mStage);

	uint32 w = (uint32) (mWorld->GetWidth () * 2.5f);
	uint32 h = (uint32) (mWorld->GetHeight() * 3.0f);

	// Used for clearing the interface
	const char* empty = "                                                    ";

	// Compute machine clock resolution
	float res = 1000.0 / CLOCKS_PER_SEC;
		// This is mainly because CLOCKS_PER_SEC differs from platform
		// to platform. In order to support multiple platforms we need
		// to compute the clock resolution on our own. Keep in mind that
		// we wouldn’t be using clock() if this was a real game.



	//----------------------------------------------------------------------------//
	// Game Loop                                                                  //
	//----------------------------------------------------------------------------//

	while (true)
	{
		mPressed = getch();
		mElapsed = (uint32) (clock() * res) - mLastUpdate;

		if (mPressed != ERR)
		{
			// Handle escape, pause game
			if (mPressed == 27)
			{
				mvprintw (h+2, w-18, "GAME PAUSED, PRESS ANY KEY TO RESUME");
				mvprintw (h+3, w-17, "Press Q to return to the main menu"); refresh();
				timeout (-1); mPressed = getch(); timeout (0);
				mvprintw (h+2, w-18, empty); mvprintw (h+3, w-17, empty);

				if ((mPressed | 32) == 'q') break;
				mLastUpdate = (uint32) (clock() * res);
			}

			// Handle player control
			else mPlayer->KeyPress (mPressed);
		}

		if (mElapsed > 15)
		{
			// Update the game world
			mWorld->Update (mElapsed);

			// Draw the game world
			Graphics::Draw (mWorld);

			// Draw the game interface
			uint32 w = mWorld->GetWidth () * 5;
			uint32 h = mWorld->GetHeight() * 3;

			mvprintw (h, 0, "Score: %09d", mPlayer->GetScore());

			int32 m = (int32) (mWorld->GetTime() / 60000);
			int32 s = (int32) (mWorld->GetTime() % 60000 / 1000);
			mvprintw (h, (w / 2) - 1, "%d:%02d", m, s);

			mvprintw (h, w - 9, "E%d L%d S%02d",
				mWorld->GetEnemies()->Count(), mPlayer->GetHealthpacks(), mStage + 1);

			Graphics::Refresh();

			// Update the timings
			mLastUpdate = (uint32) (clock() * res);
		}

		// Check player status
		if (!mPlayer->IsAlive())
		{
			if (mPlayer->GetHealthpacks() != 0)
			{
				mvprintw (h+2, w-18, "YOU HAVE DIED, PRESS ENTER TO RESPAWN");
				mvprintw (h+3, w-14, "You have %d respawns remaining", mPlayer->GetHealthpacks()); refresh();
				timeout (-1); while (getch() != '\n'); timeout (0);
				mvprintw (h+2, w-18, empty); mvprintw (h+3, w-14, empty);

				mPlayer->SetLives (1);
				mPlayer->AddHealthpacks (-1);

				WorldBuilder::CreateWorld (mWorld, mStage);
				mLastUpdate = (uint32) (clock() * res);
			}

			else
			{
				mvprintw (h+2, w-14, "YOU HAVE DIED, GAME OVER :-(");
				mvprintw (h+3, w-16, "Press ENTER to return to the menu"); refresh();
				timeout (-1); while (getch() != '\n'); timeout (0);
				mvprintw (h+2, w-14, empty); mvprintw (h+3, w-16, empty);

				mStage = 0;
				break;
			}
		}

		// Check if hatch was found (or if secret key was pressed)
		elif (mPlayer->IsHatchFound() || (mPressed | 32) == 'p')
		{
			mvprintw (h+2, w-7 , "CONGRATULATIONS");
			mvprintw (h+3, w-14, "Press ENTER to enter stage %d", (++mStage) + 1); refresh();
			timeout (-1); while (getch() != '\n'); timeout (0);
			mvprintw (h+2, w-7, empty); mvprintw (h+3, w-14, empty);

			mPlayer->HatchReset();

			if (mStage != 0 && mStage % 4 == 0)
				mPlayer->AddHealthpacks (1);

			WorldBuilder::CreateWorld (mWorld, mStage);
			mLastUpdate = (uint32) (clock() * res);
		}
	}



	//----------------------------------------------------------------------------//
	// Shutdown                                                                   //
	//----------------------------------------------------------------------------//

	delete mWorld;
	delete mPlayer;

	// Block getch
	timeout (-1);
}
