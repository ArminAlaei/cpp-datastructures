#include <chrono>  // for high_resolution_clock
#include <fstream>  // for ofstream
#include <iostream>  // for cout
#include <stdexcept>  // for runtime_error
#include <vector>  // for vector (exercise 1f)

using namespace std;
using namespace std::chrono;struct

Node{
  int value;
  Node *next = nullptr;
  Node *prev = nullptr;
  Node(int value) : value(value)
  {
  }
  Node(int value, Node *next) : value(value), next(next)
  {

  }
};


class LinkedList
{
private:
  Node *head = nullptr;
  Node *tail = nullptr;
public:
  LinkedList(){

  }
  void append(int value)
  {
    Node *node = new Node{value};
    if (head==nullptr){
      head = node;
      return;
    }
    Node *current;
    current = head;
    while (current->next){
      current = current->next;
    }
    current->next=node;
  }


  void print() {
      Node* current = head;
      cout << "[";
      while (current->next != nullptr) {
          cout << current->value;
          cout << ", ";
          current = current->next;
      }
      cout << current->value << "]" << endl;
  }

  ~LinkedList() {
    Node* current;
    Node* next;

    current = head;

    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
}


int length() {
    Node* current = head;
    int count = 0;

    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}


int& operator[](int index) {
    return get_node(index)->value;
}
Node* get_node(int index) {
    if (index < 0 or index >= length()) {
        throw range_error("IndexError: Index out of range");
    }

    Node* current = head;
    for (int i=0; i<index; i++) {
        current = current->next;
    }
    return current;
}

void insert(int val, int index) {
  if (index<length()){
    Node* prev = get_node(index-1);
    Node* next = prev->next;
    prev->next = new Node(val, next);
  }

}


void pop() {

  Node* current;
  Node* previous;
  current = head;
  while(current->next!=NULL)
			{
				previous=current;
				current=current->next;
			}
			tail=previous;
			previous->next=NULL;
			delete current;


}
void remove(int pos){
  Node *current;
  Node* previous;
  current = head;
  for(int i=0; i < pos; i++)
    {
       previous=current;
       current=current->next;
    }
    previous->next=current->next;
    delete current;


}

int pop(int pos){
    int val = pos;
    remove(pos);
    return val;
}

};


//int main(){
//    cout << "Linked Array list - insert front \n";
//    ofstream ofs{"linked_list_insert.txt"};
//    if (!ofs) {
//        throw runtime_error("Unable to open file");
//    }
//    for (int N = 100; N < 1E6; N *= 10) {
//        auto start = high_resolution_clock::now();
//        LinkedList ll{};
//        for (int i = 0; i < N; i++) {
//            ll.insert(i, 0);
//        }
//
//        auto stop = high_resolution_clock::now();
//        auto duration = duration_cast<microseconds>(stop - start);
//        cout << N << " " << duration.count() / (double) N << "\n";
//        ofs << N << " " << duration.count() / (double) N << "\n";
//    }
//    return 0;
//}


int main(){
  LinkedList ll{};
  ll.append(2);
  ll.append(3);
  ll.append(1);
  ll.print();

  ll.insert(77,2);
  ll.print();
  cout<< ll.pop(2) <<endl;
  ll.remove(2);
  ll.print();
  ll.pop();
  ll.print();
  return  0;
}
