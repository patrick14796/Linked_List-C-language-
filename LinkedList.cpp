#include "LinkedList.h"             
#include "Node.h"
using namespace std;


Node* LinkedList::createNode(const char* data, Node* next) {  // method that create a new node in the linkedlist //
	Node* newy = new Node(data, next);   // create a new Node //
	size++;   // increase the size //
	return newy;  // return the node//

}

Node* LinkedList::get(int index) const{   // methode that get index and return the node //

	Node* temp;         // create a new node in name temp //
	temp = head;        
	for (int i = 0; i <= index-1; i++)    // loop from 0 to the index-1 to get the next of the previuos node // 
	{
		temp = temp->getNext();   
	}
	return temp;
}

LinkedList::LinkedList() {    // default CTOR//

	size = 0;        // the size in 0 //
	head = NULL;     // the head is equal  to NULL //
	tail = NULL;      // the tail is equal to NULL //
}

LinkedList::LinkedList(const LinkedList& other) {   //  COPY CTOR  // 

	if (other.size==0)  
	{
		tail = NULL;
		head = NULL;                        // if the linkedlist is empty the tail and head is NULL and the size is 0 //
		this->size = 0;
	}
	else
	{
		Node* tmp=other.get(0);
		createNode(tmp->getData(), NULL);
		tmp = tmp->getNext();
		for (int i = 1; i < other.length(); i++)            // if the linked list is NOT empty i creat a new node and comp all the node in the linked list that recive //
		{
			append(tmp->getData());
			tmp = tmp->getNext();
		}
	}
	
}

void LinkedList::prepend(const char* data) {   //Add a new node to the beginning of the list //
	if (length()==0)
	{
		
		Node* newNode = createNode(data);
		Node* tmp = head;
		head = newNode;                            // if the size of the Linked list is 0 (empty) i creat a new tmp of node and make it head //
		head->setNext(tmp);                       // and also the tail is the new node because we have only 1 node in the list //
 		tail = newNode;
	}
	else
	{
		
		Node* newNode= createNode(data);
		Node* tmp = head;                        // else the linked list is not empty i create a new node and make it to be the head and the next is the node that was the head before// 
		head = newNode;
		head->setNext(tmp);
	}

 }

void LinkedList::append(const char* data) { // Add a new node to the end of the list//

	if (length() == 0)
	{
		                                              // if the length of the linked list is 0 (empty)//
		Node* newNode = createNode(data);
		Node* tmp = head;
		head = newNode;                                // create a new node and set him to be tail and head of the list //
		head->setNext(tmp);
		tail = newNode;
	}
	else                                          // if the length of the linked list is Not 0 //
	{
		
		Node* newNode = createNode(data);
		Node* tmp=head;
		while (tmp->getNext()!=NULL)
		{
			tmp = tmp->getNext();                    // create new Node and in while loop get the next //
		}
		tail = tmp;
		tmp->setNext(newNode);
		tail = newNode;                              // and place the tail to be the new Node //
	}

}

void LinkedList::insert(const char* data, int index) {   // Insert a new node at the given index //

	Node* newy = createNode(data);
	if (index < 0 || index > size + 1) {              // create a new node  //
		cout << "Invalid position!" << endl;      // print to the screen this message if the index is incorrect //
	}
	if (index==0)    // if the index is 0 //
	{
		Node* tmp = head;
		head = newy;                      // create a new node and set him to be the head and the tail //
		newy->setNext(tmp);
	}
	if (index == length())         // if the index is equal to the size of the list //
	{
		Node* blast = get(index-1);      // create a new Node //
		blast->setNext(newy);          // set the next of this node i creat to the node of the tail in the linkedlist //
		tail = newy;                  
	}
	else if(index < length() && index!=0  && index != length())      
	{
		Node* tmp;
		Node* temp2;
		temp2 = get(index - 1);
		tmp = temp2->getNext();
		temp2->setNext(newy);
		newy->setNext(tmp);
	}
	
}


bool LinkedList::isEmpty() const {     // method check if the list is empty or not //

	if (head !=NULL)         // if the head is not NULL (not empty)
	{
		return false;    // return false //
	}
	else         // else (the list is empty ) //
	{
		return true;    // return true //
	}
}

unsigned LinkedList::length() const {         // method that return the size of the list //

	return size;   // return the size //
}


