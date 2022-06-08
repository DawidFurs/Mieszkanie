#pragma once
#include "Osoba.h"
#include "WyszukiwarkaMieszkan.h"
#include <regex>

class Miejscowosc;

class Klient : public Osoba
{
public:
	string ulica;
	string miasto;
	string kodPocztowy;
	int wiek;
	Miejscowosc* miejscowosci;
	WyszukiwarkaMieszkan wyszukiwarka;

	Klient(Miejscowosc* miejscowosci);
	Klient(string imie, string nazwisko, int id, string ulica, string miasto, string kodPocztowy, int wiek);
	void menu();
	void realizujOpcje(int opcja);
	void wyszukajPoCenie();
	void kupno();
	void sprzedaz();
	Blok* wybierzBlok();

	friend ostream& operator<<(ostream& os, Klient& p);
	friend istream& operator>>(istream& is, Klient& p);
};

ostream& operator<<(ostream& os, Klient& p);
istream& operator>>(istream& is, Klient& p);