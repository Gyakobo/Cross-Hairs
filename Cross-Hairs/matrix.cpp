#include "matrix.h" 

matrix::matrix(){
	this->col = 0;
	this->row = 0;
}

matrix::matrix(const unsigned short int col, const unsigned short int row){ 
	this->col = col; 
	this->row = row; 

	for(unsigned int j=0; j<row; j++){
		vector<double> colvalues;

		for(unsigned int i=0; i<col; i++){
			colvalues.push_back(0);	
		}

		
		this->values.push_back(colvalues);
	}
}


matrix::matrix(const unsigned short int col, const unsigned short int row, const string identifier){ 
	this->col = col; 
	this->row = row; 

	for(unsigned int j=0; j<row; j++){
		vector<double> colvalues;
		vector<string> charcolvalues;

		for(unsigned int i=0; i<col; i++){
			colvalues.push_back(0);	
			if(identifier != "")
				charcolvalues.push_back(identifier + to_string(j+1) + "," + to_string(i+1));
			else
				charcolvalues.push_back("");
		}

		
		this->values.push_back(colvalues);
		this->charvalues.push_back(charcolvalues);
	}
}

matrix v2d(const double x, const double y){
	//matrix returnMatrix(1, 2, "v");
	matrix returnMatrix(1, 2);

	returnMatrix.values.at(0).at(0) = x;
	returnMatrix.values.at(1).at(0) = y;

	//returnMatrix.charvalues.at(0).at(0) = "x";
	//returnMatrix.charvalues.at(1).at(0) = "y";
	
	return returnMatrix;
}


matrix v3d(const double x, const double y, const double z){
	//matrix returnMatrix(1, 3, "v");
	matrix returnMatrix(1, 3);

	returnMatrix.values.at(0).at(0) = x;
	returnMatrix.values.at(1).at(0) = y;
	returnMatrix.values.at(2).at(0) = z;

	/*returnMatrix.charvalues.at(0).at(0) = "x";
	returnMatrix.charvalues.at(1).at(0) = "y";
	returnMatrix.charvalues.at(2).at(0) = "z";*/
	
	return returnMatrix;
}


matrix v4d(const double x, const double y, const double z, const double w){
	//matrix returnMatrix(1, 4, "v");
	matrix returnMatrix(1, 4);

	returnMatrix.values.at(0).at(0) = x;
	returnMatrix.values.at(1).at(0) = y;
	returnMatrix.values.at(2).at(0) = z;
	returnMatrix.values.at(3).at(0) = w;
	
	/*returnMatrix.charvalues.at(0).at(0) = "x";
	returnMatrix.charvalues.at(1).at(0) = "y";
	returnMatrix.charvalues.at(2).at(0) = "z";
	returnMatrix.charvalues.at(3).at(0) = "w";*/

	return returnMatrix;
}

matrix Matrix3d_vector_crossProduct(const matrix& mtr1, const matrix& mtr2){
	matrix returnMatrix(1, 3);

	returnMatrix.values.at(0).at(0) =  mtr1.values.at(1).at(0) * mtr2.values.at(2).at(0) - mtr1.values.at(2).at(0) * mtr2.values.at(1).at(0);
	returnMatrix.values.at(1).at(0) =  mtr1.values.at(2).at(0) * mtr2.values.at(0).at(0) - mtr1.values.at(0).at(0) * mtr2.values.at(2).at(0);
	returnMatrix.values.at(2).at(0) =  mtr1.values.at(0).at(0) * mtr2.values.at(1).at(0) - mtr1.values.at(1).at(0) * mtr2.values.at(0).at(0);

	return returnMatrix;
}


matrix Matrix3d_vector_norm(const matrix& mtr){
	const double var = sqrt(mtr.values.at(0).at(0)*mtr.values.at(0).at(0) + mtr.values.at(1).at(0)*mtr.values.at(1).at(0) + mtr.values.at(2).at(0)*mtr.values.at(2).at(0));
	matrix returnMatrix(1, 3);

	returnMatrix.values.at(0).at(0) = mtr.values.at(0).at(0) / (double)var;
	returnMatrix.values.at(1).at(0) = mtr.values.at(1).at(0) / (double)var;
	returnMatrix.values.at(2).at(0) = mtr.values.at(2).at(0) / (double)var;

	return returnMatrix;
}


