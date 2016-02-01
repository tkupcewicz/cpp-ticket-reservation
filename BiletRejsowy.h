#pragma once
#include "Bilet.h"
class BiletRejsowy : public Bilet
{
private:
	std::string nazwaFirmy;
	
public:
	void wyswietl();
	BiletRejsowy();
	~BiletRejsowy();
	std::string getNazwaFirmy();
};

