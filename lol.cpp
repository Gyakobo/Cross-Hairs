double determinant =    +A(0,0)*(A(1,1)*A(2,2)-A(2,1)*A(1,2))
                        -A(0,1)*(A(1,0)*A(2,2)-A(1,2)*A(2,0))
                        +A(0,2)*(A(1,0)*A(2,1)-A(1,1)*A(2,0));
double invdet = 1/determinant;
result(0,0) =  (A(1,1)*A(2,2)-A(2,1)*A(1,2))*invdet;
result(1,0) = -(A(0,1)*A(2,2)-A(0,2)*A(2,1))*invdet;
result(2,0) =  (A(0,1)*A(1,2)-A(0,2)*A(1,1))*invdet;

result(0,1) = -(A(1,0)*A(2,2)-A(1,2)*A(2,0))*invdet;
result(1,1) =  (A(0,0)*A(2,2)-A(0,2)*A(2,0))*invdet;
result(2,1) = -(A(0,0)*A(1,2)-A(1,0)*A(0,2))*invdet;

result(0,2) =  (A(1,0)*A(2,1)-A(2,0)*A(1,1))*invdet;
result(1,2) = -(A(0,0)*A(2,1)-A(2,0)*A(0,1))*invdet;
result(2,2) =  (A(0,0)*A(1,1)-A(1,0)*A(0,1))*invdet;





double determinant = 	+ values.at(0).at(0) * (values.at(1).at(1)*values.at(2).at(2) - values.at(2).at(1)*values.at(1).at(2))
			- values.at(0).at(1) * (values.at(1).at(0)*values.at(2).at(2) - values.at(1).at(2)*values.at(2).at(0))
			+ values.at(0).at(2) * (values.at(1).at(0)*values.at(2).at(1) - values.at(1).at(1)*values.at(2).at(0));

double invdet = 1.0 / determinant;

returnMatrix.values.at(0).at(0) = (values.at(1).at(1)*values.at(2).at(2) - values.at(2).at(1)*values.at(1).at(2)) * invdet;
returnMatrix.values.at(1).at(0) = (values.at(0).at(1)*values.at(2).at(2) - values.at(0).at(2)*values.at(2).at(1)) * invdet;
returnMatrix.values.at(2).at(0) = (values.at(0).at(1)*values.at(1).at(2) - values.at(0).at(2)*values.at(1).at(1)) * invdet;


returnMatrix.values.at(0).at(1) = (values.at(1).at(0)*values.at(2).at(2) - values.at(1).at(2)*values.at(2).at(0)) * invdet;
returnMatrix.values.at(1).at(1) = (values.at(0).at(0)*values.at(2).at(2) - values.at(0).at(2)*values.at(2).at(0)) * invdet;
returnMatrix.values.at(2).at(1) = (values.at(0).at(0)*values.at(1).at(2) - values.at(1).at(0)*values.at(0).at(2)) * invdet;

returnMatrix.values.at(0).at(2) = (values.at(1).at(0)*values.at(2).at(1) - values.at(2).at(0)*values.at(1).at(1)) * invdet;
returnMatrix.values.at(1).at(2) = (values.at(0).at(0)*values.at(2).at(1) - values.at(2).at(0)*values.at(0).at(1)) * invdet;
returnMatrix.values.at(2).at(2) = (values.at(0).at(0)*values.at(1).at(1) - values.at(1).at(0)*values.at(0).at(1)) * invdet;


