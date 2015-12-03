#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "SaveFile.h"
#include "LoadFile.h"
#include "mapEditor.h"
#include "gamedriver.h"
#include "player.h"
#include "map.h"

using namespace std;

int Menu();
void Play();
void CreateEdit();
bool fileExist(string, string);

void main()
{
	int option;
	string mapname;
	
	while(true)
	{
		option=Menu();

		if(option==1)
		{
			cin.clear(); // reset failbit
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			system("cls");
			Play();
			system("pause");
			break;
		}
		else if(option==2)
		{
			cin.clear(); // reset failbit
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			system("cls");
			CreateEdit();
		}
		else
			break;
	}

}

int Menu()
{
	int option;

	cout<<"Welcome to RISK!\n\n";
	cout<<"Main menu\n\n";
	cout<<"1.Play Now\n";
	cout<<"2.Create/Edit Map\n";
	cout<<"3.Exit game\n";

	while(!(cin>>option) || option < 1 || option > 3)
	{
		cin.clear(); // reset failbit
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
		// next, request user reinput
		cout << "Invalid input. Please try again(digits only):\n";
	}

	return option;
}

void Play()
{
	Map gameMap;
	vector<Player>* players;
	
	string mapName, fileExtension;
	LoadFile loader;

	cout<<"Please enter the name of the map you want to play on: ";
	getline(cin,mapName);

	cout << "Please enter the file format(map or txt): ";
	getline(cin, fileExtension);

	while (fileExtension != "map" && fileExtension != "txt")
	{
		cout << "Invalid file type. Please enter a correct file type(map or txt): ";
		getline(cin, fileExtension);
	}

	while(!fileExist(mapName, fileExtension))
	{
		cout<<"Map does not exist. Please chose a valid map(ex:World): ";
		getline(cin,mapName);

		cout << "Please enter the file format(map or txt): ";
		getline(cin, fileExtension);

		while (fileExtension != "map" && fileExtension != "txt")
		{
			cout << "Invalid file type. Please enter a correct file type(map or txt): ";
			getline(cin, fileExtension);
		}
	}

	if (!loader.load(fileExtension, mapName))
		return;

	gameMap = loader.getMap();
	
	GameDriver driver(gameMap);

	driver.gameSetup();
	driver.phaseController();
}

void CreateEdit(void)
{
	string file, fileExtension;
	int option;

	MapEditor editor;

	while (true)
	{
		system("cls");

		cout << "1.Create new map\n";
		cout << "2.Edit existing map\n";
		cout << "3.Exit\n";
		cout << "Please choose one of the option above(digits only):\n";

		while (!(cin >> option) || option < 1 || option > 3)
		{
			cin.clear(); // reset failbit
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			// next, request user reinput
			cout << "Invalid input. Please try again(digits only):\n";
		}

		if (option == 1)
		{
			
			cin.clear(); // reset failbit
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			editor.createMap();
		}
		else if (option == 2)
		{
			
			cin.clear(); // reset failbit
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << "\nPlease enter the name of the map to be edited:\n";
			getline(cin, file);

			cout << "Please enter the file format(map or txt): ";
			getline(cin, fileExtension);

			while (fileExtension != "map" && fileExtension != "txt")
			{
				cout << "Invalid file type. Please enter a correct file type(map or txt): ";
				getline(cin, fileExtension);
			}

			editor.editMap(fileExtension, file);
		}
		else
		{
			system("cls");
			break;
		}

	}
}

bool fileExist(string name, string extension) 
{
	ifstream in;

	in.open("../MapFiles/"+name+"."+extension);
	
	if(in.fail())
		return false;

	in.close();
	return true;
}