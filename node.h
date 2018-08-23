#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    T data;
    struct Node* next;

    Node<T>(): data(NULL), next(NULL) {};

    void killSelf(){
        if (next){
            delete next;
        }
    }
};

#endif