void DrawWuLine (Mat& image, short X0, short Y0, short X1, short Y1,
		short BaseColor, short NumLevels, unsigned short IntensityBits){

	//	static void dot(Mat& image, const unsigned short int x, const unsigned short int y);

	//	CDC *pDC, short X0, short Y0, short X1, short Y1, short BaseColor, short NumLevels, unsigned short IntensityBits

	/*
	Arguments:
    	+  pDC is where line is drawn. Can be memory device context.
    	+  (X0,Y0) is start point of line.
    	+  (X1, Y1) is end point of line.
    	+  BaseColor is intensity of line. Pass 0 for black line.
    	+  NumLevels is number of gray scale levels. Pass 256.
    	+  IntensityBits denotes bits used to represent color component. Pass 8.
	*/

	unsigned short IntensityShift, ErrorAdj, ErrorAcc;
   	unsigned short ErrorAccTemp, Weighting, WeightingComplementMask;
   	short DeltaX, DeltaY, Temp, XDir;

   	/* Make sure the line runs top to bottom */
   	if (Y0 > Y1) {
      		Temp = Y0; Y0 = Y1; Y1 = Temp;
      		Temp = X0; X0 = X1; X1 = Temp;
   	}
   	/* Draw the initial pixel, which is always exactly intersected by
      	the line and so needs no weighting */

   	DrawPixel(pDC,X0, Y0, BaseColor);



   	if ((DeltaX = X1 - X0) >= 0) {
      		XDir = 1;
   	} else {
      		XDir = -1;
      		DeltaX = -DeltaX; /* make DeltaX positive */
   	}
   	/* Special-case horizontal, vertical, and diagonal lines, which
      	require no weighting because they go right through the center of
      	every pixel */
   	if ((DeltaY = Y1 - Y0) == 0) {
      	/* Horizontal line */
      		while (DeltaX-- != 0) {
         		X0 += XDir;
         		DrawPixel(pDC,X0, Y0, BaseColor);
      		}
      		return;
   	}	
   	if (DeltaX == 0) {
      	/* Vertical line */
      		do {
         		Y0++;
         		DrawPixel(pDC,X0, Y0, BaseColor);
      			} while (--DeltaY != 0);
      		return;
   	}	
   	if (DeltaX == DeltaY) {
      	/* Diagonal line */
      		do {
         		X0 += XDir;
         		Y0++;
         		DrawPixel(pDC,X0, Y0, BaseColor);
      		} while (--DeltaY != 0);
      		return;
  	}	
   	/* Line is not horizontal, diagonal, or vertical */
   	ErrorAcc = 0;  /* initialize the line error accumulator to 0 */
   	/* # of bits by which to shift ErrorAcc to get intensity level */
   	IntensityShift = 16 - IntensityBits;
   	/* Mask used to flip all bits in an intensity weighting, producing the
      	result (1 - intensity weighting) */
   	WeightingComplementMask = NumLevels - 1;
   	/* Is this an X-major or Y-major line? */
   	if (DeltaY > DeltaX) {
      	/* Y-major line; calculate 16-bit fixed-point fractional part of a
         pixel that X advances each time Y advances 1 pixel, truncating the
         result so that we won't overrun the endpoint along the X axis */
      	ErrorAdj = ((unsigned long) DeltaX << 16) / (unsigned long) DeltaY;
      	/* Draw all pixels other than the first and last */
      	while (--DeltaY) {
        	ErrorAccTemp = ErrorAcc;   /* remember current accumulated error */
         	ErrorAcc += ErrorAdj;      /* calculate error for next pixel */
         	if (ErrorAcc <= ErrorAccTemp) {
            	/* The error accumulator turned over, so advance the X coord */
            	X0 += XDir;
         	}
         	Y0++; /* Y-major, so always advance Y */
         	/* The IntensityBits most significant bits of ErrorAcc give us the
            	intensity weighting for this pixel, and the complement of the
            	weighting for the paired pixel */
         	Weighting = ErrorAcc >> IntensityShift;
         	DrawPixel(pDC,X0, Y0, BaseColor + Weighting);
         	DrawPixel(pDC,X0 + XDir, Y0,
               	BaseColor + (Weighting ^ WeightingComplementMask));
	}
      		/* Draw the final pixel, which is 
         	always exactly intersected by the line
         	and so needs no weighting */
      	DrawPixel(pDC,X1, Y1, BaseColor);
      	return;
   	}
   	/* It's an X-major line; calculate 16-bit fixed-point fractional part of a
      	pixel that Y advances each time X advances 1 pixel, truncating the
      	result to avoid overrunning the endpoint along the X axis */
   	ErrorAdj = ((unsigned long) DeltaY << 16) / (unsigned long) DeltaX;
   	/* Draw all pixels other than the first and last */
   	while (--DeltaX) {
      		ErrorAccTemp = ErrorAcc;   /* remember current accumulated error */
      		ErrorAcc += ErrorAdj;      /* calculate error for next pixel */
      		if (ErrorAcc <= ErrorAccTemp) {
         	/* The error accumulator turned over, so advance the Y coord */
         	Y0++;
      	}
      	X0 += XDir; /* X-major, so always advance X */
      	/* The IntensityBits most significant bits of ErrorAcc give us the
        intensity weighting for this pixel, and the complement of the
        weighting for the paired pixel */
      	Weighting = ErrorAcc >> IntensityShift;
      	DrawPixel(pDC,X0, Y0, BaseColor + Weighting);
      	DrawPixel(pDC,X0, Y0 + 1,
        BaseColor + (Weighting ^ WeightingComplementMask));
}
   	/* Draw the final pixel, which is always exactly intersected by the line
      	and so needs no weighting */
   	DrawPixel(pDC,X1, Y1, BaseColor);
}
