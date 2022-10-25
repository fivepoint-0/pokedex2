/******************************************************
** Program: pokemon.cpp
** Author: Travis Foster
** Date: 10/24/2022
** Description:
** Input:
** Output:
******************************************************/

// #include <iostream>
// #include <string>
// #include <fstream> //file stream

#include "pokemon.h"
// add a comment

// using namespace std;

int main()
{ // creates a variable named filename
	string filename;

	cout << "enter file: " << endl;
	cin >> filename; // allows the user to input a file name

	ifstream file;				 // input file object: file
	file.open(filename.c_str()); // opens read file given by filename and converts string to character

	// check if the file is successfully open
	if (!file.is_open())
	{
		cout << "Error opening the file..." << endl;
		return 1;
	}

	// dyn array of pokemon
	int size = 0;
	file >> size;

	// creates an array called dex to hold info from struct
	Pokemon *dex = create_pokemon(size);

	// populates the text from the file into the dex array
	populate_pokemon(dex, size, file);
	int menu;
	// creates variable menu for user input data
	//  int menu;
	//  string option;
	bool x = true;
	while (x)
	{

		cout << "press 1 for dex num \n"
			 << "press 2 for name \n"
			 << "press 3 for type \n"
			 << "press 4 to exit \n";
		// cin >> menu; // allows the user to select how to search
		if(!(cin >> menu)){
			x = false;
		}
		cout << menu;
		// menu = stoi(option);

		string user_dex_name, user_dex_type; // string variables used in the search function

		// the switch case allows the user to select how they would like to search and displays the resulting info
		bool found = false;
		if (cin.fail())
		{
			switch(menu)
			{
			case 1: // allows the user to search by dex number and displays the info
				int user_dex_num;
				cout << "Search by dex num: \n";
				cin >> user_dex_num;
				for (int i = 0; i < size; i++)
				{
					if (dex[i].dex_num == user_dex_num)
					{
						print_pokemon(dex[i]);
						found = true;
					}
				}
				break;
			case 2: // allows the user to search by name and displays the info
				cout << "search by name: \n";
				cin >> user_dex_name;
				for (int i = 0; i < size; i++)
				{
					if (dex[i].name == user_dex_name)
					{
						print_pokemon(dex[i]);
						found = true;
					}
				}
				break;
			case 3: // allows the user to search by type and displays the info
				cout << "search by type: \n";
				cin >> user_dex_type;
				for (int i = 0; i < size; i++)
				{
					if (dex[i].type == user_dex_type)
					{
						print_pokemon(dex[i]);
						found = true;
					}
				}
				break;
			case 4: // allows the user to exit the program
				cout << "Exit \n";
				file.close();
				x = false;
				break;
			case 0:
				cout << "default \n";
				menu = 1;
				cout << "press 1 for dex num \n"
					 << "press 2 for name \n"
					 << "press 3 for type \n"
					 << "press 4 to exit \n";
				cin >> menu;
				break;
			}
			if (!found && menu < 4)
			{
				pokemon_not_found();
			}
			cin.clear();
		}
		cin.clear();
	}
	// file.close(); // closes the read file

	// this was for adding pokemon to the database by creating a new file
	ofstream file_out;
	file_out.open("new_dex.txt"); // opens a write file for the dex info to be stored

	// outputs all pokemon in dex to the new file
	//  for (int i = 0; i < size; ++i)
	//  {
	//  	output_pokemon(dex[i], file_out);
	//  }

	file_out.close(); // closes the write file

	delete_info_pokemon(dex, size); // frees memory from the heap

	return 0;
}