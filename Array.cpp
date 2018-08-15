#include "Array.h"

//Methods for class "Array:

//Creating Array.
template <class E, class Y> void Array<E, Y>::createArray() {
lab1:
	cout << "\n\tStarting creating of array. Enter size (should be >= 0):" << endl << "-> ";
	cin >> size;
	if (size < 0) { //Checking size.
		cout << "\n\n\t\aError #I1: Size of array shouldn't be less, than 0! And you entered: " << size << "." << endl;
		goto lab1;
	}
	element = new Element<E>[size]; //Creating array.
}

//Entering Array.
template <class E, class Y> void Array<E, Y>::enterArray() {
	cout << "\nStarted entering of array.\n" << endl;
	cout << "Array size is: " << size << ".\n";
	cout << "Now enter values for each element of array: " << endl;
	E tmp = "";
	for (Y i = 0; i < size; i++) { //Cycle for entering array of elements.

	retry1: //***LABEL RETRY1***This label is using if the user entered an empty string.

		element[i].setValue(""); //Just to make right retry.
		cout << "Element [" << i + 1 << "] = "; //Beautiful printing.
		cin >> tmp;
		element[i].setValue(tmp);//Entering values.
		if (element[i].getValue() == "") { //If entered value is null .

		retry2: //***LABEL RETRY2***This label is using if the user entered something other than Y or N.

			tmp = ""; //Just to have right checking.
			cout << "\nAre You shure, that this element is empty? (Y/N): ";
			cin >> tmp;
			if (tmp == "Y") continue; //If Y: Continuing to next iteration.
			else if (tmp == "N") goto retry1; //If N: Allow the user to enter the value again by going to label "retry1".
			else {
				cout << "Error #I2: You should answer with Y or N. (Your answer is: " << tmp << "). Try again." << endl; //If not Y or N:
				goto retry2;                                                            //Moving user to label "retry2".
			}
		}
	}
	cout << "\nNice. Array was successfully created." << endl;
}

//Printing array.
template <class E, class Y> void Array<E, Y>::showArray() {
	cout << "Size: " << size << endl;
	cout << "Array:\n{\n" << endl;
	for (Y i = 0; i < size; i++) {
		cout << "\tElement [" << i + 1 << "] = " << element[i].getValue() << ";\n";
	}
	cout << "}" << endl;
}

//Add element to array.
template <class E, class Y> void Array<E, Y>::addElement() {
	cout << "\nStarted adding element." << endl;
	Element<E> *temp = new Element<E>[size + 1]; //Creating temporary array to add element.
	for (Y i = 0; i < size; i++) {
		temp[i].setValue(element[i].getValue()); //Copying all elements from Array.
	}
	E v;
	size++; //Increasing size.
	delete[] element; //Deleting pointer.
	element = temp; //Now element is pointer for bigger array.
	temp = 0;
retry1: //***LABEL RETRY1***This label is using if the user entered an empty string.
	cout << "\nNow enter value of element, which you want to add:" << endl << "-> ";
	cin >> v;
	element[size - 1].setValue(v);
	if (element[size - 1].getValue() == "") { //If entered value is null .

	retry2: //***LABEL RETRY2***This label is using if the user entered something other than Y or N.
		E tmp = ""; //Just to have right checking.
		cout << "\nAre You shure, that this element is empty? (Y/N): ";
		cin >> tmp;
		if (tmp == "N") goto retry1; //If N: Allow the user to enter the value again by going to label "retry1".
		else if (tmp != "Y") {
			cout << "Error #I2: You should answer with Y or N. (Your answer is: " << tmp << "). Try again." << endl; //If not Y or N:
			goto retry2;                                                            //Moving user to label "retry2".
		}
	}
	cout << "\nAdding new element ended successfully.\n";
}

//Checking occurence of element in array.
template <class E, class Y> bool Array<E, Y>::checkOccurenceOfElement(E tmp) {
	for (Y i = 0; i < size; i++) {
		if (tmp == element[i].getValue()) return true;
	}
	return false;
}

