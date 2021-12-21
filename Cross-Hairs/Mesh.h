#ifndef MESH_H
#define MESH_H

#include <iostream>                                                                              
#include <stdio.h>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#include <fstream>
#include <strstream>

#include <vector> 
#include "vect.h"
#include "matrix.h"
#include "quaternion.h"

#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/core.hpp>

#include "MeshPoints.h"
#include "screensize.h"


using namespace std;
using namespace cv;


class Mesh{
private:
	const double theta = (45.0 * M_PI) / 180.0;
	const double fi = 1.0 / tan(theta/2.0);

	double x=0.0, y=0.0, z=0.0;

	vector<matrix> pointMtr;
	vector<matrix> m_pointMtr;

public:
	Mesh();
	Mesh(const double x_m, const double y_m, const double z_m);
	Mesh(string FileName);
	void buildMesh(const Mat& image, const double x_m, const double y_m);

	void PerspectiveRender();
	void m_buildMesh(const Mat& image);
	void mnew_buildMesh(const Mat& image);

	void Transform(const double x_m, const double y_m, const double z_m);
	void Rotate(const double alpha, const double beta, const double gamma);
	void Scale(const double x_scaleNumb, const double y_scaleNumb, const double z_scaleNumb);


	void texturize();
};

#endif
