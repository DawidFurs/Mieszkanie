#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <future>
#include <chrono>
#include <sstream>
#include <filesystem>
#include "Klient.h"
#include "WyszukiwarkaMieszkan.h"

namespace fs = std::filesystem;
using namespace std;

struct Lista
{
	Miejscowosc* head = nullptr;
	Miejscowosc* tail = nullptr;
};

Lista wczytajWszystko(string nazwaPliku, int& counter)
{
    ifstream file(nazwaPliku);

    if (!file.is_open())
    {
        cout << "Nie mozna otworzyc pliku: " << nazwaPliku << endl;
        exit(-1);
    }

    stringstream s;
    while (!file.eof())
    {
        string line;
        getline(file, line);
        auto index = line.find("//");
        if (index != string::npos)
        {
            line = line.substr(0, index);
        }
        s << line << endl;
    }
    file.close();

    int iloscMiejscowosci = 0;
    s >> iloscMiejscowosci;
    Lista miejscowosci;
    for (int i = 0; i < iloscMiejscowosci; i++, counter++)
    {
        Miejscowosc* m = new Miejscowosc();
        s >> *m;
        if (miejscowosci.head == nullptr)
        {
            miejscowosci.head = m;
        }
        else
        {
            miejscowosci.tail->setNext(m);
        }
        miejscowosci.tail = m;
    }
    return miejscowosci;
}

int main(int argc, char** argv)
{
    /*string filename = "TekstMieszkania.txt";
    string sourcePath = filename;
    string destinationPath = "T:\\test\\" + filename;
    if (!fs::exists("T:\\test\\"))
    {
        fs::create_directory("T:\\test\\");
    }
    if (fs::exists(destinationPath))
    {
        fs::remove(destinationPath);
    }
    fs::copy(sourcePath, destinationPath);*/

    int counter = 0;
    auto result = std::async(&wczytajWszystko, string("TekstMieszkania.txt"), ref(counter));
    cout << "Wczytywanie danych.." << endl;
    while(counter < 1)
    {
        cout << "\r";
        for (int j = 0; j <= counter; j++)
        {
            cout << "#";
        }
        cout << 4 * counter << "%";
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
    cout << "\n";
    result.wait();

	Klient klient(result.get().head);
	klient.menu();
	cout<< endl << "Dziala";
	return 0;
}