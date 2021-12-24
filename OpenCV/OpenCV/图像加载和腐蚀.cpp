//// OpenCV.cpp : 定义应用程序的入口点。
////
//
//#include<opencv2\core\core.hpp>
//#include<opencv2\highgui\highgui.hpp>//高亮处理模块头文件
//#include<opencv2/imgproc/imgproc.hpp>//图像处理头文件
//using namespace cv;//包含cv的所有命名空间
//using namespace std;
//int main()//main函数是控制台程序，所以子系统应该是选择控制台
//{
//	// 读入一张图片  
//	Mat img = imread("1.jpg");
//	//// 创建一个名为 "My name is BanTanger"窗口  
//	//cvNamedWindow("My name is BanTanger");
//	// 在窗口中显示游戏原画  
//	imshow("【学习路线】", img);//imshow（）显示函数
//	Mat element = getStructuringElement(MORPH_RECT, Size(15, 15));
//	//定义一个Mat类型的变量element来接收函数的返回值
//	//getStructuringElement的返回值是固定尺寸（也可以自己更改）和形状。
//	Mat dstImage;
//	erode(img, dstImage, element);//图像腐蚀函数
//	//显示效果图
//	imshow("【效果图】腐蚀操作",dstImage);
//	// 等待10000 ms后窗口自动关闭  
//	waitKey(0);
//	return 0;
//}
