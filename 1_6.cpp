/*
 * =====================================================================================
 *
 *       Filename:  Problem6.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/12/2014 14:17:19
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kaizhe Gong
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#define N 3

using namespace std;

int** rotate(int input[N][N])
{
    int** result = new int*[N];

    for (int i=0; i<N; ++i)
    {
	result[i] = new int[N];	
	for (int j=0; j<N; ++j)
	{
	    result[i][j] = input[N-1-j][i];
	}
    }

    return result;
}

void rotateInPlace(int matrix[N][N])
{
    for (int layer = 0; layer < N/2; ++layer)
    {
	int first = layer;
	int last = N - 1 - layer;
	for (int i = first; i < last; ++i)
	{
	    int offset = i - first;
	    // save top
	    int top = matrix[first][i];

	    // left -> top
	    matrix[first][i] = matrix[last-offset][first];

	    // bottom -> left
	    matrix[last - offset][first] = matrix[last][last - offset];

	    // right -> bottom
	    matrix[last][last - offset] = matrix[i][last];

	    // top -> right
	    matrix[i][last] = top;
	}
    }
}

void print(int input[N][N])
{
    for (int i=0; i<N; ++i)
    {
	for (int j=0; j<N; ++j)
	{
	    cout << input[i][j] << " ";
	}
	cout << endl;
    }
}

void print(int** input)
{
    for (int i=0; i<N; ++i)
    {
	for (int j=0; j<N; ++j)
	{
	    cout << input[i][j] << " ";
	}
	cout << endl;
    }
}

int main()
{
    int test[N][N] = {{1,2,3},{4,5,6},{7,8,9}};
    cout << "Before rotate:" << endl;
    print(test);
    //int** result = rotate(test);
    rotateInPlace(test);
    cout << "After rotate:" << endl;
    //print(result);
    print(test);
}