matrix R2(double theta){
	//matrix RotationMatrix(2, 2, "");
	matrix RotationMatrix(2, 2);
	theta = (M_PI * theta) / 180.0;

	RotationMatrix.values.at(0).at(0) = cos(theta);
	RotationMatrix.values.at(0).at(1) = -sin(theta); 
	RotationMatrix.values.at(1).at(0) = sin(theta);
	RotationMatrix.values.at(1).at(1) = cos(theta);


	/*RotationMatrix.charvalues.at(0).at(0) = "cos(@)";
	RotationMatrix.charvalues.at(0).at(1) = "(-sin(@))"; 
	RotationMatrix.charvalues.at(1).at(0) = "sin(@)";
	RotationMatrix.charvalues.at(1).at(1) = "cos(@)";*/
	
	return RotationMatrix;
}

matrix Rx3(double theta){
	//matrix RotationMatrix(3, 3, "");
	matrix RotationMatrix(3, 3);
	theta = (M_PI * theta) / 180.0;

	//ROW 0
	RotationMatrix.values.at(0).at(0) = 1;
	RotationMatrix.values.at(0).at(1) = 0;
	RotationMatrix.values.at(0).at(2) = 0;
	
	//ROW 1
	RotationMatrix.values.at(1).at(0) = 0;
	RotationMatrix.values.at(1).at(1) = cos(theta);
	RotationMatrix.values.at(1).at(2) = -sin(theta);
	
	//ROW 2
	RotationMatrix.values.at(2).at(0) = 0;
	RotationMatrix.values.at(2).at(1) = sin(theta);
	RotationMatrix.values.at(2).at(2) = cos(theta);

	/*RotationMatrix.charvalues.at(0).at(0) = "1";
	RotationMatrix.charvalues.at(0).at(1) = "0";
	RotationMatrix.charvalues.at(0).at(2) = "0";
	
	RotationMatrix.charvalues.at(1).at(0) = "0";
	RotationMatrix.charvalues.at(1).at(1) = "cos(@)";
	RotationMatrix.charvalues.at(1).at(2) = "(-sin(@))";
	
	RotationMatrix.charvalues.at(2).at(0) = "0";
	RotationMatrix.charvalues.at(2).at(1) = "sin(@)";
	RotationMatrix.charvalues.at(2).at(2) = "cos(@)";*/

	return RotationMatrix;
}

matrix Ry3(double theta){
	//matrix RotationMatrix(3, 3, "");
	matrix RotationMatrix(3, 3);
 	theta = (M_PI * theta) / 180.0;
  
 	//ROW 0
 	RotationMatrix.values.at(0).at(0) = cos(theta);
	RotationMatrix.values.at(0).at(1) = 0;
	RotationMatrix.values.at(0).at(2) = -sin(theta);
          
	//ROW 1
	RotationMatrix.values.at(1).at(0) = 0;
	RotationMatrix.values.at(1).at(1) = 1;
	RotationMatrix.values.at(1).at(2) = 0;
          
	//ROW 2
	RotationMatrix.values.at(2).at(0) = sin(theta);
	RotationMatrix.values.at(2).at(1) = 0;
	RotationMatrix.values.at(2).at(2) = cos(theta);
 
 	/*RotationMatrix.charvalues.at(0).at(0) = "cos(@)";
	RotationMatrix.charvalues.at(0).at(1) = "0";
	RotationMatrix.charvalues.at(0).at(2) = "-sin(@)";
          
	RotationMatrix.charvalues.at(1).at(0) = "0";
	RotationMatrix.charvalues.at(1).at(1) = "1";
	RotationMatrix.charvalues.at(1).at(2) = "0";
          
	RotationMatrix.charvalues.at(2).at(0) = "sin(@)";
	RotationMatrix.charvalues.at(2).at(1) = "0";
	RotationMatrix.charvalues.at(2).at(2) = "cos(@)";*/
 
	return RotationMatrix;
}

matrix Rz3(double theta){
	//matrix RotationMatrix(3, 3, "");
	matrix RotationMatrix(3, 3);
 	theta = (M_PI * theta) / 180.0;
 
 	//ROW 0
 	RotationMatrix.values.at(0).at(0) = cos(theta);
 	RotationMatrix.values.at(0).at(1) = -sin(theta);
	RotationMatrix.values.at(0).at(2) = 0;
          
	//ROW 1
	RotationMatrix.values.at(1).at(0) = sin(theta);
	RotationMatrix.values.at(1).at(1) = cos(theta);
	RotationMatrix.values.at(1).at(2) = 0;
         
	//ROW 2
	RotationMatrix.values.at(2).at(0) = 0;
	RotationMatrix.values.at(2).at(1) = 0;
	RotationMatrix.values.at(2).at(2) = 1; 

 	/*RotationMatrix.charvalues.at(0).at(0) = "cos(@)";
 	RotationMatrix.charvalues.at(0).at(1) = "-sin(@)";
	RotationMatrix.charvalues.at(0).at(2) = "0";
          
	RotationMatrix.charvalues.at(1).at(0) = "sin(@)";
	RotationMatrix.charvalues.at(1).at(1) = "cos(@)";
	RotationMatrix.charvalues.at(1).at(2) = "0";
         
	RotationMatrix.charvalues.at(2).at(0) = "0";
	RotationMatrix.charvalues.at(2).at(1) = "0";
	RotationMatrix.charvalues.at(2).at(2) = "1";*/

	return RotationMatrix;
}


