#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include "vect.h"
#include <vector>
#include "stdio.h"
#include "math.h"

#include "string"

using namespace std;

class matrix{
private:
	double theta;

public:
	// Matrix Constructor
	matrix();
	matrix(const unsigned short int col, const  unsigned short int row);
	matrix(const unsigned short int col, const unsigned short int row, const string identifier);

	double col, row;

	matrix getTranspose();
	matrix getInverse();

	vector<vector<string>> charvalues;
	vector<vector<double>> values;

	void showMatrix();
	void showcharMatrix();
};

// Matrix vector Constructor
matrix v2d(const double x, const double y);
matrix v3d(const double x, const double y, const double z);
matrix v4d(const double x, const double y, const double z, const double w);

matrix Matrix3d_vector_crossProduct(const matrix& mtr1, const matrix& mtr2);
matrix Matrix3d_vector_norm(const matrix& mtr);

matrix operator+(const matrix& mtr1, const matrix& mtr2);
matrix operator-(const matrix& mtr1, const matrix& mtr2);

matrix operator*(const double& a, const matrix& mtr);
matrix operator*(const matrix& mtr, const double& a);

matrix operator*(const matrix& a, const matrix& b);

matrix R2(const double theta);
         
matrix Rx3(double theta);
matrix Ry3(double theta);
matrix Rz3(double theta);

const matrix I2();
const matrix I3();

matrix decoyMatrix(const int col, const int row, const double numb);

#endif
