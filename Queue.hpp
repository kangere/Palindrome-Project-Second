#ifndef QUEUE_HPP
#define QUEUE_HPP

template <typename T>
class Queue{
	
	private:
		int queueSize, f , r , numItems;
		T *queueArray;
		
		
	public:
		//Queue constructors
		Queue(int);
		
		Queue(const Queue&);
		
		//Destructor
		~Queue();
		
		//util functions
		void enqueue(T);
		
		T dequeue();
		
		T front() const;
		
		bool isEmpty() const
		{return (numItems == 0);}
		
		int getSize() const
		{return queueSize;}
};

/**
 * @brief constructor to initialize the static queue
 * @param size
 */
template <typename T>
Queue<T>::Queue(int size)
{
	queueArray  = new T[size];
	
	queueSize = size;
	f = -1;
	r = -1;
	numItems = 0;
	
}

/**
 * @brief destructor
 */
template <typename T>
Queue<T>::~Queue()
{
	if(!isEmpty())
		delete [] queueArray;
}

template <typename T>
Queue<T>::Queue(const Queue& copy)
{
	//TODO finish copy constructor
	queueArray = new T[copy.getSize()];
	queueSize = copy.getSize();
}

/**
 * @brief adds element to queue
 * @param item
 */
template <typename T>
void Queue<T>::enqueue(T item)
{
	
	if(numItems > queueSize)
	{//if full exit funciton
		std::cout << "Queue is full, unable to insert more elements" << std::endl;
		return;
	}
	
	//update rear position
	r = (r + 1) % queueSize;
	
	//add element t back of the queue
	queueArray[r] = item;
	
	numItems++;
		
}

/**
 * @brief function removes an element from the queue
 * @return an element from the queue
 */
template <typename T>
T Queue<T>::dequeue()
{
	if(isEmpty())
		throw "Queue is empty";
	
	//update front position
	f = (f + 1) % queueSize;
	
	//remove element from queue
	T item = queueArray[f];
	
	numItems--;
	
	return item;	
}

/**
 * @brief functions returns the front element of the queue
 * @return the front element in the queue
 */
template <typename T>
T Queue<T>::front() const
{
	if(isEmpty())
		throw "Queue is empty";
	else
		return queueArray[f];
}
#endif