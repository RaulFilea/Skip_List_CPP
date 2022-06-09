//
// Created by Almost on 21/05/2022.
//

#ifndef PROJECT2_SKIPLIST_H
#define PROJECT2_SKIPLIST_H

#include "Node.h"

class SkipList {
private:
    Node * first;
    int size;
    const int max_size = 100;
    Node * mem[3];
public:
    SkipList();
    int search(char * name, int mode);
    void insert(char * name, bool really = true);
    void remove(char * name);
    void display();
    static int get_rand();
};

#endif //PROJECT2_SKIPLIST_H
