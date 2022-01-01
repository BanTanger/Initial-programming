#define _CRT_SECURE_NO_WARNINGS 1
#include<opencv2\opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

#define SHOW_RESULT
#define SHOW_CIRCLE
#define DEBUG_LOG
#define DEBUG
//#define RED 
#define BLUE
int main() {
	VideoCapture capture("小能量机关.mp4");
	//VideoCapture capture("大能量机关.mp4");
	Mat frame, srcImage;
	Point2i center;//定义矩形中心
	while (1) {
		capture >> frame; // 死循环读取帧
		resize(frame, srcImage, Size(frame.cols , frame.rows));
		//调节视频大小(压缩视频)

		//center = markred(srcImage);// 抓中心
		//cout << center << endl;
	
	//图像预处理
		// 1.分离颜色通道
		vector<Mat> imgChannels;
		split(srcImage, imgChannels);
		blur(srcImage, srcImage, Size(9, 9), Point(-1, -1));

		//readCapture();// 1.获取图像 readCapture()
		//pretreatCap();// 2.图像预处理 pretreatCap()
#ifdef RED
		//通过红蓝通道相减来得到一个明显的轮廓。at(0/1/2)代表BGR
		//Mat可以相减。
		Mat midImage2 = imgChannels.at(2) - imgChannels.at(0);
#endif 
#ifdef BLUE
		Mat midImage2 = imgChannels.at(0) - imgChannels.at(2);
#endif // BLUE

		// 2.二值化，背景黑，图案白
		threshold(midImage2,midImage2, 120, 256, THRESH_BINARY);
#ifdef DEBUG
		//读取二值化视频
		namedWindow("midImage2", 0);
		//cvResizeWindow("midImage2", 500, 500);
		imshow("midImage2", midImage2);
#endif // DEBUG
		int structElementSize = 1;
		Mat element = 
		getStructuringElement(MORPH_RECT, 
		Size( structElementSize + 1, 
		      structElementSize + 1), 
		Point(structElementSize, structElementSize));
		//Size 参数为了获得奇数长度的结构元素
		//Point 参数得到结构元素的中心
		dilate(midImage2, midImage2, element, Point(structElementSize, structElementSize),1);
		//膨胀运算，第三参数为结构元素
		structElementSize = 1;
		element = 
		getStructuringElement(MORPH_RECT,
		Size(structElementSize + 1,
			 structElementSize + 1),
		Point(structElementSize, structElementSize));
		morphologyEx(midImage2, midImage2, MORPH_CLOSE, element, Point(structElementSize, structElementSize), 1);

#ifdef DEBUG
		namedWindow("dilate", 0);
		//cvResizeWindow("dilate", 500, 500);
		imshow("dilate", midImage2);
#endif // DEBUG
		//边缘检测

#ifdef SHOW_RESULT
		imshow("大能量机关", frame);
		if (waitKey(1000/24) >= 0)
			break;
#endif // SHOW_RESULT
	}
}

