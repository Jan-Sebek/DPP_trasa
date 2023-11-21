// DPP_trasa.cpp : Tento soubor obsahuje funkci main. Provádění programu se tam zahajuje a ukončuje.
//

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include "Stop.h"
#include "functions.h"


using namespace std;


int main()
{
	map<string, Stop> stop_list;
	cout << "Loading data, please wait ... (est. time 1 min)" << endl;
	//ofstream otu("otu.txt");

	loadStops(stop_list, "stops.txt");
	
	setupEgdes(stop_list, "stop_times.txt");

	cout << "Data succesfully loaded" << endl;
	/*
	for (pair<string, Stop> s : stop_list)
	{
		otu << s.second.getName() << ": " << s.second.getNeighbours(stop_list) << endl;
	}*/
	while (true)
	{
		cout << "Do u want to search Prague ? (y/n) ";
		char y_n = 'n';
		cin >> y_n;
		if (y_n != 'y') { break; }
		string start;
		string finish;
		while (true)
		{
			cout << "Enter part of starting station name: ";
			cin >> start;
			printOptions(stop_list, start);
			cout << "is you station here ? (y/n) ";
			cin >> y_n;
			if (y_n == 'n') { cout << "shame, try again" << endl; continue; }
			cout << "Enter starting station code: ";
			cin >> start;
			cout << "U have selected: " << stop_list[start].getName() << "; Are u satisfied ? (y/n) ";
			cin >> y_n;
			if (y_n == 'y') { break; }
		}
		while (true)
		{
			cout << "Enter part of destination name: ";
			cin >> finish;
			printOptions(stop_list, finish);
			cout << "is you station here ? (y/n)";
			cin >> y_n;
			if (y_n == 'n') { cout << "shame, try again" << endl; continue; }
			cout << "Enter target station code: ";
			cin >> finish;
			cout << "U have selected: " << stop_list[finish].getName() << "; Are u satisfied ? (y/n) ";
			cin >> y_n;
			if (y_n == 'y') { break; }
		}

		list<Stop> path;
		findPath(stop_list, start, finish, path);

		for (Stop s : path)
		{
			cout << s.getName() << endl;
		}

	}



	cout << "Everything ok ! :D" << endl;
}


// Spuštění programu: Ctrl+F5 nebo nabídka Ladit > Spustit bez ladění
// Ladění programu: F5 nebo nabídka Ladit > Spustit ladění

// Tipy pro zahájení práce:
//   1. K přidání nebo správě souborů použijte okno Průzkumník řešení.
//   2. Pro připojení ke správě zdrojového kódu použijte okno Team Explorer.
//   3. K zobrazení výstupu sestavení a dalších zpráv použijte okno Výstup.
//   4. K zobrazení chyb použijte okno Seznam chyb.
//   5. Pokud chcete vytvořit nové soubory kódu, přejděte na Projekt > Přidat novou položku. Pokud chcete přidat do projektu existující soubory kódu, přejděte na Projekt > Přidat existující položku.
//   6. Pokud budete chtít v budoucnu znovu otevřít tento projekt, přejděte na Soubor > Otevřít > Projekt a vyberte příslušný soubor .sln.
