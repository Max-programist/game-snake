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

void clean_map(std::vector<std::vector<char>>& arr) {
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            arr[i][j] = '.';
        }
    }

}


int main() {
    std::vector<std::vector<char>> arr = create();
    border(arr);
    MyList example;
    example.add_front(6, 6);
    example.add_front(7, 6);
    example.add_front(8, 6);
    example.draw_snake(arr);
    print(arr);

// e - left; r - right; d - down;f - up
    for(; ;) {
        char c = getchar();
        std::cout << "log getchar " << c << "\n";
        if(c == 'q') {

            break;    
            
        } else if(c == '\n') {
        }
        else if(c == 'e') {
        } else{
            std::pair<int, int> head = example.get_data();
            head.first += 1;
            example.add_front(head.first, head.second);
            example.pop_back(); //FIIX MEEEEEEEEEEEEEEEEEEEEEEEEE
            
            example.show();
       }
       clean_map(arr);
       border(arr);
       example.draw_snake(arr);
       print(arr);
    }

    return 0;
}