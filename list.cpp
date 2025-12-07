#include "list.h"

MyList::~MyList() {
  free_list();
  std::cout << "Gabella \n";
};

MyList::MyList() {
  head = NULL;
  std::cout << "Dosvidos \n";
};

bool MyList::find(int x, int y) {
  bool flag = false;
  struct list *temp = head;
  for (; temp != NULL;) {
    if(x == temp->x && y == temp->y) {
      flag = true;
    }
    temp = temp->next;
  }

  return flag;
}

int MyList::size() {
  struct list *temp = head;
  int counter = 0;
  for (; temp != NULL; counter++) {
    temp = temp->next;
  }
  return counter;
}

void MyList::free_list() {
  for (; head != NULL;) {
    struct list *temp = head;
    head = head->next;
    free(temp);
  }
}
void MyList::remove(int elem) {
  struct list *temp = head;
  struct list *prev = NULL;
  for (; temp != NULL;) {
    if ((*temp).x == elem) {
      if (prev != NULL) {
        prev->next = temp->next;
      } else {
        head = temp->next;
      }
      free(temp);
      temp = NULL;
      break;
    }
    prev = temp;
    if (temp != NULL) {
      temp = temp->next;
    }
  }
}

void MyList::add_back(int elem) {
  struct list *node = create_elem(elem);
  if (head == NULL) {
    head = node;
  } else {
    struct list *temp = head;
    for (; temp->next != NULL;) {
      temp = temp->next;
    }
    temp->next = node;
  }
}

void MyList::show() { // 100 21 377 NUll
  struct list *temp = head;
  for (; temp != NULL;) {
    std::cout << temp->x << ";" << temp->y << "->";
    temp = temp->next;
  }
  std::cout << "NULL" << std::endl;
}

void MyList::add_front(int elem) {
  struct list *node = create_elem(elem);
  if (head == NULL) {
    head = node;
  } else {
    node->next = head;
    head = node;
  }
}

void MyList::sort() {// FIX ME
  struct list *temp = head;
  for (; temp != NULL;) {
    for (struct list *needle = temp->next; needle != NULL;
         needle = needle->next) {
      if ((*temp).x < needle->x) {
        swap(temp, needle);
      }
    }
    temp = temp->next;
  }
}
// 1 - find;;  2 - link;;yy 
void MyList::pop_back() {
  struct list* temp = head;
  struct list* prev = NULL;
  if(head != NULL) {
    for(; temp->next != NULL;) {
      prev = temp;
      temp = temp->next;
    }
  }
  prev->next = NULL;
  free(temp);
}
