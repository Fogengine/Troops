#pragma once

struct TVector2
{
public:
	TVector2();
	TVector2(float, float);

	void operator = (TVector2&);
	TVector2 operator + (TVector2&);
	TVector2 operator - (TVector2&);
	TVector2 operator * (TVector2&);
	TVector2 operator * (float);
	TVector2 operator / (TVector2&);
	TVector2 operator / (float);
	void operator += (TVector2&);
	void operator -= (TVector2&);

	float x, y;
};