//#include<opencv2/opencv.hpp>
//#include<opencv2/imgproc/imgproc.hpp>
//#include<opencv2\core\core.hpp>
//#include<opencv2\highgui\highgui.hpp>//高亮处理模块头文件
//using namespace cv;
//
//int main() {
//	//0.载入原始图
//	Mat srcImage = imread("1.jpg");//工程目录里放置一张1.jpg的图片
//	imshow("【原始图】Canny边缘检测",srcImage);
//	Mat dstImage, edge, grayImage;
//
//	//1.创建与src同类型和大小的矩阵（dst）
//	dstImage.create(srcImage.size(), srcImage.type());
//
//	//2.将原图像装换成灰度图像
//	cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);
//	
//	//3.使用3*3内核降噪
//	blur(grayImage, edge, Size(4, 4));
//
//	//4.运行Canny算子
//	Canny(edge, edge, 3, 9, 3);
//
//	//5.显示效果图
//	imshow("【效果图】Canny边缘化检测", edge);
//
//	waitKey(0);
//
//	return 0;
//}