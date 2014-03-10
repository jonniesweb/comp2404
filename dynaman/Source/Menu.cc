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

#include "Menu.h"
#include <curses.h>



//----------------------------------------------------------------------------//
// Functions                                                                  //
//----------------------------------------------------------------------------//

////////////////////////////////////////////////////////////////////////////////
/// <summary> Prints the menu. </summary>

void Menu::Draw (void)
{
	clear();

	uint8 x = 21, y = 5;
	attron (COLOR_PAIR (57));

	for (uint8 i = 0; i < 9; ++i)
		mvprintw (++y, x, "                                                 ");

	attroff (COLOR_PAIR (57));
	x = 23; y = 6;

	mvprintw (++y, x, "                                             ");
	mvprintw (++y, x, "                D Y N A M A N                ");
	mvprintw (++y, x, "                -------------                ");
	mvprintw (++y, x, "                                             ");
	mvprintw (++y, x, "                 Normal Game                 ");
	mvprintw (++y, x, "                  Exit Game                  ");
	mvprintw (++y, x, "                                             ");

	refresh();
}

////////////////////////////////////////////////////////////////////////////////
/// <summary> Asks the user for a menu selection. </summary>

Menu::Option Menu::GetOption (void)
{
	static int8 option = 0;
	while (true)
	{
		uint8 x = 24, y = 10;

		mvprintw (++y, x, "                Normal Game                ");
		mvprintw (++y, x, "                 Exit Game                 ");

		attron (COLOR_PAIR (57));
		switch (option)
		{
			case 0:
				mvprintw (11, x, "                Normal Game                ");
				break;

			case 1:
				mvprintw (12, x, "                 Exit Game                 ");
				break;
		}
		attroff (COLOR_PAIR (57)); refresh();

		switch (getch())
		{
			case KEY_UP		: if (--option < 0) option = 1; break;
			case KEY_DOWN	: if (++option > 1) option = 0; break;
			case 27			: return Menu::eExit;
			case '\n'		: return (Option) option;
		}
	}
}
