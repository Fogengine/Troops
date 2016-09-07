#pragma once

struct alignas(16) TMatrix
{
public:
	TMatrix();
	
	TMatrix operator + (TMatrix&);
	TMatrix operator - (TMatrix&);
	TMatrix operator * (TMatrix&);
	TMatrix operator * (float);
	float* const operator[](const int);
	TMatrix Inverse();

	void SetElement(const int, const int, const float);

	static TMatrix IndentityMatrix();
private:

	float mData[4][4];
};