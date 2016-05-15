#ifndef _KAROSSZERIA_HIBA_H_
#define _KAROSSZERIA_HIBA_H_

#include <string>
#include "munka.h"

class KarosszeriaHiba :public Munka {
	std::string szin;
	double meret;
public:
	KarosszeriaHiba(int munkaOra, const char* szin, double meret) : Munka(munkaOra), szin(szin), meret(meret) {}
	void print(std::ostream& os) const;
	~KarosszeriaHiba() {}
};

#endif//_KAROSSZERIA_HIBA_H_