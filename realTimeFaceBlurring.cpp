#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <vector>

int main() {

	const std::string address = "https://{your_phone_ip_address}/video";
	cv::VideoCapture camera(address);


	cv::CascadeClassifier face_cascade;
	cv::Mat frame, frameResized;

	face_cascade.load("./Resources/haarcascade_frontalface_default.xml");

	while (true) {
		camera.read(frame);

		cv::resize(frame, frameResized, cv::Size(), 0.5, 0.5);

		std::vector<cv::Rect> faces;

		face_cascade.detectMultiScale(frameResized, faces, 1.3, 5);

		for (int i = 0; i < faces.size(); i++) {

			cv::Rect roi = cv::Rect(faces[i].tl(), faces[i].br());
			cv::GaussianBlur(frameResized(roi), frameResized(roi), cv::Size(51, 51), 0);

		}

		imshow("Real-time face blurring", frameResized);
		cv::waitKey(1);
	}
}
