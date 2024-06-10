#ifndef VECT_H
#define VECT_H

#include <iostream>
#include <cmath>
using namespace std;

class vect{
private:
public:
	vect();
	vect(double x, double y);
	vect(double x, double y, double z);
	vect(double x, double y, double z, double w);

	double x=0.0, y=0.0, z=0.0, w=0.0;
	
	double module(vect& a);
	double scalerProduct(vect& a, vect& b);
	
	vect operator+(vect& a);
	vect operator+=(vect& a);

	vect operator-(vect& a);
	vect operator-=(vect& a);
};


vect vectorProduct2d(vect& a, vect& b);
vect vectorProduct3d(vect& a, vect& b);
vect vectorProduct4d(vect& a, vect& b);

vect operator*(const double& a, const vect& b);
vect operator*(const vect& b, const double& a);

#endif
