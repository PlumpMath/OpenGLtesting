#include "QuadVert.h"


QuadVert::QuadVert()
{
}


QuadVert::~QuadVert()
{
}

void QuadVert::set(float x0, float y0, float x1, float y1, float x2, float y2, float x3, float y3)
{
	x[0] = x0;
	y[0] = y0;
	x[1] = x1;
	y[1] = y1;
	x[2] = x2;
	y[2] = y2;
	x[3] = x3;
	y[3] = y3;
}

float *QuadVert::verts()
{
	float positions[8] = {
		x[0], y[0],
		x[1], y[1],
		x[2], y[2],
		x[3], y[3],
	};
	return positions;
}

