#include "memtrace.h"
#include "munka.h"

void Munka::print(std::ostream& os) const {
	os << "MunkaOra: " << munkaOra << std::endl;
}