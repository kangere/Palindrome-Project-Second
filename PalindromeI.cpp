#include "PalindromeI.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include <ctype.h>

/**
 * @brief function tests string if it is a palindrom by iteration
 * @param s the string to be tested
 * @return -1 if it is a palindrome else returns position of the error
 */
int PalindromeI::test_string(const std::string &s)
{
	int stringSize = s.size();
	int errorPosition = 0;
	
	//Create Queue and stack
	Stack<char> stack;
	Queue<char> queue(stringSize);
	
	//iterator to iterate through string
	auto iter = s.begin();
	
	//loop through string
	while(iter != s.end())
	{
		char temp = *iter;
		
		//check if the character is alphanumeric
		if(!isalnum(temp)){
			iter++;
			continue;
		}
		
		//make all letters lowercase
		if(isupper(temp))
			temp = tolower(temp);
		
		//store characters in stack and queue
		stack.push(temp);
		queue.enqueue(temp);
		iter++;
	}
	
	//loop through stack and queue
	while(!queue.isEmpty() && !stack.isEmpty())
	{
		//Create temp variables to store char from queue and stack
		char queueChar = queue.dequeue();
		
		char stackChar; 
		stack.pop(stackChar);
		
		if(queueChar != stackChar)
			return errorPosition;
		
		errorPosition++;
	}
	
	return -1;
} 
