#pragma once 
#include <iostream>
#include <stdlib.h>
# include "Point.hpp"

using namespace std;
namespace ariel{}

class Character{
    private:
    
        string Name;
        Point Location;
        int Hit_points;
    

    public:
    //constructors
    Character();
        Character(string name , Point location , int hitPoints);

    //getters :
    string getName();
    Point getLocation();
    //methods:
        bool isAlive();
        double distance(Character &other);
        void hit(int number);
        void print();

};

class Cowboy : public Character{
    private:
        int num_of_bullet;

    public:
    // constructors:
    Cowboy(string name , Point location , int hitPoints , int numBullet);
       
        void shoot(Character &anamy);
        bool hasboolets();
        void reload();
    
};

class Ninja: public Character{
private :
        int speed;
    public:
     // constructors:
    Ninja(string name , Point location , int hitPoints, int speedtype);
    Ninja();

        void move(Character &anamy);
        void slash(Character &anamy);
};

class YountNinja: public Ninja{
    // private :
    //     int speed;
    public:
     // constructors:
    YountNinja(string name , Point location , int hitPoints );
        
        // void move(Character &anamy);
        // void slash(Character &anamy);
};

class OldNinja: public Ninja{
  
    public:
     // constructors:
    OldNinja(string name , Point location , int hitPoints );
       
};

class TrainedNinja: public Ninja{
    
    public:
     // constructors:
    TrainedNinja(string name , Point location , int hitPoints );

};