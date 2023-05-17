
#include "Team.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include "array"


using namespace std;
namespace ariel{}

Team::Team (Character *leader){
    size = 1;
    // Initialize the array elements or perform any other necessary setup
    warriors[0] = leader;
    this->leader = leader;
    }
    
void Team :: print(){
    for (size_t i =0 ; i < this->size ; i++){
        cout << warriors[i]->print() << " , ";
    }
    cout<<"\n";
    }

void Team:: add(Character *warr){
    if (!warr)
        return;

    if (size < 10)
    {
    warriors[size] = warr;
    size++;
    }
    else
    {
        cout <<  "this team already have ten warriors";
    }
}


void Team:: attack(Team *enemyTeam){
    
    if ( ! this->leader->isAlive()){
        // new leader:
        this->leader = ClosestCharToLead();
        }
    
    Character *victim = ClosestCharToLead(enemyTeam);
    for (size_t i=0; i<this->size; i++){
        
        if(enemyTeam->stillAlive() == 0)
            return;

        if (warriors[i]->getType() == 1){
            Cowboy* co = static_cast<Cowboy*>(warriors[i]);
            if (co->isAlive() && co->getNumBullet()>0){
                co->shoot(victim);
            }
            else if(co->isAlive() && co->getNumBullet() == 0){
                co->reload();
            }
        }
        else if (warriors[i]->getType() == 2){
            Ninja* nin  = static_cast<Ninja*>(warriors[i]);
            if (nin->isAlive() && nin->distance(victim)<1){
                nin->slash(victim);
            }
            else if(nin->isAlive() && nin->distance(victim)>1){
                nin->move(victim);
            }
        }
        if (victim->isAlive() == false){
            victim = ClosestCharToLead(enemyTeam);
        }
    }
    
    }

int Team::stillAlive(){
    int res =0; 
    for (size_t i =0 ; i < (this->size); i++){
            if( this->warriors[i]->isAlive() == true)
                res++;
    }
    return res;
}

Character* Team :: ClosestCharToLead(){
    //in the team
    double min_dis = __DBL_MAX__;
    size_t idx_new; 
        for (size_t i =0 ; i < this->size; i++)
        {
         if (this->leader != warriors[i])
         { 
            double dis = (this->leader)->distance(warriors[i]);
            if (warriors[i]->isAlive() && dis < min_dis){
                min_dis= dis ;
                idx_new = i;
            }
        }
        }
    return warriors[idx_new];   
}

Character* Team :: ClosestCharToLead(Team* EnemyTeam){
    double min_dis = __DBL_MAX__;
    size_t idx_new = 0;
    for (size_t i =0 ; i < EnemyTeam->size; i++)
        {
          double dis = (this->leader)->distance(EnemyTeam->warriors[i]);
            if (EnemyTeam->warriors[i]->isAlive() && dis < min_dis){
                min_dis= dis ;
                idx_new = i;
            }  
        }
     if (EnemyTeam->warriors[0]->isAlive()==false && idx_new==0) 
        {
            cout << "there is no one alive in the enemy team ";
           return nullptr;     
        }
    return EnemyTeam->warriors[idx_new];
   }
