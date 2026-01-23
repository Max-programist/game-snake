#include <iostream>
#include <vector>


struct list {
  int x;
  int y;
  struct list *next;
};

class MyList {
private:
  struct list *head;
  struct list *create_elem(int x, int y) {
    struct list *result = (struct list *)malloc(sizeof(struct list));
    result->x = x;
    result->y = y;
    result->next = NULL;
    return result;
  }
  void swap(struct list *node1, struct list *node2) {
    int temp = node1->x;
    node1->x = node2->x;
    node2->x = temp;
    temp = node1->y;
    node1->y = node2->y;
    node2->y = temp;
  }

public:
  bool check_game_over();
  int get_x_front();
  void sort();
  int pop_back();
  void free_list();
  void remove(int x, int y);
  void add_back(int x, int y);
  void add_front(int x, int y);
  void show();
  int size();
  bool find(int x, int y);
  void draw_snake_on_map(std::vector<std::vector<char>> &arr, char name);
  std::pair<int, int> get_data();
  MyList();
  MyList(const MyList& my_list);
  ~MyList();
};


