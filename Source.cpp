/*
Name: patrick lugassy
ID: 319266177
ASSIGNMENT 1
*/


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;
#include "LinkedList.h"
#include "Node.h"
#include "Stack.h"
#include "Queue.h"
#define ExitNumber "9999"   // define the Exit number - 9999 //
#define MaxChars 100        // define Maxchars can the user put - 100 chars //

void printOnScreen();
bool isbalanced(const char* str);

int main() {

	printOnScreen();    // all the function  print on screen  // 
	cout << endl;
	string a;        // creat a variable string //
	cout << "Enter a experssion:" << endl;
	cin  >> a;                                 // get the string from the user //
	bool b = isbalanced(a.c_str());     // creat a boolean variable //
	cout << "the answear was : " << endl;                 
	if (b==1)
	{
		cout << "TRUE" << endl;                        // check if the value return from the function is TRUE or FALSE //
	}
	else
	{
		cout << "FALSE" << endl;               // print to screen //
	}
	return 0;
}

void printOnScreen() {                       // function that recive numbers untill the user put 9999 // 
	
	Queue number;        // create a queue number// 
	char num[MaxChars];   // creat a variable in name num that culld contains 100 chars//

	cout << "Please insert numbers (The number 9999 will Finish scan numbers from you):" << endl;   // print to screen //
	cin >> num;      // get the number from the user //
	while (strcmp(num, "9999") != 0)    // while the number that user put is not 9999 it will continue to check burckets //
	{
		number.enqueue(num);    // put the bracket in the front of the queue //
		cout << "please enter another num, if you want to exit enter 9999" << endl;   // print to screen //
		cin >> num;    // get the number from the user //
	}
	cout << endl;     
	cout << "The Numbers you insert are:" << endl;

	number.print();    // print all the number the user put to the screen //
}

bool isbalanced(const char* str) {
	Stack s;     // create a stack in name s //
	const char* a;   // create variable const char a //
	for (int i = 0; i <strlen(str) ; ++i)    // foor loop from 0 to the size of the string //
	{
		if (str[0]==']'|| str[0] == ')'|| str[0] == '}')    //check if the first char is one of this bracket //
		{
			return false;   // return false //
		}
		if (str[i]=='['|| str[i]=='('|| str[i]=='{')    // check if the first char is one of this bracket //
		{
			a = &(str[i]);   
			s.push(a);     // push the bracket in the fist place on the stack //

		}
		if (str[i]==']')      // check if the bracket is this //
		{
			if (*(s.top()) == '[')  // check if the bracket in the top of the stack is this bracket //
			{
				s.pop();   // it mean the open bracket have the close bracket and get it out from the stack //
			}
			else
				return false;   // else it mean that is werong and return false //
		}
		if (str[i] == ')')    // check if the bracket is this //
		{
			if (*(s.top()) == '(')  // check if the bracket in the top of the stack is this bracket //
			{
				s.pop();      //it mean the open bracket have the close bracket and get it out from the stack //
			}
			else
				return false;  // return false //
		}
		if (str[i] == '}')     // check if the bracket is this //
		{
			if (*(s.top()) == '{') // check if the bracket in the top of the stack is this bracket //
			{
				s.pop();  //it mean the open bracket have the close bracket and get it out from the stack //
			}
			else
				return false;    // return false //
		}
	}
	
	return s.isEmpty();    // return TRUE //
}