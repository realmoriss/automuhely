#ifndef _ELEKTROMOS_HIBA_H_
#define _ELEKTROMOS_HIBA_H_

#include <string>
#include "munka.h"

class ElektromosHiba :public Munka {
	std::string alkatreszek;
public:
	ElektromosHiba(int munkaOra, const char* alkatreszek) : Munka(munkaOra), alkatreszek(alkatreszek) {}
	void print(std::ostream& os) const;
	~ElektromosHiba() {}
};

#endif//_ELEKTROMOS_HIBA_H_