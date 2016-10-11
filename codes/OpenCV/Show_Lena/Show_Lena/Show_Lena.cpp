// Simple OpenCV Example......
#include <stdlib.h>  
#include <opencv2/opencv.hpp> 

// Define the namespaces to use......
using namespace std; 
using namespace cv; 

//==============================================================================
// Main function to the executable
int main(int argc, char** argv)
{
  // Read in the image as graysale
  // What happens when you set the flag to 1??? 
  Mat im = imread("lena.png",0); 

  // Display the image
  imshow("Result",im);

  // Then wait for a key press
  waitKey(0);
}