//Removing one element.
template <class E, class Y> void Array<E, Y>::removeElement() {
	cout << "\nStarted removing of element." << endl;
	this->showArray();
lab3:
	cout << "If you want to delete element by index, enter 1. \nIf you want to remove element by value, enter 2." << endl;
	cout << "Your answer -> ";
	int check = 0;
	cin >> check;
	switch (check) {
	case 1: //If user decided to delete element by index in array.
	{
	lab2:
		Y index = 0;
		cout << "\nDeleting element by index." << endl;
		cout << "Now enter index of element, you want to delete: ";
		cin >> index;
		if (index <= 0 || index > size) { //Checking index to be right.
			cout << "\nError #I3: Index should be less, than " << size << ", and bigger, than 0." << endl;
			goto lab2;
		}
		for (Y i = index - 1; i < size - 1; i++) //If checked successfull, deleting:
			element[i].setValue(element[i + 1].getValue()); //In result: last element will be not needed.
		Element<E> *temp = new Element<E>[size - 1]; //creating temporary object to decreese size of array
		for (Y i = 0; i < size - 1; i++)
			temp[i].setValue(element[i].getValue()); //Copying to temp
		delete[] element; //Clearing original
		element = temp; //Pointing original to temp
		size--; //Minus size;
		temp = 0; //"Destroying temp"
		cout << "\nSuccessfully removed.\n";
		break;
	}
	case 2:
	{
		cout << "\nDeleting element by value." << endl;
		cout << "Enter value of element, which you need to remove: ";
		E inStr; //Creating buffer string
		cin >> inStr;
		if (!this->checkOccurenceOfElement(inStr)) { //checking for occurence
			cout << "\nElement not found." << endl;
			break;
		}
		Y tInd; //if element found getting
		for (Y i = 0; i < size; i++) {
			if (element[i].getValue() == inStr) //if element equals to needed
				tInd = i;                      //remember it's index
		}
		for (Y i = tInd; i < size - 1; i++)
			element[i].setValue(element[i + 1].getValue()); //moving elements for 1 to left (with destroying needed element)
		Element<E> *temp = new Element<E>[size - 1]; //same as with indexes
		for (Y i = 0; i < size - 1; i++)
			temp[i].setValue(element[i].getValue());
		delete[] element;
		size--;
		element = temp;
		temp = 0;

		cout << "\nSuccessfully removed.\n";
		break;
	}
	default: { //If user's answer != 1 or 2
		cout << "\nError #I4: Your answer should be 1 or 2.\n";
		goto lab3;
		break;
	}
	}
}

