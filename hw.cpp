#include <iostream>
#include "list.h"


int main() {
    MyList example;
    int g = 0;
    for(; g != -1;) {
        std::cin >> g;
        if(g != -1) {
            example.add_back(g, 0);
        }
    }
    std::cout << example.pop_back() << " " << example.get_x_front() << "\n";
   
    return 0;
}