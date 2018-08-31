#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    struct Node* next;

    Node<T>(): data(NULL), next(NULL) {}; // data no debería ser NULL

    void killSelf(){ // Esto está mal, debería ser if (next) next->killSelf(); delete this;
        if (next){
            delete next;
        }
    }
};

#endif