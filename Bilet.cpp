#include "stdafx.h"
#include "Bilet.h"
#include <string>


Bilet::Bilet()
{
	data = std::to_string(rand() % 31) + "." + std::to_string(rand() % 13) + ".2016";
	czas = std::to_string(rand() % 24) + ":" + std::to_string(rand() % 60);
	start = 'a' + rand() % 26;
	koniec = 'a' + rand() % 26;
	czasPodrozy = std::to_string(rand() % 10) + ":" + std::to_string(rand() % 60);
	cena = (rand() % 99) * 10 + 9;
}

Bilet::~Bilet()
{
}

std::string Bilet::getData()
{
	return(data);
}

std::string Bilet::getCzas()
{
	return(czas);
}

std::string Bilet::getStart()
{
	return(start);
}

std::string Bilet::getKoniec()
{
	return(koniec);
}

std::string Bilet::getCzasPodrozy()
{
	return(czasPodrozy);
}

void Bilet::setData(std::string d)
{
	data = d;
}

void Bilet::setCzas(std::string c)
{
	czas = c;
}

void Bilet::setStart(std::string s)
{
	start = s;
}

void Bilet::setKoniec(std::string k)
{
	koniec = k;
}

void Bilet::setCzasPodrozy(std::string cp)
{
	czasPodrozy = cp;
}

void Bilet::setCena(int c) {
	cena = c;
}

int Bilet::getCena()
{
	return cena;
}
