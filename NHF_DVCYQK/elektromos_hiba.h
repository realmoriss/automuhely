#ifndef _ELEKTROMOS_HIBA_H_
#define _ELEKTROMOS_HIBA_H_

#include "munka.h"

class ElektromosHiba :public Munka {
	String alkatreszek;
public:
	ElektromosHiba(int munkaOra, String alkatreszek) : Munka(munkaOra), alkatreszek(alkatreszek) {}
	void print(std::ostream& os) const;
	~ElektromosHiba() {}
};

#endif//_ELEKTROMOS_HIBA_H_