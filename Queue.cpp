#include "Node.h"
#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"


Queue::Queue() {             // NOT need to implement this it work default//
}

Queue::~Queue() {
	                        //// NOT need to implement this it work default//
}

void Queue::enqueue(const char* value) {    //Place a new value at the front of the queue. //

	this->list.append(value);
}

void Queue::dequeue() {         //  Remove the value from the front of the queue. //

	this->list.remove(0);

}

const char* Queue::front() const {       //Get the value from the front of the queue.//

	return this->list.at(0);
	
}

bool Queue::isEmpty() const {      //Whether or not the current queue contains values.//

	return this->list.isEmpty();
}


void Queue::print() const {              //Print the contents of the queue.//
	if ((this->list.length()) == 0)
	{
		cout << "The Queue is empty!!!" << endl;   // print to screen //
	}
	else
	{
		this->list.print();
	}
	
}