#ifndef ENGINE_H
#define ENGINE_H

#include "cell.h"

class engine
{
private:
	//funkcja sprawdza czy jest s¹siad
	int check_neighbors(int height, int width);
protected:
	// w i k do poprawy kompilacja od wersji 2011

	//liczba kolumn
	int height = 20;  
	//liczba wierszy
	int width = 20;  
	//tablica glowna
	cell** main_tab; 
	//tablica pomocnicza
	cell** tmp_tab; 

public:
	// w i k inicializowane z pamiêci
	engine(); 
	//podanie nowych w i k
	engine(int ww, int hh); 
	//konstruktor kopiuj¹cy
	engine(const engine& eng);
	const engine& operator=(const engine& engin);
	//zwolnienie z pamiêci
	virtual ~engine();
	//analiza stanu
	void analyze();
	//ustalenie ¿ywych komórek na pocz¹tku
	void init();
	//rysowanie tabelki
	void draw_tab();
	//virtual void view() = 0;
};
#endif

