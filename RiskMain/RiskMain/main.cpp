#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "save.h"
#include "load.h"
#include "mapEditor.h"
#include "gamedriver.h"
#include "player.h"
#include "map.h"

using namespace std;

int Menu();
void Play();
void CreateEdit();
bool fileExist(string);

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
	
	string mapName;

	cout<<"Please enter the name of the map you want to play on: ";
	getline(cin,mapName);

	while(!fileExist(mapName))
	{
		cout<<"Map does not exist. Please chose a valid map(ex:World): ";
		getline(cin,mapName);
	}

	Load LD("../MapFiles/"+mapName+".map");
	gameMap = LD.getMap();
	
	GameDriver driver(gameMap);

	driver.gameSetup();
}

void CreateEdit(void)
{
	MapEditor editor;
	string file;
	int option;

	while(true)
	{
		cout<<"1.Create new map\n";
		cout<<"2.Edit existing map\n";
		cout<<"3.Exit\n";
		cout<<"Please choose one of the option above(digits only):\n";
		
		while(!(cin>>option) || option < 1 || option > 3)
		{
			cin.clear(); // reset failbit
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			// next, request user reinput
			cout << "Invalid input. Please try again(digits only):\n";
		}

		if(option == 1)
		{
			cin.clear(); // reset failbit
			cin.ignore(numeric_limits<streamsize>::max(),'\n');
			
			editor.createMap();
		}
		else if(option==2)
		{
			cin.clear(); // reset failbit
			cin.ignore(numeric_limits<streamsize>::max(),'\n');

			cout<<"\nPlease enter the name of the map to be edited(ex:a1.map):\n";
			getline(cin,file);

			editor.editMap("../MapFiles/"+file);
		}
		else
			break;
	}
}

bool fileExist(string name) 
{
	ifstream in;

	in.open("../MapFiles/"+name+".map");
	
	if(in.fail())
		return false;

	in.close();
	return true;
}