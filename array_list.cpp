#include <iostream>
#include <cassert>
#include <vector>
#include  <stdexcept>
#include <chrono>  // for high_resolution_clock
#include <fstream>  // for ofstream
#include<cmath>
using namespace std;
using namespace  chrono;

//Here we create the class ArrayList
class ArrayList {
    private:
    int *data;
    int growth = 2;
    int capacity = 1;
    public:
      int size = 0;
      ArrayList(){
        data = new int[capacity];
    }

    ArrayList( vector<int> initial) {
      size = 0;
      capacity = 1024;
      data = new int[capacity];

      for (int e: initial) {
          append(e);
      }
  }
    public:
    int length() {
        return size;
    }

  //1b Adding a destructor
    ~ArrayList() {
        delete[] data;
    }
    public:


    void append(int n) {
        if (size < capacity) {
            data[size] = n;
        } else {
            resize();
            data[size] = n;
        }
        size += 1;
    };
    private:
    void resize(){
        capacity *= growth;
        int *tmp = new int[capacity];
        for (int i=0; i<size; i++) {
            tmp[i] = data[i];
        }
        delete[] data;
        data = tmp;
    }

    public:
    void print(){
         cout << "[";
        for (int i=0; i<size-1; i++){
                     cout << data[i];
             cout << ", ";
        }
         cout << data[size-1] << "]" <<  endl;
    }

    int& operator[](int i){
        if (i>=size){
            throw  out_of_range("index is out of range");
        }
        else{
            return data[i];
        }
    }


       void insert(int index,int val)
       {
           if(index<size)
           {
               if(data[index]==-1)
               {
                   data[index]=val;
               }
               else{
               int id;
               id =data[index];
               data[index]=val;
               int id2;
               for(int i=index+1;i<size; i++)
               {
                   id2 = data[i];
                   data[i]=id;
                   id=id2;
                   if(id==-1)
                   break;
               }
               }
           }
       }

    void remove(int index){
        if (index > size){
            throw  out_of_range("index is out of range");
        }
        else{
            size = size - 1;
            for (int i=index; i<size; i++){
                data[i] = data[i+1];
            }
        }

    }

    int pop(int index){
        int val = data[index];
        remove(index);
        return val;
    }

    int pop(){
        return pop(size-1);
    }

//fikk ikke til shrink_to_fit
};


bool is_prime(int n) {
    if (n == 1) {
        return false;
    }

    for (int d=2; d<n; d++) {
        if (n % d == 0) {
            return false;
        }
    }
    return true;
}


//test funksjon utenfor classen
void test_is_prime(){
    int n=1;
    ArrayList a;
    while(a.length() <10){
        if (is_prime(n)){
            a.append(n);
        }
        n++;
    }
    a.print();
};



//int main(){
//    cout << "Linked Array list - insert front \n";
//    ofstream ofs{"array_list_insert.txt"};
//    if (!ofs) {
//        throw runtime_error("Unable to open file");
//    }
//    for (int N = 100; N < 1E6; N *= 10) {
//        auto start = high_resolution_clock::now();
//        ArrayList ll{};
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
  ArrayList primes({2, 3, 5, 7, 11});
  primes.print();
    primes.insert(4, 2);
    primes.append(99);
    primes.print();
    primes.remove(2);
    primes.print();
    cout << primes.pop() <<  endl;
    return 0;
}
