﻿//buddy - sasiad
#include <iostream>// ctrl +k,ctrl+d automatyczne formatowanie kodu 
#include <vector>
#include <stack>


using namespace std;

struct node {
	double value = 0;
	bool visited = false;
	vector <int> buddy;
};

void wypisz_graf(const vector<node>& graf) {
	cout << "\nAktualny graf :\n";
	for (int i = 1; i < graf.size(); ++i) {
		cout << "Wierzcholek " << i << ", wartosc: " << graf[i].value << ", sasiedzi: ";
		for (int sasiad : graf[i].buddy) {
			cout << sasiad << ",";
		}
		cout << endl;
	}
}

void wybranie_grafu1(vector<node>& graf) {
	cout << "\nWybrano graf 1" << endl;
	node w0 = { };
	node w1 = { 12, 0, {2, 3, 6, 7, 8} };
	node w2 = { 18, 0, {1, 3, 4, 8} };
	node w3 = { 24, 0, {1, 2, 5, 8} };
	node w4 = { 3, 0, {2} };
	node w5 = { 62, 0, {3} };
	node w6 = { 55, 0, {1} };
	node w7 = { 2137, 0, {1} };
	node w8 = { 123, 0, {1, 2, 3} };

	graf = { w0, w1, w2, w3, w4, w5, w6, w7, w8 };

	wypisz_graf(graf);
}

void wybranie_grafu2(vector<node>& graf) {
	cout << "\nWybrano graf 2" << endl;
	node w0 = { };
	node w1 = { 112, 0, {2,3,5} };
	node w2 = { 198, 0, {1,4,6} };
	node w3 = { 264, 0, {1,5} };
	node w4 = { 355, 0, {2,6} };
	node w5 = { 362, 0, {1,3,6} };
	node w6 = { 535, 0, {2,4,5} };

	graf = { w0, w1, w2, w3, w4, w5, w6 };

	wypisz_graf(graf);
}

void wybranie_grafu3(vector<node>& graf) {
	cout << "\nWybrano graf 3" << endl;
	node w0 = { };
	node w1 = { 121, 0, {4,9} };
	node w2 = { 184, 0, {3,10} };
	node w3 = { 224, 0, {2,4,6,8} };
	node w4 = { 31, 0, {1,3,7} };
	node w5 = { 62, 0, {7,8} };
	node w6 = { 55, 0, {3,8} };
	node w7 = { 2137, 0, {4,5,8} };
	node w8 = { 56, 0, {3,5,6,7} };
	node w9 = { 457, 0, {1,10} };
	node w10 = { 1233, 0, {2,9} };

	graf = { w0, w1, w2, w3, w4, w5, w6, w7, w8, w9, w10 };

	wypisz_graf(graf);
}

void dodaj_do_grafu(vector<node>& graf) { //do poprawy: dodawanie wierzcholka, gdy graf jest pusty i niektore warunki
	double value;
	cout << "Podaj wartosc nowego wierzcholka\n";
	cin >> value;

	node nowyWierzcholek;
	nowyWierzcholek.value = value;
	nowyWierzcholek.visited = false;
	graf.push_back(nowyWierzcholek);

	int ileKrawedzi;
	cout << "Ile krawedzi ma wychodzic z tego wierzcholka?\n";
	cin >> ileKrawedzi;
	if (ileKrawedzi >= 1 && ileKrawedzi < graf.size() - 1) {
		cout << "Do ktorych wierzcholkow maja prowadzic te krawedzie?\n";
		for (int i = 0; i < ileKrawedzi; ++i) {
			int buddy;
			cin >> buddy;
			if (buddy >= 1 && buddy < graf.size() - 1) {
				graf[graf.size() - 1].buddy.push_back(buddy);
				graf[buddy].buddy.push_back(graf.size() - 1);
			}
			else { cout << "Nie ma takiego wierzcholka!\n"; }
		}
	}
	else { cout << "Nie ma tylu wierzcholkow!\n"; }
	cout << "Nowy wierzcholek dodany do grafu.\n\n";
	wypisz_graf(graf);
};

