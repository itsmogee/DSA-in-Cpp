#include "list.h"

List::List() {
  this->size = 0;
  this->head = nullptr;
  this->tail = nullptr;
}

int List::getSize() { return 0; };

bool List::isEmpty() { return true; }

int List::valueAt(int index) { return 0; }

void List::pushFront(int value) { return; }

int List::popFront() { return 0; }

void List::pushBack(int value) {};
int List::popBack() { return 1; };
int List::front() { return 1; };
int List::back() { return 1; };
void List::insert(int index, int value) {};
void List::erase(int index) {};
void List::reverse() {};
void List::removeValue(int value) {};
