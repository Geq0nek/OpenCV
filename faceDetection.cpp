#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

int main() {
	cv::VideoCapture camera(0);
	cv::CascadeClassifier facedetect;
	cv::Mat img;
	facedetect.load("./Resources/haarcascade_frontalface_default.xml");

	while (true) {	
		camera.read(img);

		std::vector<cv::Rect> faces;

		facedetect.detectMultiScale(img, faces, 1.3, 5);

		std::cout << faces.size() << std::endl;

		for (int i = 0; i < faces.size(); i++) {
			cv::rectangle(img, faces[i].tl(), faces[i].br(), cv::Scalar(50, 50, 255), 3);
			cv::rectangle(img, cv::Point(0,0), cv::Point(50, 50), cv::Scalar(50, 50, 255), cv::FILLED);
			putText(img, std::to_string(faces.size()), cv::Point(10, 40), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(255, 255, 255), 1);
		}

		imshow("Face detection", img);
		cv::waitKey(1);
	}
}