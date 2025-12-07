#include <iostream>

struct list {
  int x;
  int y;
  struct list *next;
};

class MyList {
private:
  struct list *head;
  struct list *create_elem(int elem) {
    struct list *result = (struct list *)malloc(sizeof(struct list));
    result->x = elem;
    result->next = NULL;
    return result;
  }
  void swap(struct list *node1, struct list *node2) {
    int temp = node1->x;
    node1->x = node2->x;
    node2->x = temp;
  }

public:
  void sort();
  void pop_back();
  void free_list();
  void remove(int elem);
  void add_back(int elem);
  void add_front(int elem);
  void show();
  int size();
  bool find(int x, int y);
  MyList();
  ~MyList();
};

bool find_elem(struct list *node, int elem);
int size_list(struct list *head);
