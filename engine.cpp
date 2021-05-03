#include "engine.h"
#include <iostream>

int engine::check_neighbors(int height, int width)
{
	int neighbor = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (main_tab[i][j - 1].state == 1) { 
				neighbor += 1; 
			}
		}
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
	int neighbor = 0;

	for (int i = 0; i < height; i++) 
	{
		for (int j = 0; j < width; j++) 
		{
			neighbor = check_neighbors(height, width);
			if (main_tab[i][j].state == 1){
				if (neighbor == 2 || neighbor == 3) {
					tmp_tab[i][j].state = 1;
				}
				if (neighbor < 2 && neighbor>=4) {
					tmp_tab[i][j].state = 0;
				}
				
			}
			if (main_tab[i][j].state == 0) {
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
	tmp_tab[2][2].state = 1;
	tmp_tab[2][1].state = 1;
	tmp_tab[3][1].state = 1;
	tmp_tab[3][2].state = 1;
	tmp_tab[4][2].state = 1;
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
				std::cout << " | ";
		}
		std::cout << std::endl;
	}
}


engine::~engine()
{
	if (main_tab||tmp_tab)
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

