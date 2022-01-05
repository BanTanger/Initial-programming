#define _CRT_SECURE_NO_WARNINGS 1
#include<opencv2\opencv.hpp>
#include<iostream>
using namespace cv;
using namespace std;

//#define MY_METHOD_TRY
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

Mat srcImage, midImage;
vector<Point2f> cirV;
Mat drawcircle;
int value = 30;
const int valueMax = 255;
#ifdef MY_METHOD
static inline bool ContoursSortFun(vector<cv::Point> contour1, vector<cv::Point> contour2)
{
	return (contour1.size() > contour2.size());
}
#endif // MY_METHOD

static bool CircleInfo2(std::vector<cv::Point2f>& pts, cv::Point2f& center, float& radius)
{
	center = cv::Point2d(0, 0);//圆心
	radius = 0.0;
	if (pts.size() < 3) return false;;

	//各参数设置（抄轮子）
	double sumX = 0.0;
	double sumY = 0.0;
	double sumX2 = 0.0;
	double sumY2 = 0.0;
	double sumX3 = 0.0;
	double sumY3 = 0.0;
	double sumXY = 0.0;
	double sumX1Y2 = 0.0;
	double sumX2Y1 = 0.0;
	const double N = (double)pts.size();
	for (int i = 0; i < pts.size(); ++i)
	{
		double x = pts.at(i).x;
		double y = pts.at(i).y;
		double x2 = x * x;
		double y2 = y * y;
		double x3 = x2 * x;
		double y3 = y2 * y;
		double xy = x * y;
		double x1y2 = x * y2;
		double x2y1 = x2 * y;

		sumX += x;
		sumY += y;
		sumX2 += x2;
		sumY2 += y2;
		sumX3 += x3;
		sumY3 += y3;
		sumXY += xy;
		sumX1Y2 += x1y2;
		sumX2Y1 += x2y1;
	}
	double C = N * sumX2 - sumX * sumX;
	double D = N * sumXY - sumX * sumY;
	double E = N * sumX3 + N * sumX1Y2 - (sumX2 + sumY2) * sumX;
	double G = N * sumY2 - sumY * sumY;
	double H = N * sumX2Y1 + N * sumY3 - (sumX2 + sumY2) * sumY;

	double denominator = C * G - D * D;
	if (std::abs(denominator) < DBL_EPSILON) return false;
	double a = (H * D - E * G) / (denominator);
	denominator = D * D - G * C;
	if (std::abs(denominator) < DBL_EPSILON) return false;
	double b = (H * C - E * D) / (denominator);
	double c = -(a * sumX + b * sumY + sumX2 + sumY2) / N;

	center.x = a / (-2);
	center.y = b / (-2);
	radius = std::sqrt(a * a + b * b - 4 * c) / 2;
	return true;
}
//class Pretreat;
class Spot;
//class Pretreat {
//public:
//	Pretreat() {}
//	~Pretreat() {}
//	void splitChannels();
//	void prethreshold();
//	void predilate();
//};
class Spot {
public:
	//查找轮廓
	Spot() {}
	~Spot() {}
	void findcontoursfun(Mat& drawcircle);
};
// Pretreat类 膨胀操作。
//void Pretreat::predilate() {
//	int structElementSize = 1;
//	Mat element =getStructuringElement(MORPH_RECT,Size(2*structElementSize + 1,2*structElementSize + 1),Point(structElementSize, structElementSize));
//	//Size 参数为了获得奇数长度的结构元素
//	//Point 参数得到结构元素的中心
//	dilate(midImage, midImage, element, Point(structElementSize, structElementSize), 1);
//	//膨胀运算，第三参数为结构元素
//	structElementSize = 1;
//	element =getStructuringElement(MORPH_RECT,Size(2*structElementSize + 1,2*structElementSize + 1),Point(structElementSize, structElementSize));
//	morphologyEx(midImage, midImage, MORPH_CLOSE, element, Point(structElementSize, structElementSize), 1);
//
//#ifdef DEBUG
//	namedWindow("dilate", WINDOW_AUTOSIZE);
//	//cvResizeWindow("dilate", 500, 500);
//	imshow("dilate", midImage);
//#endif // DEBUG
//}
// Pretreat类 分离通道操作。
//void Pretreat::splitChannels() {
//#ifdef DEBUG_TEST
//	//一开始想用canny边缘检测，因为可以顺便二值化操作，但发现有较大误差
//	Mat canny;
//	int structElementSize = 1;
//	Mat element = getStructuringElement(MORPH_RECT, Size(structElementSize + 1, structElementSize + 1), Point(structElementSize, structElementSize));
//	Canny(srcImage, canny, 80, 160, 3, false);
//	dilate(canny, canny, element);
//	imshow("Canny", canny);
//#endif 
//	// 1.分离颜色通道
//	vector<Mat> imgChannels;
//	split(srcImage, imgChannels);
//#ifdef RED
//	//通过红蓝通道相减来得到一个明显的轮廓。at(0/1/2)代表BGR
//	//Mat可以相减。
//	midImage = imgChannels.at(2) - imgChannels.at(0);
//#endif 
//#ifdef BLUE 
//	midImage = imgChannels.at(0) - imgChannels.at(2);
//#endif // BLUE
//}
// Pretreat类 阈值化操作。
//void Pretreat::prethreshold() {
//	//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//	//blur(midImage, midImage, Size(9, 9), Point(-1, -1));//滤波会导致二值化直接被膨胀，不理解原理，所以直接除去
//	//与周珺讨论认为是之前的闭运算和二值化已经消除大部分噪音，此时再用均值滤波就是适得其反。
//	
//	// 2.二值化，背景黑，图案白
//	threshold(midImage, midImage, value, valueMax, THRESH_BINARY | CV_THRESH_OTSU);
//#ifdef DEBUG
//	//读取二值化视频
//	namedWindow("midImage", WINDOW_AUTOSIZE);
//	//cvResizeWindow("midImage2", 500, 500);
//	imshow("midImage", midImage);
//#endif // DEBUG
//}
//void prethreshold(int,void*) {
//	threshold(midImage, midImage, value, valueMax, THRESH_BINARY|CV_THRESH_OTSU);
//}

