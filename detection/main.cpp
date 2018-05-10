#include <iostream>
#include "MTCNN.h"
#include "opencv2/opencv.hpp"
#include <time.h>
#include <sys/types.h>
#include <cstring>

using namespace std;
using namespace cv;
//
//int main() {
//
//    vector<string> model_file = {
//            "E:/MTCNN/model/det1.prototxt",
//            "E:/MTCNN/model/det2.prototxt",
//            "E:/MTCNN/model/det3.prototxt"
////            "../model/det4.prototxt"
//    };
//
//    vector<string> trained_file = {
//            "E:/MTCNN/model/det1.caffemodel",
//            "E:/MTCNN/model/det2.caffemodel",
//            "E:/MTCNN/model/det3.caffemodel"
////            "../model/det4.caffemodel"
//    };
//
//    MTCNN mtcnn(model_file, trained_file);
//
//	vector<String> files;
//	glob("E:/MTCNN/faces/*.bmp", files);
//	for (int i = 0; i < files.size();i++)
//	{
//		Mat img = imread(files[i]);
//		vector<Rect> rectangles;
//		mtcnn.detection(img, rectangles);
//		for (int j = 0; j < rectangles.size();j++)
//		{
//			rectangle(img, rectangles[j], Scalar(0, 255, 0), 2);
//		}
//		imshow("result", img);
//		waitKey(0);
//	}
//    return 0;
//}
// 
int main() {


    //the vector used to input the address of the net model
    vector<string> model_file = {
            "E:/MTCNN/model/det1.prototxt",
            "E:/MTCNN/model/det2.prototxt",
            "E:/MTCNN/model/det3.prototxt"
//            "../model/det4.prototxt"
    };

    //the vector used to input the address of the net parameters
    vector<string> trained_file = {
            "E:/MTCNN/model/det1.caffemodel",
            "E:/MTCNN/model/det2.caffemodel",
            "E:/MTCNN/model/det3.caffemodel"
//            "../model/det4.caffemodel"
    };

    MTCNN mtcnn(model_file, trained_file);
	vector<String> files;
	glob("E:/MTCNN/faces/*.jpg", files);
	for (int i = 0; i < files.size(); i++)
	{
		Mat img = imread(files[i]);
		vector<Rect> rectangles;
		vector<float> confidences;
		std::vector<std::vector<cv::Point>> alignment;
		mtcnn.detection(img, rectangles, confidences, alignment);

		for (int i = 0; i < rectangles.size(); i++)
		{
			int green = confidences[i] * 255;
			int red = (1 - confidences[i]) * 255;
			rectangle(img, rectangles[i], cv::Scalar(0, green, red), 3);
			for (int j = 0; j < alignment[i].size(); j++)
			{
				cv::circle(img, alignment[i][j], 5, cv::Scalar(255, 255, 0), 3);
			}
		}
		imshow("Live", img);
		waitKey(0);
	}

	
    return 0;
}

