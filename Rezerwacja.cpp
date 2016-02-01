#include "stdafx.h"
#include "Rezerwacja.h"
#include <string>
#include <iostream>

Rezerwacja::Rezerwacja() {

}

Rezerwacja::Rezerwacja(std::string i, std::string n, std::string t, std::string d, std::string c, std::string s, std::string k, std::string cp, std::string pc)
{
	imie = i;
	nazwisko = n;
	typ = t;
	setData(d);
	setCzas(c);
	setStart(s);
	setKoniec(k);
	setCzasPodrozy(cp);
	setCena(std::stoi(pc));
}


Rezerwacja::~Rezerwacja()
{
}

void Rezerwacja::konwersja(BiletLotniczy b)
{ 
	typ = "lot";
	setData(b.getData());
	setCzas(b.getCzas());
	setStart(b.getStart());
	setKoniec(b.getKoniec());
	setCzasPodrozy(b.getCzasPodrozy());
	setCena(b.getCena());
}

void Rezerwacja::konwersja(BiletRejsowy b)
{
	typ = "rejs";
	setData(b.getData());
	setCzas(b.getCzas());
	setStart(b.getStart());
	setKoniec(b.getKoniec());
	setCzasPodrozy(b.getCzasPodrozy());
	setCena(b.getCena());
}

void Rezerwacja::setImie(std::string i)
{
	imie = i;
}

void Rezerwacja::setNazwisko(std::string n)
{
	nazwisko = n;
}

void Rezerwacja::setTyp(std::string ty)
{
	typ = ty;
}

std::string Rezerwacja::toString()
{
	std::string a;
	a = imie + ";" + nazwisko + ";" + typ + ";" + getData() + ";" + getCzas() + ";" + getStart() + ";" + getKoniec() + ";" + getCzasPodrozy() + ";" + std::to_string(getCena()) + "\n";
	return a;
}

void Rezerwacja::wyswietl()
{
	std::cout << "Imie: " + imie +
		"\nNazwisko: " + nazwisko +
		"\nTyp biletu: " + typ + 
		"\nData: " + getData() +
		"\nGodzina: " + getCzas() +
		"\nZ: " + getStart() +
		"\nDo: " + getKoniec() +
		"\nCzas podrozy: " + getCzasPodrozy() +
		"\nCena: " + std::to_string(getCena());
}
