
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
    size=0;
    // Initialize the array elements or perform any other necessary setup
    this->leader = leader;
    this->add(leader);
    }
    
  void Team::print()
{
    for (size_t i = 0; i < this->size; ++i) {
        if(warriors[i]->getType() == 1)
            cout << warriors.at(i)->print() << endl;
    }
    for (size_t i = 0; i < this->size; ++i) {
        if(warriors[i]->getType() == 2)
            cout << warriors.at(i)->print() << endl;
    }
}  

void Team:: add(Character *warr){
    /*here we will sort all the cowboys first then all ninjas */ 
    if (!warr)
        return;
    int count = this->size-1;
    bool insert_success = false;
    
    if (this->size == 0){
        warriors[0] = warr;
        size++;
        insert_success = true;
        return;
    }

    if (size < 10)
    {
    
    if (warr->getType()==1 && !insert_success){
    for (size_t i=this->size-1 ; i>=0; i--){
        if (warriors[i]->getType()!=2 && warriors[i+1] == nullptr){
            warriors[i+1] = warr;
            size++;
            insert_success = true;
            return;
        }
        else if (warriors[i]->getType()!=2 && warriors[i+1] != nullptr && !insert_success){
            //move all the characters that places right to i one place right.
            for (size_t j=this->size ; j>i+1; j--){
                warriors[j] = warriors[j-1];
            }
            warriors[i+1]= warr;
            insert_success = true;
            size++;
            return;
        }
        count-- ;
    }
    if (count == 0 && !insert_success){
        //if the cowboy not inserted to team yet - all the team is ningas
        for (size_t i=this->size ; i>0; i--){
            // move each character one to right.
            warriors[i] = warriors[i-1];
        }
        warriors[0] = warr;
        insert_success = true;
        size++;
        return;
    }
    }

    else if (warr->getType() == 2 && !insert_success)
    { // ninja we can insert at the end
        warriors[size] = warr;
        insert_success = true;
        size++;
        return;
    }
    }

    else
    {
        cout <<  "this team already have ten warriors";
    }
    if (!insert_success){
        throw invalid_argument ("the insert failed");
    }

}



void Team:: attack(Team *enemyTeam){
    if(enemyTeam == nullptr)
        throw std::invalid_argument("null input");
        
    if(this->stillAlive() == 0)
        throw std::invalid_argument("cannot attack if there is no player alive");
    
    if(enemyTeam->stillAlive() == 0)
        throw std::runtime_error("enemy team already dead");
    
    if(enemyTeam == this)
        throw std::invalid_argument("sory , Team would not attack itself");
    
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
    for (size_t i =(this->size) ; i >0; i--){
            if( this->warriors[i-1]->isAlive() == true)
                res++;
    }
    return res;
}

Character* Team :: ClosestCharToLead(){
    //in the team
    double min_dis = __DBL_MAX__;
    size_t idx_new = 0; 
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
    

    /***************************************************************************************/
void Team2 :: print(){
    for (size_t i =0 ; i < this->size ; i++){
        cout << warriors[i]->print() << " , ";
    }
    cout<<"\n";
    }
    
    void Team2::add(Character* some){//regular add
        if (!some)
            return;
        
        if (size < 10)
        {
            warriors[size] = some;
            size++;
        }
        else
        {
            cout <<  "this team already have ten warriors";
        }
}


    Character* Team2::ClosestCharToLead(Team* EnemyTeam) {
        // Implementation of the ClosestCharToLead function
    return Team::ClosestCharToLead(EnemyTeam);
    }
    
    void Team2::attack(Team *enemyTeam) {
    if(enemyTeam == nullptr)
        throw std::invalid_argument("null input");
        
    if(this->stillAlive() == 0)
        throw std::invalid_argument("cannot attack if there is no player alive");
    
    if(enemyTeam->stillAlive() == 0)
        throw std::runtime_error("enemy team already dead");
    
    if(enemyTeam == this)
        throw std::invalid_argument("sory , Team would not attack itself");
    
    if ( ! this->leader->isAlive()){
        // new leader:
        this->leader = Team::ClosestCharToLead();
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

/***********************************************************************************************/

void SmartTeam::attack(Team *EnemyTeam) {
        // Implementation of the attack function
    }
void SmartTeam:: add(Character* some){
        if (!some)
            return;
        
        if (size < 10)
        {
            warriors[size] = some;
            size++;
        }
        else
        {
            cout <<  "this team already have ten warriors";
        }
    }