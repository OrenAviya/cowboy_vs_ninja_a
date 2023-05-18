#pragma once

#include "Character.hpp"
#include <stdio.h>
#include<stdlib.h>
#include "array"

using namespace std;
namespace ariel{}

class Team{
// The transition to the characters will be according to cowboy first
   public:
    array <Character* , 10> warriors;
    
    Character *leader;
    // (the same but not tameplate): Character warriors [10];
    
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
        virtual void add(Character *warr);
        virtual void attack(Team *anamyTeam);
        int stillAlive();
       virtual void print();
        /// @brief method to find the closest character to the leader in the team
        /// @return pointer to that character
        virtual Character* ClosestCharToLead();
        /// @brief method to find the closest character to the leader of the team 
        // in the anamy team
        /// @param EnemyTeam 
        /// @return pointer to that character
        Character* ClosestCharToLead(Team* EnemyTeam);
        Character* getLeader(){
            return this->leader;
        }
};

class Team2 : public Team {
public:
    Team2(Character *leader) : Team(leader) {}
    void  add(Character* some);
    void print() ;
    Character* ClosestCharToLead(Team* EnemyTeam) ;
    void attack(Team *EnemyTeam) ;
};

class SmartTeam : public Team {
//The transition to the characters will be according to your choice
SmartTeam(Character *leader): Team(leader){}
void  add(Character* some);
void attack(Team *EnemyTeam);
};