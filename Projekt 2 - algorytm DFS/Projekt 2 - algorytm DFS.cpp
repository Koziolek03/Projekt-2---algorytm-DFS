//buddy - sasiad
#include <iostream>
#include <vector>
using namespace std;

struct wektory {
    double value;
    bool visited;
    vector <int> buddy;
};

void wybranie_grafu1() {
    cout << "Wybrano graf 1" << endl;

    wektory w1 = { 12, 0, {2, 3, 6, 7, 8} };
    wektory w2 = { 18, 0, {1, 3, 4, 8} };
    wektory w3 = { 24, 0, {1, 2, 6, 8} };
    wektory w4 = { 3, 0, {2} };
    wektory w5 = { 62, 0, {3} };
    wektory w6 = { 55, 0, {1} };
    wektory w7 = { 2137, 0, {1} };
    wektory w8 = { 123, 0, {1, 2, 3} };

    vector<wektory> graf = { w1, w2, w3, w4, w5, w6, w7, w8 };

    for (int i = 0; i < graf.size(); ++i) {
        cout << "Wierzcholek "<< i <<", wartosc: " << graf[i].value << ", sasiedzi: ";
        for (int sasiad : graf[i].buddy) {
            cout << sasiad << ",";
        }
        cout << endl;
    }
}
void wybranie_grafu2() {
    cout << "Wybrano graf 2" << endl;

    wektory w1 = { 112, 0, {2,3,5} };
    wektory w2 = { 198, 0, {1,4,6} };
    wektory w3 = { 264, 0, {1,5} };
    wektory w4 = { 355, 0, {2,6} };
    wektory w5 = { 362, 0, {1,3,6} };
    wektory w6 = { 535, 0, {2,4,5} };

    vector<wektory> graf = { w1, w2, w3, w4, w5, w6 };

    for (int i = 0; i < graf.size(); ++i) {
        cout << "Wierzcholek " << i << ", wartosc: " << graf[i].value << ", sasiedzi: ";
        for (int sasiad : graf[i].buddy) {
            cout << sasiad << ",";
        }
        cout << endl;
    }
}
void wybranie_grafu3() {
    cout << "Wybrano graf 3" << endl;

    wektory w1 = { 121, 0, {4,9} };
    wektory w2 = { 184, 0, {3,10} };
    wektory w3 = { 224, 0, {2,4,6,8} };
    wektory w4 = { 31, 0, {1,3,7} };
    wektory w5 = { 62, 0, {7,8} };
    wektory w6 = { 55, 0, {3,8} };
    wektory w7 = { 2137, 0, {4,5,8} };
    wektory w8 = { 56, 0, {3,5,6,7} };
    wektory w9 = { 457, 0, {1,10} };
    wektory w10 = { 1233, 0, {2,9} };

    vector<wektory> graf = { w1, w2, w3, w4, w5, w6, w7, w8, w9, w10 };

    for (int i = 0; i < graf.size(); ++i) {
        cout << "Wierzcholek " << i << ", wartosc: " << graf[i].value << ", sasiedzi: ";
        for (int sasiad : graf[i].buddy) {
            cout << sasiad << ",";
        }
        cout << endl;
    }
}

    void dodaj_do_grafu() {
        cout << "2";
    };
    void usun_z_grafu() {
        cout << "3";
    };


    void menu() {
        bool exit = 0;
        int choice;
        while(!exit){
        cout << "1. Wybieranie grafu 1\n";
        cout << "2. Wybieranie grafu 2\n";
        cout << "3. Wybieranie grafu 3\n";
        cout << "4. Dodawanie do grafu\n";
        cout << "5. Usuwanie z grafu\n";
        cout << "6. exit\n";

        cin >> choice;

        switch (choice) {
        case 1:
            wybranie_grafu1();
            break;
        case 2:
            wybranie_grafu2();
            break;
        case 3:
            wybranie_grafu3();
            break;
        case 4:
            dodaj_do_grafu();
            break;
        case 5:
            usun_z_grafu();
            break;
        case 6:
            exit = 1;
            break;
        }
    }
    }

    int main()
    {
    cout << "Algorytm DFS przeszukujacy graf \n";
    cout << "Made by Jakub Kozlowski 197623 & Szymon Mielniczak 197956\n";

    menu();
   
}

