#include <iostream>
#include <fstream>
#include "SkipList.h"

void menu(){
    std::cout << "\nType:\n1. To reserve a ticket for a person;\n2. To cancel a reservation for a given person;\n";
    std::cout << "3. To check whether a ticket is reserved for a particular person;\n";
    std::cout << "4. To display the passengers;\n0. To quit.\n";
}

void prepopulate(SkipList &sl) {
    std::string fileName = "prep1.txt";
    std::string line;
    std::ifstream fin (fileName);
    if (fin.is_open()) {
        while (getline(fin, line)) {
            sl.insert(const_cast<char *>(line.c_str()), false);
        }
    }
    std::cout << "###########################\n";
    std::cout << "Prepopulated with " << fileName << "\n";
    std::cout << "###########################\n\n\n";
}

int main() {
    SkipList sl;
    char name[20];
    int option;

    // Can be commented
    prepopulate(sl);

    while(true) {
        menu();
        std::cout << ">>>";
        std::cin >> option;
        switch (option) {
            case 1:
                std::cin.get();
                std::cin.getline(name, 20);
                sl.insert(name);
                break;
            case 2:
                std::cin.get();
                std::cin.getline(name, 20);
                sl.remove(name);
                break;
            case 3:
                std::cin.get();
                std::cin.getline(name, 20);
                if (sl.search(name, 1) == 0){
                    std::cout << "Error 404 (name not found)!\n";
                } else {
                    std::cout << "Person has reservation!\n";
                }
                break;
            case 4:
                sl.display();
                break;
            case 0:
                _exit(0);
            default:
                menu();
                break;
        }
    }
}
