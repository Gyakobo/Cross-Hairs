#ifndef MESHPOINTS_H
#define MESHPOINTS_H

#include <string>

const double var = 1.0;
const double zfar = 1.0;
const double znear = -1.0;

const unsigned short int m_cubeCols 	 	= 18;		// 18
const unsigned short int m_cubeRows 	 	= 6;		// 6
const unsigned short int m_cubeNumbPoints 	= 6*m_cubeRows;	// 36

const double cubeVertices[6][18] = {
	//South
	{-var,-var,znear,	-var,var,znear,		var,var,znear,		-var,-var,znear,	var,var,znear,		var,-var,znear},
	//East
	{var,-var,znear,	var,var,znear,		var,var,zfar,		var,-var,znear,		var,var,zfar,		var,-var,zfar},
	//Front
	{var,-var,zfar,		var,var,zfar,		-var,var,zfar,		var,-var,zfar,		-var,var,zfar,		-var,-var,zfar},
	//West
	{-var,-var,zfar,	-var,var,zfar,		-var,var,znear,		-var,-var,zfar,		-var,var,znear,		-var,-var,znear},
	//Top
	{-var,var,znear,	-var,var,zfar,		var,var,zfar,		-var,var,znear,		var,var,zfar,		var,var,znear},
	//Down
	{var,-var,zfar,		-var,-var,zfar,		-var,-var,znear,	var,-var,zfar,		-var,-var,znear,	var,-var,znear}
};
#endif
