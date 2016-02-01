#pragma once
#include "Bilet.h"
class BiletLotniczy : public Bilet
{
private:
	int liczbaPersonelu;
public:
	void wyswietl();
	BiletLotniczy();
	~BiletLotniczy();
	int getLiczbaPersonelu();
};

