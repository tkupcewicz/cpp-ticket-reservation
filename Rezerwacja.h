#pragma once
#include "Bilet.h"
#include "BiletLotniczy.h"
#include "BiletRejsowy.h"
class Rezerwacja : public Bilet
{
private:
	std::string typ;
	std::string imie;
	std::string nazwisko;
public:
	Rezerwacja::Rezerwacja();
	Rezerwacja::Rezerwacja(std::string i, std::string n, std::string t, std::string d, std::string c, std::string s, std::string k, std::string cp, std::string pc);
	~Rezerwacja();
	void konwersja(BiletLotniczy b);
	void konwersja(BiletRejsowy b);
	void setImie(std::string i);
	void wyswietl();
	void setNazwisko(std::string n);
	void setTyp(std::string ty);
	std::string toString();
};

