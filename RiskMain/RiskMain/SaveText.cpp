/*
SaveText.cpp
SaveLoad for Risk

Created by Dich-Ky Tran on 10/10/2015
Copyright (C) 2015 Dich-Ky Tran. All right reserved.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "SaveText.h"

#include "continent.h"
#include "territory.h"

using namespace std;

void SaveText::saveText(Map map, string fileName)
{
	ofstream out;

	vector<Continent> continents = map.continents;
	vector<Territory> territories = map.territories;

	cout << "Saving map content, please wait..." << endl;

	out.open("../MapFiles/" + fileName+".txt");

	out << "[Territories]" << endl;

	for (Continent c : continents)
	{
		for (Territory t : territories)
		{
			if (t.getContinent() == c.getName())
			{
				out << t.getName() << "," << t.getXcoordinate() << "," << t.getYcoordinate() << "," << t.getContinent();

				for (const string& adj : t.getAdjTerritory())	//iterating through the Territory's AdjacentTerritories vector and writing out to the .map file
					out << "," << adj;

				out << endl;
			}
		}
		out << endl;
	}

	out << endl;

	out << "[Continents]" << endl;

	for (int i = 0; i<continents.size(); i++)		//iterating through the map's Continent vector and writing it to the .map text file
	{
		out << continents[i].getName() << "=" << continents[i].getVal() << endl;
	}

	out << endl;

	out << "[Map]" << endl;

	out << "author=" << map.getAuthor() << endl;
	out << "image=" << map.getImage() << endl;
	out << "wrap=" << map.getWrap() << endl;
	out << "scroll=" << map.getScroll() << endl;
	out << "warn=" << map.getWarn() << endl;

	out.close();

	cout << "Saving done!" << endl;
}