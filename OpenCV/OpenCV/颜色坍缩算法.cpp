//#define _CRT_SECURE_NO_WARNINGS 1
//#include<opencv2/opencv.hpp>
//#include<iostream>
//using namespace std;
//using namespace cv;
//
//void colorReduce(Mat& inputImage, Mat& outputImage, int div);
//int main() {
//	Mat srcImage = imread("1.jpg");
//	imshow("原始图像", srcImage);
//
//	//2.按原始图的参数大小来创建效果图
//	Mat dstImage;
//	dstImage.create(srcImage.rows, srcImage.cols, srcImage.type());
//	//create()初始化函数
//
//	//3.记录起始时间
//	double time0 = static_cast<double>(getTickCount());
//	//getTickCount()计数函数。
//
//	//4.调用颜色坍缩算法
//	colorReduce(srcImage, dstImage, 32);
//
//	//5.计算运行时间并输出
//	time0 = ((double)getTickCount() - time0) / getTickFrequency();
//	cout << "此方法运行时间为：" << time0 << "秒" << endl;
//
//	//6.显示
//	imshow("效果图", dstImage);
//	waitKey(0);
//}
//
////指针法，容易造成内存泄露。指针越界
////void colorReduce(Mat& inputImage, Mat& outputImage, int div) {
////	outputImage = inputImage.clone();//复制
////	int rowNumber = outputImage.rows;//行数
////	int colNumber = outputImage.cols * outputImage.channels();
////	//每一行元素的个数为管道数乘列数。
////
////	//双重for循环，遍历所有元素
////	for (int i = 0; i < rowNumber; i++) {
////		uchar* data = outputImage.ptr<uchar>(i);
////		//获取第i行的数，返回为首地址，所以需要指针。
////		for (int j = 0; j < colNumber; j++) {
////			data[j] = data[j] / div * div + div / 2;
////		}
////	}
////}
//
////迭代器
////void colorReduce(Mat& inputImage, Mat& outputImage, int div) {
////	outputImage = inputImage.clone();//复制
////	Mat_<Vec3b>::iterator it = outputImage.begin<Vec3b>();
////	Mat_<Vec3b>::iterator itend = outputImage.end<Vec3b>();
////
////	//存取彩色图像像素
////	for (; it != itend; ++it) {
////		(*it)[0] = (*it)[0] / div * div + div / 2;
////		(*it)[1] = (*it)[1] / div * div + div / 2;
////		(*it)[2] = (*it)[2] / div * div + div / 2;
////	}
////}
//
////动态地址
//void colorReduce(Mat& inputImage, Mat& outputImage, int div) {
//	outputImage = inputImage.clone();//复制
//	int rowNumber = outputImage.rows;//行数
//	int colNumber = outputImage.cols;//列数。
//
//	//存取彩色图像像素
//	for (int i = 0; i < rowNumber; i++) {
//
//		//Vec3b三通道方向向量。并且CV通过BGR来存储像素，所以<Vec3b>(i,j)[0]是蓝色通道。
//		for (int j = 0; j < colNumber; j++) {
//			//蓝色通道，B
//			outputImage.at<Vec3b>(i, j)[0] =
//				outputImage.at<Vec3b>(i, j)[0] / div * div + div / 2;
//			//绿色通道，G
//			outputImage.at<Vec3b>(i, j)[1] =
//				outputImage.at<Vec3b>(i, j)[1] / div * div + div / 2;
//			//红色通道，R
//			outputImage.at<Vec3b>(i, j)[2] =
//				outputImage.at<Vec3b>(i, j)[2] / div * div + div / 2;
//		}
//	}
//	
//}