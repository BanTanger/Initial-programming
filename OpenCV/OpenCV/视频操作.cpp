//#define _CRT_SECURE_NO_WARNINGS 1
//#include<opencv2/opencv.hpp>
//using namespace cv;
//
//int main() {
//	//1.读入视频
//	//VideoCapture capture("video1.mp4");//调用视频
//
//	VideoCapture capture(0);//调用摄像头
//	//capture捕获，俘获
//
//	//2.循环显示每一帧
//	while (1) {
//		Mat frame;//定义一个Mat变量，用于存储每一帧画面
//		capture >> frame;//读取当前帧
//		//frame框架
//
//		//其实是不断更新图片。 		
//		imshow("读取视频", frame);
//
//		waitKey(30);//延时30ms
//	}
//	return 0;
//}