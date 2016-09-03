#pragma once

struct TVector3
{
public:
	TVector3();
	TVector3(float, float, float);

	void operator = (TVector3&);
	TVector3 operator + (TVector3&);
	TVector3 operator - (TVector3&);
	TVector3 operator * (TVector3&);
	TVector3 operator * (float);
	TVector3 operator / (TVector3&);
	TVector3 operator / (float);
	void operator += (TVector3&);
	void operator -= (TVector3&);


	float x, y, z;
};