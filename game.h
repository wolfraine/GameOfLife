#ifndef GAME_H
#define GAME_H

#include "engine.h"

class game : public engine
{
private:
	//engine started_game;

public:
	//konstruktor bezparametorwy
	game();
	game(int ww, int hh);
	//konstruktor kopiuj¹cy
	game(const game& gamee);
	//destrukotr
	virtual ~game();
	game& operator=(const game& gamee);

	void play();
	void view();
};
#endif

 