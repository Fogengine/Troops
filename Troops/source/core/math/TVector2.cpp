#include "TVector2.h"

TVector2::TVector2()
{
	x = 0;
	y = 0;
}

TVector2::TVector2(float InX, float InY)
{
	x = InX;
	y = InY;
}

void TVector2::operator = (TVector2& InV)
{
	x = InV.x;
	y = InV.y;
}

TVector2 TVector2::operator + (TVector2& InV)
{
	return TVector2(x + InV.x, y + InV.y);
}

TVector2 TVector2::operator - (TVector2& InV)
{
	return TVector2(x - InV.x, y - InV.y);
}

TVector2 TVector2::operator * (TVector2& InV)
{
	return TVector2(x * InV.x, y * InV.y);
}

TVector2 TVector2::operator * (float In)
{
	return TVector2(x * In, y * In);
}

TVector2 TVector2::operator / (TVector2& InV)
{
	return TVector2(x / InV.x, y / InV.y);
}

TVector2 TVector2::operator / (float In)
{
	return TVector2(x / In, y / In);
}

void TVector2::operator += (TVector2& InV)
{
	x += InV.x;
	y += InV.y;
}

void TVector2::operator -= (TVector2& InV)
{
	x -= InV.x;
	y -= InV.y;
}