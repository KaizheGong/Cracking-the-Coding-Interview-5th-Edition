/*
 * =====================================================================================
 *
 *       Filename:  Problem7.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/12/2014 14:34:02
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kaizhe Gong 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <map>

#define M 4
#define N 5

using namespace std;

void print(int input[M][N])
{
    for (int i=0; i<M; ++i)
    {
	for (int j=0; j<N; ++j)
	{
	    cout << input[i][j] << " ";
	}
	cout << endl;
    }
}

void setZero(int input[M][N])
{
    map<int,bool> rol;
    map<int,bool> col;
    
    for(int i=0; i<M; ++i)
    {
	for(int j=0; j<N; ++j)
	{
	    if (col.find(j) == col.end() && rol.find(i) == rol.end())
	    {
		if (input[i][j] == 0)
		{
		    // set the whole row equals to 0
		    for (int colIt =0; colIt < N; ++colIt)
		    {
			input[i][colIt] = 0;
		    }
		    // set the whole col equals to 0
		    for (int rowIt =0; rowIt < M; ++rowIt)
		    {
			input[rowIt][j] = 0;
		    }
		    // update map
		    rol[i] = true;
		    col[j] = true;
		}	
	    }
	}
    }
}

int main()
{
    int test[M][N] = {{1,0,3,4,5},{6,7,8,9,0},{3,2,1,2,6},{7,3,7,7,8}};
    cout << "before set: " << endl;
    print(test);
    cout << "after set: " << endl;
    setZero(test);
    print(test);
}
