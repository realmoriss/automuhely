#ifndef _STRING_H_
#define _STRING_H_

#include <iostream>

class String {
    char *pData;
    size_t len;
public:
	String() :pData(0), len(0) {}
	const char* c_str() const;
    String(char ch);
    String(const char *p);
    String(const String& s1);
    ~String() { delete[] pData; }
    String& operator=(const String& rhs_s);
	String& operator+=(const String& rhs_s);
    String operator+(const String& rhs_s) const;
	String operator+(char rhs_c) const;
	char& operator[](unsigned int idx);
	const char& operator[](unsigned int idx) const;
	void erase();
};

std::ostream& operator<<(std::ostream& os, const String& s0);
std::istream& operator>>(std::istream& is, String& s0);
String operator+(char ch, const String& str);

#endif

