#include <iostream>
#include <string>
#include <limits>
#include <cstddef>
#include "memtrace.h"

#include "elektromos_hiba.h"
#include "karosszeria_hiba.h"
#include "motor_hiba.h"
#include "auto.h"
#include "muhely.hpp"

int main(void) {
	Muhely<500> muh;
	std::string valasz;

	while (!std::cin.eof()) {
		std::cout << "Parancsok: hozzaad, torol, listaz, kilep" << std::endl;
		std::cin >> valasz;

		if (!valasz.compare("hozzaad")) {
			std::cout << "Mit szeretne hozzaadni? (auto, munka)" << std::endl;
			std::cin >> valasz;
			if (!valasz.compare("auto")) {
				std::cout << "Irja be a rendszamot: ";
				std::cin >> valasz;
				if (valasz.length() > 0) {
					try {
						muh.autot_felvesz(valasz.c_str());
					}
					catch (const char* hiba) {
						std::cerr << "Hiba a hozzaadasnal: " << hiba << std::endl;
					}
				}
				else {
					std::cerr << "Ures rendszam lett megadva auto hozzaadasanal" << std::endl;
				}
			}
			else if (!valasz.compare("munka")) {
				std::cout << "Irja be a rendszamot: ";
				std::cin >> valasz;
				if (valasz.length() > 0) {
					try {
						Auto* aut = muh.autot_keres(valasz.c_str());
						std::cout << "Milyen munkat szeretne hozzaadni? (motor, karosszeria, elektromos)" << std::endl;
						std::cin >> valasz;
						int ora;
						if (!valasz.compare("motor")) {
							std::cout << "Irja be a motor fajtajat: ";
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::getline(std::cin, valasz);
							std::cout << "Irja be a becsult munkaorat: ";
							std::cin >> ora;
							if (std::cin.fail()) {
								std::cin.clear();
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								std::cerr << "Ervenytelen ertek lett megadva idonek" << std::endl;
							}
							else {
								aut->hozzaad(new MotorHiba(ora, valasz.c_str()));
								std::cout << "Munka hozzaadva!" << std::endl;
							}
						}
						else if (!valasz.compare("karosszeria")) {
							std::cout << "Irja be a szint: ";
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::getline(std::cin, valasz);
							std::cout << "Irja be a meretet: ";
							double meret;
							std::cin >> meret;
							if (std::cin.fail()) {
								std::cin.clear();
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								std::cerr << "Ervenytelen ertek lett megadva meretnek" << std::endl;
							}
							else {
								std::cout << "Irja be a becsult munkaorat: ";
								std::cin >> ora;
								if (std::cin.fail()) {
									std::cin.clear();
									std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
									std::cerr << "Ervenytelen ertek lett megadva idonek" << std::endl;
								}
								else {
									aut->hozzaad(new KarosszeriaHiba(ora, valasz.c_str(), meret));
									std::cout << "Munka hozzaadva!" << std::endl;
								}
							}
						}
						else if (!valasz.compare("elektromos")) {
							std::cout << "Irja be az alkatreszeket: ";
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::getline(std::cin, valasz);
							std::cout << "Irja be a becsult munkaorat: ";
							std::cin >> ora;
							if (std::cin.fail()) {
								std::cin.clear();
								std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
								std::cerr << "Ervenytelen ertek lett megadva idonek" << std::endl;
							}
							else {
								aut->hozzaad(new ElektromosHiba(ora, valasz.c_str()));
								std::cout << "Munka hozzaadva!" << std::endl;
							}
						}
						else {
							std::cerr << "Nem megfelelo tipus torles parancsnal" << std::endl;
						}
					} catch (const char* hiba) {
						std::cerr << "Hiba a keresesnel: " << hiba << std::endl;
					}
				}
				else {
					std::cerr << "Ures rendszam lett megadva munka hozzaadasanal" << std::endl;
				}
			}
			else {
				std::cerr << "Nem megfelelo tipus hozzaadas parancsnal" << std::endl;
			}
		}
		else if (!valasz.compare("torol")) {
			std::cout << "Mit szeretne torolni? (auto, munka)" << std::endl;
			std::cin >> valasz;
			if (!valasz.compare("auto")) {
				std::cout << "Irja be a rendszamot: ";
				std::cin >> valasz;
				if (valasz.length() > 0) {
					try {
						muh.autot_torol(valasz.c_str());
					}
					catch (const char* hiba) {
						std::cerr << "Hiba a torlesnel: " << hiba << std::endl;
					}
				}
				else {
					std::cerr << "Ures rendszam lett megadva torlesnel" << std::endl;
				}
			}
			else if (!valasz.compare("munka")) {
				std::cout << "Irja be a rendszamot: ";
				std::cin >> valasz;
				if (valasz.length() > 0) {
					try {
						Auto* aut = muh.autot_keres(valasz.c_str());
						unsigned sorszam;
						std::cout << "Irja be hanyadik munkat akarja torolni: ";
						std::cin >> sorszam;
						if (std::cin.fail()) {
							std::cin.clear();
							std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
							std::cerr << "Ervenytelen ertek lett megadva sorszamnak" << std::endl;
						}
						else {
							try {
								aut->torol(sorszam);
								std::cout << "Munka torolve!" << std::endl;
							} catch (const char* hiba) {
								std::cerr << "Hiba a torlesnel: " << hiba << std::endl;
							}
						}
					}
					catch (const char* hiba) {
						std::cerr << "Hiba a keresesnel: " << hiba << std::endl;
					}
				}
				else {
					std::cerr << "Ures rendszam lett megadva munka hozzaadasanal" << std::endl;
				}
			}
			else {
				std::cerr << "Nem megfelelo tipus torles parancsnal" << std::endl;
			}

		}
		else if (!valasz.compare("listaz")) {
			std::cout << "Mit szeretne listazni? (auto, mind)" << std::endl;
			std::cin >> valasz;
			if (!valasz.compare("auto")) {
				std::cout << "Irja be a rendszamot: ";
				std::cin >> valasz;
				if (valasz.length() > 0) {
					try {
						Auto* aut = muh.autot_keres(valasz.c_str());
						aut->kiir();
					}
					catch (const char* hiba) {
						std::cerr << "Hiba a keresesnel: " << hiba << std::endl;
					}
				}
				else {
					std::cerr << "Ures rendszam lett megadva listazasnal" << std::endl;
				}
			}
			else if (!valasz.compare("mind")) {
				muh.listaz_mind();
			}
			else {
				std::cerr << "Nem megfelelo tipus listazas parancsnal" << std::endl;
			}
		}
		else if (!valasz.compare("kilep")) {
			return 0;
		}
		else {
			std::cerr << "Nem megfelelo parancs" << std::endl;
		}
	}

	return 0;
}
