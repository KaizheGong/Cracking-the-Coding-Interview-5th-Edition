/*
 * =====================================================================================
 *
 *       Filename:  Problem3.cpp
 *
 *    Description:  Cracking the coding interview Chapter 1, problem 3
 *
 *        Version:  1.0
 *        Created:  29/11/2014 22:38:48
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
#include <map>

bool isPermutation(const std::string& input_1, const std::string& input_2)
{
    if (input_1.length() != input_2.length())
    {
	return false;
    } else {
	std::map<char, int> charCounter1;
	std::map<char, int> charCounter2;

	for (std::string::const_iterator itr1 = input_1.begin(); itr1 != input_1.end(); ++itr1)
	{
	    if (charCounter1.find(*itr1) == charCounter1.end())
	    {
		charCounter1[*itr1] = 1;
	    } else {
		++charCounter1[*itr1];
	    }
	}

	for (std::string::const_iterator itr2 = input_2.begin(); itr2 != input_2.end(); ++itr2)
	{
	    if (charCounter2.find(*itr2) == charCounter2.end())
	    {
		charCounter2[*itr2] = 1;
	    } else {
		++charCounter2[*itr2];
	    }
	}

	if (charCounter1.size() != charCounter2.size())
	{
	    return false;
	} else {
	    std::map<char, int>::const_iterator mapIt_1 = charCounter1.begin();
	    for (; mapIt_1 != charCounter1.end(); ++mapIt_1)
	    {
		if (charCounter1[mapIt_1->first] != charCounter2[mapIt_1->first])
		{
		    return false;
		}
	    }
	}
	return true;
    }

}

int main()
{
    std::cout << "Go! Kaizhe!" << std::endl;
    std::cout << "testing for abcded and ddecba: " << isPermutation("abcded","ddecba") << std::endl;
    std::cout << "testing for abkd and mkoh: " << isPermutation("abkd", "mkoh") << std::endl;
    std::cout << "testing for mkyuq and qupou: " << isPermutation("mkyuq","qupou") << std::endl;
    std::cout << "testing for abcd abcde: " << isPermutation("abcd","abced") << std::endl;
}
