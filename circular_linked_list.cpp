#include <iostream>  // for cout
#include <stdexcept>  // for runtime_error


using namespace std;

struct
Node{
  int value;
  Node *next=nullptr;
  Node(int value) : value(value)
  {
  }
  Node(int value, Node *next) : value(value), next(next)
  {

  }
};


class CircLinkedList
{
private:
  Node *head = nullptr;
public:
  CircLinkedList(){

  }
  void append(int value)
  {
    Node *node = new Node{value};
    if (head==nullptr){
      head = node;
      node -> next=head;
      return;
    }
    Node *current;
    current = head;
    while (current->next != head){
      current = current->next;
    }
    current->next=node;
    node -> next = head;
  }




       void print() {
           Node* current = head;
           cout << "[";
           while (current->next != head) {
               cout << current->value;
               cout << ", ";
               current = current->next;
           }
           cout << current->value << "]" << endl;
       }

       int& operator[](int index) {
           return get_node(index)->value;
       }
       Node* get_node(int index) {

           Node* current = head;
           for (int i=0; i<index; i++) {
               current = current->next;
           }
           return current;
       }


};

int main(){

  CircLinkedList clist;
clist.append(0);
clist.append(2);
clist.append(4);
cout<< clist[1] <<endl;
clist.print();

return 0;
}
