#include "Mesh.h"

Mesh::Mesh(){
	this->x = 0.0;
	this->y = 0.0;
	this->z = 0.0;

	//Calculate vectors
	for(unsigned int row=0; row<m_cubeRows; row++){
		for(unsigned int col=0; col<m_cubeCols; col=col+3){
			this->pointMtr.push_back(v3d(cubeVertices[row][col], cubeVertices[row][col+1], cubeVertices[row][col+2]));
			this->m_pointMtr.push_back(v3d(cubeVertices[row][col], cubeVertices[row][col+1], cubeVertices[row][col+2]));
		}
	}
}


Mesh::Mesh(const double x_m, const double y_m, const double z_m){
	this->x = x_m;
	this->y = y_m;
	this->z = z_m;

	//Calculate vectors
	for(unsigned int row=0; row<m_cubeRows; row++){
		for(unsigned int col=0; col<m_cubeCols; col=col+3){
			this->pointMtr.push_back(v3d(cubeVertices[row][col]+x_m, cubeVertices[row][col+1]+y_m, cubeVertices[row][col+2]+z_m));
			this->m_pointMtr.push_back(v3d(cubeVertices[row][col]+x_m, cubeVertices[row][col+1]+y_m, cubeVertices[row][col+2]+z_m));
		}
	}
}


Mesh::Mesh(string FileName){
	ifstream f(FileName);
	vector<matrix> verts;

	while(!f.eof()){
		char line[128];
		f.getline(line, 128);
		
		strstream s;
		s << line;

		char junk;

		if(line[0] == 'v'){
			matrix tempVertex(1, 3);
			s >> junk >> tempVertex.values.at(0).at(0) >> tempVertex.values.at(1).at(0) >> tempVertex.values.at(2).at(0);
			verts.push_back(tempVertex);
		}

		if(line[0] == 'f'){
			int f[3];
			s >> junk >> f[0] >> f[1] >> f[2];
			pointMtr.push_back(verts.at(f[0]-1));
			pointMtr.push_back(verts.at(f[1]-1));
			pointMtr.push_back(verts.at(f[2]-1));

			m_pointMtr.push_back(verts.at(f[0]-1));
			m_pointMtr.push_back(verts.at(f[1]-1));
			m_pointMtr.push_back(verts.at(f[2]-1));
		}
	}
}








void Mesh::buildMesh(const Mat& image, const double x_m, const double y_m){
	const double x_offset = width/2.0 + x_m;
	const double y_offset = height/2.0 + y_m;

	for(unsigned int vertex=0; vertex<m_cubeNumbPoints; vertex++){
		if((vertex+1)%4 != 0)
			line(image, Point(this->pointMtr.at(vertex).values.at(0).at(0) + x_offset, this->pointMtr.at(vertex).values.at(1).at(0) + y_offset), Point(this->pointMtr.at(vertex+1).values.at(0).at(0) + x_offset, this->pointMtr.at(vertex+1).values.at(1).at(0) + y_offset), Scalar(0, 0, 255), 1);
		else
			line(image, Point(this->pointMtr.at(vertex).values.at(0).at(0) + x_offset, this->pointMtr.at(vertex).values.at(1).at(0) + y_offset), Point(this->pointMtr.at(vertex-3).values.at(0).at(0) + x_offset, this->pointMtr.at(vertex-3).values.at(1).at(0) + y_offset), Scalar(0, 255, 0), 1);
	}
}


void Mesh::m_buildMesh(const Mat& image){
	const double x_offset = (width)/2.0;
	const double y_offset = (height)/2.0;

	for(unsigned int vertex=0; vertex<m_cubeNumbPoints; vertex++){
		if((vertex+1)%4 != 0) 
			line(image, Point(this->m_pointMtr.at(vertex).values.at(0).at(0)+x_offset, this->m_pointMtr.at(vertex).values.at(1).at(0)+y_offset), Point(this->m_pointMtr.at(vertex+1).values.at(0).at(0)+x_offset, this->m_pointMtr.at(vertex+1).values.at(1).at(0)+y_offset), Scalar(0, 0, 255), 1);
	}
}

