// #include <iostream>
// #include <string>
// #include <fstream> //file stream

#include "pokemon.h"

// using namespace std;
// displays the pokemon info
void print_pokemon(Pokemon p){
	cout << "--------------------" << endl;
	cout << "dex_num: " << p.dex_num << endl;
	cout << "name: " << p.name << endl;
	cout << "type:" << p.type << endl;
	for (int i = 0; i < p.num_moves; ++i)
	{
		cout << "moves " << i+1 << ": " << p.moves[i] << endl;
	}
	cout << endl;
}

// void print_pokedex(Pokedex d){
// 	for(int i = 0; i < d.dex; ++i){
// 		cout << "pokemon: " << d.dex << endl;
// 	}
// }
// This allows info to be written to a new file
void output_pokemon (Pokemon p, ofstream &file){
	file << "--------------------" << endl;
	file << "dex_num: " << p.dex_num << endl;
	file << "name: " << p.name << endl;
	file << "type: " << p.type << endl;
	for (int i = 0; i < p.num_moves; ++i)
	{
		file << "moves " << i+1 << ": " << p.moves[i] << endl;
	}
	file << endl;
}

// Pokedex* create_pokedex(int size){
// 	Pokedex* d = new Pokedex [size];
// 	return d;
// }
// This creates the pokemon array
Pokemon* create_pokemon(int size){
	Pokemon* db = new Pokemon [size];
	return db;
}
//this creates the moves array
string* create_moves(int size){
	string* m = new string [size];
	return m;
}
//This allows the moves array to be populated
void populate_moves(string* moves, int size, ifstream& file){
	for (int i = 0; i < size; ++i){
		file >> moves[i];
	}
}

void populate_pokemon(Pokemon *dex, int size, ifstream &file){

	for (int i = 0; i < size; ++i)
	{	//This is populating the array with dex number, pokemon name, type and the number of moves
		file >> dex[i].dex_num >> dex[i].name >> dex[i].type >> dex[i].num_moves;
		//This creates the moves array within the dex array
		dex[i].moves = create_moves(dex[i].num_moves);
		//This populates the moves array
		populate_moves(dex[i].moves, dex[i].num_moves, file);
		
	}
}

// void populate_pokedex(Pokedex* my_dex, int size, ifstream &file){

// 	for(int i = 0; i < size; ++i){
// 		file >> my_dex[i].dex;
		
// 		my_dex[i].dexs = create_pokemon(my_dex[i].dex);

// 		populate_pokemon(my_dex[i].dexs, my_dex[i].dex, file);
// 	}
// }

void delete_info_pokemon(Pokemon *dex, int size){
	for (int i = 0; i < size; ++i)
	{	//goes into moves array and sets back to NULL
		delete [] dex[i].moves;
		dex[i].moves = NULL;
	}
	//sets the poke_array to null
	delete [] dex;
	dex = NULL;
}

void pokemon_not_found(){
	cout << "Error pokemon not found! \n" << endl;

}
// void delete_info_pokedex(Pokedex *my_dex, int size){
// 	delete [] my_dex;
// 	my_dex = NULL;
// }

// bool search_name(Pokemon const &dex){

// 	string namesearch;
// 	cout << "enter a name" << endl;
// 	cin >> namesearch;

// 	for(int i = 0; i < dex[i].name; i++){
// 		if (namesearch == dex[i].name){
// 			print_pokemon(dex[i]);
// 		}
// 	}
// 	cout << "not found" << endl;
// 	return false;
// }

