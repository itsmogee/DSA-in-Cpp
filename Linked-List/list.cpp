#include "list.h"
#include "node.h"

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
    return 0;
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
    return 0;
}

void List::pushBack(int value) {};
int List::popBack()
{
    return 1;
};
int List::front()
{
    return 1;
};
int List::back()
{
    return 1;
};
void List::insert(int index, int value) {};
void List::erase(int index) {};
void List::reverse() {};
void List::removeValue(int value) {};
