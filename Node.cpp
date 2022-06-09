//
// Created by Almost on 21/05/2022.
//

#include "Node.h"
#include <cstring>

char * Node::get_data() {
    return this -> data;
}

Node::Node(char * data, int level) {
    char * new_string = new char[20];
    strcpy(new_string, data);
    this -> data = new_string;
    this -> level = level;
    this -> bot = nullptr;
    this -> mid = nullptr;
    this -> top = nullptr;
}

Node * Node::get_bot() {
    return this -> bot;
}

void Node::set_bot(Node * bot) {
    this -> bot = bot;
}

Node * Node::get_mid() {
    return this -> mid;
}

void Node::set_mid(Node * mid) {
    this -> mid = mid;
}

Node * Node::get_top() {
    return this -> top;
}

void Node::set_top(Node * top) {
    this -> top = top;
}

int Node::get_level() {
    return this -> level;
}
