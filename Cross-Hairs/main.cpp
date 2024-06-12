#include "main.h"


int main(int, char**){
	//Mat image(height, width, CV_8UC3);
	Mat image = imread("background.png");

	//imwrite("NewBackground.jpg", newImg);
	
	Mat Player = imread("rabbit.png");
	
	Mat stalag1 = imread("stalagtite1.png");
	Mat stalag2 = imread("stalagtite2.png");
	Mat stalag3 = imread("stalagtite3.png");
	Mat stalag4 = imread("dino.png");
	Mat stalag5 = imread("dog.png");
	Mat stalag6 = imread("spaceship.png");
	Mat stalag7 = imread("snow.png");
	Mat stalag8 = imread("bone.png");

	int a[] = {1, 2, 3, 4, 5, 6};
	int score = 0;
	string StrScore = "";
	
	Mat carrot1 = imread("carrot.png");
	Mat carrot2 = imread("carrot.png");
	Mat carrot3 = imread("carrot.png");
	Mat carrot4 = imread("carrot.png");
	Mat carrot5 = imread("carrot.png");
	Mat carrot6 = imread("carrot.png");

	
	resize(Player, Player, Size(Player.cols/12, Player.rows/12), INTER_LINEAR);

	resize(stalag1, stalag1, Size(stalag1.cols/6, stalag1.rows/6), INTER_LINEAR);
	resize(stalag2, stalag2, Size(stalag2.cols/4, stalag2.rows/4), INTER_LINEAR);
	resize(stalag3, stalag3, Size(stalag3.cols/7, stalag3.rows/7), INTER_LINEAR);
	resize(stalag4, stalag4, Size(stalag4.cols/5.5, stalag4.rows/5.5), INTER_LINEAR);
	resize(stalag5, stalag5, Size(stalag5.cols/4.5, stalag5.rows/4.5), INTER_LINEAR);
	resize(stalag6, stalag6, Size(stalag6.cols/4.5, stalag6.rows/4.5), INTER_LINEAR);
	resize(stalag7, stalag7, Size(stalag7.cols/4, stalag7.rows/4), INTER_LINEAR);
	resize(stalag8, stalag8, Size(stalag8.cols/3.5, stalag8.rows/3.5), INTER_LINEAR);

	resize(carrot1, carrot1, Size(carrot1.cols/14, carrot1.rows/14), INTER_LINEAR);
	resize(carrot2, carrot2, Size(carrot2.cols/14, carrot2.rows/14), INTER_LINEAR);
	resize(carrot3, carrot3, Size(carrot3.cols/14, carrot3.rows/14), INTER_LINEAR);
	resize(carrot4, carrot4, Size(carrot4.cols/14, carrot4.rows/14), INTER_LINEAR);
	resize(carrot5, carrot5, Size(carrot5.cols/14, carrot5.rows/14), INTER_LINEAR);
	resize(carrot6, carrot6, Size(carrot6.cols/14, carrot6.rows/14), INTER_LINEAR);
	
	Mat stalag11 = stalag1;
	
	clock_t timer 		= clock();
	clock_t elapsed_time 	= clock();

	Particle CreateImg;

	vector<vector<Particle>> stallions;
	vector<vector<Particle>> Carrots;
	
	//stallions.push_back(CreateObjects(Player, width/2, height/2));

	vector<Particle> Rabbit = CreateObjects(Player, width/2, height/2);

	stallions.push_back(CreateObjects(stalag5, 30, 20));
	stallions.push_back(CreateObjects(stalag1, 240, 100));
	stallions.push_back(CreateObjects(stalag11, 10, 110));
	stallions.push_back(CreateObjects(stalag4, 300, 200));
	stallions.push_back(CreateObjects(stalag6, 493, 340));
	stallions.push_back(CreateObjects(stalag7, 10, 280));
	stallions.push_back(CreateObjects(stalag8, 450, 8));

	Carrots.push_back(CreateObjects(carrot1, 70, 30));
	Carrots.push_back(CreateObjects(carrot2, 280, 110));
	Carrots.push_back(CreateObjects(carrot3, 297, 310));
	Carrots.push_back(CreateObjects(carrot4, 680, 180));
	Carrots.push_back(CreateObjects(carrot5, 200, 380));
	Carrots.push_back(CreateObjects(carrot6, 600, 130));

	for(;;){
		// Main Timer
		blackout(image);
		
		elapsed_time = (clock() - timer) / 100.0;
		CreateImg.UpdatePlayerPosition(player_x, player_y);
		
		cursor(image, player_x, player_y);

		//player_x = x_mouse;
		//player_y = y_mouse;
	
		for (unsigned short int i=0; i<Carrots.size(); i++) {
			for (unsigned short int j=0; j<Carrots.at(i).size(); j++) {
				if (a[i]) Carrots.at(i).at(j).dot(image);
			}
		}
		
		for (unsigned short int i=0; i<stallions.size(); i++) {
			for (unsigned short int j=0; j<stallions.at(i).size(); j++) {
				stallions.at(i).at(j).dot(image);
				stallions.at(i).at(j).AdjustBrightness();
				stallions.at(i).at(j).move();
			}
		}

		for (unsigned short int i=0; i<Rabbit.size(); i++) {
			Rabbit.at(i).dot(image);
		}



		player_x = x_mouse;
		player_y = y_mouse;

		switch(score) {
			case 0:
				StrScore = "Score: ";	
				break;
			case 1:
				StrScore = "Score: 1";	
				break;
			case 2:
				StrScore = "Score: 2";	
				break;
			case 3:
				StrScore = "Score: 3";	
				break;
			case 4:
				StrScore = "Score: 4";	
				break;
			case 5:
				StrScore = "Score: 5";	
				break;
		}


		cout << score << endl;

		putText(image, StrScore, Point(10, 480), FONT_HERSHEY_DUPLEX, 1, CV_RGB(255, 255, 255), 2);

		if(leftMouseClick)  {
			leftMouseClick = false;

			bool flag = false;

			for (unsigned short int i=0; i<stallions.size(); i++) {
				for (unsigned short int j=0; j<stallions.at(i).size(); j++) {
					stallions.at(i).at(j).ChangeType(SAND);
				}
			}
			for (unsigned short int i=0; i<Carrots.size(); i++) {
				for (unsigned short int j=0; j<Carrots.at(i).size(); j++) {
					if(Carrots.at(i).at(j).SelectCarrot()) {
						if(!flag) {
							score++;
							a[i] = 0;
							flag = true;
						}
					}
				}
				flag = false;
			}
			//player_x = x_mouse;
			//player_y = y_mouse;
			
		}
		if(rightMouseClick) { 
			rightMouseClick = false;
		}

		while(elapsed_time < 0.001) elapsed_time = (clock() - timer) / 100.0; 
		timer = clock();


		// End of code 	
		namedWindow("Hi there", CV_WINDOW_AUTOSIZE);
		imshow("Hi there", image);
		setMouseCallback("Hi there", CallBackFunc, &image);

		if(waitKey(10) == 27) break;

		//if(waitKey(10) & 0XFF == 27) break;
		
	}

	image.release();
	destroyAllWindows();
}

