#define _CRT_SECURE_NO_WARNINGS 1
#include<opencv2/opencv.hpp>
using namespace cv;

int main() {
	//1.读取图像
	Mat srcImage1 = imread("dota_pa.jpg");
	Mat logoImage = imread("dota_logo.jpg");
	if (!srcImage1.data) { return -1; }
	if (!logoImage.data) { return -1; }
	//异常情况抛出

	//2.定义Mat类型并给其设定ROI区域
	Mat imageROI = srcImage1(Rect(200, 250, logoImage.cols, logoImage.rows));
	//Rect函数，前两个参数是左上角的坐标，后两个参数是矩形长宽，通常在覆盖图像中的长宽选择。
	
	//3.加载掩膜（必须是灰度图）
	Mat mask = imread("dota_logo.jpg", 0);//灰度图像参数为0
	
	//4.掩膜复制到ROI
	logoImage.copyTo(imageROI, mask);
	
	//5.显示结果
	namedWindow("<1>图像叠加示例窗口");
	imshow("<1>利用ROI实现图像叠加示例窗口", srcImage1);
	imshow("<2>", logoImage);

	waitKey(0);
	return true;
}