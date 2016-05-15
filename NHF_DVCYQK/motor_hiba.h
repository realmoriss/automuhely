#ifndef _MOTOR_HIBA_H_
#define _MOTOR_HIBA_H_

#include <string>
#include "munka.h"

class MotorHiba :public Munka {
	std::string fajta;
public:
	MotorHiba(int munkaOra, const char* fajta) : Munka(munkaOra), fajta(fajta) {}
	void print(std::ostream& os) const;
	~MotorHiba() {}
};

#endif//_MOTOR_HIBA_H_