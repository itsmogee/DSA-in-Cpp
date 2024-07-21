#include "list.h"
#include "iostream"
#include "node.h"

using namespace std;

List::List()
{
    this->size = 0;
    this->head = nullptr;
    this->tail = nullptr;
}

List::~List()
{
    // Empty List
    if (this->head == nullptr) {
        return;
    }

    // List with only one item
    if (this->head == this->tail) {
        delete this->head;
        return;
    }

    // List with multiple items
    while (this->head->next != nullptr) {
        Node* temp = this->head;
        this->head = this->head->next;
        delete temp;
    }
    delete this->head;
}

int List::getSize()
{
    return this->size;
};

bool List::isEmpty()
{
    if (this->head == nullptr) {
        return true;
    } else {
        return false;
    }
}

int List::valueAt(int index)
{
    int idx = 0;

    // Index out of bounds
    if (index >= this->size || index < 0) {
        cout << endl
             << "Out of bounds";
        return -9999;
    }

    Node* ptr = this->head;
    while (idx != index) {
        idx += 1;
        ptr = ptr->next;
    }
    return ptr->Key;
}

void List::pushFront(int value)
{
    // Increase list size
    this->size += 1;

    // Create new node and replace head
    Node* temp = new Node(value);
    if (this->head == nullptr) {
        this->head = temp;
        this->tail = temp;
    } else {
        temp->next = this->head;
        this->head = temp;
    }
}

int List::popFront()
{
    // Remove front item and return the value
    if (!this->head) {
        return -9999;
    }

    Node* tempNode = this->head;
    int removedValue = tempNode->Key;

    this->head = tempNode->next;
    delete tempNode;
    this->size -= 1;
    return removedValue;
}

void List::pushBack(int value)
{
    // Adds item at the end of the array

    // Empty list
    Node* newNode = new Node(value);
    this->size += 1;

    if (!this->head) {
        this->head = newNode;
        this->tail = newNode;
    } else {
        Node* temp = this->tail;
        temp->next = newNode;
        this->tail = newNode;
    }
};

int List::popBack()
{
    // Empty List
    if (!this->head) {
        return -999;
    } else if (this->head == this->tail) {
        int retValue = this->head->Key;
        delete this->head;
        this->head = nullptr;
        this->tail = nullptr;
        this->size = 0;
        return retValue;
    }

    Node* temp = this->head;
    while (temp->next != this->tail) {
        temp = temp->next;
    }
    this->size -= 1;
    int retValue = this->tail->Key;
    delete this->tail;
    this->tail = temp;
    this->tail->next = nullptr;
    return retValue;
};

int List::front()
{
    if (!this->head) {
        return -9999;
    }
    return this->head->Key;
};

int List::back()
{
    if (!this->tail) {
        return -9999;
    }
    return this->tail->Key;
};

void List::insert(int index, int value)
{
    /**
    Insert a value at an index, the new index item will point to the old index item
    Increment list size since its insertion
    Find the value at
    What if index is last value or larger ?
    **/

    if (index > this->size - 1) {
        cout << "Index : " << index << " out of range " << endl;
        return;
    }

    if (!this->head) {
        // Empty List
        this->head = new Node(value);
        this->tail = this->head;
        this->size += 1;
        return;
    } else if (this->head == this->tail || index == 0) {
        // List with one item
        this->pushFront(value);
        return;
    }

    // Find the node at the index, keep track of previous node
    Node* temp = this->head;
    Node* prev = nullptr;
    int idx = 0;
    while (idx != index) {
        idx += 1;
        prev = temp;
        temp = temp->next;
    }

    Node* newNode = new Node(value);
    prev->next = newNode;
    newNode->next = temp;
    this->size += 1;
    return;
};

void List::erase(int index) {};
void List::reverse() {};
void List::removeValue(int value) {};
