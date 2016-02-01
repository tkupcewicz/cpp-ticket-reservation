// RezerwacjaBiletow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Bilet.h"
#include "BiletLotniczy.h"
#include "BiletRejsowy.h"
#include "Baza.cpp"
#include "Rezerwacja.h"
#include <iostream>
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <vector>

using namespace std;

void zapisRezerwacji(Baza<Rezerwacja> r) {
	ofstream out("rezerwacje.txt");
	for (int i = 0; i < r.size(); i++) {
		out << r.get(i).toString();
	}
	out.close();
}

std::vector<std::string> &split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}

std::vector<std::string> split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}

Baza<Rezerwacja> wczytajRezerwacje() {
	ifstream in("rezerwacje.txt");
	std::string line;
	std::string i;
	std::string n;
	std::string t;
	std::string d;
	std::string c;
	std::string s;
	std::string k;
	std::string cp;
	std::string pc;
	Baza<Rezerwacja> rez;
	while (getline(in, line)) {
		std::vector<std::string> x = split(line, ';');
		pc = x.back();
		x.pop_back();
		cp = x.back();
		x.pop_back();
		k = x.back();
		x.pop_back();
		s = x.back();
		x.pop_back();
		c = x.back();
		x.pop_back();
		d = x.back();
		x.pop_back();
		t = x.back();
		x.pop_back();
		i = x.back();
		x.pop_back();
		n = x.back();
		Rezerwacja alfa = Rezerwacja(i, n, t, d, c, s, k, cp, pc);
		rez += alfa;
	}
	in.close();
	return rez;
}


		

int main()
{	

	srand(time(NULL));
	Baza<BiletLotniczy> biletyLotnicze;
	Baza<BiletRejsowy> biletyRejsowe;
	Baza<Rezerwacja> rezerwacje = wczytajRezerwacje();
	for (int i = 0; i < rand() % 5 + 5; i++) {
		BiletLotniczy l;
		biletyLotnicze += l;
	}
	for (int i = 0; i < rand() % 5 + 5; i++) {
		BiletRejsowy r;
		biletyRejsowe += r;
	}
	std::string a;
	std::string b;
	std::string nr;
	cout << "Wpisz:" << endl << "'1' aby zarezerwowac bilet" << endl << "'2' aby anulowac rezerwacje" << endl << "'3' aby wyswietlic rezerwacje" << endl << "'koniec' aby zakonczyc dzialanie programu" << endl;
	while (std::cin >> a) {
		if (a == "koniec") {
			
			system("cls");
			cout << "Czy na pewno chcesz wyjsc?" << endl << "tak/nie" << endl;
			cin >> b;
			if (b == "tak") {
				return 0;
			}
			else if (b == "nie") {
				system("cls");
			}
		}
		if (a == "1") {

			cout << "Bilety lotnicze: " << endl;
			for (int i = 0; i < biletyLotnicze.size(); i++) {
				cout << endl << i << ": " << endl;
				biletyLotnicze.get(i).wyswietl();
			}
			cout << "Bilety rejsowe: " << endl;
			for (int i = 0; i < biletyRejsowe.size(); i++) {
				cout << endl << i << ": " << endl;
				biletyRejsowe.get(i).wyswietl();
			}
			cout << endl;
			cout << "Wpisz: rejs 'nr' lub lot 'nr' aby zarezerwowac bilet\n";
			cin >> b >> nr;
			if (b == "rejs") {
				if (std::stoi(nr) > biletyRejsowe.size()) {
					cout << "Bledny numer\n";
					system("pause");
				}
				else {
					std::string im;
					std::string nazw;
					cout << "Na kogo ma zostac zapisana rezerwacja?\nImie:\n";
					cin >> im;
					cout << "Nazwisko:\n";
					cin >> nazw;
					Rezerwacja rez;
					rez.konwersja(biletyLotnicze.get(std::stoi(nr)));
					rez.setImie(im);
					rez.setNazwisko(nazw);
					rezerwacje += rez;
					zapisRezerwacji(rezerwacje);
					cout << "Rezerwacja pomyslnie przyjeta\n";
					system("pause");
				}
			}
			else if (b == "lot") {
				if (std::stoi(nr) > biletyLotnicze.size()) {
					cout << "Bledny numer\n";
					system("pause");
				}
				else {
					std::string im;
					std::string nazw;
					cout << "Na kogo ma zostac zapisana rezerwacja?\nImie:\n";
					cin >> im;
					cout << "Nazwisko:\n";
					cin >> nazw;
					Rezerwacja rez;
					rez.konwersja(biletyLotnicze.get(std::stoi(nr)));
					rez.setImie(im);
					rez.setNazwisko(nazw);
					rezerwacje += rez;
					zapisRezerwacji(rezerwacje);
					cout << "Rezerwacja pomyslnie przyjeta\n";
					system("pause");
					
				}
			}
			else {
				cout << "Bledna rezerwacja\n";
				system("pause");
			}
		}
		else if (a == "2") {
			cout << "Wpisz numer rezerwacji do anulowania\n";
			cin >> nr;
			if (std::stoi(nr) > rezerwacje.size()) {
				cout << "Bledny numer rezerwacji\n";
				system("pause");
			}
			else {
				rezerwacje.deleteElement(std::stoi(nr));
				cout << "Rezerwacja anulowana\n";
				zapisRezerwacji(rezerwacje);
				system("pause");
			}

		}
		else if (a == "3"){
			for (int i = 0; i < rezerwacje.size(); i++) {
				cout << endl << i << ": " << endl;
				rezerwacje.get(i).wyswietl();
				cout << endl;
			}
			system("pause");
		}
		system("cls");
		cout << "Wpisz:" << endl << "'1' aby zarezerwowac bilet" << endl << "'2' aby anulowac rezerwacje" << endl << "'3' aby wyswietlic rezerwacje" << endl << "'koniec' aby zakonczyc dzialanie programu" << endl;
	}

	system("PAUSE");
    return 0;
}

