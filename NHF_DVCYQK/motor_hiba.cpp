#include "memtrace.h"
#include "motor_hiba.h"

void MotorHiba::print(std::ostream& os) const {
	os << "-----" << std::endl;
	os << "Motorhiba" << std::endl;
	os << "Motor fajta : " << fajta << std::endl;
	Munka::print(os);
};