void LinkedList::remove(int index) {      // method that remove the Node in the given index //
	Node* x=head;                       // creat a Node //
	if (index>size || index<0)      // check if the index given is correct or not //
	{
		cout << "The index is incorrect!" << endl;   // print to screen //
	}
	
	else if (index == 0 && length()==1)      // check if the index is 0 (the firs node) and the length of the list is 1 mean is the only node //
	{
		tail = NULL;
		head = NULL;
		--size;       // decrease the size of the list //
	}

	else if (index>0 && length()>1)           // check if the index is bigger than 0 and the length also//
	{
		Node* blast = get(index-1);     //A new node and inserts the index in one place before //
		blast->setNext(blast->getNext()->getNext());  
		--size;      // decrease the size of the list //
	}
	else if (index==0 && length()>1)     // check if the index given is 0 and the length is bigger than 1 //
	{
		Node* first = head;     //A new node and is the head  //
		Node* second = get(index + 1);   //A new node and is the Next node in the list //
		head = second;   // the head is the second node //
		--size;   // decrease the size of the list //
	}

	else if (index=length())    // check if the index given is equal to the size of thr list //
	 {
		 for (int i = 0; i < size-2; ++i)
		 {
			 x = x->getNext();   //get the next of the node x , the end is the node one befor the finall node // 
		 }
		 tail = NULL;
		 x->setNext(NULL);     // make the tail node to NULL  //
		 tail = x;    // the tail is x node // 
		 --size;   // decrease the size of the list //
	 }
}



void LinkedList::print() const {      // method that print the nodes in the list //
	if (length()==0)     // if the list is emty //
	{
		cout << "The list is empty!!!" << endl;    // print to screen this //
	}
	else
	{                                  // else it will run in loop and print the data in the nodes . //
		Node *temp = head;
		for (int j = 0; j < length(); ++j)
		{
			cout << temp->getData() << endl;
			temp = temp->getNext();
		}
	}
	
}


const char*LinkedList::at(int index) const {        // Get the value of a node at a given index //

	Node* temporary;
	temporary = get(index);     
	return temporary->getData();
}


bool LinkedList::operator==(const LinkedList& other) const {       // Compare two lists to see if they contain the same values.//
	Node* temp1=this->head;
	Node* temp2=other.head;           // create 2 nodes one point to the head of this list and the another to the head of the other head //
	if (this->size != other.length())
	{
		cout << "The 2 objects are different!" << endl;
		return false;
	}

	else
	{
		int counter = 0;                          // create variable //
		for (int i = 0; i < length(); ++i)    // loop from 0 to the length of the list //
		{
			Node* temp2 = other.head;
			for (int j = 0; j < length(); ++j)
			{
				if (strcmp(temp1->getData(),temp2->getData())==0)     // compare between the 2 temps //
				{
					++counter;    // if the 2 temps are equal i increase the counter //
					break;
				}
				else
				{
					temp2 = temp2->getNext();         // get the next of the temp 2 //
				}
			}
			temp1 = temp1->getNext();
		}
		if (counter==size)
		{
			cout << "The 2 objects are equal !!!" << endl;
			return true;
		}
		else
		{
			cout << "The 2 objects are different!" << endl;
			return false;
		}
	}
}


bool LinkedList::contains(const char* value) const {          //  Whether or not the list contains a given value. //

	Node* tmp;
	tmp = head;                          // create temp node //
	for (int i = 0; i < size; ++i)
	{
		if (strcmp(tmp->getData(),value) == 0)           // compare between the data i recive to check and the data in the node //
		{
			cout << "yes it contains the value you insert" << endl;
			return true;    // return true if the 2 data is equal //
		}
		tmp = tmp->getNext();
	}

	cout << " it is NOT contains the value you insert!!!" << endl;
	return false;     // return false if the 2 data is NOT equal //
}

LinkedList::~LinkedList() {          //DTOR of the linked list  (Remove all node from the list.) //
	if (head!=NULL)
	{
		Node* tmp = head->getNext();      // create a node //
		Node* This = head;                // the node is the head //
		while (This != NULL)
		{
			delete This;         // delete the node if the linkedlist is no empty // 
			--size;               // decrease the size of the list //
			if (tmp == NULL)
			{
				This = NULL;
			}
			else
			{
				This = tmp;
				tmp = tmp->getNext();        // get the nex of the node //
			}
	}

	}
	
}

