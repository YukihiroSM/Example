#pragma once
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

template<class E>
class Element
{
private:
	E value; //Value of element;
public:
	Element() { value = ""; } //Default constructor;
	Element(E inValue) { value = inValue; } //Condstructor with parameter;
	Element(const Element<E>& el) { value = el.value; } //Copy constructor;
	E getValue() { // get value of element
		return value;
	}
	void setValue(E val) { //set value of element
		value = val;
	}
	~Element() {   //Destructor
		value = "";//Just making this empty
	}
};

template <class E, class Y>
class Array
{
private:
	Y size; //Size of array
	Element<E> *element; //pointer to create array of objects || example of agregation.
public:
	Array() { size = 0; } //Default constructor
	Array(Y inSize) {//Constuctor with params;
		if (inSize < 0) { //Checking size.
			cout << "\n\n\tError #I1: Size of array shouldn't be less, than 0! And you entered: " << inSize << "." << endl;
			cout << "\tSize of array has been setted to 1." << endl;
			inSize = 1;
		}
		size = inSize;
	}
	Array(const Array<E, Y>& a) { //Copy constructor;
		size = a.size;
		element = a.element;
	}
	void createArray(); //Create array of Elements;
	void enterArray(); //Entering array of Elements;
	void showArray(); //Printing all data about array;
	void addElement(); //Add one element to array;
	void removeElement(); //Remove one element from array;
	bool checkOccurenceOfElement(E); //Check if element is in array;

	~Array() { //destructor
		delete[] element;
		cout << "\n\n\t\tSYSINFO: Object deleted.\n\n";
	}
};