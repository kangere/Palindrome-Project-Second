#ifndef STACK_HPP
#define STACK_HPP

#include <iostream>

template <typename T>
class Stack {

private:

		struct Node {
			Node* next;
			T item;
		};
		
		Node* top;
		int stackSize;
	
public:
	//constructor
	Stack(){ top = nullptr; stackSize = 0;}
	
	//Copy constructor
	Stack(const Stack&);
	
	//destructor
	~Stack();
	
	//Util functions
	void pop(T&);
	void push(T);
	
	void displayContent();
	
	bool isEmpty(){
		return (top == nullptr);
	}
	
	int getSize(){
		return stackSize;
	}
	
};

template <typename T>
void Stack<T>::push(T newItem)
{
	//Create nodes to store item and traverse linked list
	Node *newNode = nullptr;
	
	
	newNode = new Node();
	newNode->item = newItem;
	
		if(isEmpty())
		{
			top = newNode;
			newNode->next = nullptr;
			stackSize+=1;
		}
		else
		{
				newNode->next = top;
				top = newNode;
				
				stackSize+=1;
		}
}

template <typename T>
void Stack<T>::pop(T& item)
{
	if(isEmpty())
		return;
		
	Node *temp;
	
	
	item = top->item;
	
	temp = top->next;
	delete top;
	top = temp;
	
	stackSize -= 1;
	
}

template< typename T>
void Stack<T>::displayContent()
{
	if(isEmpty())
		return;
	
	Node *nodePtr = top;
	
	while(nodePtr)
	{
		std::cout << nodePtr->item << std::endl;
		nodePtr = nodePtr->next;
	}
}

template <typename T>
Stack<T>::~Stack()
{
	Node *nodePtr, *nextNode;
	
	nodePtr = top;
	
	while(nodePtr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}

#endif