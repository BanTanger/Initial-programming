#define _CRT_SECURE_NO_WARNINGS 1
#include<opencv2\opencv.hpp>
#include<iostream>
#include <chrono>
#include <thread>
using namespace cv;
using namespace std;
using namespace chrono;

//#define MY_METHOD_TRY
#define MY_METHOD_TRY_TWO
//#define JIANGDA
//#define MY_METHOD
#define MY_METHOD_TWO
//#define USE_TEMPLATE
//#define SHOW_ALLRECT
#define SHOW_RESULT
#define SHOW_CIRCLE
//#define DEBUG_LOG
//#define DEBUG
//#define DEBUG_TEST
//#define LEAF_IMG

/* *****************************************************************************
		经过调试，Spot和Pretreat部分都已经没有问题，红蓝都可以正常运行。
   ***************************************************************************** */
#define RED 
//#define BLUE
float factor = 0.08;
Mat srcImage, midImage;
vector<Point2f> cirV;
queue<Point2f> circleV;
Mat drawcircle;
int value = 30;
const int valueMax = 255;
static bool CircleInfo2(vector<Point2f>& m_Points, Point2f& Centroid, float& dRadius)
{
	if (!m_Points.empty())
	{
		int iNum = (int)m_Points.size();
		if (iNum < 3)	return 1;
		double X1 = 0.0;
		double Y1 = 0.0;
		double X2 = 0.0;
		double Y2 = 0.0;
		double X3 = 0.0;
		double Y3 = 0.0;
		double X1Y1 = 0.0;
		double X1Y2 = 0.0;
		double X2Y1 = 0.0;
		vector<cv::Point2f>::iterator iter;
		vector<cv::Point2f>::iterator end = m_Points.end();
		for (iter = m_Points.begin(); iter != end; ++iter)
		{
			X1 = X1 + (*iter).x;
			Y1 = Y1 + (*iter).y;
			X2 = X2 + (*iter).x * (*iter).x;
			Y2 = Y2 + (*iter).y * (*iter).y;
			X3 = X3 + (*iter).x * (*iter).x * (*iter).x;
			Y3 = Y3 + (*iter).y * (*iter).y * (*iter).y;
			X1Y1 = X1Y1 + (*iter).x * (*iter).y;
			X1Y2 = X1Y2 + (*iter).x * (*iter).y * (*iter).y;
			X2Y1 = X2Y1 + (*iter).x * (*iter).x * (*iter).y;
		}
		double C = 0.0;
		double D = 0.0;
		double E = 0.0;
		double G = 0.0;
		double H = 0.0;
		double a = 0.0;
		double b = 0.0;
		double c = 0.0;
		C = iNum * X2 - X1 * X1;
		D = iNum * X1Y1 - X1 * Y1;
		E = iNum * X3 + iNum * X1Y2 - (X2 + Y2) * X1;
		G = iNum * Y2 - Y1 * Y1;
		H = iNum * X2Y1 + iNum * Y3 - (X2 + Y2) * Y1;
		a = (H * D - E * G) / (C * G - D * D);
		b = (H * C - E * D) / (D * D - G * C);
		c = -(a * X1 + b * Y1 + X2 + Y2) / iNum;
		double A = 0.0;
		double B = 0.0;
		double R = 0.0;
		A = a / (-2);
		B = b / (-2);
		R = double(sqrt(a * a + b * b - 4 * c) / 2);
		Centroid.x = A;
		Centroid.y = B;
		dRadius = R;
		return 0;
	}
	else
		return 1;
	return 0;
}
//class Pretreat;
//class Pretreat {
//public:
//	Pretreat() {}
//	~Pretreat() {}
//	void splitChannels();
//	void prethreshold();
//	void predilate();
//};
class Spot;
class Spot {
public:
	//查找轮廓
	Spot() {}
	~Spot() {}
	void findcontoursfun(Mat& drawcircle);
};
void speed() {
	double v = 10;//一分十转
	double danwantime = 1;//秒
}
void speed(Point2f& centerR, Point2f& prepoints, Point2f& curpoints) {
	//centerR圆心。prepoints前一个点,curpoints当前点
	double chacheng = (prepoints.x * curpoints.x + prepoints.y * curpoints.y)
		/ ((sqrt((prepoints.x - centerR.x) * (prepoints.x - centerR.x) + ((prepoints.y - centerR.y) * (prepoints.y - centerR.y))))
	  *(sqrt((curpoints.x - centerR.x) * (curpoints.x - centerR.x) + ((curpoints.y - centerR.y) * (curpoints.y - curpoints.y)))));
	double cos = chacheng * factor;
	double angle = acos(cos);
	double t;
	cout << "cos:" << cos << endl;
	cout << "angle:" << angle << endl;
	double spica = angle * 12;//一帧1/12秒,反三角得到angle， angle/ 1/12 == angle*12
	cout << "角速度:" << spica <<endl;
	double spt;
	//spt = 0.785 * sin(1.884 * t) + 1.305;
	//cout << "角速度(官方)" << spt << endl;
}
void direction(Point2f cc,Point2f precenter,Point2f center) {
	double a_x = abs(precenter.x - cc.x);
	double b_x = abs(center.x - cc.x);
	double a_y = abs(precenter.y - cc.y);
	double b_y = abs(center.y - cc.y);
	double fangcheng = a_x * b_y - a_y * b_x;
	if (fangcheng > 0)cout << "方向为逆时针" << endl;
	else cout << "方向为顺时针" << endl;
}
 //spot 类函数 轮廓查找
