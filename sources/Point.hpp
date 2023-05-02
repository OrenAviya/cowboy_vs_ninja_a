#pragma once 
#include <iostream>
#include <stdlib.h>

using namespace std;
namespace ariel{}
    class Point{
       private:
        double x ;
        double y ;

    public:
        //constructors:
        // regular
        Point(double coordinate_x , double coordinate_y): x(coordinate_x) , y(coordinate_y){}
       // empty
        Point():x(0) , y(0){}

        //methods:
        double distance(Point other);
        void print();
        Point moveTowards(Point source ,Point destination , double distance);



    };
