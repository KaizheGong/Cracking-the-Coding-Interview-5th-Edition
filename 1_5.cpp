/*
 * =====================================================================================
 *
 *       Filename:  Problem5.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  06/12/2014 21:18:35
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kaizhe Gong
 *   Organization:  
 *
 * =====================================================================================
 */

#include<iostream>
#include<string>

using namespace std;

string compression(const string& input)
{
    string result = "";

    string::const_iterator it = input.begin();

    while (it != input.end())
    {
	char curr = *it;
	int count = 1;
	++it;
	while(*it == curr)
	{
	    ++it;
	    ++count;
	}
	result += (curr + to_string(count));
    }

    return result;
}

int main ()
{
    string input  = "aabcccccaa";
    cout << compression(input) << endl;
}
