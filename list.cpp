#include "list.h"


MyList::~MyList() {
  free_list();
  std::cout << "Gabella \n";
};

MyList::MyList() {
  head = NULL;
  std::cout << "Dosvidos \n";
};

MyList::MyList(const MyList& my_list) {//test me
  head = create_elem(my_list.head->x, my_list.head->y);
  struct list* c_head = head;

  struct list* temp = my_list.head;
  temp = temp->next;
  for(; temp != NULL;) {
    
    c_head->next = create_elem(temp->x, temp->y);
    c_head = c_head->next;
    temp = temp->next;
  }
  std::cout << "SPPDA{WK}  \n";
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
void MyList::remove(int x, int y) {
  struct list *temp = head;
  struct list *prev = NULL;
  for (; temp != NULL;) {
    if ((*temp).x == x && (*temp).y == y) {
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

void MyList::add_back(int x, int y) {
  struct list *node = create_elem(x, y);
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

void MyList::add_front(int x, int y) {
  struct list *node = create_elem(x, y);
  if (head == NULL) {
    head = node;
  } else {
    node->next = head;
    head = node;
  }
}

void MyList::sort() {
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
int MyList::pop_back() {
  struct list* temp = head;
  struct list* prev = NULL;
  if(head != NULL) {
    for(; temp->next != NULL;) {
      prev = temp;
      temp = temp->next;
    }
  }
  prev->next = NULL;
  int result = temp->x;
  free(temp);
  return result;
}

void MyList::draw_snake(std::vector<std::vector<char>> &arr) {
  struct list *temp = head;
  for(; temp != NULL; temp = temp->next) {
    std::cout << temp->x << temp->y << "log draw_snake \n";
    arr[temp->x][temp->y] = 'o';
  }
}


int MyList::get_x_front() {
  if(size() == 0) {
    return -1;
  }
  return head->x;

} 

std::pair<int, int> MyList::get_data() {
  std::pair<int, int> result{};
  result.first = head->x;
  result.second = head->y;

  return result;
}

bool MyList::check_game_over() {
  sort();
  bool res = false;
  struct list* temp = head;
  for(; temp != NULL;) {
    if(temp->x == temp->next->x && temp->y == temp->next->y ) {
      res = true;
    }
  }
  return res;
}