void usun_puste_wierzcholki(vector<node>& graf) {
	for (int i = 1; i < graf.size();) {
		if (graf[i].buddy.empty()) {
			graf.erase(graf.begin() + i);
		}
		else {
			++i;
		}
	}
	// Aktualizacja sąsiadów
	for (int i = 1; i < graf.size(); ++i) {
		for (int& sasiad : graf[i].buddy) {
			if (sasiad > i) {
				--sasiad;
			}
		}
	}
	cout << "Usunieto puste wierzcholki i uporzadkowano graf.\n\n";
	wypisz_graf(graf);
}
//void usun_z_grafu(vector<node>& graf) {
//	if (graf.size() > 1) {
//		cout << "Co chcesz usunac :\n1 - wierzcholek \n2 - krawedz\n3 - wszystko\n";
//		int choice;
//		cin >> choice;
//		if (choice == 1) {
//			cout << "Ktory wierzcholek chcesz usunac?\n";
//			int ktory;
//			cin >> ktory;
//			if (ktory >= 1 && ktory < graf.size()) {
//				for (int i = 1; i < graf.size(); ++i) {  // Usuń wszystkie krawędzie prowadzące do tego wierzchołka
//					auto& buddies = graf[i].buddy;
//					buddies.erase(remove(buddies.begin(), buddies.end(), ktory), buddies.end());
//				}
//				// Usuń wszystkie krawędzie wychodzące z tego wierzchołka
//				graf[ktory].buddy.clear();
//				cout << "Wierzcholek " << ktory << " usuniety z grafu.\n\n";
//			}
//			else {
//				cout << "Nie ma takiego wierzcholka!\n";
//			}
//		}
//		else if (choice == 2) {
//			cout << "Ktora krawedz chcesz usunac?\n";
//			int start, koniec;
//			cin >> start >> koniec;
//			if (start >= 1 && start < graf.size() && koniec >= 1 && koniec < graf.size()) {
//				auto& startBuddies = graf[start].buddy;
//				startBuddies.erase(remove(startBuddies.begin(), startBuddies.end(), koniec), startBuddies.end());
//
//				auto& endBuddies = graf[koniec].buddy;
//				endBuddies.erase(remove(endBuddies.begin(), endBuddies.end(), start), endBuddies.end());
//
//				cout << "Krawedz pomiedzy wierzcholkami " << start << " i " << koniec << " usunieta z grafu.\n\n";
//
//			}
//			else {
//				cout << "Nie ma takich wierzcholkow!\n";
//			}
//		}
//		else if (choice == 3) {
//			graf.clear();
//			node w0 = { };
//			cout << "Graf zostal usuniety\n";
//		}
//		else {
//			cout << "Nie ma takiej operacji\n";
//		}
//	}
//	else {
//		cout << "Nie ma czego usuwac\n";
//	}
//	usun_puste_wierzcholki(graf);
//}
void usun_wierzcholek(vector<node>& graf, int& ktory) {
	bool przesuwanie = 0;
	graf[ktory] = { };

	for (int i = 1; i < graf.size(); i++) {
		przesuwanie = 0;
		for (int j = 0; j < graf[i].buddy.size(); j++) {
			if (graf[i].buddy[j] == ktory) {
				przesuwanie = 1;
			}
			if (przesuwanie && j < graf[i].buddy.size() - 1) {
				graf[i].buddy[j] = graf[i].buddy[j + 1];
			}
			else if (przesuwanie) {
				graf[i].buddy.pop_back();
				//cout << "graf" << i << "zawiera " << graf[i].buddy.size() <<endl;
			}
		}
	}

	for (int i = ktory; i < graf.size() - 1; i++) {
		graf[i] = graf[i + 1];
	}
	graf.pop_back();

	//cout << "teraz graf zawiera " << graf.size()<<"-1"<<endl;

	for (int i = 1; i < graf.size(); i++) {
		for (int j = 0; j < graf[i].buddy.size(); j++) {

			if (graf[i].buddy[j] > ktory) {
				--graf[i].buddy[j];
			}
		}
	}


		wypisz_graf(graf);
}


