#ifndef _AUTO_H_
#define _AUTO_H_

#include <string>
#include "munka.h"

const int MAX_MUNKAK = 100;

class Auto {
	std::string rendszam;
	Munka* munkak[MAX_MUNKAK];
	size_t db;
	Auto(const Auto&) {}
	Auto& operator=(const Auto&) {}
public:
	Auto(const char* rendszam): rendszam(rendszam), db() {}
	~Auto();

	void hozzaad(Munka*);
	void torol(unsigned);
	Munka& operator[](int);
	const Munka& operator[](int) const;

	std::string getRendszam() const;
	size_t getdb() const;

	void kiir(std::ostream& os = std::cout) const;
};

#endif//_AUTO_H_