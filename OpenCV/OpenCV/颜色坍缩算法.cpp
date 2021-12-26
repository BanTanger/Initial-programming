#define _CRT_SECURE_NO_WARNINGS 1
#include<opencv2/opencv.hpp>
#include<iostream>
using namespace std;
using namespace cv;

void colorReduce(Mat& inputImage, Mat& outputImage, int div);
int main() {
	Mat srcImage = imread("1.jpg");
	imshow("原始图像", srcImage);

	//2.按原始图的参数大小来创建效果图
	Mat dstImage;
	dstImage.create(srcImage.rows, srcImage.cols, srcImage.type());
	//create()初始化函数

	//3.记录起始时间
	double time0 = static_cast<double>(getTickCount());
	//getTickCount()计数函数。

	//4.调用颜色坍缩算法
	colorReduce(srcImage, dstImage, 32);

	//5.计算运行时间并输出
	time0 = ((double)getTickCount() - time0) / getTickFrequency();
	cout << "此方法运行时间为：" << time0 << "秒" << endl;

	//6.显示
	imshow("效果图", dstImage);
	waitKey(0);
}