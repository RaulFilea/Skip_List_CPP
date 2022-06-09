//
// Created by Almost on 21/05/2022.
//

#include <iostream>
#include <cstring>
#include "SkipList.h"

SkipList::SkipList() {
    this -> first = new Node("", 3);
    this -> size = 0;
}

void SkipList::insert(char * name, bool verbose) {
    if (this -> size == this -> max_size){
        if (verbose) {
            std::cout << "No more tickets available! (max: " << this->max_size << ")\n";
        }
        return;
    }
    int chk = search(name, 0);
    if (chk == 0){
        return;
    }
    int level = get_rand();
    Node * new_node = new Node(name, level);
    if (level >= 3){
        new_node -> set_top(this -> mem[2] -> get_top());
        this -> mem[2] -> set_top(new_node);
    }
    if (level >= 2){
        new_node -> set_mid(this -> mem[1] -> get_mid());
        this -> mem[1] -> set_mid(new_node);
    }
    if (level >= 1){
        new_node -> set_bot(this -> mem[0] -> get_bot());
        this -> mem[0] -> set_bot(new_node);
    }
    this -> size += 1;
    if (verbose) {
        std::cout << "Added reservation for " << name << "\n";
    }
}

int SkipList::get_rand() {
    return std::rand() % 3 + 1;
}

void SkipList::display() {
    if (this -> size == 0){
        std::cout << "The list is empty!\n";
        return;
    }
    Node * node = this -> first;
    if (node == nullptr) {
        return;
    }
    std::cout << "These are the registrations:\n";
    while (node -> get_bot() != nullptr) {
        node = node -> get_bot();
        std::cout << node -> get_data() << "\n";
    }
    std::cout << "\n";
}

int SkipList::search(char * name, int mode) {
    this->mem[0] = this->mem[1] = this->mem[2] = this->first;
    Node *node = this->first;
    Node *next_node = node;
    while (node->get_top() != nullptr) {
        next_node = node->get_top();
        if (strcmp(name, next_node->get_data()) <= 0) {
            break;
        }
        node = next_node;
        this->mem[2] = node;
        this->mem[1] = node;
        this->mem[0] = node;
    }
    if (strcmp(name, next_node->get_data()) == 0 && mode == 0) {
        std::cout << "Ticket already reserved for " << name << "!\n";
        return mode;
    } else {
        while (node->get_mid() != nullptr) {
            next_node = node->get_mid();
            if (strcmp(name, next_node->get_data()) <= 0) {
                break;
            }
            node = next_node;
            this->mem[1] = node;
            this->mem[0] = node;
        }
        if (strcmp(name, next_node->get_data()) == 0 && mode == 0) {
            std::cout << "Ticket already reserved for " << name << "!\n";
            return mode;
        } else {
            while (node->get_bot() != nullptr) {
                next_node = node->get_bot();
                if (strcmp(name, next_node->get_data()) <= 0) {
                    break;
                }
                node = next_node;
                this->mem[0] = node;
            }
            if (strcmp(name, next_node->get_data()) == 0) {
                if (mode == 0) {
                    std::cout << "Ticket already reserved for " << name << "!\n";
                }
                return mode;
            } else {
                return !mode;
            }
        }
    }
}

void SkipList::remove(char *name) {
    if (this -> size == 0){
        std::cout << "The list is empty!\n";
        return;
    }
    int chk = search(name, 1);
    if (chk == 0) {
        std::cout << "Error 404 (name not found)!\n";
        return;
    }
    Node * to_delete = this -> mem[0] -> get_bot();
    int level = to_delete -> get_level();
    if (level >= 3){
        this -> mem[2] -> set_top(to_delete -> get_top());
    }
    if (level >= 2){
        this -> mem[1] -> set_mid(to_delete -> get_mid());
    }
    if (level >= 1){
        this -> mem[0] -> set_bot(to_delete -> get_bot());
    }
    delete to_delete;
    this -> size -= 1;
    std::cout << "Removed reservation for " << name << "\n";
}
