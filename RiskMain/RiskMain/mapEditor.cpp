/*
mapEditor.cpp
SaveLoad for Risk

Created by Dich-Ky Tran on 10/10/2015
Copyright (C) 2015 Dich-Ky Tran. All right reserved.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "mapEditor.h"
#include "load.h"
#include "save.h"

#include "continent.h"
#include "territory.h"

using namespace std;

MapEditor::MapEditor()
{
}

void MapEditor::editMap(string filePath)
{	
	try
	{
		Load load(filePath);		//Loading existing map to edit
		this->map = load.getMap();

		while(true)
		{
			system("cls");

			int option;

			cout << "1. Create Continent\n";
			cout << "2. Create Territory\n";
			cout << "3. Assign Territory to Continent\n";
			cout << "4. Assign Adjacent Territories\n";
			cout << "5. Save and return to main Menu\n";
			cout << "Please an option(digits only):\n";

			while(!(cin>>option) || option < 1 || option > 5)
			{
				cin.clear(); // reset failbit
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				// next, request user reinput
				cout << "Invalid input. Please try again(digits only):\n";
			}

			if(option==1)				//Creating Continents
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				system("cls");
				createContinent();
			}
			else if(option==2)			//Creating Territories
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				system("cls");
				createTerritory();
			}
			else if(option==3)			//Adding Territories to Continents
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				system("cls");
				int index;
				string name;

				vector<Continent> continents=this->map.continents;

				cout<<"Please enter a Continent to assign Territories to: ";
				getline(cin,name);

				while(!continentExist(name))
				{
					cout<<"Invalid Continent. Please enter a valid Continent:\n";
					getline(cin,name);
				}

				for (int i=0;i<continents.size();i++) 
				{
					if(continents[i].getName() == name)
						index = i;
				}

				system("cls");

				assignTerrToCont(continents[index].getName());
			}
			else if(option==4)					//Adding adjacent Territory
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(),'\n');
				system("cls");
				int index;
				string name;

				cout<<"Please enter a Territory to assign Adjacent Territories to: ";
				getline(cin,name);

				while(!territoryExist(name))
				{
					cout<<"Invalid Territory. Please enter a valid Territory:\n";
					getline(cin,name);
				}

				for (int i=0;i<this->map.territories.size();i++)				//grabbing the index of the Territory to modify it
				{
					if(this->map.territories[i].getName() == name)
						index = i;
				}

				system("cls");

				assignAdjTerr(this->map.territories[index]);

				////Testing output
				//system("cls");
				//for(string c:this->map.territories[index].getAdjTerritory())
				//{
				//	cout<<c+" ";
				//}
				//cout<<endl;
			}
			else if (option==5)
			{
				Save save(map,filePath);		//Sending the map and file path where to write and save the .map text file
				break;
			}
		}
	}
	catch(string e ) {
		cout << e;
	}
}

void MapEditor::createMap()
{
	system("cls");
	string fileName,author,ans;

	cout<<"Creating new map\n\n";
	cout<<"Please enter the Name of the new Map: ";
	getline(cin,fileName);

	while(fileExist(fileName))
	{
		cout<<"This map already exist, please choose another name: ";
		getline(cin,fileName);
	}

	cout<<"\nPlease enter your name as the Author: ";
	getline(cin,author);

	this->map.setAuthor(author);
	this->map.setImage("world.bmp");
	this->map.setWrap("no");
	this->map.setScroll("horizontal");
	this->map.setWarn("yes");

	system("cls");

	cout<<"Creating Continents\n\n";
	
	while(true){
		createContinent();
		
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');

		cout<<"Would you like to add more Continents?(y/n): ";
		getline(cin,ans);
		
		while(ans!="y" && ans!="yes" && ans!="n" && ans!="no")
		{
			cout<<"Invalid input. Answer\"y\" or \"n\": ";
			getline(cin,ans);
		}

		if(ans=="n" || ans =="no")
			break;
		system("cls");
	}
	
	system("cls");

	cout<<"Creating Territories\n\n";

	while(true){
		createTerritory();

		cout<<"Would you like to add more Territories?(y/n): ";
		getline(cin,ans);
		
		while(ans!="y" && ans!="yes" && ans!="n" && ans!="no")
		{
			cout<<"Invalid input. Answer\"y\" or \"n\": ";
			getline(cin,ans);
		}

		if(ans=="n" || ans =="no")
			break;
		system("cls");
	}

	cout<<fileName+" is being saved.\n\n";

	Save save(map,"../MapFiles/"+fileName+".map");		//Sending the map and file path where to write and save the .map text file
}

void MapEditor::createContinent()
{
	string name;
	int val;
	
	cout<<"Enter Name of the Continent: ";
	getline(cin,name);
	
	while(continentExist(name))
	{
		cout<<"Continent Name alreasy exist. Please chose another name: ";
		getline(cin,name);
	}


	while((cout<<"Enter Value of the Continent: ")&&(!(cin>>val) || val < 0))
	{
		cout<<"Invalid Input!"<<endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
	}

	Continent cont(name,val);

	this->map.addContinents(cont);

	////Testing output
	//for(Continent c:this->map.continents)
	//{
	//	cout<<c.getName()+" ";
	//}
	//cout<<endl;
}

void MapEditor::createTerritory()
{
	Territory terr;

	string name;
	int x;
	int y;
	string cont;

	cout<<"Enter Name of Territory: ";
	getline(cin,name);

	while(territoryExist(name))
	{
		cout<<"Territory Name alreasy exist. Please chose another name: ";
		getline(cin,name);
	}

	while((cout<<"Enter X-Coordinate of the Territory: ")&&(!(cin>>x) || x < 0))
	{
		cout<<"Invalid Input!"<<endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
	}

	while((cout<<"Enter Y-Coordinate of the Territory: ")&&(!(cin>>y) || y < 0))
	{
		cout<<"Invalid Input!"<<endl;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(),'\n');
	}

	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');

	cout<<"Enter Name of the Continent: ";
	getline(cin,cont);

	while(!continentExist(cont))
	{
		cout<<"Continent does not exist. Please chose aother Continent: ";
		getline(cin,cont);
	}

	terr.setName(name);
	terr.setXcoordinate(x);
	terr.setYcoordinate(y);
	terr.setContinent(cont);

	if(this->map.territories.size()>0)
	{
		string ans;

		cout<<"Would you like to assign an Adjacent Territory to "+terr.getName()+" (y/n)? ";
		getline(cin,ans);

		while(ans!="y" && ans!="yes" && ans!="n" && ans!="no")
		{
			cout<<"Invalid input. Answer\"y\" or \"n\": ";
			getline(cin,ans);
		}

		if(ans=="y" || ans =="yes")
			assignAdjTerr(terr);
	}

	this->map.addTerritories(terr);
}

void MapEditor::assignTerrToCont(string continent)
{
	string territory,ans;
	int index;

	cout<<"Assigning Territories to "+continent<<endl<<endl;

	while(true)
	{
		cout<<"Please enter a Territory to be added to "+continent+": ";
		getline(cin,territory);

		while(!territoryExist(territory))
		{
			cout<<"Invalid Territory. Please enter a valid Territory:\n";
			getline(cin,territory);
		}

		for (int i=0;i<this->map.territories.size();i++) 
		{
			if(this->map.territories[i].getName() == territory)
				this->map.territories[i].setContinent(continent);				
		}

		cout<<"Would you like to assign more Territories to "+continent+"?(y/n): ";
		getline(cin,ans);
		
		while(ans!="y" && ans!="yes" && ans!="n" && ans!="no")
		{
			cout<<"Invalid input. Answer\"y\" or \"n\": ";
			getline(cin,ans);
		}

		if(ans=="n" || ans =="no")
			break;
	}
}

void MapEditor::assignAdjTerr(Territory &terr)
{
	string adjTerr,ans;

	cout<<"Assigning adjacent Territories to " + terr.getName() << endl<<endl;
	
	while(true)
	{
		cout<<"Please enter a Territory adjacent to "+terr.getName()+" (or type exit to exit): ";
		getline(cin,adjTerr);

		if(adjTerr=="exit")
			break;

		while(!territoryExist(adjTerr)||terr.isAdjacent(adjTerr))
		{
			cout<<"Invalid Territory. Please enter a valid Territory:\n";
			getline(cin,adjTerr);
		}

		terr.addAdjTerritory(adjTerr);

		for (int i=0;i<this->map.territories.size();i++) 
		{
			if(this->map.territories[i].getName() == adjTerr)
				this->map.territories[i].addAdjTerritory(terr.getName());
		}

		cout<<"Would you like to assign more adjacent Territories?(y/n): ";
		getline(cin,ans);
		
		while(ans!="y" && ans!="yes" && ans!="n" && ans!="no")
		{
			cout<<"Invalid input. Answer\"y\" or \"n\": ";
			getline(cin,ans);
		}

		if(ans=="n" || ans =="no")
			break;
	}
}

bool MapEditor::continentExist(string name)
{
	vector<Continent> continents = this->map.continents;

	for(Continent c: continents)
	{
		if(c.getName() == name)
			return true;
	}

	return false;
}

bool MapEditor::territoryExist(string name)
{
	vector<Territory> territories = this->map.territories;

	for(Territory t:territories)
	{
		if(t.getName() == name)
			return true;
	}

	return false;
}


bool MapEditor::fileExist(string name) 
{
	ifstream in;

	in.open("../MapFiles/"+name);
	
	if(in.fail())
		return false;

	in.close();
	return true;
}