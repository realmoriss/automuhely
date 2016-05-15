#ifndef _KAROSSZERIA_HIBA_H_
#define _KAROSSZERIA_HIBA_H_

#include "munka.h"

class KarosszeriaHiba :public Munka {
	String szin;
	double meret;
public:
	KarosszeriaHiba(int munkaOra, String szin, double meret) : Munka(munkaOra), szin(szin), meret(meret) {}
	void print(std::ostream& os) const;
	~KarosszeriaHiba() {}
};

#endif//_KAROSSZERIA_HIBA_H_