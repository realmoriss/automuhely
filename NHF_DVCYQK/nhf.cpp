#include <iostream>
#include "memtrace.h"

#include "string.h"
#include "elektromos_hiba.h"
#include "karosszeria_hiba.h"
#include "motor_hiba.h"
#include "auto.h"

void teszt_1() {
	Auto a("DVCYQK");
	// Kiirja az auto rendszamat
	std::cout << "Rendszam: " << a.getRendszam() << std::endl;
	// Kiirja, hogy hany db munkat vettunk fel az autohoz
	std::cout << "Munka db: " << a.getdb() << std::endl;
}


void teszt_2() {
	Auto a("DVCYQK");
	// Hozzaadunk nehany munkat
	a.hozzaad(new ElektromosHiba(2, "2m rezkabel, 4db saru"));
	a.hozzaad(new MotorHiba(1, "olajcsere"));
	a.hozzaad(new KarosszeriaHiba(6, "piros", 0.02));

	a[0].print(std::cout); std::cout << std::endl; // ElektromosHiba kiirasa
	a[1].print(std::cout); std::cout << std::endl; // MotorHiba kiirasa
	a[2].print(std::cout); std::cout << std::endl; // KarosszeriaHiba kiirasa
}

void teszt_3() {
	Auto a("DVCYQK");

	a.hozzaad(new ElektromosHiba(2, "2m rezkabel, 4db saru"));
	a.hozzaad(new MotorHiba(1, "olajcsere"));
	a.hozzaad(new KarosszeriaHiba(6, "piros", 0.02));

	a.torol(0);	// ElektromosHiba torlodik
	a.torol(1); // KarosszeriaHiba torlodik
	a.torol(0); // MotorHiba torlodik
}

void teszt_4() {
	Auto* muhely[100];
	muhely[0] = new Auto("ABC-123");
	muhely[1] = new Auto("DEF-456");
	delete muhely[0];
	delete muhely[1];
}

const int main(void) {
	teszt_1();
	teszt_2();
	teszt_3();
	return 0;
}
