#ifndef _MOTOR_HIBA_H_
#define _MOTOR_HIBA_H_

#include "munka.h"

class MotorHiba :public Munka {
	String fajta;
public:
	MotorHiba(int munkaOra, String fajta) : Munka(munkaOra), fajta(fajta) {}
	void print(std::ostream& os) const;
	~MotorHiba() {}
};

#endif//_MOTOR_HIBA_H_