#include "Particle.h"

Particle::Particle() {
	SetImg();
}

Particle::Particle (double life_time, int velocity, unsigned short int x, unsigned short int y, unsigned short int type){
	this->life_time = life_time;
	this->velocity = velocity;
	
	this->x = x;
	this->y = y;
	
	this->type = type;
	Img[this->x][this->y] = type;
}
Particle::Particle (double life_time, int velocity, unsigned short int x, unsigned short int y, unsigned short int type, int r, int g, int b){
	this->life_time = life_time;
	this->velocity = velocity;
	
	this->x = x;
	this->y = y;

	this->r = r;
	this->g = g;
	this->b = b;
	
	this->type = type;
	
	Img[this->x][this->y] = type;
}

Particle::~Particle() {}

void Particle::dot(Mat& image){
	switch(this->type) {
		case MANUAL:
			image.at<Vec3b>(this->y, this->x)[0] = this->b;
			image.at<Vec3b>(this->y, this->x)[1] = this->g;
			image.at<Vec3b>(this->y, this->x)[2] = this->r;
				
			for (unsigned short int c=0; c<image.channels(); c++) { 
				image.at<Vec3b>(this->y,this->x)[c] = saturate_cast<uchar>( this->alpha*image.at<Vec3b>(y,x)[c] + this->brightness );
			}
			//image.at<Vec3b>(this->y, this->x)[2] = saturate_cast<uchar>( this->*image.at<Vec3b>(y,x)[c] + this->brightness );;
			
			break;
		case SAND:
			image.at<Vec3b>(this->y, this->x)[0] = this->b;
			image.at<Vec3b>(this->y, this->x)[1] = this->g;
			image.at<Vec3b>(this->y, this->x)[2] = this->r;
				
			for (unsigned short int c=0; c<image.channels(); c++) { 
				image.at<Vec3b>(this->y,this->x)[c] = saturate_cast<uchar>( this->alpha*image.at<Vec3b>(y,x)[c] + this->brightness );
			}
			//image.at<Vec3b>(this->y, this->x)[2] = saturate_cast<uchar>( this->*image.at<Vec3b>(y,x)[c] + this->brightness );;
			
			break;

		/*case SAND:
			image.at<Vec3b>(this->y, this->x)[0] = 0;
			image.at<Vec3b>(this->y, this->x)[1] = 166;
			image.at<Vec3b>(this->y, this->x)[2] = 180;
			break;*/

		case WATER:
			image.at<Vec3b>(this->y, this->x)[0] = 232;
			image.at<Vec3b>(this->y, this->x)[1] = 128;
			image.at<Vec3b>(this->y, this->x)[2] = 104;
			break;

	}
}

