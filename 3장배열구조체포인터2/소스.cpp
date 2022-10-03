#include <iostream>
#include <math.h>
using namespace std;

typedef struct point
{
	int x,y;

}point;

double get_distance(point p1, point p2);

int main()
{
	point p1 = { 1,2 };
	point p2 = { 5,4 };
	cout << fixed;
	cout.precision(2);
	cout << get_distance(p1, p2);

}
double get_distance(point p1, point p2)
{
	double distance;
	distance = sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));

	return distance;
}