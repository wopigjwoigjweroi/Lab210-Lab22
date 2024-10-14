// COMSC-210 | Lab-22 | Jeremiah Ortiz
#include <iostream>
using namespace std;

class DoublyLinkedList {
private:

struct Node {
int data;

Node* prev;

Node* next;

Node(int val, Node* p = nullptr, Node* n = nullptr) {
  
  data = val;
  
  prev = p;
  
  next = n;
  }
};
Node* head;
Node* tail;

  public:

DoublyLinkedList() { head = nullptr; tail = nullptr; }

void push_back(int value) {
Node* newNode = new Node(value);
  if (!tail) 
head = tail = newNode;
else {
tail->next = newNode;
newNode->prev = tail;
tail = newNode;
}
}

void push_front(int value) {
Node* newNode = new Node(value);
  
  if (!head) 
head = tail = newNode;
else {
newNode->next = head;
head->prev = newNode;
head = newNode;
  }
}

void delete_val(int value) {
  
  if (!head) return; // Empty list
  Node* temp = head;
  while (temp && temp->data != value)
  
  temp = temp->next;
  
if (!temp) return; // Value not found
  
if (temp->prev) {
  
  temp->prev->next = temp->next;
  
} else {
  
  head = temp->next; // Deleting the head
}
  
if (temp->next) {
  
  temp->next->prev = temp->prev;
} else {
  
  tail = temp->prev; // Deleting the tail
}
  
  delete temp;
}

void delete_pos(int position) {

  if (!head) {
    
      return; 
  }

  Node* temp = head; 

  for (int i = 0; i < position && temp); ++i) {

    temp = temp->next; 
  }

  if (!temp) {

      return; 
  }

  if (temp->prev) {

      temp->prev->next = temp->next; 
  } else {

    head = temp->next; 
  }

  if (temp->next) {

    temp->next->prev = temp->prev; 
  } else {

    tail = temp->prev; 
  }

  delete temp; 
}



void pop_front() {

if (!head) {
  
  return; 
}

  Node* temp = head; 

  head = head->next; 

  if (!head) {

    head->prev = nullptr; 
    
  } else {

    tail = nullptr; 
  }

  delete temp;

}

void pop_back() {

    Node* temp = tail; 

    tail = tail->prev; 

    if (tail) {

        tail->next = nullptr; 
    } else {
      
        head = nullptr; 
    }
  
    delete temp;   
} 

void print() {
  
Node* current = head;
  
if (!current) return;
  
while (current) {
  
  cout << current->data << " ";
  
  current = current->next;
}
  
cout << endl;
}

void print_reverse() {
  
  Node* current = tail;
  if (!current) return;
  
while (current) {
  
  cout << current->data << " ";
  
  current = current->prev;
}
  
  cout << endl;
}



~DoublyLinkedList() {
  
  while (head) {
    
  Node* temp = head;
    
  head = head->next;
  
  delete temp;
    
  }
  
}

};

int main() {
  
  DoublyLinkedList list;

  list.push_back(10); 
  list.push_back(20); 
  
  list.push_back(30);
  list.push_bacl(40); 

  
return 0;
}
