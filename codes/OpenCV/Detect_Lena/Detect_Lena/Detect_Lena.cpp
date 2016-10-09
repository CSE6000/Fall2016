// Simple OpenCV Example......
#include <stdlib.h>  
#include <opencv2/opencv.hpp> 

// Define the namespaces to use......
using namespace std; 
using namespace cv; 

// Define some colors here
const Scalar RED = Scalar(0,0,255);
const Scalar PINK = Scalar(230,130,255);
const Scalar BLUE = Scalar(255,0,0);
const Scalar LIGHTBLUE = Scalar(255,255,160);
const Scalar GREEN = Scalar(0,255,0);
const Scalar WHITE = Scalar(255,255,255);

//==============================================================================
// Main function to the executable
int main(int argc, char** argv)
{

  // First load the face detector
  CascadeClassifier face_cascade; // Cascade classifier for detecting the face
  if(!face_cascade.load("haarcascade_frontalface_alt.xml")) {
    cout << "Unable to load the face detector!!!!" << endl;
    return -1; 
  }
  
  // Next read in the image as graysale
  Mat im = imread("lena.png",0);

  //-- Detect faces
  vector<Rect> faces; 
  face_cascade.detectMultiScale( im, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));
  
  // See if anything was detected
  cout << "Detected " << faces.size() << " faces!!!! " << endl; 

  // Next step is to display the result
  cv::Mat display_im;
  if(im.channels() == 3) display_im = im.clone(); // Why do we need to clone here?
  else cvtColor(im,display_im,CV_GRAY2RGB); // The display image  

  // If faces are detected then loop through and display bounding boxes
  if(faces.size() > 0) {
    for(int i=0; i<faces.size(); i++) {
      rectangle(display_im, faces[i], RED); 
    }
  }
  
  // Display the image
  imshow("Result",display_im);

  // Then wait for a key press
  waitKey(0);
}
