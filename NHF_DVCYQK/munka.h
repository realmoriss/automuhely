#ifndef _MUNKA_H_
#define _MUNKA_H_

#include <iostream>

class Munka {
	int munkaOra;
public:
	Munka(int munkaOra) : munkaOra(munkaOra) {}
	virtual ~Munka() {}
	virtual void print(std::ostream& os) const;
};

#endif//_MUNKA_H_