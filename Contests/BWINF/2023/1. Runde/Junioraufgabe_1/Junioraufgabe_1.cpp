#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define endl "\n"
#define all(x) (x).begin(), (x).end()
#define MOD 1000000007

// main class welche command-line Eingaben annimmt 
int main(int argc, char* argv[]) {
    // input von der Datei einlesen, welche in der command-line als Argument gegeben wurde
    ifstream fin(argv[1]);
    
    ios::sync_with_stdio(0);
    cin.tie(0);

    // Variablen für Anzahl von Tüten und Spielen definieren und einlesen
    int anzahl_tueten, anzahl_spiele; fin >> anzahl_tueten >> anzahl_spiele;
    // Anzahl an Spielen pro "Sorte" einlesen und in einem Vector speichern
    vector<int> spiele(anzahl_spiele);
    for(auto &x: spiele) fin >> x;

    // Vector welcher für jede Tüte von einem Kind einen Vector speichert in welchem die Spiele gespeichert werden welche in die Tüte kommen
    vector<vector<int>> tueten(anzahl_tueten);

    // Spiele verteilen; Algorithmus in Dokumentation erklärt
    int cur = 0;
    for(int i=0; i<anzahl_spiele; i++) {
        for(int j=0; j<spiele[i]; j++) {
            tueten[cur].push_back(i+1);
            cur++;
            cur %= anzahl_tueten;
        }
    }

    // Lösung ausgeben
    for(int i=0; i<anzahl_tueten; i++) {
        cout << "T\x81te " << i+1 << ": ";
        for(auto &x: tueten[i]) cout << x << " ";
        cout << endl;
    }
}