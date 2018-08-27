#include <iostream>
#include "list.h"
#include "node.h"

int main() {
    List<int> *list = new List<int>;

    list->push_back(3);
    list->push_back(6);
    list->push_back(2);
    list->push_back(8);
    list->push_back(6);
    list->push_back(7);
    list->print(); cout << endl;
    cout << "Size: " << list->size() << endl;
    cout << "Front: " << list->front() << endl;
    cout << "Back: " << list->back() << endl;

    cout << "Element at position " << 2 << ": " << list->get(2) << endl;

    cout << "Deleting element at front..." << endl;
    list->pop_front();
    cout << "New list: ";
    list->print();
    cout << endl;

    cout << "Deleting element at back..." << endl;
    list->pop_back();
    cout << "New list: ";
    list->print();
    cout << endl;

    cout << "Clearing list..." << endl;
    list->clear();
    cout << "New list: ";
    list->print();
    cout << endl;

    cout << "======================" << endl;

    List<int> *aList = new List<int>;
    List<int> *anotherList = new List<int>;

    aList->push_back(1);
    aList->push_back(2);
    aList->push_back(3);

    anotherList->push_back(4);
    anotherList->push_back(5);
    anotherList->push_back(6);

    cout << "List A: ";
    aList->print();
    cout << endl;
    cout << "List B: ";
    anotherList->print();
    cout << endl;

    cout << "Concatenating list A with B..." << endl;
    aList->concat(anotherList);
    cout << "Result: ";
    aList->print();
    cout << endl;

    cout << "Reversing..." << endl;
    cout << "Result: ";
    aList->print_reverse();
    cout << endl;


    return 0;
}