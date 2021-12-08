//#define _CRT_SECURE_NO_WARNINGS 1
//#include<iostream>
//
//using namespace std;
//
//class Point
//{
//private:
//    double x, y;
//public:
//    Point(double x_ = 0, double y_ = 0) :x(x_), y(y_) {}
//    Point(const Point& rhs);
//    ~Point();
//    Point& operator = (const Point& rhs);
//    friend ostream& operator <<(ostream& os, const Point& rhs);
//    friend class Line;
//};
//
//Point::Point(const Point& rhs)
//{
//    if (this != &rhs)
//    {
//        x = rhs.x;
//        y = rhs.y;
//    }
//}
//
//Point::~Point()
//{
//    cout << "~ ~ ~Point X , Y " << x << " , " << y << endl;
//}
//
//Point& Point::operator = (const Point& rhs)
//{
//    x = rhs.x;
//    y = rhs.y;
//    return (*this);
//}
//
//ostream& operator <<(ostream& os, const Point& rhs)
//{
//    os << "(" << rhs.x << " , " << rhs.y << ")" << endl;
//    return (os);
//}
//
//class Line
//{
//private:
//    Point point0, point1;
//public:
//    Line(double x0 = 0, double y0 = 0, double x1 = 0, double y1 = 0) :point0(x0, y0), point1(x1, y1) { }
//    Line(const Line& rhs);
//    ~Line();
//    Point Jiaodian(const Line zhi1);
//};
//
//Line::Line(const Line& rhs)
//{
//    if (this != &rhs)
//    {
//        point0 = rhs.point0;
//        point1 = rhs.point1;
//    }
//}
//
//Line::~Line()
//{
//    cout << "~ ~ ~Line Point0 , Point1" << endl;
//}
//
//Point Line::Jiaodian(const Line zhi1)
//{
//    double a0, a1, b0, b1, c0, c1;
//    double xx, yy;
//    a0 = point1.x - point0.x;
//    b0 = point1.y - point0.y;
//    c0 = point0.y * point1.x - point1.y * point0.x;
//    a1 = zhi1.point1.x - zhi1.point0.x;
//    b1 = zhi1.point1.y - zhi1.point0.y;
//    c1 = zhi1.point0.y * zhi1.point1.x - zhi1.point1.y * zhi1.point0.x;
//    xx = (c1 * a0 - c0 * a1) / (b0 * a1 - a0 * b1);
//    yy = (c0 * b1 - c1 * b0) / (a0 * b1 - a1 * b0);
//    return   Point(xx, yy);
//}
//
//int main()
//{
//    int a, b, c, d;
//    cin >> a >> b >> c >> d;
//    Line L1(a, b, c, d);
//    cin >> a >> b >> c >> d;
//    Line L2(a, b, c, d);
//    Point aa = L1.Jiaodian(L2);
//    cout << "½»µãÎª £º" << aa;
//    return 0;
//}