void Mesh::mnew_buildMesh(const Mat& image){
	const double x_offset = width/2.0;
	const double y_offset = height/2.0;

	matrix camera = v3d(0.0, 0.0, 0.0);

	//for(unsigned int vertex=0; vertex<m_cubeNumbPoints; vertex++){
	for(unsigned int m_vertex=0; m_vertex<m_cubeNumbPoints; m_vertex=m_vertex+3){
		matrix normal = Matrix3d_vector_norm(Matrix3d_vector_crossProduct(this->m_pointMtr.at(m_vertex+1)-this->m_pointMtr.at(m_vertex), this->m_pointMtr.at(m_vertex+2)-this->m_pointMtr.at(m_vertex)));
		for(unsigned int vertex=m_vertex; vertex<m_vertex+3; vertex++){
			matrix normal = Matrix3d_vector_crossProduct(this->m_pointMtr.at(m_vertex+1)-this->m_pointMtr.at(m_vertex), this->m_pointMtr.at(m_vertex+2)-this->m_pointMtr.at(m_vertex));

			/*if(normal.values.at(0).at(0) * (this->m_pointMtr.at(vertex).values.at(0).at(0)-camera.values.at(0).at(0)) +
		   	   normal.values.at(1).at(0) * (this->m_pointMtr.at(vertex).values.at(1).at(0)-camera.values.at(1).at(0)) +
		   	   normal.values.at(2).at(0) * (this->m_pointMtr.at(vertex).values.at(2).at(0)-camera.values.at(2).at(0))<0.0){*/
			if(normal.values.at(2).at(0) < 0.0){
				if((vertex+1)%3 != 0)
					line(image, Point(this->m_pointMtr.at(vertex).values.at(0).at(0)+x_offset, this->m_pointMtr.at(vertex).values.at(1).at(0)+y_offset), Point(this->m_pointMtr.at(vertex+1).values.at(0).at(0)+x_offset, this->m_pointMtr.at(vertex+1).values.at(1).at(0)+y_offset), Scalar(0, 0, 255), 1);
				
				else
					line(image, Point(this->m_pointMtr.at(vertex).values.at(0).at(0)+x_offset, this->m_pointMtr.at(vertex).values.at(1).at(0)+y_offset), Point(this->m_pointMtr.at(vertex-2).values.at(0).at(0)+x_offset, this->m_pointMtr.at(vertex-2).values.at(1).at(0)+y_offset), Scalar(0, 0, 255), 1);
					
			}
		}
	}
}




void Mesh::Rotate(const double alpha, const double beta, const double gamma){
	for(unsigned int vertex=0; vertex<m_cubeNumbPoints; vertex++){
		this->pointMtr.at(vertex) = this->pointMtr.at(vertex) - v3d(this->x, this->y, this->z);
		this->pointMtr.at(vertex) = Rx3(alpha) * Ry3(beta) * Rz3(gamma) * this->pointMtr.at(vertex);
		this->pointMtr.at(vertex) = this->pointMtr.at(vertex) + v3d(this->x, this->y, this->z);
	}
}




void Mesh::Scale(const double x_scaleNumb, const double y_scaleNumb, const double z_scaleNumb){
	for(unsigned int vertex=0; vertex<m_cubeNumbPoints; vertex++){
		this->pointMtr.at(vertex) = this->pointMtr.at(vertex) - v3d(this->x, this->y, this->z);
		this->pointMtr.at(vertex).values.at(0).at(0) = x_scaleNumb * this->pointMtr.at(vertex).values.at(0).at(0);
		this->pointMtr.at(vertex).values.at(1).at(0) = y_scaleNumb * this->pointMtr.at(vertex).values.at(1).at(0);
		this->pointMtr.at(vertex).values.at(2).at(0) = z_scaleNumb * this->pointMtr.at(vertex).values.at(2).at(0);
		this->pointMtr.at(vertex) = this->pointMtr.at(vertex) + v3d(this->x, this->y, this->z);
	}
}



void Mesh::PerspectiveRender(){
	//Calculate 3d perspective
	double applicateDist, applicateNear = 0.1, applicateFar = 1000.0;

	applicateDist = (double)(applicateFar - applicateNear);

	for(int vertex=0; vertex<m_cubeNumbPoints; vertex++){
		double zfactor = (double)this->pointMtr.at(vertex).values.at(2).at(0) + this->z;

		this->m_pointMtr.at(vertex) = v3d( 	( ((double)height/(double)width) * fi * this->pointMtr.at(vertex).values.at(0).at(0)) / zfactor, 
							(fi * this->pointMtr.at(vertex).values.at(1).at(0)) / zfactor, 
							zfactor * (applicateFar/applicateDist) - (applicateFar*applicateNear)/applicateDist);
		
		this->m_pointMtr.at(vertex).values.at(0).at(0) *= 0.5 * (double)width;
		this->m_pointMtr.at(vertex).values.at(1).at(0) *= 0.5 * (double)width;
		this->m_pointMtr.at(vertex).values.at(2).at(0) *= 0.5 * (double)width;
	}
}


void Mesh::Transform(const double x_m, const double y_m, const double z_m){
	for(unsigned int vertex=0; vertex<m_cubeNumbPoints; vertex++)
		this->pointMtr.at(vertex) = this->pointMtr.at(vertex) - v3d(this->x, this->y, this->z);

	this->x = x_m;
	this->y = y_m;
	this->z += z_m;

	for(unsigned int vertex=0; vertex<m_cubeNumbPoints; vertex++)
		this->pointMtr.at(vertex) = this->pointMtr.at(vertex) + v3d(this->x, this->y, this->z);
}

