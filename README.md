




For compilation of the code used the following command in terminal:

>>> c++ filename.cpp -o nickname -std=c++11
>>> ./nickname

For each file:
c++ array_list.cpp -o array -std=c++11
./array

c++ linked_list.cpp -o linked -std=c++11
./linked


c++ circular_linked_list.cpp -o sirkel -std=c++11
./sirkel






Answer to 4g:
If n = 67 and k = 7 then person at position 61 is the last survivor.

Get element 𝑖 by index:

Dynamic Array;
Because arrays are contiguous in memory, accessing any element by index is trivial
The cost in big O notation will be O(1)

Linked;
In linked lists nodes are not stored contiguous in memory. They are stored in
completely different places in the memory. The cost here depends on the size of
the list so it will be O(n).


Insert at front:
Dynamic Array;
To insert an element at the front of a dynamic array, we would need to first make space for it, by moving every other element in the list one index up. This operation would require the existing 𝑛 elements, which would cost O(n). The total cost would be O(n)+O(1)=O(n)
Linked;
This method is just as simple if there is 0 elements in the list, or 10, or a million. No matter the size of the list it is only a few operations, and so the cost is O(1)

Insert at back (aka append):
Dynamic Array;
For a dynamic array, appending an element is the same as assign that value to the first unused element of the underlying storage array. The cost is independent of the size of the array. The cost is O(1).
Linked;
Because we are iterating from the head of the list, all the way to the end, we are doing 𝑛 operations. If the list consists of 100 nodes, the loop needs to run 100 times. The complete append method costs O(n).

Insert into middle of list:
Dynamic Array;
To insert somewhere in the middle of the list, the situation is slightly better than adding to the front, as we only have to move all the elements with indices above it to make room. The cost will be O(n) or O(n-i).
Linked;
For a linked list, the insertion of a new node itself is not very costly, we only need to create a new node and hook it into the chain. The insertion itself would only cost O(1). The cost is O(n).

Remove element from front:
Dynamic Array;

Linked;

Remove element from back:
Dynamic Array;

Linked;


Remove element from middle:
Dynamic Array;

Linked;

Print:
Dynamic Array;

Linked;
