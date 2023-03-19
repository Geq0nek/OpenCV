#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

cv::Mat imgHSV, mask;
int hmin = 0, smin = 0, vmin = 0;
int hmax = 179, smax = 255, vmax = 255;

cv::VideoCapture cap(0);
cv::Mat img;

int main() 
{
	cv::namedWindow("Trackbars", (640, 200));
	cv::createTrackbar("Hue Min", "Trackbars", &hmin, 179);
	cv::createTrackbar("Hue Max", "Trackbars", &hmin, 179);
	cv::createTrackbar("Sat Min", "Trackbars", &smin, 255);
	cv::createTrackbar("Sat Max", "Trackbars", &smax, 255);
	cv::createTrackbar("Val Min", "Trackbars", &vmin, 255);
	cv::createTrackbar("Val Max", "Trackbars", &vmax, 255);

	while (true) {

		cap.read(img);

		cv::cvtColor(img, imgHSV, cv::COLOR_BGR2HSV);

		cv::Scalar lower(hmin, smin, vmin);
		cv::Scalar upper(hmax, smax, vmax);
		inRange(imgHSV, lower, upper, mask);

		std::cout << hmin << "," << smin << "," << vmin << "," << hmax << "," << smax << "," << vmax << std::endl;

		imshow("Image", img);
		imshow("Image mask", mask);

		cv::waitKey(1);
	}

	return 0;
}