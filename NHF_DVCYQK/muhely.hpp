#ifndef _MUHELY_H_
#define _MUHELY_H_

#include <iostream>
#include <string>
#include <cstddef>

#include "auto.h"

template <unsigned N = 100>
class Muhely {
	Auto* muhely[N];
	size_t db;

	Muhely(const Muhely&) {}
	Muhely& operator=(const Muhely&) {}
public:
	Muhely(): db(0) {}
	Auto* autot_felvesz(const char* rendszam);
	Auto* autot_keres(const char* rendszam) const;
	void listaz_mind(std::ostream& os = std::cout) const;
	void autot_torol(const char* rendszam);
	~Muhely();
};

template <unsigned N>
Auto* Muhely<N>::autot_felvesz(const char* rendszam) {
	if (db < N) {
		bool talalt = false;
		for (unsigned i = 0; i < db; ++i) {
			if (!muhely[i]->getRendszam().compare(rendszam)) {
				talalt = true;
			}
		}
		if (!talalt) {
			muhely[db] = new Auto(rendszam);
			return muhely[db++];
		}
		else {
			throw "A megadott rendszam mar fel lett veve";
		}
	}
	else {
		throw "Nem fer tobb auto a muhelybe";
	}

	return NULL;
}

template <unsigned N>
Auto* Muhely<N>::autot_keres(const char* rendszam) const {
	for (unsigned i = 0; i < db; ++i) {
		if (!muhely[i]->getRendszam().compare(rendszam)) {
			return muhely[i];
		}
	}
	throw "Az auto nem talalhato";
	return NULL;
}

template <unsigned N>
void Muhely<N>::listaz_mind(std::ostream& os) const {
	for (unsigned i = 0; i < db; ++i) {
		muhely[i]->kiir(os);
	}
}

template <unsigned N>
void Muhely<N>::autot_torol(const char* rendszam) {
	int talalt = -1;
	for (unsigned i = 0; i < db; ++i) {
		if (!muhely[i]->getRendszam().compare(rendszam)) {
			talalt = i;
		}
	}
	if (talalt > -1) {
		delete muhely[talalt];
		for (unsigned i = talalt + 1; i < db; ++i) {
			muhely[i - 1] = muhely[i];
		}
		db--;
	}
	else {
		throw "Az auto nem talalhato";
	}
}

template <unsigned N>
Muhely<N>::~Muhely() {
	for (unsigned i = 0; i < db; ++i) {
		delete muhely[i];
	}
}

#endif //_MUHELY_H_