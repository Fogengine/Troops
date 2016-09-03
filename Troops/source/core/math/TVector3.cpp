#include "TVector3.h"

TVector3::TVector3()
{
	x = 0;
	y = 0;
	z = 0;
}

TVector3::TVector3(float InX, float InY, float InZ)
{
	x = InX;
	y = InY;
	z = InZ;
}

void TVector3::operator = (TVector3& InV)
{
	x = InV.x;
	y = InV.y;
	z = InV.z;
}

TVector3 TVector3::operator + (TVector3& InV)
{
	return TVector3(x + InV.x, y + InV.y, z + InV.z);
}

TVector3 TVector3::operator - (TVector3& InV)
{
	return TVector3(x - InV.x, y - InV.y, z - InV.z);
}

TVector3 TVector3::operator * (TVector3& InV)
{
	return TVector3(x * InV.x, y * InV.y, z * InV.z);
}

TVector3 TVector3::operator * (float In)
{
	return TVector3(x * In, y * In, z * In);
}

TVector3 TVector3::operator / (TVector3& InV)
{
	return TVector3(x / InV.x, y / InV.y, z / InV.z);
}

TVector3 TVector3::operator / (float In)
{
	return TVector3(x / In, y / In, z / In);
}

void TVector3::operator += (TVector3& InV)
{
	x += InV.x;
	y += InV.y;
	z += InV.z;
}

void TVector3::operator -= (TVector3& InV)
{
	x -= InV.x;
	y -= InV.y;
	z -= InV.z;
}