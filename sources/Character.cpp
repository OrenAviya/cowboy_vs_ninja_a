#pragma once

#include "Character.hpp"
#include <stdio.h>
#include <stdlib.h>


using namespace std;
namespace ariel{}

Character::Character(string name , Point location , int hitPoints){

}
Character::Character(){}

string Character ::  getName(){}
Point Character::getLocation(){}

bool Character::isAlive(){}
double Character::distance(Character &other){}
void Character::hit(int number){}
void Character::print(){}

/************************************************************************************/
Cowboy::Cowboy(string name , Point location , int hitPoints , int numBullet):
Character(name , location, hitPoints), num_of_bullet(numBullet){}

void Cowboy::shoot(Character &anamy){}
bool Cowboy::hasboolets(){}
void Cowboy::reload(){}

/************************************************************************************/
Ninja::Ninja(string name , Point location , int hitPoints, int speedtype): 
Character(name , location , hitPoints), speed(speedtype){} 

Ninja::Ninja(){}

void Ninja::move(Character &anamy){}
void Ninja::slash(Character &anamy){}

/************************************************************************************/
OldNinja::OldNinja(string name , Point location , int hitPoints )://speed = 8
Ninja(name , location , hitPoints , 8){}


/************************************************************************************/
YountNinja::YountNinja(string name , Point location , int hitPoints )//speed=14
:Ninja(name , location , hitPoints , 14){}


/************************************************************************************/
TrainedNinja::TrainedNinja(string name , Point location , int hitPoints ): //speed =12
Ninja(name , location , hitPoints , 12){}