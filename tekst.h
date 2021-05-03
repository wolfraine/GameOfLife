#ifndef TEKST_H
#define TEKST_H

#include "game.h"

class tekst :public game
{
public:
	tekst();
	tekst(const tekst& txt);
	const tekst& operator=(const tekst& txt);
	virtual void view();
	virtual ~tekst();
};
#endif