const matrix I2(){
	matrix RotationMatrix(2, 2, "");
 
 	//ROW 0
 	RotationMatrix.values.at(0).at(0) = 1;
 	RotationMatrix.values.at(0).at(1) = 0;
          
	//ROW 1
	RotationMatrix.values.at(1).at(0) = 0;
	RotationMatrix.values.at(1).at(1) = 1;
         
 	RotationMatrix.charvalues.at(0).at(0) = "1";
 	RotationMatrix.charvalues.at(0).at(1) = "0";
          
	RotationMatrix.charvalues.at(1).at(0) = "0";
	RotationMatrix.charvalues.at(1).at(1) = "1";
         
	return RotationMatrix;
}

const matrix I3(){
	matrix RotationMatrix(3, 3, "");
 
 	//ROW 0
 	RotationMatrix.values.at(0).at(0) = 1;
 	RotationMatrix.values.at(0).at(1) = 0;
	RotationMatrix.values.at(0).at(2) = 0;
          
	//ROW 1
	RotationMatrix.values.at(1).at(0) = 0;
	RotationMatrix.values.at(1).at(1) = 1;
	RotationMatrix.values.at(1).at(2) = 0;
         
	//ROW 2
	RotationMatrix.values.at(2).at(0) = 0;
	RotationMatrix.values.at(2).at(1) = 0;
	RotationMatrix.values.at(2).at(2) = 1; 

 	RotationMatrix.charvalues.at(0).at(0) = "1";
 	RotationMatrix.charvalues.at(0).at(1) = "0";
	RotationMatrix.charvalues.at(0).at(2) = "0";
          
	RotationMatrix.charvalues.at(1).at(0) = "0";
	RotationMatrix.charvalues.at(1).at(1) = "1";
	RotationMatrix.charvalues.at(1).at(2) = "0";
         
	RotationMatrix.charvalues.at(2).at(0) = "0";
	RotationMatrix.charvalues.at(2).at(1) = "0";
	RotationMatrix.charvalues.at(2).at(2) = "1"; 

	return RotationMatrix;
}


matrix decoyMatrix(int col, int row, double numb){
	matrix returnMatrix(col, row, to_string(numb));
	
	for(unsigned int r=0; r<row; r++){
		for(unsigned int c=0; c<col; c++){
			returnMatrix.values.at(r).at(c) = numb;
		}
	}

	return returnMatrix;
}


matrix matrix::getTranspose(){
	matrix returnMatrix(this->row, this->col, "t");
	
	for(unsigned int j=0; j<this->row; j++){
		for(unsigned int i=0; i<this->col; i++){
			returnMatrix.values.at(i).at(j) = this->values.at(j).at(i);
			returnMatrix.charvalues.at(i).at(j) = this->charvalues.at(j).at(i);
		}
	}

	return returnMatrix;
}


