#include "TMatrix.h"
#include <string.h>

TMatrix::TMatrix()
{
	memset(mData, 0, sizeof(int) * 16);
}

TMatrix TMatrix::operator+(TMatrix& InM)
{
	TMatrix matrix;
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			matrix.mData[i][j] = mData[i][j] + InM.mData[i][j];
		}
	}
	return matrix;
}

TMatrix TMatrix::operator-(TMatrix& InM)
{
	TMatrix matrix;
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			matrix.mData[i][j] = mData[i][j] - InM.mData[i][j];
		}
	}
	return matrix;
}

TMatrix TMatrix::operator*(TMatrix& InM)
{
	TMatrix matrix;
	for (int i = 0;i < 4;i++)
	{
		for (int k = 0;k < 4;k++)
		{
			for (int j = 0;j < 4;j++)
			{
				matrix.mData[i][k] += mData[i][j] * InM.mData[j][k];
			}
		}
	}
	return matrix;
}

TMatrix TMatrix::operator*(float In)
{
	TMatrix matrix;
	for (int i = 0;i < 4;i++)
	{	
		for (int j = 0;j < 4;j++)
		{
			matrix.mData[i][j] = mData[i][j] * In;
		}
	}
	return matrix;
}

float* const TMatrix::operator[](const int In)
{
	return mData[In];
}

TMatrix TMatrix::Inverse()
{
	TMatrix matrix;
	const double s0 = (double)(mData[0][0]); const double s1 = (double)(mData[0][1]); const double s2 = (double)(mData[0][2]); const double s3 = (double)(mData[0][3]);
	const double s4 = (double)(mData[1][0]); const double s5 = (double)(mData[1][1]); const double s6 = (double)(mData[1][2]); const double s7 = (double)(mData[1][3]);
	const double s8 = (double)(mData[2][0]); const double s9 = (double)(mData[2][1]); const double s10 = (double)(mData[2][2]); const double s11 = (double)(mData[2][3]);
	const double s12 = (double)(mData[3][0]); const double s13 = (double)(mData[3][1]); const double s14 = (double)(mData[3][2]); const double s15 = (double)(mData[3][3]);

	double inv[16];
	matrix.mData[0][0] = s5 * s10 * s15 - s5 * s11 * s14 - s9 * s6 * s15 + s9 * s7 * s14 + s13 * s6 * s11 - s13 * s7 * s10;
	matrix.mData[0][1] = -s1 * s10 * s15 + s1 * s11 * s14 + s9 * s2 * s15 - s9 * s3 * s14 - s13 * s2 * s11 + s13 * s3 * s10;
	matrix.mData[0][2] = s1 * s6  * s15 - s1 * s7  * s14 - s5 * s2 * s15 + s5 * s3 * s14 + s13 * s2 * s7 - s13 * s3 * s6;
	matrix.mData[0][3] = -s1 * s6  * s11 + s1 * s7  * s10 + s5 * s2 * s11 - s5 * s3 * s10 - s9  * s2 * s7 + s9  * s3 * s6;
	matrix.mData[1][0] = -s4 * s10 * s15 + s4 * s11 * s14 + s8 * s6 * s15 - s8 * s7 * s14 - s12 * s6 * s11 + s12 * s7 * s10;
	matrix.mData[1][1] = s0 * s10 * s15 - s0 * s11 * s14 - s8 * s2 * s15 + s8 * s3 * s14 + s12 * s2 * s11 - s12 * s3 * s10;
	matrix.mData[1][2] = -s0 * s6  * s15 + s0 * s7  * s14 + s4 * s2 * s15 - s4 * s3 * s14 - s12 * s2 * s7 + s12 * s3 * s6;
	matrix.mData[1][3] = s0 * s6  * s11 - s0 * s7  * s10 - s4 * s2 * s11 + s4 * s3 * s10 + s8  * s2 * s7 - s8  * s3 * s6;
	matrix.mData[2][0] = s4 * s9  * s15 - s4 * s11 * s13 - s8 * s5 * s15 + s8 * s7 * s13 + s12 * s5 * s11 - s12 * s7 * s9;
	matrix.mData[2][1] = -s0 * s9  * s15 + s0 * s11 * s13 + s8 * s1 * s15 - s8 * s3 * s13 - s12 * s1 * s11 + s12 * s3 * s9;
	matrix.mData[2][2] = s0 * s5  * s15 - s0 * s7  * s13 - s4 * s1 * s15 + s4 * s3 * s13 + s12 * s1 * s7 - s12 * s3 * s5;
	matrix.mData[2][3] = -s0 * s5  * s11 + s0 * s7  * s9 + s4 * s1 * s11 - s4 * s3 * s9 - s8  * s1 * s7 + s8  * s3 * s5;
	matrix.mData[3][0] = -s4 * s9  * s14 + s4 * s10 * s13 + s8 * s5 * s14 - s8 * s6 * s13 - s12 * s5 * s10 + s12 * s6 * s9;
	matrix.mData[3][1] = s0 * s9  * s14 - s0 * s10 * s13 - s8 * s1 * s14 + s8 * s2 * s13 + s12 * s1 * s10 - s12 * s2 * s9;
	matrix.mData[3][2] = -s0 * s5  * s14 + s0 * s6  * s13 + s4 * s1 * s14 - s4 * s2 * s13 - s12 * s1 * s6 + s12 * s2 * s5;
	matrix.mData[3][2] = s0 * s5  * s10 - s0 * s6  * s9 - s4 * s1 * s10 + s4 * s2 * s9 + s8  * s1 * s6 - s8  * s2 * s5;

	float det = s0 * matrix.mData[0][0] + s1 * matrix.mData[1][0] + s2 * matrix.mData[2][0] + s3 * matrix.mData[3][0];
	if (det != 0.0)
	{
		det = 1.0 / det;
	}

	return matrix*det;
}

void TMatrix::SetElement(const int row, const int column, const float data)
{
	if (row >= 0 && row <= 3 && column >= 0 && column <= 3)
	{
		mData[row][column] = data;
	}
}

TMatrix TMatrix::IndentityMatrix()
{
	TMatrix matrix;

	matrix.mData[0][0] = 1;
	matrix.mData[1][1] = 1;
	matrix.mData[2][2] = 1;
	matrix.mData[3][3] = 1;

	return matrix;
}