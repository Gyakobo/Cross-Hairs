#ifndef MAIN_H
#define MAIN_H


//System Requirements
#include <iostream>                                                                              
#include <stdio.h>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>

//Math
#include <vector> 
#include "vect.h"
#include "matrix.h"
#include "matrix.cpp"
#include "quaternion.h"

//OpenCV
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui/highgui_c.h>
#include <opencv2/core.hpp>
//#include <opencv2/imgproc/imgproc.hpp>

//Chrono
#include <chrono>
#include <ctime>

//Mesh classes
#include "Mesh.h"

//Screen size
#include "screensize.h"

//Particle
#include "Particle.h"

#define SAND	0
#define WATER	1	
#define WOOD	2	
#define MANUAL	3	
#define CARROT	4	

#define DEFAULT	15	

vector<Particle> CreateObjects(Mat& image, unsigned short int m_x,  unsigned short int m_y) {
	vector<Particle> particles;

	for(int x=0; x<image.cols; x++) {
		for(int y=0; y<image.rows; y++) {
			Vec3b & color = image.at<Vec3b>(y, x);
 
			if(int(color[0]) != 0 && int(color[1]) != 0 && int(color[2]) != 0)     
				particles.push_back(Particle(0, 1, x+m_x, y+m_y, MANUAL, int(color[2]), int(color[1]), int(color[0])));
		}
	}

	return particles;
}

using namespace std;
using namespace cv;


int  x_mouse=0, y_mouse=0;
bool leftMouseClick = false;
bool rightMouseClick = false;

unsigned short int player_x = width/2, player_y = height/2;

static Mat BrightContrast(Mat& image, double alpha, double beta) {
	for( unsigned short int y = 0; y < image.rows; y++ ) {
		for( unsigned short int x = 0; x < image.cols; x++ ) {
			for( unsigned short int c = 0; c < image.channels(); c++ ) {
				image.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( alpha*image.at<Vec3b>(y,x)[c] + beta );
			}
		}
	}
}

static Mat background = imread("background.png");

static void blackout(Mat& img1){
	for(unsigned short int y=0; y<500; y++) {
		for(unsigned short int x=0; x<1000; x++) {
			//for (unsigned short int c = 0; c < 3; c++) {
				img1.at<Vec3b>(y, x)[0] = background.at<Vec3b>(y, x)[0];
				img1.at<Vec3b>(y, x)[1] = background.at<Vec3b>(y, x)[1];
				img1.at<Vec3b>(y, x)[2] = background.at<Vec3b>(y, x)[2];
				//img1.at<Vec3b>(y,x)[c] = saturate_cast<uchar>( alpha*img1.at<Vec3b>(y,x)[c] + beta );
			//}
		}
	}

	//BrightContrast(image, -1, -110);
}

/*void blackout(Mat& image){
	for(unsigned int y=0; y<image.rows; y++){
		for(unsigned int x=0; x<image.cols; x++){
			image.at<Vec3b>(y, x)[0] = 0;
			image.at<Vec3b>(y, x)[1] = 0;
			image.at<Vec3b>(y, x)[2] = 0;
		}
	}
}*/



/*static void dot(Mat& image, const unsigned short int x, const unsigned short int y){
	for(int m_x = -5; m_x <= 5; m_x++){
		for(int m_y = -5; m_y <= 5; m_y++){
        		Vec3b & color = image.at<Vec3b>(m_y+y,m_x+x);

        		color[0] = 121;
        		color[1] = 121;
        		color[2] = 122;

        		image.at<Vec3b>(Point(m_y+y,m_x+x)) = color;
		}
	}
}*/



static void cursor(Mat& image, unsigned short x,  unsigned short y){
	line(image, Point(5+x, 5+y), Point(-5+x, -5+y), Scalar(0, 0, 255), 2.7);
	line(image, Point(-5+x, 5+y), Point(5+x, -5+y), Scalar(0, 0, 255), 2.7);
}



void CallBackFunc(int event,int x, int y, int flags, void* param)
{
     	if  ( event == EVENT_LBUTTONDOWN ){
          	//cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
		leftMouseClick = true;
     	}
     	else if  ( event == EVENT_RBUTTONDOWN ){
          	//cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
		rightMouseClick = true;
     	}
     	else if  ( event == EVENT_MBUTTONDOWN ){
          	//cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
     	}
	else if ( event == EVENT_MOUSEMOVE ){
        	//cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;
 	}
	x_mouse = x;
	y_mouse = y;
}

#endif
