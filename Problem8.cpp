/*
 * =====================================================================================
 *
 *       Filename:  Problem8.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  16/12/2014 11:40:24
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Kaizhe Gong
 *   Organization:  
 *
 * =====================================================================================
 */

#include <iostream>
#include <string>

using namespace std;

bool isSubstring(const string& part, const string& whole)
{
    if (part.length() > whole.length())
    {
	return false;
    } else {
	for (int i=0; i<=whole.length()-part.length(); ++i)
	{
	    if (whole[i] == part[0] && 
		whole.substr(i,part.length()) == part)
	    {
		return true;
	    }
	}
	return false;
    }
}

bool isRotation(const string& s1, const string& s2)
{
    if (s1.length() != s2.length())
    {
	return false;
    } else {
	int i = 0;
	for (; i<s2.length(); ++i)
	{
	    if( !isSubstring(s2.substr(0,i+1), s1) ) break;
	}
	return isSubstring(s2.substr(i), s1);
    }
}

bool isRotation2(const string& s1, const string& s2)
{
    if (s1.length() != s2.length())
    {
	return false;
    } else {
	string ss = s2+s2;
	return isSubstring(s1,ss);
    }
}

int main()
{
    // testing substring:
    string whole = "waterbottle";
    string part = "erbottlewat";
    cout << isSubstring(part, whole) << endl;
    cout << isRotation2(part, whole) << endl;
}
