#pragma once
#include "Pozycja.h"

#include <iostream>
using namespace std;

class ObiektUzytecznosci
{
private:
	string nazwa;
	Pozycja pozycja;

public:
	string getNazwa();
	friend ostream& operator<<(ostream& os, ObiektUzytecznosci& ob);
	friend istream& operator>>(istream& is, ObiektUzytecznosci& ob);
	Pozycja getPozycja() { return pozycja; }
};

ostream& operator<<(ostream& os, ObiektUzytecznosci& ob);
istream& operator>>(istream& is, ObiektUzytecznosci& ob);