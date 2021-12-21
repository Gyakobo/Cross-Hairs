#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <stdio.h>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

#include <vector>
#include "vect.h"
#include "matrix.h"

#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/core.hpp>

#include "screensize.h"

#define SAND	0
#define WATER	1
#define WOOD	2
#define MANUAL	3
#define CARROT	4

#define DEFAULT 15	

using namespace std;
using namespace cv;

static const unsigned int Width=1000, Height=500;
static unsigned int Img[Width][Height];

static unsigned int Player_x = Width/2, Player_y = Height/2;

static double dist(double x, double y, double m_x, double m_y) {
	return sqrt((x-m_x)*(x-m_x) + (y-m_y)*(y-m_y));
}

static void SetImg() {
	for (unsigned short int i=0; i<Width; i++) {
		for (unsigned short int j=0; j<Height; j++) {
			Img[i][j] = DEFAULT;
		}
	}
}

class Particle{
private:
	double life_time;
	int velocity;
	unsigned short int x, y, type;
	int r, g, b;
	double brightness = 0.0;
	double alpha = 1.0;

public:
	Particle();
	Particle(double life_time, int velocity, unsigned short int x, unsigned short int y, unsigned short int type);
	Particle(double life_time, int velocity, unsigned short int x, unsigned short int y, unsigned short int type, int r, int g, int b);
	~Particle();
	void dot(Mat& image);	
	void move();
	void AdjustBrightness();
	void UpdatePlayerPosition(double player_x, double player_y);
	void ChangeType(unsigned short int type);

	bool SelectCarrot();
};


#endif 
