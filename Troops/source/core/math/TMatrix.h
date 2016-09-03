#pragma once

struct alignas(16) TMatrix
{
public:
	TMatrix();

	float x1, y1, z1, w1;
	float x2, y2, z2, w2;
	float x3, y3, z3, w3;
	float x4, y4, z4, w4;
};