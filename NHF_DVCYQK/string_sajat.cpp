#ifdef _MSC_VER
  #define _CRT_SECURE_NO_WARNINGS
#endif

#include <iostream>
#include <cstring>
#include "memtrace.h"

#include "string_sajat.h"

using std::cin;
using std::ios_base;

const char* String::c_str() const {
	if (pData) return pData; else return "";
}

String::String(char ch) {
    len = 1;
    pData = new char[len+1];
    pData[0] = ch;
    pData[1] = '\0';
}

String::String(const char *p) {
    len = strlen(p);
    pData = new char[len+1];
	strcpy(pData, p);
}

String::String(const String& s1) {
    len = s1.len;
    pData = new char[len+1];
    strcpy(pData, s1.pData);
}

String& String::operator=(const String& rhs_s) {
    if (this != &rhs_s) {
        len = rhs_s.len;
        pData = new char[len+1];
        strcpy(pData, rhs_s.pData);
    }
    return *this;
}

String& String::operator+=(const String& rhs_s) {
	*this = *this + rhs_s;
	return *this;
}

char& String::operator[](unsigned int idx) {
    if (idx >= len) throw "String: index";
    return pData[idx];
}

const char& String::operator[](unsigned int idx) const {
    if (idx >= len) throw "String: index";
    return pData[idx];
}

String String::operator+(const String& rhs_s) const {
    String temp;
    temp.len = len + rhs_s.len;
    delete[] temp.pData;
    temp.pData = new char[temp.len+1];
    strcpy(temp.pData, pData);
    strcat(temp.pData, rhs_s.pData);
    return temp;

}

String String::operator+(char rhs_c) const {
	return *this + String(rhs_c);
}

void String::erase() {
	*this = "";
}

std::ostream& operator<<(std::ostream& os, const String& s0) {
    os << s0.c_str();
    return os;
}

std::istream& operator>>(std::istream& is, String& s0) {
    unsigned char ch;
    s0 = String("");
	std::ios_base::fmtflags fl = is.flags();
	is.setf(ios_base::skipws);
    while (is >> ch) {
	    is.unsetf(ios_base::skipws);
        if (isspace(ch)) {
            is.putback(ch);
            break;
        } else {
            s0 = s0 + ch;
        }
    }
	is.setf(fl);
    return is;
}

String operator+(char ch, const String& str) {
	return String(ch) + str;
}
