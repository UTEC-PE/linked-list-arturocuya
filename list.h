#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "node.h"
#include "iterator.h"

using namespace std;

template<typename T>
class List {
private:
    Node<T> *head;
    Node<T> *tail;
    int nodes;

    void print_reverse(Node<T> *head);

public:
    List() : head(NULL), tail(NULL) {};

    T front() {
        if (head == NULL) {
            return NULL;
        } else {
            return head->data;
        }
    };

    T back() {
        if (head == NULL) {
            return NULL;
        } else {
            Node<T> *Tmp = head;
            while (Tmp->next) {
                Tmp = Tmp->next;
            }
            return Tmp->data;
        }
    };

    void push_front(T value) {
        Node<T> *Tmp = new Node<T>;
        Tmp->data = value;
        if (head == NULL) {
            head = Tmp;
        } else {
            Tmp->next = head;
            head = Tmp;
        }
    };

    void push_back(T value) {
        Node<T> *NewNode = new Node<T>;
        NewNode->data = value;
        if (head == NULL) {
            head = NewNode;
        } else {
            Node<T> *Tmp = head;
            while (Tmp->next) {
                Tmp = Tmp->next;
            }
            Tmp->next = NewNode;
        }
    };

    void pop_front() {
        Node<T> *Tmp = head;
        head = Tmp->next;
        delete Tmp;
        Tmp = nullptr;
    };

    void pop_back() {
        Node<T> *Tmp = head;
        while (Tmp->next->next) {
            Tmp = Tmp->next;
        }
        delete Tmp->next;
        Tmp->next = nullptr;
    };

    T get(int position) {
        if (position < 0) {
            // TODO: Throw accurate exception: Index out of range
            return NULL;
        } else if (head == NULL) {
            // TODO: Throw accurate exception: List empty
            return NULL;
        } else if (position == 0) {
            return head->data;
        } else {
            int aux = 0;
            Node<T> *Tmp = head;
            while (Tmp) {
                if (position == aux) {
                    break;
                }
                Tmp = Tmp->next;
                aux += 1;
            }
            if (position > aux) {
                // TODO: Throw accurate exception: Index out of range
                return NULL;
            }
            return Tmp->data;
        }
    };

    void concat(List<int> *other) {
        if (!this->empty()) {
            if (!other->empty()) {
                Node<T> *Tmp = head;
                while (Tmp->next) {
                    Tmp = Tmp->next;
                }
                Tmp->next = other->head;
            } // En caso que la otra lista esté vacía, no hago nada :)
        } else {
            head = other->head;
        }
    };

    bool empty() {
        return head == NULL;
    };

    int size() {
        int r = 0;
        if (head == NULL) {
            return r;
        } else {
            Node<T> *Tmp = head;
            while (Tmp) {
                r += 1;
                Tmp = Tmp->next;
            }
            return r;
        }
    };

    void print() {
        if (head == NULL) {
            cout << "Empty list" << endl;
        } else {
            Node<T> *Tmp = head;

            while (Tmp) {
                cout << Tmp->data << " ";
                Tmp = Tmp->next;
            }
        }
    };

    void print_reverse() {
        Node<T> *NTmp = head;
        List<T> *LTmp = new List<T>;
        while (NTmp) {
            LTmp->push_front(NTmp->data);
            NTmp = NTmp->next;
        }
        LTmp->print();
        LTmp->clear();
    };

    void clear() {
        if (head != NULL) {
            Node<T> *iNode = head;
            while (iNode) {
                Node<T> *toDelete = iNode;
                iNode = iNode->next;
                delete toDelete;
                toDelete = nullptr;
            }
            delete iNode;
            iNode = nullptr;
            head = NULL;
        }
    };

    Iterator<T> begin();

    Iterator<T> end();

    ~List() {
        if (head) {
            head->killSelf();
        }
        head = NULL;
    }
};

#endif