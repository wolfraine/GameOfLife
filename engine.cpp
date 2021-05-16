#include "engine.h"
#include <iostream>
/*
13.05.2021 - problemy z funkcja analiza lub s¹siedzi
aktualizacja - s¹siedzi siê tworz¹, problem nie znikaj¹ problem z kolejn¹ funckja?
13.05.2021 - problem rozwi¹zany b³¹d przy sprawdzaniu s¹siadów, liczy³em 9 pionów zamiast 8, pozycja x,y nie jest brana pod uwage przy liczeniu s¹siadów

*/
int engine::check_neighbors(int height, int width)
{
	int neighbor = 0;

	if (main_tab[height - 1][width + 1].state == 1) {
		neighbor += 1;
	}
	if (main_tab[height][width + 1].state == 1) {
		neighbor += 1;
	}
	if (main_tab[height + 1][width + 1].state == 1) {
		neighbor += 1;
	}
	if (main_tab[height - 1][width].state == 1) {
		neighbor += 1;
	}
	if (main_tab[height + 1][width].state == 1) {
		neighbor += 1;
	}
	if (main_tab[height - 1][width - 1].state == 1) {
		neighbor += 1;
	}
	if (main_tab[height][width - 1].state == 1) {
		neighbor += 1;
	}
	if (main_tab[height + 1][width - 1].state == 1) {
		neighbor += 1;
	}
	return neighbor;
}

engine::engine()
{
	main_tab = new cell * [height];
	tmp_tab = new cell * [height];
	for (int i = 0; i < height; i++)
	{
		main_tab[i] = new cell[width];
		tmp_tab[i] = new cell[width];
	}
}

engine::engine(int ww, int hh)
{
	if (hh == 0)
	{
		hh = ww;
	}
	height = hh;
	width = ww;
	main_tab = new cell * [height];
	tmp_tab = new cell * [height];
	for (int i = 0; i < height; i++)
	{
		main_tab[i] = new cell[width];
		tmp_tab[i] = new cell[width];
	}
}

void engine::analyze()
{

	int hh = height - 1;
	int ww = width - 1;
	for (int i = 1; i < hh; i++)
	{
		for (int j = 1; j < ww; j++)
		{
			int neighbor = 0;
			neighbor = check_neighbors(i, j);
			if (main_tab[i][j].state == 1) {
				if (neighbor == 2 || neighbor == 3) {
					tmp_tab[i][j].state = 1;
				}
				else if (neighbor < 2 || neighbor >= 4) {
					tmp_tab[i][j].state = 0;
				}

			}
			else if (main_tab[i][j].state == 0) {
				if (neighbor == 3) {
					tmp_tab[i][j].state = 1;
				}
			}
		}
	}
	for (int t = 0; t < height; t++)
	{
		for (int k = 0; k < width; k++)
		{
			main_tab[t][k].state = tmp_tab[t][k].state;
		}
	}
}

void engine::init()
{
	tmp_tab[1][2].state = 1;
	tmp_tab[2][3].state = 1;
	tmp_tab[3][1].state = 1;
	tmp_tab[3][2].state = 1;
	tmp_tab[3][3].state = 1;
}

void engine::draw_tab()
{
	system("cls");
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (main_tab[i][j].state == true)
				std::cout << " x ";
			else
				std::cout << " o ";
		}
		std::cout << std::endl;
	}
}


engine::~engine()
{
	if (main_tab || tmp_tab)
	{
		for (int i = 0; i < height; i++)
		{
			delete[] main_tab[i];
			delete[] tmp_tab[i];
		}
		delete main_tab;
		delete tmp_tab;
	}
}

