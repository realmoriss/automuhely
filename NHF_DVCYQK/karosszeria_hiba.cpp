#include "memtrace.h"
#include "karosszeria_hiba.h"

void KarosszeriaHiba::print(std::ostream& os) const {
	os << "-----" << std::endl;
	os << "Karosszeria hiba" << std::endl;
	os << "Szin: " << szin << ", meret: " << meret << " m2" << std::endl;
	Munka::print(os);
}