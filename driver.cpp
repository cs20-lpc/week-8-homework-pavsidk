#include <iostream>
#include "StackFactory.hpp"
#include "LinkedListStack.hpp"
using namespace std;
#include <string>

int main() {

    Stack<string>* myStack = StackFactory<string>::GetStack();

    cout << "   TESTING PUSH" << endl;
    cout << "*--------------------*" << endl;
    cout << "Checking using the 'isEmpty' method: ";
    if (myStack->isEmpty()) {
        cout << "The stack is empty. " << endl;
    }
    else {
        cout << "The stack is not empty. " << endl;
    }

    myStack->push("This");
    myStack->push("is");
    myStack->push("a");
    myStack->push("test");
    cout << "Length of myStack after pushing four strings: " << myStack->getLength() << endl;
    cout << "Contents of myStack: ";
    myStack->print();
    cout << endl;
    cout << endl;

    cout << "   TESTING PEEK" << endl;
    cout << "*--------------------*" << endl;
    cout << "Top element of myStack using peek: " << myStack->peek() << endl;
    cout << endl;
    cout << endl;

    cout << "   TESTING POP" << endl;
    cout << "*--------------------*" << endl;
    cout << "Contents of myStack: ";
    myStack->print();
    cout << "Popping the top element of myStack. " << endl;
    myStack->pop();
    cout << "Contents of myStack after one pop: ";
    myStack->print();
    cout << "Length of myStack: " << myStack->getLength() << endl;
    cout << "   *----*" << endl;

    cout << "Popping all remaining elements of myStack. " << endl;
    myStack->pop();
    myStack->pop();
    myStack->pop();
    cout << "Contents of myStack: ";
    myStack->print();
    cout << "Length of myStack: " << myStack->getLength() << endl;
    cout << "Checking if myStack is empty now: ";
    if (myStack->isEmpty()) {
        cout << "The stack is empty. " << endl;
    }
    else {
        cout << "The stack is not empty. " << endl;
    }

    cout << "Trying to pop an element from an empty stack. " << endl;
    try {
        myStack->pop();
    }
    catch (string& e) {
        cerr << e << endl;
    }
    cout << endl;
    cout << endl;

    cout << "   TESTING ROTATE" << endl;
    cout << "*--------------------*" << endl;
    myStack->push("one");
    myStack->push("two");
    myStack->push("three");
    myStack->push("four");
    cout << "Contents of myStack before rotation: ";
    myStack->print();
    cout << "   *----*" << endl;

    cout << "Rotating stack LEFT. " << endl;
    myStack->rotate(Stack<string>::LEFT);
    cout << "Contents of myStack after rotating to LEFT: ";
    myStack->print();
    cout << "   *----*" << endl;

    cout << "Rotating stack RIGHT. " << endl;
    myStack->rotate(Stack<string>::RIGHT);
    cout << "Contents of myStack after rotating to RIGHT: ";
    myStack->print();
    cout << endl;
    cout << endl;

    cout << "   TESTING CLEAR" << endl;
    cout << "*--------------------*" << endl;
    cout << "Clearing contents of myStack. " << endl;
    myStack->clear();
    cout << "Contents of myStack: ";
    myStack->print();
    cout << "Length of myStack: " << myStack->getLength() << endl;
    cout << endl;
    cout << endl;

    cout << "   OTHER DATATYPE" << endl;
    cout << "*--------------------*" << endl;
    Stack<int>* intStack = StackFactory<int>::GetStack();
    intStack->push(10);
    intStack->push(20);
    cout << "Contents of intStack: ";
    intStack->print();
    cout << "   *----*" << endl;
    cout << "Popping one element from intStack. " << endl;
    intStack->pop();
    cout << "Contents of intStack: ";
    intStack->print();
    cout << "   *----*" << endl;
    cout << "Pushing two more elements into intStack. " << endl;
    intStack->push(30);
    intStack->push(40);
    cout << "Contents of intStack: ";
    intStack->print();
    cout << "   *----*" << endl;
    cout << "Rotating intStack LEFT. " << endl;
    intStack->rotate(Stack<int>::LEFT);
    cout << "Contents of intStack after rotating LEFT: ";
    intStack->print();
    cout << "   *----*" << endl;
    cout << "Rotating intStack RIGHT. " << endl;
    intStack->rotate(Stack<int>::RIGHT);
    cout << "Contents of intStack after rotating RIGHT: ";
    intStack->print();
    cout << endl;

    delete myStack;
    delete intStack;
}
