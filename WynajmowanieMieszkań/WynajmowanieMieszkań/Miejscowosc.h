#include <iostream>
#include <vector>
#include <thread>
#include <future>
#include <algorithm>
#include "Blok.h"
#include "ObiektUzytecznosci.h"

using namespace std;

class Miejscowosc
{

	std::string nazwa;
	vector<Blok> bloki;
	vector<ObiektUzytecznosci> obiektyUzytecznosci;
	Miejscowosc* next = nullptr;
public:
	std::string getNazwa() { return nazwa; }
	Miejscowosc* getNext() { return next; }
	void setNext(Miejscowosc* next) { this->next = next; }
	void pokaz();
	Blok* wybieszblok();

	friend std::ostream& operator<<(std::ostream& os, Miejscowosc& m);
	friend std::istream& operator>>(std::istream& is, Miejscowosc& m);
	friend class WyszukiwarkaMieszkan;
};

  std::ostream& operator<<(std::ostream& os, Miejscowosc& m);
  std::istream& operator>>(std::istream& is, Miejscowosc& m);