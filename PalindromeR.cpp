#include "PalindromeR.hpp"
#include <string>
#include <ctype.h>

/**
 * @brief function tests if string passed is a palindrome or not using recursion
 * @param s the string to be tested
 * @return -1 if string is palindrom or 1 if it is not a palindrome
 */
int PalindromeR::test_string(const std::string &s)
{
	//create variable to store string
	std::string temp = s;
	
	//base case
	if(temp.size() <= 1)
	{
		return -1;
	}
	else if(!isalnum(temp.at(0)))
	{
		//if first character is not alphanumeric recursively call without it
		return test_string(temp.substr(1,temp.size()));
	}
	else if(!isalnum(temp.at(temp.size() - 1)))
	{	
		//if last character is not alphanumeric recursively call without it
		return test_string(temp.substr(0, temp.size() - 1));
	}
	else if(tolower(temp.at(0)) != tolower(temp.at(temp.size() - 1)))
	{
		return 1;
	}
	//recursion call without first and last charcters
	return test_string(temp.substr(1,temp.size() - 2));
	
}
