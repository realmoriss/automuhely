#include <iostream>
#include "memtrace.h"

#include "auto.h"

Auto::~Auto() {
	for (int i = 0; i < db; i++) {
		delete munkak[i];
	}
}

void Auto::hozzaad(Munka* m) {
	munkak[db] = m;
	db++;
}

void Auto::torol(int melyiket) {
	delete munkak[melyiket];
	for (int i = melyiket+1; i < db; ++i) {
		munkak[i-1] = munkak[i];
	}
	--db;
}

Munka& Auto::operator[](int melyik) {
	return *munkak[melyik];
}

const Munka& Auto::operator[](int melyik) const {
	return *munkak[melyik];
}

String Auto::getRendszam() const {
	return rendszam;
}

int Auto::getdb() const {
	return db;
}

void Auto::kiir(std::ostream& os) const {
	os << "-----AUTO-----" << std::endl;
	// Kiirja az auto rendszamat
	os << "Rendszam: " << rendszam << std::endl;
	// Kiirja, hogy hany db munkat vettunk fel az autohoz
	os << "Munka db: " << db << std::endl;
	for (int i = 0; i < db; ++i) {
		munkak[i]->print(os);
	}
}