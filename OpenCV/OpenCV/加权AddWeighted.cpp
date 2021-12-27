#define _CRT_SECURE_NO_WARNINGS 1
#include<opencv2/opencv.hpp>
using namespace cv;

int main() {
	double alphaValue = 0.5;
	double betaValue;
	betaValue = (1.0) - alphaValue;//混合加权，总权和为1，所以设一个未知量之后，另一个未知量为1-前未知量。
	Mat srcImage1, srcImage2, dstImage;

	srcImage1 = imread("mogu.jpg");
	srcImage2 = imread("rain.jpg");

	if (!srcImage1.data) { return -1; }
	if (!srcImage2.data) { return -1; }

	//两张图片的尺寸必须一致。
	addWeighted(srcImage1, alphaValue, srcImage2, betaValue, 0.0, dstImage);
	//参数解释，图片一，图一权重，图二，图二权重，标量值（暂时不明白什么意思，先用0.0）,输出图

	imshow("<2>线性混合示例窗口【原图】", srcImage2);

	imshow("<3>线性混合示例窗口【效果图】", dstImage);
	
	waitKey(0);
	return true;
}