//Специализация для E = string & Y = int
template <>
class Array<string, int>
{
private:
	int size; //Size of array
	Element<string> *element; //pointer to create array of objects || example of agregation.
public:
	Array() { size = 0; } //Default constructor
	Array(int inSize) {//Constuctor with params;
		if (inSize < 0) { //Checking size.
			cout << "\n\n\tError #I1: Size of array shouldn't be less, than 0! And you entered: " << inSize << "." << endl;
			cout << "\tSize of array has been setted to 1." << endl;
			inSize = 1;
		}
		size = inSize;
	}
	Array(const Array<string, int>& a) { //Copy constructor;
		size = a.size;
		element = a.element;
	}
	void createArray() { //Create array of Elements;
	lab1:
		cout << "\n\tStarting creating of array. Enter size (should be >= 0):" << endl << "-> ";
		cin >> size;
		if (size < 0) { //Checking size.
			cout << "\n\n\t\aError #I1: Size of array shouldn't be less, than 0! And you entered: " << size << "." << endl;
			goto lab1;
		}
		element = new Element<string>[size]; //Creating array.
	}
	void enterArray() { //Entering array of Elements;
		cout << "\nStarted entering of array.\n" << endl;
		cout << "Array size is: " << size << ".\n";
		cout << "Now enter values for each element of array: " << endl;
		string tmp = "";
		for (int i = 0; i < size; i++) { //Cycle for entering array of elements.
		retry1: //***LABEL RETRY1***This label is using if the user entered an empty string.

			element[i].setValue(""); //Just to make right retry.
			cout << "Element [" << i + 1 << "] = "; //Beautiful printing.
			cin >> tmp;
			element[i].setValue(tmp);//Entering values.
			if (element[i].getValue() == "") { //If entered value is null .

			retry2: //***LABEL RETRY2***This label is using if the user entered something other than Y or N.

				tmp = ""; //Just to have right checking.
				cout << "\nAre You shure, that this element is empty? (Y/N): ";
				cin >> tmp;
				if (tmp == "Y") continue; //If Y: Continuing to next iteration.
				else if (tmp == "N") goto retry1; //If N: Allow the user to enter the value again by going to label "retry1".
				else {
					cout << "Error #I2: You should answer with Y or N. (Your answer is: " << tmp << "). Try again." << endl; //If not Y or N:
					goto retry2;                                                            //Moving user to label "retry2".
				}
			}
		}
		cout << "\nNice. Array was successfully created." << endl;
	}
	void showArray() { //Printing all data about array;
		cout << "Size: " << size << endl;
		cout << "Array:\n{\n" << endl;
		for (int i = 0; i < size; i++) {
			cout << "\tElement [" << i + 1 << "] = " << element[i].getValue() << ";\n";
		}
		cout << "}" << endl;
	}
	void addElement() { //Add one element to array;
		cout << "\nStarted adding element." << endl;
		Element<string> *temp = new Element<string>[size + 1]; //Creating temporary array to add element.
		for (int i = 0; i < size; i++) {
			temp[i].setValue(element[i].getValue()); //Copying all elements from Array.
		}
		string v;
		size++; //Increasing size.
		delete[] element; //Deleting pointer.
		element = temp; //Now element is pointer for bigger array.
		temp = 0;
	retry1: //***LABEL RETRY1***This label is using if the user entered an empty string.
		cout << "\nNow enter value of element, which you want to add:" << endl << "-> ";
		cin >> v;
		element[size - 1].setValue(v);
		if (element[size - 1].getValue() == "") { //If entered value is null .

		retry2: //***LABEL RETRY2***This label is using if the user entered something other than Y or N.
			string tmp = ""; //Just to have right checking.
			cout << "\nAre You shure, that this element is empty? (Y/N): ";
			cin >> tmp;
			if (tmp == "N") goto retry1; //If N: Allow the user to enter the value again by going to label "retry1".
			else if (tmp != "Y") {
				cout << "Error #I2: You should answer with Y or N. (Your answer is: " << tmp << "). Try again." << endl; //If not Y or N:
				goto retry2;                                                            //Moving user to label "retry2".
			}
		}
		cout << "\nAdding new element ended successfully.\n";
	}
	void removeElement() { //Remove one element from array;
		cout << "\nStarted removing of element." << endl;
		this->showArray();
	lab3:
		cout << "If you want to delete element by index, enter 1. \nIf you want to remove element by value, enter 2." << endl;
		cout << "Your answer -> ";
		int check = 0;
		cin >> check;
		switch (check) {
		case 1: //If user decided to delete element by index in array.
		{
		lab2:
			int index = 0;
			cout << "\nDeleting element by index." << endl;
			cout << "Now enter index of element, you want to delete: ";
			cin >> index;
			if (index <= 0 || index > size) { //Checking index to be right.
				cout << "\nError #I3: Index should be less, than " << size << ", and bigger, than 0." << endl;
				goto lab2;
			}
			for (int i = index - 1; i < size - 1; i++) //If checked successfull, deleting:
				element[i].setValue(element[i + 1].getValue()); //In result: last element will be not needed.
			Element<string> *temp = new Element<string>[size - 1]; //creating temporary object to decreese size of array
			for (int i = 0; i < size - 1; i++)
				temp[i].setValue(element[i].getValue()); //Copying to temp
			delete[] element; //Clearing original
			element = temp; //Pointing original to temp
			size--; //Minus size;
			temp = 0; //"Destroying temp"
			cout << "\nSuccessfully removed.\n";
			break;
		}
		case 2:
		{
			cout << "\nDeleting element by value." << endl;
			cout << "Enter value of element, which you need to remove: ";
			string inStr; //Creating buffer string
			cin >> inStr;
			if (!this->checkOccurenceOfElement(inStr)) { //checking for occurence
				cout << "\nElement not found." << endl;
				break;
			}
			int tInd; //if element found getting
			for (int i = 0; i < size; i++) {
				if (element[i].getValue() == inStr) //if element equals to needed
					tInd = i;                      //remember it's index
			}
			for (int i = tInd; i < size - 1; i++)
				element[i].setValue(element[i + 1].getValue()); //moving elements for 1 to left (with destroying needed element)
			Element<string> *temp = new Element<string>[size - 1]; //same as with indexes
			for (int i = 0; i < size - 1; i++)
				temp[i].setValue(element[i].getValue());
			delete[] element;
			size--;
			element = temp;
			temp = 0;

			cout << "\nSuccessfully removed.\n";
			break;
		}
		default: { //If user's answer != 1 or 2
			cout << "\nError #I4: Your answer should be 1 or 2.\n";
			goto lab3;
			break;
		}
		}
	}
	bool checkOccurenceOfElement(string tmp) { //Check if element is in array;
		for (int i = 0; i < size; i++) {
			if (tmp == element[i].getValue()) return true;
		}
		return false;
	}

	~Array() { //destructor
		delete[] element;
		cout << "\n\n\t\tSYSINFO: Object deleted.\n\n";
	}
};