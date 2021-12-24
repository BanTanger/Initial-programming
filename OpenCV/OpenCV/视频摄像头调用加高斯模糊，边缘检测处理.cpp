//#define _CRT_SECURE_NO_WARNINGS 1
//#include<opencv2/opencv.hpp>
//using namespace cv;
//
//int main() {
//	VideoCapture capture(0);
//	Mat edges;
//
//	//死循环显示每一帧
//	while (1) {
//		//1.读入图像
//		Mat frame;
//		capture >> frame;
//
//		//2.将原图像转化成灰度图像。
//		cvtColor(frame, edges, CV_BGR2GRAY);//转化彩图为灰度图
//
//		//3.使用3*3内核降噪(2*3+1 = 7)
//		blur(edges, edges, Size(7, 7));
//
//		//4.进行canny边缘检测并显示
//		Canny(edges, edges, 0, 30, 3);
//		imshow("被canny后的视频", edges);//显示经过处理的当前帧。
//		if (waitKey(30) >= 0)break;
//	}
//	return 0;
//}