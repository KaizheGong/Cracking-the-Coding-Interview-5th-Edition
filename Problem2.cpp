/*
 * =====================================================================================
 *
 *       Filename:  Problem2.cpp
 *
 *    Description:  Cracking the coding interview chapter 1 problem 2
 *
 *        Version:  1.0
 *        Created:  29/11/2014 21:30:00
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

/* 
 * 1.2 Implement a function void reverse(char* str) in C or C++ which reverse a null-terminated string
 */
void reverse(char* input)
{
    char* end = input;
    while (*end != '\0') ++end;
    --end;

    while (input < end)
    {
	char temp = *input;
	*input++ = *end;
	*end-- = temp;
    }
}

int main ()
{
    std::cout << "Go, kaizhe!" << std::endl;

    char test[] = "abcde";
    std::cout << "Before reverse:" << test << std::endl;
    reverse(test);
    std::cout << "After reverse:" << test << std::endl; 
}
