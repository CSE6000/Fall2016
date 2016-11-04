/**
* @function Geometric_Transforms_Demo.cpp
* @brief Demo code for Geometric Transforms
* @author OpenCV team
*/

#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

/// Global variables
const char* source_window = "Source image";
const char* warp_window = "Affine Warp";

/**
* @function main
*/
int main(int argc, char** argv)
{
	Point2f srcTri[3];
	Point2f dstTri[3];

	Mat warp_mat(2, 3, CV_32FC1);
	Mat src, warp_dst;

	/// Load the image
	src = imread("HappyFish.jpg", 1);

	/// Set the dst image the same type and size as src
	warp_dst = Mat::zeros(src.rows, src.cols, src.type());

	/// Set your 3 points to calculate the  Affine Transform
	srcTri[0] = Point2f(0, 0);
	srcTri[1] = Point2f(src.cols - 1.f, 0);
	srcTri[2] = Point2f(0, src.rows - 1.f);

	dstTri[0] = Point2f(src.cols*0.0f, src.rows*0.33f);
	dstTri[1] = Point2f(src.cols*0.85f, src.rows*0.25f);
	dstTri[2] = Point2f(src.cols*0.15f, src.rows*0.7f);

	/// Get the Affine Transform warp with getAffineTransform()
	//warp_mat = 

	cout << "srcTri = " << endl << " " << srcTri[0] << endl << " " << srcTri[1] << endl << " " << srcTri[2] << endl << endl;
	cout << "dstTri = " << endl << " " << dstTri[0] << endl << " " << dstTri[1] << endl << " " << dstTri[2] << endl << endl;
	cout << "warp_mat = " << endl << " " << warp_mat << endl << endl;

	/// Apply the Affine Transform just found to the src image with warpAffine()
	// Get warped image "warp_dst" 

	float *pA;	//src points
	float *pX;  //warp matrix
	float *pB;  //dst points

	/// Get the Affine Transform warp with Intel MKL

	/// Print out affine warp and compare with result of OpenCV

	if (argc > 1)
	{
		/// Show what you got
		namedWindow(source_window, WINDOW_AUTOSIZE);
		imshow(source_window, src);

		namedWindow(warp_window, WINDOW_AUTOSIZE);
		imshow(warp_window, warp_dst);

		/// Wait until user exits the program
		waitKey(0);
	}

	return 0;
}
