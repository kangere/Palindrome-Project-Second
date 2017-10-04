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
	
	/**
	 * @brief checks if stack is empty
	 * @return true if the stack is empty else returns false
	 */
	bool isEmpty(){
		return (top == nullptr);
	}
	
	/**
	 * @brief 
	 * @return 
	 */
	int getSize(){
		return stackSize;
	}
	
};

/**
 * @brief adds item to the top of stack
 * @param newItem - item to be added
 */
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

/**
 * @brief remove an element from the top of the stack
 * @param item - the item to store the popped value
 */
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

/**
 * @brief displays contents of the stack
 */
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

/**
 * @brief Destructor to avoid memory leaks
 */
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

/**
 * @brief copy constructor
 * @param copy the other stack to copy values from
 */
template <typename T>
Stack<T>::Stack(const Stack &copy)
{
	if(copy.top == nullptr)
	{ 
		top = nullptr;
		stackSize = 0;
	}
	else
	{
		//create pointer to point to copy
		Node* nodePtr = copy.top;
		
		//create new node 
		//assign value of copy to new node
		Node* newNode = new Node;
		newNode->item = nodePtr->item;
		
		//let top point to top node
		top = newNode;
		
		//move to the next node
		nodePtr = nodePtr->next;
		
		while(nodePtr)
		{
			//create new node
			//move pointer to new node
			newNode->next = new Node;
			newNode = newNode->next;
			
			//assign value of copy
			newNode->item = nodePtr->item;
			
			//move to the next node
			nodePtr = nodePtr->next;
		}
		
		newNode->next = nullptr;
	
	}
}

#endif
