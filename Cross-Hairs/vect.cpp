#include "vect.h"

vect::vect(){}


vect::vect(double x, double y){
	this->x = x;
	this->y = y;
}

vect::vect(double x, double y, double z){
	this->x = x;
	this->y = y;
	this->z = z;
}


vect::vect(double x, double y, double z, double w){
	this->x = x;
	this->y = y;
	this->z = z;
	this->w = w;
}

double vect::module(vect& a){
	return sqrt(a.x*a.x + a.y*a.y + a.z*a.z + a.w*a.w);
}

double vect::scalerProduct(vect& a, vect& b){
	return (a.x*b.x + a.y*b.y + a.z*b.z, a.w*b.w);
}

vect vectorProduct2d(vect& a, vect& b){
	return vect(0, 0, a.x* b.y - b.x * a.y);
}

vect vectorProduct3d(vect& a, vect& b){
	return vect(a.y*b.z-a.z*b.y,  a.z*b.x-a.x*b.z, a.x*b.y-a.y*b.x);
}

vect vectorProduct4d(vect& a, vect& b){
	return vect(b.z*(a.y-a.w), b.w*(a.z-a.x), b.x*(a.w-a.y), b.y*(a.x-a.z));
}

vect vect::operator+(vect& a){
	return vect(this->x + a.x, this->y + a.y, this->z + a.z, this->w + a.w);
}
vect vect::operator+=(vect& a){
	return vect(this->x + a.x, this->y + a.y, this->z + a.z, this->w + a.w);
}




vect vect::operator-(vect& a){
	return vect(this->x - a.x, this->y - a.y, this->z - a.z, this->w - a.w);
}
vect vect::operator-=(vect& a){
	return vect(this->x - a.x, this->y - a.y, this->z - a.z, this->w - a.w);
}



vect operator*(const double& a, const vect& b){
	return vect(b.x * a, b.y * a, b.z * a, b.w * a);
}

vect operator*(const vect& b, const double& a){
	return vect(b.x * a, b.y * a, b.z * a, b.w * a);                                              
}
