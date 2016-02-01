#include <string>
#include "Obiekt.h"
#pragma once
class Bilet : public Obiekt
{
private:
	std::string data;
	std::string czas;
	std::string start;
	std::string koniec;
	std::string czasPodrozy;
	int cena;

public:
	Bilet();
	~Bilet();
	std::string getData();
	std::string getCzas();
	std::string getStart();
	std::string getKoniec();
	std::string getCzasPodrozy();
	void setData(std::string d);
	void setCzas(std::string c);
	void setStart(std::string s);
	void setKoniec(std::string k);
	void setCzasPodrozy(std::string cp);
	void setCena(int c);
	int getCena();
	virtual void wyswietl() = 0;
};

