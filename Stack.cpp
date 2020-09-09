#include "Node.h"
#include "LinkedList.h"
#include "Stack.h"


Stack::Stack() {                      // Create an empty stack.  ( default CTOR ) //
	this->list = new LinkedList();

}

Stack::~Stack() {                         //  Remove all values from the stack. //
	if (this->list->length()==0)
	{
		
		delete list;           // delete the list //
	}
	else
	{
		this->list->~LinkedList();       //active the ditructor in the linked list //
		
	}
}

const char* Stack::top() const {                      //Get the value from the top of the stack. //
	
	int lenght;
	lenght= list->length();
	return list->at(lenght-1);

}

void Stack::pop() {                     //Remove the value from the top of the stack. //
	int lenght = list->length();
	list->remove(lenght-1);
}


void Stack::push(const char* data) {       //Place a new value at the top of the stack.//
	this->list->append(data);
}

bool Stack::isEmpty() const {                //  Whether or not the current stack contains values. //
	return this->list->isEmpty();

}


void Stack::print() const {          //Print the contents of the stack. //
	this->list->print();
}