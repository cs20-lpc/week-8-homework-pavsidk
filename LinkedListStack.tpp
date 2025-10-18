#include "LinkedListStack.hpp"

template <typename T>
LinkedListStack<T>::LinkedListStack()
{ 
    top=nullptr;
    this->length = 0;
}

template <typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& copyObj) {
    copy(copyObj);
}

template <typename T>
LinkedListStack<T>& LinkedListStack<T>::operator=(const LinkedListStack<T>& rightObj) {
    if (this != &rightObj) {
        clear();
        copy(rightObj);
    }
    return *this;
}

template <typename T>
LinkedListStack<T>::~LinkedListStack() {
    clear();
}

template <typename T>
void LinkedListStack<T>::clear() {
    // TO DO: Delete all the elements in the stack
    Node<T>* temp = top;
    while (temp != nullptr) {
        Node<T>* after = top->next;
        delete temp;
        temp = temp->next;
    }
    top = nullptr;
}

template <typename T>
void LinkedListStack<T>::copy(const LinkedListStack<T>& copyObj) {
    // TO DO: Implement copy 
    if (copyObj.top == nullptr) {
        top = nullptr;
        return;
    }

    top = new Node<T>(copyObj.top->data);

    Node<T>* copyCurr = copyObj.top->next;
    Node<T>* curr = top;

    while (copyCurr != nullptr) {
        curr->next = new Node<T>(copyCurr->data);
        copyCurr = copyCurr->next;
        curr = curr->next;
    }
    curr->next = nullptr;
}

template <typename T>
int LinkedListStack<T>::getLength() const {
    return this->length;
}


template <typename T>
bool LinkedListStack<T>::isEmpty() const {
    return this->length == 0;
}

template <typename T>
T LinkedListStack<T>::peek() const {
    // TO DO: implement peek
    return top->data;
}

template <typename T>
void LinkedListStack<T>::pop() {
    // TO DO: Implement pop
    if (top == nullptr) {
        throw string("Error: ");
    }

    Node<T>* temp = top;
    top = top->next;
    delete temp;

    this->length--;
}

template <typename T>
void LinkedListStack<T>::push(const T& elem) {
    // TO DO: Implement push
    Node<T>* temp = top;
    top = new Node<T>(elem);
    top->next = temp;

    this->length++;
}

template <typename T>
void LinkedListStack<T>::rotate(typename Stack<T>::Direction dir) {
    // TO DO: Implement rotate
    if (top == nullptr || top->next == nullptr) {
        return;
    }

    if (dir == Stack<T>::LEFT) {
        Node<T>* temp = top;
        top = top->next;

        Node<T>* curr = top;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = temp;
        temp->next = nullptr;
    }
    else if (dir == Stack<T>::RIGHT) {
        Node<T>* curr = top;
        while (curr->next->next != nullptr) {
            curr = curr->next;
        }
        Node<T>* temp = curr->next;
        curr->next = nullptr;
        temp->next = top;
        top = temp;
    }
}

template <typename T>
void LinkedListStack<T>::print() {
    cout << "LinkedListStack contents: ";
    if (isEmpty()) {
        cout << "Stack is empty, no elements to display.\n";
    }
    else {
        Node<T> *curr = top;
        while (curr != nullptr){
            cout <<  curr->data  << "\t";
            curr = curr->next;
        }
    }

    cout << endl;
}
