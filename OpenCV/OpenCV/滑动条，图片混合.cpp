//#define _CRT_SECURE_NO_WARNINGS 1
//#include<opencv2/opencv.hpp>
//#include<opencv2/highgui/highgui.hpp>
//using namespace cv;
//
//#define WINDOW_NAME "线性混合示例"  //窗口定义宏
//
//const int g_nMaxAlphaValue = 100;//Alpha 值的最大值
//int g_nAlphaValueSlider;//滑动条对应的变量。createTrack函数的第六参数。
//double g_dAlphaValue;
//double g_dBetaValue;
//
////声明存储图像的变量。
//Mat g_srcImage1;
//Mat g_srcImage2;
//Mat g_dstImage;
//
////on_Trackbar()函数
////相应滑动条的回调函数
//void on_Trackbar(int ,void *) {
//	//第一个参数是轨迹条的位置，第二个参数是用户数据
//
//	g_dAlphaValue = (double)g_nAlphaValueSlider / g_nMaxAlphaValue;
//	//求得当前alpha值相对最大值的比例。
//	g_dBetaValue = (1.0 - g_dAlphaValue);
//	//beta值为1-alpha值
//
//	//根据alpha和beta值进行线性混合
//	addWeighted(g_srcImage1, g_dAlphaValue, g_srcImage2, g_dBetaValue, 0.0, g_dstImage);
//
//	//显示
//	imshow(WINDOW_NAME, g_dstImage);
//	
//}
//
//int main(int argc,char** argv) {
//	//加载图片，两张图片大小要一致
//	g_srcImage1 = imread("1.jpg");
//	g_srcImage2 = imread("2.jpg");
//	if (!g_srcImage1.data){
//		printf("读取第一张图片失败，请确认目录下是否有imread函数指定的图片存在!\n");
//		return -1;
//	}
//	if (!g_srcImage2.data) {
//		printf("读取第二张图片失败，请确认目录下是否有imread函数指定的图片存在!\n");
//		return -1;
//	}
//
//	//设置滑动条初始值为70
//	g_nAlphaValueSlider = 70;
//
//	//创建窗体
//	namedWindow(WINDOW_NAME, 1);
//
//	//在创建的窗体中创建一个滑动条控件
//	char TrackbarName[50];
//	sprintf(TrackbarName, "透明值 %d", g_nMaxAlphaValue);
//
//	createTrackbar(TrackbarName, WINDOW_NAME, &g_nAlphaValueSlider, g_nMaxAlphaValue, on_Trackbar);
//	//参一：轨迹条名字，二：窗口名字，三：int*类型的指针，表示滑块的位置，当前的值
//	//四：表示滑块最大值，五：回调函数，滑块位置改变时函数进行回调。
//	//六：用户传给回调函数的数据，如果这个数据用全局变量来处理，可以不用设置。
//	
//	//回调函数显示结果
//	on_Trackbar(g_nAlphaValueSlider, 0);
//
//	waitKey(0);
//
//	return 0;
//}