void Spot::findcontoursfun(Mat& drawcircle) {
	vector<vector<Point>> contours;
	vector<vector<Point>> contours_ploy;
	vector<Vec4i> hierarchy;
	//Point2f center;
	Mat canny;
	RotatedRect box;
	float R;//拟合圆心获取
	Point2f cc = Point(0,0);
	Canny(midImage, canny, 50, 100, 3);// canny边缘检测。顺便二值化加去噪
	//vector<RotatedRect> minRects;
	//vector<RotatedRect> minRects(contours.size());
	findContours(canny, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);//CHAIN_APPROX_SIMPLE只保留拐点信息
#ifdef MY_METHOD_TWO
	Mat drawing = Mat::zeros(canny.size(), CV_8UC3);
	Point2f rescenterPoint;
	//通过遍历hierarachy轮廓个数来判断哪个是未击打的
#ifdef MY_METHOD_TRY
	int contour[20] = { 0 };
	for (int i = 0; i < contours.size(); i++) {
		if (hierarchy[i][3] != -1) // 是否有内嵌轮廓判断，如果有内嵌轮廓。
			contour[hierarchy[i][3]]++;//对父轮廓进行计数。
		//遍历到一个子轮廓就让夫轮廓对应数组元素加一，
		//通过看父轮廓数组个数就能得知到底有几个子轮廓了。
	}
#endif // MY_METHOD_TRY
	Point2f meanPoints = Point2f(256, 273);//不抖动相对稳定点。
	for (int j = 0; j < contours.size(); j++) {
		double area_of_contour = contourArea(contours[j],true);
		//很奇怪，把contourArea的第二参数写成true封闭时已经可以得到最小框
#ifdef MY_METHOD_TRY_TWO
		//有bug，不会修
		/*圆心卡了很久，没有办法解决。直接近似圆心为出现次数的均值情况。进而求取角速度和cos*/
			if (area_of_contour > 100 && area_of_contour <= 250) {
				Scalar color(rand() & 255, rand() & 255, rand() & 255);
				drawContours(midImage, contours, j, color, CV_FILLED, 8, hierarchy);
			//标准圆在图片上一般是椭圆，所以采用OpenCV中拟合椭圆的方法求解中心
				Mat pointsf;
				Mat(contours[0]).convertTo(pointsf, CV_32F);
				RotatedRect minR = fitEllipse(contours[0]);
				vector<Point2d> circlePoints;
				if (((minR.center.x >= 230) && (minR.center.x <= 300)) && ((minR.center.y >= 230) && (minR.center.y <= 300))) {
					circle(srcImage, minR.center, 1, Scalar(0, 255, 0), 2);
					cout << "\r" << minR.center << endl;
				}
				else {
					circle(srcImage, meanPoints, 1, Scalar(0, 255, 0), 2);
					cout << "\r" << meanPoints << endl;
				}
			}
#endif // MY_METHOD_TRY
		if ((area_of_contour >= 1200) && (area_of_contour <= 2000)) {//只有一个子轮廓的情况
			box = minAreaRect(contours[hierarchy[j][2]]);//把轮廓的所有点存入旋转矩形中。
			//这里minAreaRect寻找的是最小矩形轮廓的边缘。所以是minAreaRect(contours[hierarchy[j][2]])
			//hierarchy[j][2] ,2代表的是子轮廓，也就是最外轮廓的内嵌轮廓。
			Point2f points[4];//四点坐标存入
			box.points(points);
			Point2f center = box.center;//得到旋转矩形的中心点。
			Point2f precenter = minAreaRect(contours[hierarchy[(j + 1) % 4][2]]).center;//得到旋转矩形的中心点。
#ifdef DEBUG
			cout << "center" << center << endl;
#endif // DEBUG
			circle(srcImage, center, 1, Scalar(0, 255, 0), 2);//打印出中心点。
#ifdef SHOW_CIRCLE
			circle(drawcircle, center, 1, Scalar(0, 0, 255), 10);
			if (cirV.size() < 120) {
				cirV.push_back(center);
				circleV.push(center);
			}
			else {
				CircleInfo2(cirV, cc, R);
				//circle(drawcircle, cc, 1, Scalar(255, 0, 0), 2);
				//circle(drawcircle, cc, R, Scalar(255, 0, 0), 2);
				//circle(srcImage, cc, 1, Scalar(255, 0, 0), 2);
				//circle(srcImage, cc, R, Scalar(255, 0, 0), 2);
#if (defined DEBUG_LOG) && (defined SHOW_CIRCLE)
				cout << endl << "center " << cc.x << " , " << cc.y << endl;
#endif
				//cirV.erase(cirV.begin());//全部清除，节省资源
				if ((cc.x != 0) && (cc.y != 0)) {
					//一秒60度，一帧5/2，但sin只能识别整数
					Mat rot = getRotationMatrix2D(cc, 5/2, 1);
#if (defined DEBUG_LOG)&& (defined SHOW_CIRCLE)
					cout << endl << "center " << cc.x << " , " << cc.y << endl;
#endif
					/*Point2f center：表示旋转的中心点
					  double angle：表示旋转的角度
					  double scale：图像缩放因子*/
					float sinA = rot.at<double>(0, 1);//sin(60);
					float cosA = rot.at<double>(0, 0);//cos(60);
					float xx = -(cc.x - center.x);
					float yy = -(cc.y - center.y);
					rescenterPoint = Point2f(cc.x + cosA * xx - sinA * yy, cc.y + sinA * xx + cosA * yy);//可以作为偏移量。
					circle(srcImage, rescenterPoint, 1, Scalar(0, 255, 0), 5);
				}
			}
#endif // SHOW_CIRCLE
			for (int i = 0; i < 4; i++) {
				cout << "第" << i << "个坐标点" << points[i] << endl;
				line(srcImage, points[i], points[(i + 1) % 4], Scalar(127, 127, 0), 2, CV_AA);
			}
			Scalar color(rand() & 255, rand() & 255, rand() & 255);
			//putText(srcImage, "target", points[0], FONT_HERSHEY_SIMPLEX, 0.8, color,1.5);//打印字体
			//参一：处理图像，二，内容，三，文本字符串的左下标位置，四，字体格式（风格）,五，大小，七，厚度
			
			//方向判断
			direction(cc,precenter, center);
			//速度解算
			//speed(cc,precenter,center);
#if(defined SHOW_CIRCLE)&&(defined SHOW_RESULT)
			//namedWindow("circle", WINDOW_AUTOSIZE);
			
			//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
			//imshow("circle", drawcircle);//奇怪的bug，blue不能识别，只有red能识别。
#endif // SHOW_CIRCLE
		}
	}
#endif
}       
static void pretreat(int,void*) {
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
#ifdef RED
	//通过红蓝通道相减来得到一个明显的轮廓。at(0/1/2)代表BGR
	//Mat可以相减。
	midImage = imgChannels.at(2) - imgChannels.at(0);
#endif 
#ifdef BLUE 
	midImage = imgChannels.at(0) - imgChannels.at(2);
#endif // BLUE
	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
	//blur(midImage, midImage, Size(9, 9), Point(-1, -1));//滤波会导致二值化直接被膨胀，不理解原理，所以直接除去
	//与周珺讨论认为是之前的闭运算和二值化已经消除大部分噪音，此时再用均值滤波就是适得其反。

	// 2.二值化，背景黑，图案白
	threshold(midImage, midImage, value, valueMax, THRESH_BINARY);
#ifdef DEBUG
	//读取二值化视频
	namedWindow("midImage", WINDOW_AUTOSIZE);
	//cvResizeWindow("midImage2", 500, 500);
	imshow("midImage", midImage);
#endif // DEBUG
	int structElementSize = 1;
	Mat element = getStructuringElement(MORPH_RECT, Size(2 * structElementSize + 1, 2 * structElementSize + 1), Point(structElementSize, structElementSize));
	//Size 参数为了获得奇数长度的结构元素
	//Point 参数得到结构元素的中心
	dilate(midImage, midImage, element, Point(structElementSize, structElementSize), 1);
	//膨胀运算，第三参数为结构元素
	structElementSize = 1;
	element = getStructuringElement(MORPH_RECT, Size(2 * structElementSize + 1, 2 * structElementSize + 1), Point(structElementSize, structElementSize));
	morphologyEx(midImage, midImage, MORPH_CLOSE, element, Point(structElementSize, structElementSize), 1);

#ifdef DEBUG
	namedWindow("dilate", WINDOW_AUTOSIZE);
	//cvResizeWindow("dilate", 500, 500);
	imshow("dilate", midImage);
#endif // DEBUG
}
int main() {
	//Pretreat Image;
	Spot spot;
	Mat frame, currentframe, previousframe,difframe;
#ifdef BLUE
	VideoCapture capture("小能量机关.avi");
#endif // BULE
#ifdef RED
	VideoCapture capture("大能量机关.avi");
#endif // RED
	while (1) {
		milliseconds start_time = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		drawcircle = Mat(srcImage.rows, srcImage.cols, CV_8UC3, Scalar(0, 0, 0));
		capture >> srcImage; // 死循环读取帧
		//Image.splitChannels();
		createTrackbar("阈值调节", "大能量机关", &value, valueMax ,pretreat);
		pretreat(0, 0);
		milliseconds func1_time = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		//Image.prethreshold();
		//Image.predilate();
		spot.findcontoursfun(drawcircle);
		milliseconds func2_time = duration_cast<milliseconds>(system_clock::now().time_since_epoch());

#ifdef SHOW_RESULT
		namedWindow("大能量机关", WINDOW_AUTOSIZE);
		imshow("大能量机关", srcImage);
		//previousframe = srcImage.clone();
		//capture >> srcImage;
		//currentframe = srcImage.clone();
		//cvtColor(currentframe, currentframe, COLOR_BGR2GRAY);
		//cvtColor(previousframe, previousframe, COLOR_BGR2GRAY);
		//absdiff(currentframe, previousframe, difframe);
		//threshold(difframe, frame, 20, 255.0, CV_THRESH_BINARY|CV_THRESH_OTSU);
		//dilate(frame, frame, Mat());//膨胀  
		//erode(frame, frame, Mat());//腐蚀
		////imshow("帧差法", frame);
		milliseconds end_time = duration_cast<milliseconds>(system_clock::now().time_since_epoch());
		cout << "Pretreat_Func_耗时:" << milliseconds(func1_time).count() - milliseconds(start_time).count()<< " ms" << endl;
		cout << "Findcontours_Func_耗时:" << milliseconds(func2_time).count() - milliseconds(func1_time).count()<< " ms" << endl;
		cout << "总耗时:" << milliseconds(end_time).count() - milliseconds(start_time).count()<< " ms" << endl;
		if (waitKey(1000/24) >= 0)
			break;
#endif // SHOW_RESULT
	}
}
/*
		时长两天的bug解决心得：所需参数：阈值，长度宽度的参数设置，area的面积可以用ContoursArea()函数获得，
		然后通过打印而不是调试的手段来测试修改参数，最重要的就是框选未击打的范围，这里借鉴了其他大神的方法，
		通过contoursortfun（）的方式来对contours轮廓点进行排序，保证area调试的清晰，更好确定后面要筛选的范围

		找完轮廓后，绝大部分需求就是再获取最大轮廓，简单的可以按照轮廓周长或轮廓面积来排序。
		排序函数直接用std库：sort(contours.begin(), contours.end(), ContoursSortFun);
		框选未击打范围大同小异，已击打的周长和面积肯定比未击打的周长面积大，所以通过sort拍到后面，只要选择时不要超界就好。

		ps:这里还是不明白江达的方法，我只能进入一次for (int i = 0; i >= 0; i = hierarchy[i][0])，子父轮廓的概念还是不太清晰，需要好好加强。
		并且之前一直错在认为没有imshow显示就没有进去循环，其实是一开始的时候还没有开始显示（苦笑不得）。
		之后通过打印长宽比，面积等等方式去找到参数范围。

		学习笔记：<vector>hierarchy，这是我们要传给findContours函数的，
		用来存放每个轮廓contours[i]对应的4个hierarchy元素.hierarchy[i][0]~hierarchy[i][3]。

		第不知道多少个坑：出现多个框：1.没有让minAreaRect得到子轮廓的边缘。2.没有筛选面积
		边框闪动：错误将闭运算处理成开运算，经过谭思敏老哥的指点明白开运算和闭运算的不同，
		开闭运算会影响图像亮度（二值化后），经过对比发现开运算下二值化图像更加模糊。大概是原因所在
		边框无法定位，所以会一直闪动。

		第第不知道多少个坑加一：画不出圆形，一开始是封装成了一个函数，因为没有在循环内部，所以认为cirV点集向量没有塞入旋转矩形中心。
		但删去了DrawCircle函数把功能放在Spot里面依然无法塞入，经过彭淐老哥和刘时宇老哥的帮助得知了全局变量和局部变量的区别，我把cirV点集设置成局部变量
		所以每次进入循环都会被初始化，所以调试的时候打印cirV.size()一直都是1，改成全局函数就ok，然后就是imshow（drawcircle）出了问题，显示什么
		Assertion failed（size.width>=0,size.height>=0）,去查也是说路径错误，经过彭淐老哥的细心解答，
		总结三个可能出现问题的地方，1.函数传参需要引用（没犯错），2.要把drawcircle（要显示的内容）放在while循环里去反复创建（但这样就是一个闪动的点），
		或者把drawcircle创建成一个全局变量，不断去赋值。3，把imshow放在函数里面（必须！）
*/