matrix matrix::getInverse(){
	matrix returnMatrix(3, 3, "");

	/*
	double determinant =	+ this->values.at(0).at(0) * (this->values.at(1).at(1)*this->values.at(2).at(2) - this->values.at(2).at(1)*this->values.at(1).at(2))
				- this->values.at(0).at(1) * (this->values.at(1).at(0)*this->values.at(2).at(2) - this->values.at(1).at(2)*this->values.at(2).at(0))
				+ this->values.at(0).at(2) * (this->values.at(1).at(0)*this->values.at(2).at(1) - this->values.at(1).at(1)*this->values.at(2).at(0));
	*/

	double determinant = 	+ this->values.at(0).at(0) * (this->values.at(1).at(1)*this->values.at(2).at(2) - this->values.at(2).at(1)*this->values.at(1).at(2))
				- this->values.at(0).at(1) * (this->values.at(1).at(0)*this->values.at(2).at(2) - this->values.at(2).at(0)*this->values.at(1).at(2))
				+ this->values.at(0).at(2) * (this->values.at(1).at(0)*this->values.at(2).at(1) - this->values.at(2).at(0)*this->values.at(1).at(1));
	
	cout<<"Determinant = "<<determinant <<endl<<endl;

	if(determinant != 0){
		double invdet = 1.0 / determinant;

		returnMatrix.values.at(0).at(0) = (this->values.at(1).at(1)*this->values.at(2).at(2) - this->values.at(2).at(1)*this->values.at(1).at(2)) * invdet;
		returnMatrix.values.at(0).at(1) = (this->values.at(2).at(1)*this->values.at(0).at(2) - this->values.at(0).at(1)*this->values.at(2).at(2)) * invdet;
		returnMatrix.values.at(0).at(2) = (this->values.at(0).at(1)*this->values.at(1).at(2) - this->values.at(0).at(2)*this->values.at(1).at(1)) * invdet;

		returnMatrix.values.at(1).at(0) = (this->values.at(1).at(2)*this->values.at(2).at(0) - this->values.at(2).at(2)*this->values.at(1).at(0)) * invdet;
		returnMatrix.values.at(1).at(1) = (this->values.at(2).at(2)*this->values.at(0).at(0) - this->values.at(0).at(2)*this->values.at(2).at(0)) * invdet;
		returnMatrix.values.at(1).at(2) = (this->values.at(0).at(2)*this->values.at(1).at(0) - this->values.at(0).at(0)*this->values.at(1).at(2)) * invdet;

		returnMatrix.values.at(2).at(0) = (this->values.at(1).at(0)*this->values.at(2).at(1) - this->values.at(2).at(0)*this->values.at(1).at(1)) * invdet;
		returnMatrix.values.at(2).at(1) = (this->values.at(2).at(0)*this->values.at(0).at(1) - this->values.at(0).at(0)*this->values.at(2).at(1)) * invdet;
		returnMatrix.values.at(2).at(2) = (this->values.at(0).at(0)*this->values.at(1).at(1) - this->values.at(0).at(1)*this->values.at(1).at(0)) * invdet;

		return returnMatrix;
	}

	else{
		cout<<"Error in Inverse, determinant equals zero"<<endl<<endl;
		return I3();
	}
}


matrix operator+(const matrix& mtr1, const matrix& mtr2){
	matrix returnMatrix(mtr1.col, mtr1.row);
	for(unsigned int j=0; j<mtr1.row; j++){
		for(unsigned int i=0; i<mtr1.col; i++){
			returnMatrix.values.at(j).at(i) = mtr1.values.at(j).at(i) + mtr2.values.at(j).at(i);
		}
	}
	return returnMatrix;
}


matrix operator-(const matrix& mtr1, const matrix& mtr2){
	matrix returnMatrix(mtr1.col, mtr1.row);
	for(unsigned int j=0; j<mtr1.row; j++){
		for(unsigned int i=0; i<mtr1.col; i++){
			returnMatrix.values.at(j).at(i) = mtr1.values.at(j).at(i) - mtr2.values.at(j).at(i);
		}
	}
	return returnMatrix;
}

matrix operator*(const double& a, const matrix& mtr){
	matrix returnMatrix(mtr.col, mtr.row);
	for(unsigned int j=0; j<mtr.row; j++){
		for(unsigned int i=0; i<mtr.col; i++){
			returnMatrix.values.at(j).at(i) = a * mtr.values.at(j).at(i);
		}
	}
	return returnMatrix;
}


matrix operator*(const matrix& mtr, const double& a){
	matrix returnMatrix(mtr.col, mtr.row);
	for(unsigned int j=0; j<mtr.row; j++){
		for(unsigned int i=0; i<mtr.col; i++){
			returnMatrix.values.at(j).at(i) = a * mtr.values.at(j).at(i);
		}
	}
	return returnMatrix;
}



matrix operator*(const matrix& a, const matrix& b){
	matrix returnMatrix(b.col, a.row, "");

	for(unsigned int j=0; j<a.row; j++){
		for(unsigned int i=0; i<b.col; i++){
			for(unsigned int scroll=0; scroll<a.col; scroll++){
				returnMatrix.values.at(j).at(i) += a.values.at(j).at(scroll) * b.values.at(scroll).at(i);

				//returnMatrix.charvalues.at(j).at(i) += "+" + a.charvalues.at(j).at(scroll) + " * " + b.charvalues.at(scroll).at(i);
			}
		}
	}
	return returnMatrix;
}

void matrix::showMatrix(){
	cout << "[";
	for(unsigned int j=0; j<this->row; j++){
		for(unsigned int i=0; i<this->col; i++){
			if(i == (col-1) && j==(row-1))
				cout << this->values.at(j).at(i) << " ]" << endl;
			else
				cout << this->values.at(j).at(i) << ", ";
		}
		cout<<endl;
	}
}


void matrix::showcharMatrix(){
	cout << "[";
	for(unsigned int j=0; j<this->row; j++){
		for(unsigned int i=0; i<this->col; i++){
			if(i == (col-1) && j==(row-1))
				cout << this->charvalues.at(j).at(i) << " ]" << endl;
			else
				cout << this->charvalues.at(j).at(i) << ";	 ";
		}
		cout<<endl;
	}
}
