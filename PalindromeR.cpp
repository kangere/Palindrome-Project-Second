#include "PalindromeR.hpp"
#include <string>
#include <ctype.h>

int PalindromeR::test_string(const std::string &s)
{
	//create variable to store string
	std::string temp = s;
	
	//check if first character is alphanumeric
/*	if(!isalnum(temp.front()))
		temp = temp.substr(1,temp.size() - 1);*/
	
	//check if last character is alphanumeric
	if(!isalnum(temp.back()))
		temp.pop_back();
		
	
	if(temp.size() <= 1)
		return -1;
	else if(tolower(temp.front()) != tolower(temp.at(temp.back())))
		return 1;
	
	//recursion call without first and last charcters
	return test_string(temp.substr(1,temp.size() - 2));
	
}