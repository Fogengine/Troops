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