/*
 * =====================================================================================
 *
 *       Filename:  Problem4.cpp
 *
 *    Description:  1_4
 *
 *        Version:  1.0
 *        Created:  05/12/2014 20:04:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kaizhe Gong
 *   Organization:
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

void replaceSpaces (char input[], int length)
{

    for (int i=0; i!=length; ++i)
    {
	if (input[i] == ' ') {
	    input[i] = '%';

	    int j = length + 2;
	    while (j>i+2)
	    {
		input[j] = input[j-2];
		--j;
	    }
	    input[i+1] = '2';
	    input[i+2] = '0';
	    length+=2;
	} 
    }
}

int main()
{
    char testString[100] = " kai zhe   gong ";
    replaceSpaces(testString, 17);
    cout << testString << endl;
}
