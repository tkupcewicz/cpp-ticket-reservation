#include "stdafx.h"
#include "BiletLotniczy.h"
#include "Bilet.h"
#include <string>
#include<iostream>


void BiletLotniczy::wyswietl()
{
	std::cout << "Typ biletu: Lot\nData: " + getData() + " " + getCzas() +
		"\nCzas podrozy: " + getCzasPodrozy() +
		"\nLiczba personelu: " + std::to_string(getLiczbaPersonelu()) +
		"\nCena: " + std::to_string(getCena());
}

BiletLotniczy::BiletLotniczy():Bilet()
{
	liczbaPersonelu = rand() % 10;
}


BiletLotniczy::~BiletLotniczy()
{
}

int BiletLotniczy::getLiczbaPersonelu()
{
	return liczbaPersonelu;
}
