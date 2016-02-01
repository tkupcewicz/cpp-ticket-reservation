#include "stdafx.h"
#include <vector>
template <class T> class Baza {
private:
	std::vector <T> lista;
public:
	
	Baza::Baza() {
		
	}
	void LadujPlik() {

	}
	void ZapiszDoPliku() {

	}

	void operator+= (T t) {
		lista.push_back(t);
	}

	void operator-= (T t) {
		//
	}

	void deleteElement(int index) {
		lista.erase(lista.begin() + index);
	}

	unsigned int size() {
		return lista.size();
	}
	
	T get(int i) {
		return lista[i];
	}

};