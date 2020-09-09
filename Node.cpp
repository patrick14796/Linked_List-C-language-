#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
#include "Node.h"



Node::Node()  /*DEFAULT CONSTRUCOTR*/
{   
	this->Data = NULL;
	this->Next = NULL;
}



Node::Node(const char* Data, Node* Next )    // CTOR recive data and next //
{
	this->Data = new char[strlen(Data) + 1];   // creat a new char* of data in the same size of the data I recive //
	strcpy(this->Data, Data);   // copy the value in the data //
	this->Next = Next;       
}




void Node::setData(const char* dat) {     // methode put data in a Node //
	if (Data!=NULL)   // check if the data is NULL //
	{
		delete[] Data;   // delete the DATA //
	}
	this->Data = new char[strlen(dat) + 1];   // and create a new DATAT in the same size //
	strcpy(Data, dat);    // copy to the new DATA i recive in this methode from the user //
}

void Node::setNext(Node* nex) {    //methode put the Next //
	if (nex==nullptr)   // check if the next i recive in this method is null//
	{
		Next = NULL;
	}
	else   // if the next i recive in this method is not null 
	{
		this->Next = nex;
	}
	
}

Node::Node(Node const & node)  // copy constrcutor //
{
	setData(node.getData());
	Next = node.getNext();
}


Node Node::operator=(Node const & node) {  // Placement operator //

	if (this!=&node)   // check if the Node are NOt different //
	{
		setData(node.getData());   //get data //
		Next = node.getNext();     // get next //
	}

	return *this;    // return the Node //
}


/*DESTRCUTOR*/
Node::~Node()

{
	if(this->Data != NULL)     // if the data in the Node is not NULL //
		delete[] Data;         // deleted the data //
	
}

