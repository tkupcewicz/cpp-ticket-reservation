#include "stdafx.h"
#include "BiletRejsowy.h"
#include "Bilet.h"
#include <string>
#include<iostream>


void BiletRejsowy::wyswietl()
{
	std::cout << "Typ biletu: Rejs\nData: " + getData() + " " + getCzas() +
		"\nCzas podrozy: " + getCzasPodrozy() +
		"\nNazwa firmy: " + getNazwaFirmy() +
		"\nCena: " + std::to_string(getCena());
}

BiletRejsowy::BiletRejsowy():Bilet()
{
	for (int i = 0; i < rand() % 5 + 5; i++) {
		nazwaFirmy += 'a' + rand() % 26;
	}
}


BiletRejsowy::~BiletRejsowy()
{
}

std::string BiletRejsowy::getNazwaFirmy()
{
	return nazwaFirmy;
}
