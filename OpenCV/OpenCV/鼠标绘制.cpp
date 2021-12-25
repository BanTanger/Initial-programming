#define _CRT_SECURE_NO_WARNINGS 1
#include<opencv2/opencv.hpp>
using namespace cv;

#define WINDOW_NAME "【程序窗口】"

void on_MouseHandle(int event, int x, int y, int flags, void* param);
void DrawRectangle(cv::Mat& img, cv::Rect box);
void ShowHelpText();

Rect g_rectangle;
bool g_bDrawingBox = false;
RNG g_rng(12345);//随机数类。需要设置种子

int main(int argc, char** agrv) {
	g_rectangle = Rect(-1, -1, 0, 0);
	Mat srcImage(600, 800, CV_8UC3), tempImage;
	srcImage.copyTo(tempImage);
	g_rectangle = Rect(-1, -1, 0, 0);
	srcImage = Scalar::all(0);

	//2.设置鼠标操作回调函数
	namedWindow(WINDOW_NAME);
	setMouseCallback(WINDOW_NAME, on_MouseHandle, (void*)&srcImage);

	//3.程序主循环，当进行绘制的标识符为真时，进行绘制。
	while (1) {
		srcImage.copyTo(tempImage);//复制源图到临时变量。
		if (g_bDrawingBox)DrawRectangle(tempImage, g_rectangle);
		//当进行绘制的标识符为真的时候进行绘制。
		imshow(WINDOW_NAME, tempImage);
		if (waitKey(10) == 27)break;//按下ESC键，程序退出。

	}
	return 0;
}

//on_MouseHandle函数
void on_MouseHandle(int event, int x, int y, int flags, void* param) {
	Mat& image = *(cv::Mat*)param;//不理解
	switch (event)
	{
		//鼠标移动消息
		case EVENT_MOUSEMOVE:
		{
			if (g_bDrawingBox)//如果标识符为真，则记录下长和宽到RECT类
			{
				g_rectangle.width = x - g_rectangle.x;
				g_rectangle.height = y - g_rectangle.y;
			}
		}
		break;

		//左键按下消息
		case EVENT_LBUTTONDOWN:
		{
			g_bDrawingBox = true;
			g_rectangle = Rect(x, y, 0, 0);//记录初始点。
			//这里x，y是左键点击时的坐标。
		}
		break;

		//左键抬起消息
		case EVENT_LBUTTONUP:
		{
			g_bDrawingBox = false;//置标识符为false
			//对宽和高小于零的处理。
			if (g_rectangle.width < 0) {
				g_rectangle.x += g_rectangle.width;
				g_rectangle.width *= -1;//把负数转换成正数
			}
			if (g_rectangle.height < 0) {
				g_rectangle.y += g_rectangle.height;
				g_rectangle.height *= -1;
			}
			//调用函数进行绘制
			DrawRectangle(image, g_rectangle);
		}
		break;
	}
}

void DrawRectangle(cv::Mat& img, cv::Rect box) {
	rectangle(img, box.tl(), box.br(), Scalar(g_rng.uniform(0, 255),
		g_rng.uniform(0, 255), g_rng.uniform(0, 255)));//随机颜色
}