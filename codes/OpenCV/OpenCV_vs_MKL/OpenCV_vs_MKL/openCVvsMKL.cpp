#include <opencv2/opencv.hpp> // Includes the opencv library
#include <stdlib.h> // Include the standard library
#include <stdio.h>
#include <mkl.h>

using namespace std;
using namespace cv;

int main()
{
	double s_initial;
	double cv_n_secs;
	double mkl_n_secs;

	int K = 3000; // Number of columns in A
	int M = 400; // Number of rows in A
	int N = 1; // Number of columns in B
	int trials = 3000; // Number of trials

	Mat cvA = Mat(M, K, CV_64F);
	Mat cvB = Mat(K, N, CV_64F);
	Mat cvC(M, N, CV_64F);

	randu(cvA, Scalar::all(0), Scalar::all(5));
	randu(cvB, Scalar::all(0), Scalar::all(5));

	s_initial = dsecnd();
	for (int i = 0; i < trials; i++) {
		cvC = cvA * cvB; // Apply multiplication in OpenCV
	}
	cv_n_secs = (dsecnd() - s_initial);

	//cout << "cvA = \n" << cvA << ";" << endl << endl;
	//cout << "cvB = \n" << cvB << ";" << endl << endl;
	//cout << "cvC = \n" << cvC << ";" << endl << endl;	
	cout << "OpenCV took " << cv_n_secs << " seconds." << endl;

	double *pA = (double*)cvA.data;//ptr<double>(0);
	double *pB = (double*)cvB.data;//ptr<double>(0);
	double *pC = (double*)cvC.data;

	s_initial = dsecnd();
	double alpha = 1.0;
	double beta = 0.0;
	for (int i = 0; i < trials; i++) {
		cblas_dgemm(CblasRowMajor, CblasNoTrans, CblasNoTrans, M, N, K, alpha, pA, K, pB, N, beta, pC, N);
	}
	mkl_n_secs = (dsecnd() - s_initial);
	//cout << "cvC = \n" << cvC << ";" << endl << endl;
	cout << "MKL took " << mkl_n_secs << " seconds." << endl;
	cout << "MKL is " << cv_n_secs / mkl_n_secs << " times faster than OpenCV!!!" << endl;

	return 0;
}