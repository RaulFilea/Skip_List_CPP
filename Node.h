//
// Created by Almost on 21/05/2022.
//

#ifndef PROJECT2_NODE_H
#define PROJECT2_NODE_H

class Node {
private:
    char * data;
    Node * bot;
    Node * mid;
    Node * top;
    int level;
public:
    Node(char * data, int level);
    char * get_data();
    int get_level();
    Node * get_bot();
    void set_bot(Node * bot);
    Node * get_mid();
    void set_mid(Node * mid);
    Node * get_top();
    void set_top(Node * top);
};

#endif //PROJECT2_NODE_H
