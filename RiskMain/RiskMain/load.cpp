/*
load.cpp
SaveLoad for Risk

Created by Dich-Ky Tran on 10/10/2015
Copyright (C) 2015 Dich-Ky Tran. All right reserved.
*/

#include <iostream>
#include <fstream>

#include "load.h"

#include "continent.h"
#include "territory.h"

using namespace std;

Load::Load(string filePath)			//Parsing through the .map text file
{
	ifstream in;

	cout << "Loading map, please wait..." << endl;

	in.open(filePath);

	if(in.fail())
	{		
		cout << "Unable to open file." << endl;
		throw "Unable to load file";
	}
	else
	{
		string line;

		while(in.good())	//Keep on parsing line by line while there are still lines in the .map file
		{
			getline(in, line);

			if(line == "[Map]")		//Pasring through the [Map] block to get all the general info
			{
				string delimiter = "=";
				size_t pos = 0;

				for(int i=0; i<5; i++)							
				{
					getline(in, line);
					pos = line.find(delimiter);

					switch(i)
					{
					case 0:	//Grabbing Author data
						map.setAuthor(line.substr(pos+1));			//line.substr(pos+1) --> grabs the data after the "=" delimiter
						break;
					case 1:	//Grabbing Image data
						map.setImage(line.substr(pos+1));
						break;
					case 2:	//Grabbing Wrap data
						map.setWrap(line.substr(pos+1));
						break;
					case 3:	//Grabbing Scroll data
						map.setScroll(line.substr(pos+1));
						break;
					case 4:	//Grabbing Warn data
						map.setWarn(line.substr(pos+1));
						break;
					default:
						break;
					}
				}
				continue;	//restart from the top of the while loop
			}
			else if(line =="[Continents]")		//Pasring through the [Continents] block to retieve all Continents
			{
				string delimiter = "=";
				Continent cont;
				size_t pos = 0;
				int x = 0;

				getline(in,line);

				while(line != "")
				{
					pos = line.find(delimiter);

					cont.setName(line.substr(0,pos));		//Grabbing the name of the continent
					x = stoi(line.substr(pos+1));			//Grabbing and converting the value string to int
					cont.setVal(x);

					map.addContinents(cont);				//Push the continent onto map's vector of continents
					getline(in,line);
				}
				continue;		//restart from the top of the while loop
			}
			else if(line == "[Territories]")		//Pasring through the [Territories] block to retieve all Territories
			{
				string delimiter = ",";
				Continent cont;
				Territory terr;
				size_t pos = 0;
				int coorX = 0, coorY = 0;
				
				while(true)
				{
					int i = 0;
					terr.clearTerritories();

					getline(in,line);

					if(line == "")			//continue to the next line if current line is a blank
						getline(in,line);
					
					if(in.eof())			//if end of file then break and close the file
						break;

					while( (pos = line.find(delimiter)) != string::npos)		//keep on looping until all data from the line is all stored
					{
						switch(i)		//i is used as an index to determine what kind of data we are storing
						{
						case 0:	//Storing the Territory's name
							terr.setName(line.substr(0,pos));
							line.erase(0, pos + delimiter.length());
							i++;
							break;
						case 1:	//Storing the X coordinate
							coorX = stoi(line.substr(0,pos));
							terr.setXcoordinate(coorX);
							line.erase(0, pos + delimiter.length());
							i++;
							break;
						case 2:	//Storing the Y coordinate
							coorY = stoi(line.substr(0,pos));
							terr.setYcoordinate(coorY);
							line.erase(0, pos + delimiter.length());
							i++;
							break;
						case 3:	//Storing the Territory's Continent
							terr.setContinent(line.substr(0,pos));
							line.erase(0, pos + delimiter.length());
							i++;
							break;
						default:	//When index outgrows 3, then we are now storing all Adjacent Territories in a vector
							terr.addAdjTerritory(line.substr(0,pos));
							line.erase(0, pos + delimiter.length());
							break;
						}	
					}
					terr.addAdjTerritory(line);

					map.addTerritories(terr);	//Finally pushing the Territory onto the map's territory vector
				}
			}
		}
		
		in.close();

		cout << "Map has been loaded successfully!" << endl; 
	}
}