void Particle::move(){
	// Basic Gravity and Traversion

	switch(this->type) {	
		/*case MANUAL:
			if (this->y < Height && this->x < Width) {
				Img[this->x][this->y] = DEFAULT;
		
				// A	
				if (Img[this->x][this->y+1] == DEFAULT) this->y += 1 * this->velocity;
			
				// B	
				else if (Img[this->x][this->y+1] == MANUAL && Img[this->x-1][this->y+1] == DEFAULT) {
					this->y += 1 * this->velocity;
					this->x -= 1 * this->velocity;
				}
				// C	
				else if (Img[this->x][this->y+1] == MANUAL && Img[this->x-1][this->y+1] == MANUAL && Img[this->x+1][this->y+1] == DEFAULT) {
					this->y += 1 * this->velocity;
					this->x += 1 * this->velocity;
				}
				
				Img[this->x][this->y] = this->type;
			}
			else {
				this->y = Height;
			}

			//cout << "x = " << this->x << ", y = " << this->y << endl;
			break;*/

		case SAND:
			if (this->y < Height && this->x < Width) {
				Img[this->x][this->y] = DEFAULT;
		
				// A	
				if (Img[this->x][this->y+1] == DEFAULT) this->y += 1 * this->velocity;
			
				// B	
				else if ((Img[this->x][this->y+1] == SAND || Img[this->x][this->y+1] == MANUAL) && Img[this->x-1][this->y+1] == DEFAULT) {
					this->y += 1 * this->velocity;
					this->x -= 1 * this->velocity;
				}
				// C	
				else if ((Img[this->x][this->y+1] == SAND || Img[this->x][this->y+1] == MANUAL) && (Img[this->x-1][this->y+1] == SAND || Img[this->x-1][this->y+1] == MANUAL) && Img[this->x+1][this->y+1] == DEFAULT) {
					this->y += 1 * this->velocity;
					this->x += 1 * this->velocity;
				}
				
				Img[this->x][this->y] = this->type;
			}
			else {
				this->y= Height;
			}

			//cout << "x = " << this->x << ", y = " << this->y << endl;
			break;

		case WATER:
			if (this->y < Height && this->x < Width) {
				Img[this->x][this->y] = DEFAULT;
		
				// A	
				if (Img[this->x][this->y+1] == DEFAULT) this->y += 1 * this->velocity;
			
				// B	
				else if ((Img[this->x][this->y+1] == WATER || Img[this->x][this->y+1] == SAND) && Img[this->x-1][this->y+1] == DEFAULT) {
					this->y += 1 * this->velocity;
					this->x -= 1 * this->velocity;
				}
				// C	
				else if (((Img[this->x][this->y+1] == WATER && Img[this->x-1][this->y+1] == WATER) || (Img[this->x][this->y+1] == SAND && Img[this->x-1][this->y+1] == SAND)) && Img[this->x+1][this->y+1] == DEFAULT) {
					this->y += 1 * this->velocity;
					this->x += 1 * this->velocity;
				}
				// D	
				else if (((Img[this->x][this->y+1] == WATER && Img[this->x-1][this->y+1] == WATER && Img[this->x+1][this->y+1] == WATER) || (Img[this->x][this->y+1] == SAND && Img[this->x-1][this->y+1] == SAND && Img[this->x+1][this->y+1] == SAND))  && Img[this->x-1][this->y] == DEFAULT) {
					this->x -= 1 * this->velocity;
				}
				// E	
				else if (((Img[this->x][this->y+1] == WATER && Img[this->x-1][this->y+1] == WATER && Img[this->x+1][this->y+1] == WATER && Img[this->x-1][this->y] == WATER) || (Img[this->x][this->y+1] == SAND && Img[this->x-1][this->y+1] == SAND && Img[this->x+1][this->y+1] == SAND && Img[this->x-1][this->y] == SAND)) && Img[this->x+1][this->y] == DEFAULT) {
					this->x += 1 * this->velocity;
				}
				
				Img[this->x][this->y] = this->type;
			}
			else {
				this->y = Height;
			}

			//cout << "x = " << this->x << ", y = " << this->y << endl;
			break;
	}
}

void Particle::UpdatePlayerPosition(double player_x, double player_y) {
	Player_x = player_x;
	Player_y = player_y;
}

void Particle::AdjustBrightness() {
	double dist = sqrt((this->x-Player_x)*(this->x-Player_x) + (this->y-Player_y)*(this->y-Player_y));

	this->brightness	= dist * (-0.25);
	this->alpha		= 1.0 / (dist * (0.01));

	if(this->alpha > 1.0)	this->alpha = 1.0;  
}

void Particle::ChangeType(unsigned short int type) {
	double distance = dist(this->x, this->y, Player_x, Player_y);

	if(distance < 24.0) {
		this->type = type;
		Img[this->x][this->y] = type;
	}
}

bool Particle::SelectCarrot() {
	double distance = dist(this->x, this->y, Player_x, Player_y);

	if (distance < 15) {
		this->type = type;
		Img[this->x][this->y] = type;

		return true;
	}

	else return false;
}




