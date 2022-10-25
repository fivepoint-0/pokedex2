#ifndef POKEMON
#define POKEMON

#include <iostream>
#include <string>
#include <fstream> //file stream
#include <locale>  // std::locale, std::tolower

using namespace std;

// struct Pokedex 
// {
//     string trainer;
//     int num_pokemon;
//     Pokemon* dex;
// };

struct Pokemon 
{
    int dex_num;
    string name;
    string type;
    int num_moves;
    string* moves;
};



void print_pokemon(Pokemon p); // displays the pokemon info

void output_pokemon(Pokemon p, ofstream& file); // used for outputing dex data into new file for add pokemon

Pokemon* create_pokemon(int size); // creates the array to hold pokemon data

string* create_moves(int size); // creates the array to hold move names

// Pokedex* create_pokedex(int size);

void populate_moves(string* moves, int size, ifstream& file); // populates the moves array with move names

void populate_pokemon(Pokemon* dex, int size, ifstream& file); // populates the dex array with pokemon info

// void populate_pokedex(Pokedex* my_dex, int size, ifstream& file);

void delete_info_pokemon(Pokemon* dex, int size); // frees the array

void pokemon_not_found();

#endif
