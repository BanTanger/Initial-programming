#define _CRT_SECURE_NO_WARNINGS 1
#include<opencv2\opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

#define SHOW_ALLRECT
#define SHOW_RESULT
#define SHOW_CIRCLE
//#define DEBUG_LOG
#define DEBUG
#define RED 
//#define BLUE
//#define DEBUG_TEST

Mat srcImage, midImage;

class Pretreat;
class Spot;
class Pretreat {
public:
	Pretreat() {}
	~Pretreat() {}
	void splitChannels();
	void prethreshold();
	void predilate();
};
class Spot {
public:
	//查找轮廓
	Pretreat pre;
	Spot() {}
	~Spot() {}
	void findcontoursfun();
};
// Pretreat类 膨胀操作。
void Pretreat::predilate() {
	int structElementSize = 2;
	Mat element =getStructuringElement(MORPH_RECT,Size(structElementSize + 1,structElementSize + 1),Point(structElementSize, structElementSize));
	//Size 参数为了获得奇数长度的结构元素
	//Point 参数得到结构元素的中心
	dilate(midImage, midImage, element, Point(structElementSize, structElementSize), 1);
	//膨胀运算，第三参数为结构元素
	structElementSize = 2;
	element =getStructuringElement(MORPH_RECT,Size(structElementSize + 1,structElementSize + 1),Point(structElementSize, structElementSize));
	morphologyEx(midImage, midImage, MORPH_CLOSE, element, Point(structElementSize, structElementSize), 1);

#ifdef DEBUG
	namedWindow("dilate", WINDOW_AUTOSIZE);
	//cvResizeWindow("dilate", 500, 500);
	imshow("dilate", midImage);
#endif // DEBUG
}
// Pretreat类 分离通道操作。
void Pretreat::splitChannels() {
#ifdef DEBUG_TEST
	//一开始想用canny边缘检测，因为可以顺便二值化操作，但发现有较大误差
	Mat canny;
	int structElementSize = 1;
	Mat element = getStructuringElement(MORPH_RECT, Size(structElementSize + 1, structElementSize + 1), Point(structElementSize, structElementSize));
	Canny(srcImage, canny, 80, 160, 3, false);
	dilate(canny, canny, element);
	imshow("Canny", canny);
#endif 
	// 1.分离颜色通道
	vector<Mat> imgChannels;
	split(srcImage, imgChannels);
	blur(srcImage, srcImage, Size(9, 9), Point(-1, -1));//滤波
#ifdef RED
	//通过红蓝通道相减来得到一个明显的轮廓。at(0/1/2)代表BGR
	//Mat可以相减。
	midImage = imgChannels.at(2) - imgChannels.at(0);
#endif 
#ifdef BLUE 
	midImage = imgChannels.at(0) - imgChannels.at(2);
#endif // BLUE
}
// Pretreat类 阈值化操作。
void Pretreat::prethreshold() {
	// 2.二值化，背景黑，图案白
	threshold(midImage, midImage,100,256, THRESH_BINARY|THRESH_OTSU);
#ifdef DEBUG
	//读取二值化视频
	namedWindow("midImage", WINDOW_AUTOSIZE);
	//cvResizeWindow("midImage2", 500, 500);
	imshow("midImage", midImage);
#endif // DEBUG
}

double getDistance(Point source, Point end) {
	double dis;
	dis = pow((source.x - end.x), 2) + pow((source.y - end.y), 2);
	return sqrt(dis);
}

 //spot 类函数 轮廓查找
void Spot::findcontoursfun() {
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	findContours(midImage, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);
	
	//旋转矩形
	RotatedRect rect;
	Point2f src[4], dst[4];
	double width, height;
	//因为是旋转的，动态，所以不能直接用书上的例子，要构建一个旋转类，之后用向量容器把旋转对象输出
		for (int i = 0; i < contours.size(); i++) {
			//最小矩形
			rect = minAreaRect(contours[i]);
			Point2f P[4];//创建四个点。
			rect.points(P);//读取最小外接矩形的四个顶点
			Point2f rectcenters = rect.center;//最小矩形的中心；
			//获得长度。
			width = getDistance(P[0], P[1]);
			height = getDistance(P[1], P[2]);

#ifdef SHOW_ALLRECT
			Scalar color(rand() & 255, rand() & 255, rand() & 255);
			drawContours(srcImage, contours, i, color, 4, 8, hierarchy);
#endif // show_allrect
			namedWindow(" ", WINDOW_AUTOSIZE);
			imshow("",srcImage);
		}
}


int main() {
	Pretreat Image;
	Spot spot;
#ifdef BLUE
	VideoCapture capture("小能量机关.mp4");
#endif // BULE
#ifdef RED
	VideoCapture capture("大能量机关.mp4");
#endif // RED

	Mat frame;
	Point2i center;//定义矩形中心

	while (1) {
		capture >> frame; // 死循环读取帧
		resize(frame, srcImage, Size(frame.cols, frame.rows));
		
		Image.splitChannels();
		Image.prethreshold();
		Image.predilate();
		spot.findcontoursfun();

#ifdef SHOW_RESULT
		imshow("大能量机关", frame);
		if (waitKey(1) >= 0)
			break;
#endif // SHOW_RESULT
	}
}




