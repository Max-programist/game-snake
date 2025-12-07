#include <iostream>
#include <vector>
#include "list.h"


std::vector<std::vector<char>> create() {
    std::vector<std::vector<char>> arr = {};
    for(int i = 0; i < 20; i++) {
        arr.push_back(std::vector<char>());
        for(int j = 0; j < 20; j++) {
            arr[i].push_back('.');
        }
    }
    return arr;
}

void print(const std::vector<std::vector<char>>& arr) {
    
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }

}


void border(std::vector<std::vector<char>>& arr) {
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            if(i == 0 || i == 19 || j == 0 || j == 19)  {
                arr[i][j] = 'x';
           }
        }
    }
}

int main() {
    std::vector<std::vector<char>> arr = create();
    border(arr);
    print(arr);


    MyList example;

    return 0;
}