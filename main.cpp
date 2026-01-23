#include <iostream>
#include <vector>
#include "list.h"


std::vector<std::vector<char>> create() {
    std::vector<std::vector<char>> map = {};
    for(int i = 0; i < 20; i++) {
        map.push_back(std::vector<char>());
        for(int j = 0; j < 20; j++) {
            map[i].push_back('.');
        }
    }
    return map;
}

void print(const std::vector<std::vector<char>>& map) {
    
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }

}


void make_border(std::vector<std::vector<char>>& map) {
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            if(i == 0 || i == 19 || j == 0 || j == 19)  {
                map[i][j] = 'x';
           }
        }
    }
}

void clean_map(std::vector<std::vector<char>>& map) {
    for(int i = 0; i < 20; i++) {
        for(int j = 0; j < 20; j++) {
            map[i][j] = '.';
        }
    }

}
// 0 . . . . . . . . . 
// 0 . . . . . . . . . 
// 0 x x x x x x . . . 
// 0 x . . . . x . . . 
// 0 x . . . . x . . . 
// 0 x . . . . x . . . 
// 0 x . . . . x . . . 
// 0 x . . . . x . . . 
// 0 x . . . . x . . . 
// 0 x x x x x x . . . 
// 0 0 0 0 0 0 0 0 0 0
bool dead_snake(const MyList &snake) {
//snake + make_border;
    MyList temp(snake);

    std::pair<int, int> res = temp.get_data();
    if(res.first == 0 || res.second == 0 || res.first == 19 || res.second == 19) {
        return 1;

    }


    return temp.check_game_over();
}


// 1. print_apple_to_map
// 2. add_front  
// 3. make_rand_apple
// 4. finish for the game

int main() {
    char o_on_map = 'o';
    char a_on_map = 'a';
    std::vector<std::vector<char>> map = create();
    make_border(map);
    MyList snake;
    snake.add_front(5, 6);
    snake.add_front(6, 6);
    snake.add_front(7, 6);
    snake.add_front(8, 6);
    snake.add_front(9, 6);
    snake.add_front(10, 6);
    snake.add_front(11, 6);
    snake.add_front(12, 6);
    snake.draw_snake_on_map(map, o_on_map);
    MyList apples;
    apples.add_front(6, 15);
    apples.draw_snake_on_map(map, a_on_map);
    snake.show();
 
    print(map);

// e - left; r - right; d - down;f - up
    for(; ;) {
        if(dead_snake(snake) == 1) {
            break;
        }
        char c = getchar();
        std::cout << "log getchar " << c << "\n";
        if(c == 'q') {

            break;    
            
        } else if(c == '\n') {
        } else if(c == 'r') {
            std::pair<int, int> head = snake.get_data();
            head.second += 1;
            snake.add_front(head.first, head.second);
            snake.pop_back();
        } else if(c == 'w') {
            std::pair<int, int> head = snake.get_data();
            head.first -= 1;
            snake.add_front(head.first, head.second);
            snake.pop_back();   
        } else if(c == 'e') {
            std::pair<int, int> head = snake.get_data();
            head.second -= 1;
            snake.add_front(head.first, head.second);
            snake.pop_back();
        
        } else if(c == 'd'){
            std::pair<int, int> head = snake.get_data();
            head.first += 1;
            snake.add_front(head.first, head.second);
            snake.pop_back(); //FIIX MEEEEEEEEEEEEEEEEEEEEEEEEE
            
        }
        snake.show();
        clean_map(map);
        make_border(map);
        snake.draw_snake_on_map(map, o_on_map);
        apples.draw_snake_on_map(map, a_on_map);
        print(map);
    }

    return 0;
}
