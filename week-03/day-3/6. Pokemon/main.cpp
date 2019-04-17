#include <iostream>
#include <vector>

#include "Pokemon.h"


std::vector<Pokemon> initializePokemons()
{
    std::vector<Pokemon> pokemons;

    pokemons.push_back(Pokemon("Bulbasaur", "leaf", "water"));
    pokemons.push_back(Pokemon("Pikatchu", "electric", "water"));
    pokemons.push_back(Pokemon("Charizard", "fire", "leaf"));
    pokemons.push_back(Pokemon("Balbasaur", "water", "fire"));
    pokemons.push_back(Pokemon("Kingler", "water", "fire"));

    return pokemons;
}

int main(int argc, char* args[])
{
    std::vector<Pokemon> pokemonOfAsh = initializePokemons();

    // Every pokemon has a name and a type.
    // Certain types are effective against others, e.g. water is effective against fire.

    // Ash has a few pokemon.
    // A wild pokemon appeared!

    Pokemon wildPokemon("Oddish", "leaf", "water");

    // Which pokemon should Ash use?

    //Solution: In case there are more pokemon effective against the wild pokemon
    // we print out all of their names.
    std::vector<std::string> useThisPokemon;

    for (int i = 0; i < pokemonOfAsh.size(); i++) {
       Pokemon currentPokemon = pokemonOfAsh[i];
       if (currentPokemon.isEffectiveAgainst(wildPokemon)) {
           useThisPokemon.push_back(currentPokemon._name);
       }
    }

    for (int i = 0; i < useThisPokemon.size(); i++) {
        std::cout << "I choose You, " << useThisPokemon[i] << std::endl;
    }


    return 0;
}