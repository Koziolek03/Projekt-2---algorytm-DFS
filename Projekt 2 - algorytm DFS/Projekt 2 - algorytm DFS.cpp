//buddy - sasiad
#include <iostream>
#include <vector>
using namespace std;

struct wektory {
    double value;
    bool visited;
    vector <int> buddy;
};

    void wybranie_grafu() {
        cout << "1";
    };
    void dodaj_do_grafu() {
        cout << "2";
    };
    void usun_z_grafu() {
        cout << "3";
    };


    void menu() {

        int choice;

        cout << "1. Wybieranie grafu\n";
        cout << "2. Dodawanie do grafu\n";
        cout << "3. Usuwanie z grafu\n";

        cin >> choice;

        switch (choice) {
        case 1:
            wybranie_grafu();
            break;

        case 2:

            dodaj_do_grafu();
            break;

    case 3:

            usun_z_grafu();
            break;

        }
    };

    int main()
    {
    cout << "Algorytm DFS przeszukujacy graf \n";
    cout << "Made by Jakub Kozlowski 197623 & Szymon Mielniczak 197956\n";

    menu();
   
}

