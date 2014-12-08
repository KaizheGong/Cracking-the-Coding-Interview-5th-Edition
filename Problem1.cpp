/*
 * =====================================================================================
 *
 *       Filename:  Main.cpp
 *
 *    Description:  Cracking the coding interview chapter 1
 *
 *        Version:  1.0
 *        Created:  29/11/2014 19:47:15
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

/*
 * 1.1 Implement an algorithm to determin if a string has all unique characters.
 * What if you cannot use additional data structures ?
 */
bool hasAllUnique1(const std::string& input)
{
    std::map<char, bool> check;
    for (std::string::const_iterator it = input.begin(); it != input.end(); ++it)
    {
	if (check.find(*it) == check.end())
	{
	    check[*it] = true;
	} else {
	    return false;
	}
    }
    return true;
}

/*
 *  solution 2: without using any additional buffer
 */
bool hasAllUnique2(const std::string& input)
{
    for (std::string::const_iterator outIt = input.begin(); outIt != input.end(); ++outIt)
    {
	std::string::const_iterator inIt = outIt;
	++inIt;
	for (; inIt != input.end(); ++inIt)
	{
	    if (*outIt == *inIt) return false;
	}
    }
    return true;
}

int main ()
{
    std::cout << "Hello World!" << std::endl;

    std::cout << "Testing for abcde: " << hasAllUnique2("abcde") << std::endl;
    std::cout << "Testing for abcad: " << hasAllUnique2("abcad") << std::endl;
    std::cout << "Testing for aaaaa: " << hasAllUnique2("aaaaa") << std::endl;
}

