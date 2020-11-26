#include <cmath>
struct Point {
	double x;
	double y;
	Point(int x,int y):x(x),y(y){}
};
class Figure {
	virtual bool point_inside(const Point& point) = 0;
};
class Circle : public Figure {
	Point center;
	double radius;
public:
	Circle(double x, double y,size_t radius): center(x,y), radius(radius){}
	bool point_inside(const Point& point) {
		double dx = point.x - center.x;
		double dy = point.y - center.y;
		if (dx*dx+dy*dy<=radius*radius)
			return true;
		else
			return false;
	}
};
class Rectangle : public Figure {
	Point first;
	Point second;
public:
	bool point_inside(const Point& point) {
		if (point.x >= first.x && point.x <= second.x && point.y >= first.y && point.x <= second.x)
			return true;
		else
			false;
	}
};