#include "game.h"*
#include <iostream>
#include "windows.h" 


game::game():engine()
{
}

game::game(int ww, int hh):engine(ww, hh)
{
}

game::game(const game& gamee)
{
}

game::~game()
{
}

void game::play()
{
	init();
	//pêtla automatyczna
	while (true)
	{
		draw_tab();
		analyze();
		Sleep(800);
	}

	//krok z enterem
	//char sign ;
	//sign = getchar();
	//while (sign == '\n')
	//{
	//	draw_tab();
	//	analyze();
	//	sign = getchar();
	//}
}

void game::view()
{

}
