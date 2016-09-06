#pragma once

struct TMatrix
{
public:
	TMatrix();
	
	TMatrix operator + (TMatrix&);
	TMatrix operator - (TMatrix&);
	TMatrix operator * (TMatrix&);

	static TMatrix IndentityMatrix();
private:

	float mData[4][4];
};