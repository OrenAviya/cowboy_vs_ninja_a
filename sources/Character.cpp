
#include "Character.hpp"
#include <stdio.h>
#include <stdlib.h>


using namespace std;
namespace ariel{}

Character::Character(const char* name , Point location , int hitPoints):
Name(name) , Location(location) , Hit_points(hitPoints) , type(0){
    if (hitPoints<0){
        throw invalid_argument ("no character begin dead");
    }
}

Character::Character(): 
Name(NULL) , Location(Point()) , Hit_points(0), type(0){}

const char* Character ::  getName(){
    return this->Name;
}
Point Character::getLocation(){
    return this->Location;
}
int Character:: getHitPoints(){
    return this->Hit_points;
}
void Character ::setHitpoints(int number){
    this->Hit_points = number;
}
bool Character::isAlive(){
    return this->Hit_points>0;
}
double Character::distance(Character *other){
    return this->Location.distance(other->getLocation());
}
void Character::hit(int number){
    if (number <0)
        throw invalid_argument ("negative number"); 
    this->setHitpoints(this->getHitPoints() - number);
}

Character Character ::operator =(Character *some){
   Character c1 = Character(some->getName() , some->getLocation(), some->getHitPoints() );
    return c1;
}
int Character::getType(){
    return this->type;
}
string Character :: print(){
    string res = "some character";
    return res;
} 

/************************************************************************************/
Cowboy::Cowboy(const char* name , Point location ):
Character(name , location, 110), num_of_bullet(6){
    this->type =1;
}

int Cowboy:: getNumBullet(){
    return this->num_of_bullet;
}
void Cowboy::setNumBullet(int number){
    this->num_of_bullet = number;
}

void Cowboy::shoot(Character *enemy){
   if(enemy != this){
    enemy->hit(10);
    this->num_of_bullet--;
   }
   else{
    cout << "can't hit myself";
   }  
}
bool Cowboy::hasboolets(){
    return this->num_of_bullet>0;
}
void Cowboy::reload(){
    this->num_of_bullet =6; 
}


Cowboy Cowboy ::operator =(Cowboy *some){
   Cowboy c1 = Cowboy(some->getName() , some->getLocation() );
   c1.setHitpoints(some->getHitPoints());
   c1.setNumBullet(some->getNumBullet());
    return c1;
}

string Cowboy:: print(){
string res = "cowboy";
return res;
}

/************************************************************************************/
Ninja::Ninja(const char* name, Point location , int hitPoints, int speedtype): 
Character(name , location , hitPoints), speed(speedtype){
    this->type =2;
} 

Ninja::Ninja(){}

 void Ninja::move(Character *enemy){
    this->Location = this->Location.moveTowards(this->getLocation() , enemy->getLocation() , this->speed);
}

 void Ninja::slash(Character *enemy){
    bool meter = this->distance(enemy) <= 1;

    if (this->isAlive() && meter && enemy !=this){
        enemy->hit(40);
    }

}
string Ninja::print(){
    return "Ninja";
}


/************************************************************************************/
OldNinja::OldNinja(const char* name, Point location)://speed = 8
Ninja(name , location , 150 , 8){}

string OldNinja:: print(){
string res ="OldNinja";
return res;
}
/************************************************************************************/
YoungNinja::YoungNinja(const char* name , Point location  )//speed=14
:Ninja(name , location , 100 , 14){}

string YoungNinja:: print(){
string res ="YoungNinja";
return res;
}

/************************************************************************************/
TrainedNinja::TrainedNinja(const char* name , Point location  ): //speed =12
Ninja(name , location , 120 , 12){}

string TrainedNinja:: print(){
string res ="TrainedNinja";
return res;
}