void usun_z_grafu(vector<node>& graf) {
	int choice;
	if (graf.size() > 1) {
		cout << "Co chcesz usunac :\n1 - wierzcholek \n2 - krawedz\n3 - wszystko\n";
		cin >> choice;
	}
	switch (choice)
	{
	case 1:
		cout << "Ktory wierzcholek chcesz usunac?\n";
		int ktory;
		cin >> ktory;

		usun_wierzcholek(graf, ktory);
		break;
	case 2:

		break;
	case 3:


		break;
	default:
		break;
	}
}

void menu(bool& exit_menu, vector<node>& graf, bool& exit) {

	int choice;

	cout << "\n1. Wybieranie grafu 1\n";
	cout << "2. Wybieranie grafu 2\n";
	cout << "3. Wybieranie grafu 3\n";
	cout << "4. Dodawanie do grafu\n";
	cout << "5. Usuwanie z grafu\n";
	cout << "6. Odpal DFS\n";
	cout << "7. EXIT \n";

	cin >> choice;

	switch (choice) {
	case 1:
		wybranie_grafu1(graf);
		break;
	case 2:
		wybranie_grafu2(graf);
		break;
	case 3:
		wybranie_grafu3(graf);
		break;
	case 4:
		dodaj_do_grafu(graf);
		break;
	case 5:
		usun_z_grafu(graf);
		break;
	case 6:
		exit_menu = 1;//dfs
		break;
	case 7:
		exit = 1;
		exit_menu = 1;
		break;

	default:
		cout << "Nie ma takiej funkcji\n";

	}
}

void setup(vector<node> graf, stack<int>& stos, int& maxValue, bool& przeszukany) {
	przeszukany = 0;

	for (int i = 1; i < graf.size(); i++) {
		graf[i].visited = 0;

	}
	if (graf.size() >= 2) {// Sprawdź, czy istnieje pierwszy wierzchołek 
		maxValue = graf[1].value;
		graf[1].visited = true;
		if (!graf[1].buddy.empty()) {// Sprawdź, czy wektor buddy pierwszego wierzchołka nie jest pusty

			stos.push(1);//zaczynamy algorym zawsze od pierwszego wierzchołka 
		}
		else {
			cout << "Wektor buddy pierwszego wierzcholka grafu jest pusty" << endl;
		}
	}
	else {
		cout << "Wektor graf jest pusty" << endl;
	}


}
void DFS(vector<node>& graf, stack<int>& stos, bool& przeszukany, int& maxValue) {

	if (!graf[stos.top()].visited) {//poszukiwanie wartości w nowym wierzchołku 
		if (maxValue < graf[stos.top()].value) {
			maxValue = graf[stos.top()].value;
		}
		graf[stos.top()].visited = true;
	}
	cout << "Stos top: " << stos.top() << endl;
	for (int i = 0; i < graf[stos.top()].buddy.size(); i++)//iterowanie po sąsiadach wierzchołka
	{ //graf[1].buddy ,, stos.top = 1
		int tempSasiad = graf[stos.top()].buddy[i];
		if (!graf[tempSasiad].visited)//sprawdzanie czy sąsiad nie był odwiedzony
		{
			stos.push(tempSasiad);
			return;

		}

	}
	stos.pop();
	if (!stos.empty()) cout << "Stos top po pop: " << stos.top() << endl;
	if (stos.empty()) {
		przeszukany = 1;
	}
}

int main()
{
	int maxValue;
	bool exit_menu = 0;
	bool przeszukany = 0;
	bool exit = 0;
	vector<node>graf;
	stack<int>stos;
	cout << "Algorytm DFS przeszukujacy graf \n";
	cout << "Made by Jakub Kozlowski 197623 & Szymon Mielniczak 197956\n";

	while (!exit) {
		exit_menu = 0;
		while (!exit_menu)
		{
			menu(exit_menu, graf, exit);
		}
		if (!exit) {
			setup(graf, stos, maxValue, przeszukany);
			while (!przeszukany)
			{
				DFS(graf, stos, przeszukany, maxValue);
			}
			cout << "Max value wynosi: " << maxValue;
		}
	}
}
//
