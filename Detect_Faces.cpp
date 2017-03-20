#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/objdetect.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;


int main(int argc, char** argv)
{
 // capture from web camera init

 VideoCapture cap(0);
 cap.open(0);

 Mat img;

 // Initialize the inbuilt Harr Cascade frontal face detection
 // Below mention the path of where your haarcascade_frontalface_alt2.xml file is located

  CascadeClassifier face_cascade;
  face_cascade.load( "/home/dell/OpenCV_Installed/opencv-3.1.0/data/haarcascades/haarcascade_frontalface_alt2.xml" );


 for (;;)
 {
 
      // Image from camera to Mat

      cap >> img;
    
     // obtain input image from source
     cap.retrieve(img, CV_CAP_OPENNI_BGR_IMAGE);

     // Just resize input image if you want
     resize(img, img, Size(1000,640));

     // Container of faces
      vector<Rect> faces;
      
      
      // Detect faces
      face_cascade.detectMultiScale( img, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(140, 140) );

      
      //Show the results
      // Draw circles on the detected faces

    for( int i = 0; i < faces.size(); i++ )
    {
        Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
        ellipse( img, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );
    }

     // To draw rectangles around detected faces
    /* for (unsigned i = 0; i<faces.size(); i++)
				rectangle(img,faces[i], Scalar(255, 0, 0), 2, 1);*/
     

     imshow("wooohooo", img);
     int key2 = waitKey(20);

 }
 return 0;
}
