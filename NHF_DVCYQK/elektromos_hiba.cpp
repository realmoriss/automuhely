#include <iostream>
#include "memtrace.h"

#include "elektromos_hiba.h"

void ElektromosHiba::print(std::ostream& os) const {
	os << "-----" << std::endl;
	os << "Elektromos hiba" << std::endl;
	os << "Alkatreszek: " << alkatreszek << std::endl;
	Munka::print(os);
};