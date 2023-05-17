#pragma once

#include "Character.hpp"
#include <stdio.h>
#include<stdlib.h>
#include "array"

using namespace std;
namespace ariel{}

class Team{
// The transition to the characters will be according to cowboy first
    private:
    array <Character* , 10> warriors;
    
    Character *leader;
    // (the same but not tameplate): Character warriors [10];
    public:
    size_t size;
    //constructor
    Team(Character *leader);

    //destructor
~Team(){
    for (size_t i = this->size-1 ; i >=this->size ; i--){
        delete(warriors[i]) ;
    }
}
    //methods:
        void add(Character *warr);
        void attack(Team *anamyTeam);
        int stillAlive();
        void print();
        /// @brief method to find the closest character to the leader in the team
        /// @return pointer to that character
        Character* ClosestCharToLead();
        /// @brief method to find the closest character to the leader of the team 
        // in the anamy team
        /// @param AnamyTeam 
        /// @return pointer to that character
        Character* ClosestCharToLead(Team* AnamyTeam);
        Character* getLeader(){
            return this->leader;
        }
};

class smartTeam : public Team{
//The transition to the characters will be according to your choice
public:

};

class Team2 : public Team {
    //The transition to the characters will be according to order of addition
};
