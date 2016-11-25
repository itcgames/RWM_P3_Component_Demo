#pragma once
#include<stdlib.h>


//Define some basic types needed for 2D graphics


class Point2D {
public:
	float x, y;
	Point2D(float _x = 0, float _y = 0) :x(_x), y(_y) { };
	float length() { return (float)sqrt(x*x + y*y); };

};

typedef  Point2D Vector2D;


class Size2D {
public:
	float w, h;
	Size2D(float _w = 0, float  _h = 0) :w(_w), h(_h) {};
};

class Colour {
public:
	int r, g, b, a;
	Colour(int _r = 255, int  _g = 255, int _b = 255, int  _a = 255) :r(_r), g(_g), b(_b), a(_a) {};
};

class Rect {
public:
	Point2D pos;
	Size2D size;
	Rect(Point2D p, Size2D s) :pos(p), size(s) {};
	Rect(float x = 0, float y = 0, float w = 1, float h = 1) :pos(x, y), size(w, h) {};

};

inline float randBetween(float s, float e) {
	float range = e - s;

	double numBetween0_1 = (double)rand() / RAND_MAX;

	double pointInRange = range*numBetween0_1;

	return s + (float)pointInRange;

}

inline int randBetween(int s, int e) {
	return (int)randBetween((float)s, (float)e);
}