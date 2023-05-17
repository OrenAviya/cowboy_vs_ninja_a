#pragma once 
#include <iostream>
#include <stdlib.h>
# include "Point.hpp"

using namespace std;
namespace ariel{}

class Character{
    private:
    
        const char* Name;
        int Hit_points;
    
    protected:
        Point Location;
        int type;
    
    public:
    //constructors
    Character();
        Character(const char* name , Point location , int hitPoints);

    //getters :
    const char* getName();
    virtual Point getLocation();
    int getHitPoints();
    void setHitpoints(int number);
    int getType();

    //methods:
        virtual bool isAlive();
        virtual double distance(Character *other);
        virtual void hit(int number);
        virtual std::string print();
        // virtual ~Character() = default;
        Character operator =(Character *some);
};

class Cowboy : public Character{
    private:
        int num_of_bullet;
        
            public:
    // constructors:
    Cowboy(const char* name, Point location  ); //always with 6 bullet and 011 hit points
       
        void shoot(Character *enemy);
        bool hasboolets();
        void reload();
Cowboy operator =(Cowboy *some);
void setNumBullet(int number);
int getNumBullet();
virtual string print();
// virtual ~Cowboy() = default;
    
};

class Ninja: public Character{
private :
        int speed;
        
    public:
     // constructors:
    Ninja(const char* name, Point location , int hitPoints, int speedtype);
    Ninja();

        void move(Character *enemy);
        void slash(Character *enemy);
        virtual string print();
        // virtual ~Ninja() = default;
};

class YoungNinja: public Ninja{
    // private :
    //     int speed;
    public:
     // constructors:
    YoungNinja( const char* name , Point location  );
        
        // void move(Character &anamy);
        // void slash(Character &anamy);
     string print();
};

class OldNinja: public Ninja{
  
    public:
     // constructors:
    OldNinja(const char* name , Point location  );
     string print();
};

class TrainedNinja: public Ninja{
    
    public:
     // constructors:
    TrainedNinja(const char* name, Point location  );
     string print();

};