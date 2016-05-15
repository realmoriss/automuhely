#ifndef _AUTO_H_
#define _AUTO_H_

#include "string_sajat.h"
#include "munka.h"

const int MAX_MUNKAK = 100;

class Auto {
	String rendszam;
	Munka* munkak[MAX_MUNKAK];
	int db;
	Auto(const Auto&);
	Auto& operator=(const Auto&);
public:
	Auto(String rendszam): rendszam(rendszam), db() {}
	~Auto();

	void hozzaad(Munka*);
	void torol(int);
	Munka& operator[](int);
	const Munka& operator[](int) const;

	String getRendszam() const;
	int getdb() const;

	void kiir(std::ostream& os = std::cout) const;
};

#endif//_AUTO_H_