#ifdef JIANGDA
double getDistance(Point source, Point end) {
	double dis;
	dis = pow((source.x - end.x), 2) + pow((source.y - end.y), 2);
	return sqrt(dis);
}
#endif // JIANGDA


 //spot 类函数 轮廓查找
void Spot::findcontoursfun(Mat& drawcircle) {
	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;
	//Point2f center;
	Mat canny;
	RotatedRect box;
	Canny(midImage, canny, 100, 100 * 2, 3);// canny边缘检测。顺便二值化加去噪
	//vector<RotatedRect> minRects;
	//vector<RotatedRect> minRects(contours.size());
	findContours(canny, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE);//CHAIN_APPROX_SIMPLE只保留拐点信息
#ifdef MY_METHOD_TWO
	Mat drawing = Mat::zeros(canny.size(), CV_8UC3);
	Point2f rescenterPoint;
	//通过遍历hierarachy轮廓个数来判断哪个是未击打的
	int contour[20] = { 0 };
#ifdef MY_METHOD_TRY
	for (int i = 0; i < contours.size(); i++) {
		if (hierarchy[i][3] != -1) // 是否有内嵌轮廓判断，如果有内嵌轮廓。
			contour[hierarchy[i][3]]++;//对父轮廓进行计数。
		//遍历到一个子轮廓就让夫轮廓对应数组元素加一，
		//通过看父轮廓数组个数就能得知到底有几个子轮廓了。
	}
#endif // MY_METHOD_TRY
	for (int j = 0; j < contours.size(); j++) {
		double area_of_contour = contourArea(contours[j],true);
		//很奇怪，把contourArea的第二参数写成true封闭时已经可以得到最小框
		if ((area_of_contour >= 1200) && (area_of_contour <= 2000)) {//只有一个子轮廓的情况
			box = minAreaRect(contours[hierarchy[j][2]]);//把轮廓的所有点存入旋转矩形中。
			//这里minAreaRect寻找的是最小矩形轮廓的边缘。所以是minAreaRect(contours[hierarchy[j][2]])
			//hierarchy[j][2] ,2代表的是子轮廓，也就是最外轮廓的内嵌轮廓。
			Point2f points[4];//四点坐标存入
			box.points(points);
			Point2f cc = Point2f(0, 0);
			Point center = box.center;//得到旋转矩形的中心点。
#ifdef DEBUG
			cout << "center" << center << endl;
#endif // DEBUG
			circle(srcImage, center, 1, Scalar(0, 255, 0), 2);//打印出中心点。
#ifdef SHOW_CIRCLE
			circle(drawcircle, center, 1, Scalar(0, 0, 255), 10);
			if (cirV.size() < 30) {
				cirV.push_back(center);
			}
			else {
				float R;//拟合圆心获取
				CircleInfo2(cirV, cc, R);
				circle(drawcircle, cc, 1, Scalar(255, 0, 0), 2);
#if (defined DEBUG_LOG) && (defined SHOW_CIRCLE)
				cout << endl << "center " << cc.x << " , " << cc.y << endl;
#endif
				//cirV.erase(cirV.begin());//全部清除，节省资源
				if ((cc.x != 0) && (cc.y != 0)) {
					Mat rot = getRotationMatrix2D(cc, 30, 1);
#if (defined DEBUG_LOG)&& (defined SHOW_CIRCLE)
					cout << endl << "center " << cc.x << " , " << cc.y << endl;
#endif
					/*Point2f center：表示旋转的中心点
					  double angle：表示旋转的角度
					  double scale：图像缩放因子*/
					float sinA = rot.at<double>(0, 1);//sin(30);
					float cosA = rot.at<double>(0, 0);//cos(30);
					float xx = -(cc.x - center.x);
					float yy = -(cc.y - center.y);
					rescenterPoint = Point2f(cc.x + cosA * xx - sinA * yy, cc.y + sinA * xx + cosA * yy);//可以作为偏移量。
					circle(srcImage, rescenterPoint, 1, Scalar(0, 255, 0), 5);
					//float radius = sqrt(pow((cc.x - rescenterPoint.x), 2) + pow((cc.y - rescenterPoint.y), 2));
					//circle(drawcircle, cc, radius, Scalar(0, 255, 0), 3);
				}
			}
#endif // SHOW_CIRCLE
			for (int i = 0; i < 4; i++) {
				//points[i] += rescenterPoint;
				cout << "第" << i << "个坐标点" << points[i] << endl;
				line(srcImage, points[i], points[(i + 1) % 4], Scalar(127, 127, 0), 2, CV_AA);
			}
			Scalar color(rand() & 255, rand() & 255, rand() & 255);
			putText(srcImage, "target", points[0], FONT_HERSHEY_SIMPLEX, 0.8, color,1.5);//打印字体
			//参一：处理图像，二，内容，三，文本字符串的左下标位置，四，字体格式（风格）,五，大小，七，厚度
#if(defined SHOW_CIRCLE)&&(defined SHOW_RESULT)
//namedWindow("circle", WINDOW_AUTOSIZE);
			imshow("circle", drawcircle);
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
#ifdef BLUE
	VideoCapture capture("小能量机关.avi");
#endif // BULE
#ifdef RED
	VideoCapture capture("大能量机关.avi");
#endif // RED
	while (1) {
		drawcircle = Mat(srcImage.rows, srcImage.cols, CV_8UC3, Scalar(0, 0, 0));
		capture >> srcImage; // 死循环读取帧
		//Image.splitChannels();
		createTrackbar("阈值调节", "大能量机关", &value, valueMax ,pretreat);
		pretreat(0, 0);
		//Image.prethreshold();
		//Image.predilate();
		spot.findcontoursfun(drawcircle);
#ifdef SHOW_RESULT
		namedWindow("大能量机关", WINDOW_AUTOSIZE);
		imshow("大能量机关", srcImage);
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




//#ifdef MY_METHOD
//Mat drawing = Mat::zeros(canny.size(), CV_8UC3);
//for (int i = 0; i < contours.size(); i++)
//{
//	Scalar color = Scalar(0, 0, 255);
//	drawContours(drawing, contours, i, color, 1, 8, hierarchy, 0, Point());
//	//参数一，要绘制的地方，二，将找到的轮廓传入，
//	//三，轮廓是一个一个封闭保存的，所以存在多个轮廓，通过变量来把他们一个一个输入，
//	//这里也可以通过-1直接得到所有轮廓的绘制，无需建立一个循环遍历。
//	//四，颜色，可以通过Scalar直接设置，也可以用Scalar类型的color变量传参输入。
//	//五，绘制框的粗细，六，可选类型。
//	std::sort(contours.begin(), contours.end(), ContoursSortFun);
//#ifdef DEBUG
//	imshow(" ", drawing);
//#endif // DEBUG	
//	cv::RotatedRect min_center_rect;
//	vector<Point> points;
//	if (contourArea(contours[i]) == 0)
//		continue;//丢弃不需要的面积
//	double area_of_contour = contourArea(contours[i]);
//#ifdef DEBUG_LOG
//	cout << area_of_contour << endl;
//#endif // DEBUG_LOG
//	// 比较面积
//	if ((area_of_contour >= 1200) && (area_of_contour <= 2000))
//	{
//		min_center_rect = cv::minAreaRect(contours[i]);
//		double center_rect_h_w_div = min_center_rect.size.height / min_center_rect.size.width;
//		center_rect_h_w_div = center_rect_h_w_div > 1 ? center_rect_h_w_div : 1 / center_rect_h_w_div;
//		//划线找出流水灯
//		points = contours[i];
//		//拟合出最小外接矩形
//		RotatedRect rrect = fitEllipse(points);
//		cv::Point2f* vertices = new cv::Point2f[4];
//		///矩阵的四个顶点赋值给vertices
//		rrect.points(vertices);
//		// 找长宽比
//		float aim = center_rect_h_w_div;
//		//cout << aim << endl;
//		if (aim > 1.95 && aim < 2.5) {
//			cout << "第" << i << "个面积为" << contourArea(contours[i]) << endl;
//			cout << "第" << i << "个长宽比" << center_rect_h_w_div << endl;
//			for (int j = 0; j < 4; j++)
//			{
//				cout << "第" << j << "个坐标点" << vertices[i] << endl;
//				cv::line(srcImage, vertices[j], vertices[(j + 1) % 4], cv::Scalar(0, 255, 0), 1, CV_AA);//CV_AA高斯滤波保证稳定.
//				//vertices[(j + 1) % 4]通过循环数组的方式来保证数组不会越界。
//			}
//			//imshow("划线", srcImage);
//		}
//		}
//	}
//#endif // MY_METHOD
//#ifdef JIANGDA
////模板匹配
//double TemplateMatch(cv::Mat image, cv::Mat tepl, cv::Point& point, int method)
//{
//	int result_cols = image.cols - tepl.cols + 1;
//	int result_rows = image.rows - tepl.rows + 1;
//	//    cout <<result_cols<<" "<<result_rows<<endl;
//	cv::Mat result = cv::Mat(result_cols, result_rows, CV_32FC1);
//	cv::matchTemplate(image, tepl, result, method);
//
//	double minVal, maxVal;
//	cv::Point minLoc, maxLoc;
//	cv::minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc, Mat());
//
//	switch (method)
//	{
//	case CV_TM_SQDIFF:
//	case CV_TM_SQDIFF_NORMED:
//		point = minLoc;
//		return minVal;
//
//	default:
//		point = maxLoc;
//		return maxVal;
//
//	}
//}
//#endif // JIANGDA
//#ifdef JIANGDA
////旋转矩形
//RotatedRect rect;
//Point2f src[4], dst[4];
//double width, height;
//bool findTarget = 0;
//vector<vector<Point>> contours_ploy(contours.size());
//vector<Rect> ploy_rects(contours.size());
////因为是旋转的，动态，所以不能直接用书上的例子，要构建一个旋转类，之后用向量容器把旋转对象输出
//if (hierarchy.size())
//for (int i = 0; i >= 0; i = hierarchy[i][0]) {
//	approxPolyDP(Mat(contours[i]), contours_ploy[i], 3, true);
//	ploy_rects[i] = boundingRect(contours_ploy[i]);
//	rect = minAreaRect(contours[i]); // 把拐点信息传入
//	Point2f P[4]; // 创建四个点对象
//	rect.points(P);//点传入
//
//
//#ifdef MY_METHOD_TRY
//	if (contours_ploy.size()) {
//		//最小矩形
//		minRects[i] = minAreaRect(contours[i]);
//		minRects[i].points(src);
//		for (int r = 0; r < 4; r++) {
//			line(srcImage, src[r], src[(r + 1) % 4], Scalar(0, 0, 255), 1, 8);
//		}
//	}
//#endif		
//	double width;
//	double height;
//
//	//矫正提取的叶片的宽高
//	width = getDistance(P[0], P[1]);
//	height = getDistance(P[1], P[2]);
//	if (width > height)
//	{
//		src[0] = P[0];
//		src[1] = P[1];
//		src[2] = P[2];
//		src[3] = P[3];
//	}
//	else {
//		swap(width, height);
//		src[0] = P[1];
//		src[1] = P[2];
//		src[2] = P[3];
//		src[3] = P[0];
//	}
//#ifdef SHOW_ALLRECT
//	Scalar color(rand() & 255, rand() & 255, rand() & 255);
//	drawContours(srcImage, contours, i, color, 4, 8, hierarchy);
//#endif // show_allrect
//	//合适面积寻找
//	double area = height * width;
//	if (area > 5000) {
//#ifdef DEBUG_LOG
//		cout << hierarchy[i] << endl;
//#endif // DEBUG_LOG
//		dst[0] = Point2f(0, 0);
//		dst[1] = Point2f(width, 0);
//		dst[2] = Point2f(width, height);
//		dst[3] = Point2f(0, height);
//		// 应用透视变换，矫正成规则矩形
//		Mat transform = getPerspectiveTransform(src, dst);
//		Mat perspectMat;
//		warpPerspective(midImage, perspectMat, transform, midImage.size());
//#ifdef DEBUG
//		//以规则矩形的方式放在窗口的左上角，之后进行SVM训练
//		imshow("warpdst", perspectMat);
//#endif
//		// 提取扇叶图片
//		/*Mat testim;
//		testim = perspectMat(Rect(0, 0, width, height));*/
//#ifdef LEAF_IMG
//		//用于保存扇叶图片，以便接下来训练svm
//		string s = "leaf" + to_string(cnnt) + ".jpg";
//		cnnt++;
//		imwrite("./img/" + s, testim);
//#endif
//#ifdef DEBUG
//		imshow("testim", testim);
//#endif
//#ifdef DEBUG
//		namedWindow(" ", WINDOW_AUTOSIZE);
//		imshow(" ", srcImage);
//#endif // DEBUG
//#if (defined DEBUG)&&(defined USE_TEMPLATE)
//		imshow("temp1", tmp1);
//#endif
//
//#ifdef USE_TEMPLATE
//		cv::Point matchLoc;
//		Mat tmp1; //比对图像。
//		double value;
//		Mat templ[9];// 模板
//		for (int i = 1; i <= 8; i++)
//		{
//			templ[i] = imread("../OpenCV/OpenCV/template" + to_string(i) + ".jpg", IMREAD_GRAYSCALE);
//			//resize(templ[i], tmp1, Size(42, 20));
//			//imshow(" ", templ[i]);
//		}
//		vector<double> NoHit;
//		vector<double> YesHit;
//		//锤子（未击打）
//		for (int j = 1; j <= 6; j++)
//		{
//			value = TemplateMatch(tmp1, templ[j], matchLoc, CV_TM_CCOEFF_NORMED);
//			NoHit.push_back(value);
//		}
//		//宝剑（已击打）
//		for (int j = 7; j <= 8; j++)
//		{
//			value = TemplateMatch(tmp1, templ[j], matchLoc, CV_TM_CCOEFF_NORMED);
//			YesHit.push_back(value);
//		}
//		int maxv1 = 0, maxv2 = 0;
//		//寻找匹配最大的编号
//		for (int t1 = 0; t1 < 6; t1++)
//			if (NoHit[t1] > NoHit[maxv1])
//				maxv1 = t1;
//		for (int t2 = 0; t2 < 2; t2++)
//			if (YesHit[t2] > YesHit[maxv2])
//				maxv2 = t2;
//#endif
//#if (defined DEBUG_LOG)&&(defined USE_TEMPLATE)
//		cout << Vvalue1[maxv1] << endl;
//		cout << Vvalue2[maxv2] << endl;
//#endif
//#ifdef USE_SVM
//		//转化为svm所要求的格式
//		Mat test = get(testim);
//#endif
//		//预测是否是要打击的扇叶
//#ifdef USE_TEMPLATE
//		if (NoHit[maxv1] > YesHit[maxv2] && NoHit[maxv1] > 0.6)
//#endif
//#ifdef USE_SVM
//			if (svm->predict(test) >= 0.9)
//#endif
//			{
//				findTarget = true;
//				//查找装甲板
//				if (hierarchy[i][2] >= 0)
//				{
//					RotatedRect rect_tmp = minAreaRect(contours[hierarchy[i][2]]);
//					Point2f Pnt[4];
//					rect_tmp.points(Pnt);
//					//参数怎么设置的？？？？？？
//					const float maxHWRatio = 0.7153846;
//					const float maxArea = 2000;
//					const float minArea = 500;
//
//					float width = rect_tmp.size.width;
//					float height = rect_tmp.size.height;
//					if (height > width)
//						swap(height, width);
//					float area = width * height;
//
//					if (height / width > maxHWRatio || area > maxArea || area < minArea) {
//						continue;
//					}
//					Point centerP = rect_tmp.center;
//					//打击点
//					circle(srcImage, centerP, 1, Scalar(0, 0, 255), 1);
//					//画出装甲位置
//					for (int j = 0; j < 4; ++j)
//					{
//						line(srcImage, Pnt[j], Pnt[(j + 1) % 4], Scalar(0, 255, 255), 2);
//					}
//				}
//			}
//	}
//}
//#endif // JIANGDA