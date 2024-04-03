//buddy - sasiad
#include <iostream>// ctrl +k,ctrl+d automatyczne formatowanie kodu 
#include <vector>
#include <stack>


using namespace std;

struct node {
	double value;
	bool visited;
	vector <int> buddy;
};

void wybranie_grafu1(vector<node>& graf) {
	cout << "Wybrano graf 1" << endl;
	node w0 = { };
	node w1 = { 12, 0, {2, 3, 6, 7, 8} };
	node w2 = { 18, 0, {1, 3, 4, 8} };
	node w3 = { 24, 0, {1, 2, 6, 8} };
	node w4 = { 3, 0, {2} };
	node w5 = { 62, 0, {3} };
	node w6 = { 55, 0, {1} };
	node w7 = { 2137, 0, {1} };
	node w8 = { 123, 0, {1, 2, 3} };

	graf = { w0, w1, w2, w3, w4, w5, w6, w7, w8 };

	for (int i = 1; i < graf.size(); ++i) {
		cout << "Wierzcholek " << i << ", wartosc: " << graf[i].value << ", sasiedzi: ";
		for (int sasiad : graf[i].buddy) {
			cout << sasiad << ",";
		}
		cout << endl;
	}
}
void wybranie_grafu2(vector<node>& graf) {
	cout << "Wybrano graf 2" << endl;
	node w0 = { };
	node w1 = { 112, 0, {2,3,5} };
	node w2 = { 198, 0, {1,4,6} };
	node w3 = { 264, 0, {1,5} };
	node w4 = { 355, 0, {2,6} };
	node w5 = { 362, 0, {1,3,6} };
	node w6 = { 535, 0, {2,4,5} };

	graf = { w0, w1, w2, w3, w4, w5, w6 };

	for (int i = 1; i < graf.size(); ++i) {
		cout << "Wierzcholek " << i << ", wartosc: " << graf[i].value << ", sasiedzi: ";
		for (int sasiad : graf[i].buddy) {
			cout << sasiad << ",";
		}
		cout << endl;
	}
}
void wybranie_grafu3(vector<node>& graf) {
	cout << "Wybrano graf 3" << endl;
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

	for (int i = 1; i < graf.size(); ++i) {
		cout << "Wierzcholek " << i << ", wartosc: " << graf[i].value << ", sasiedzi: ";
		for (int sasiad : graf[i].buddy) {
			cout << sasiad << ",";
		}
		cout << endl;
	}
}

void dodaj_do_grafu(vector<node>& graf) {
	cout << "2";
};
void usun_z_grafu(vector<node>& graf) {
	cout << "3";
};


void menu(bool& exit, vector<node>& graf) {

	int choice;

	cout << "1. Wybieranie grafu 1\n";
	cout << "2. Wybieranie grafu 2\n";
	cout << "3. Wybieranie grafu 3\n";
	cout << "4. Dodawanie do grafu\n";
	cout << "5. Usuwanie z grafu\n";
	cout << "6. exit\n";

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
		exit = 1;
		break;

	default:
		cout << "Nie ma takiej funkcji\n";

	}
}

void setup(vector<node> graf, stack<int>& stos,int &maxValue) {


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
void DFS(vector<node>& graf, stack<int>& stos, bool przeszukany, int &maxValue) {

	if (!graf[stos.top()].visited) {//poszukiwanie wartości w nowym wierzchołku 
		if (maxValue < graf[stos.top()].value) {
			maxValue = graf[stos.top()].value;
		}
		graf[stos.top()].visited = true;
	}

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
}

int main()
{
	int maxValue;
	bool exit = 0;
	bool przeszukany = 0;
	vector<node>graf;
	stack<int>stos;
	cout << "Algorytm DFS przeszukujacy graf \n";
	cout << "Made by Jakub Kozlowski 197623 & Szymon Mielniczak 197956\n";


	while (!exit)
	{
		menu(exit, graf);
	}

	setup(graf, stos,maxValue);
	while (!przeszukany)
	{
		DFS(graf, stos, przeszukany,maxValue);
	}
}

