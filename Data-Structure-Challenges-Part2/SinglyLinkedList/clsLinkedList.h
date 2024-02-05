#pragma once
#include <iostream>
#include "clsNode.h"

using namespace std;

template <class T>
class clsLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int length = 0;

public:

int get_Lengh(){

    return length;
}

T get_Head(){

    return head->value;
}

T get_Tail(){
     return tail->value;
}


void print(){

    Node<T>* temp = head;

    while(temp != nullptr){

        cout << temp->value << " ";
        temp = temp->next;

    }

    cout << "\n";

}

/*Problem #1: Insert end
● Implemented insert_end function */

void insert_end(T Value) {
    Node<T>* new_Node = new Node<T>(Value); 

    if (head == nullptr && tail == nullptr) {
        head = tail = new_Node;
        new_Node->next = nullptr;
    } else {
        tail->next = new_Node;
        new_Node->next = nullptr;
        tail = new_Node;
    }

    length++;
}


/*Problem #2: Get_nth item
● Let’s implement: Node* get_nth(int n)
○ The function get the nth node. If not found, it returns NULL
○ Below: get_nth(4) return Node with value 15
*/

Node<T>* get_nth(int pos){
   
   if(pos < 1 || pos > length)
       return NULL;
   
   Node<T>* tmp = head;
   int counter = 1;

   while (tmp != nullptr || counter < pos)
   {
      
       tmp = tmp->next;

       if(++counter == pos){
         return tmp;
       }
   
   }

   return NULL;
}

/*Problem #3: Search item
● Similarly, we can return 0-based index of a node with specific value
● Here: list.search(15) ⇒ 3
list.search(99) ⇒ -1
*/

int search(T Value){

    Node<T>* current = head;
    int counter = 0;

    while(current != nullptr){

        if(current->value == Value){
           
           return counter;
        }
        
        counter++;
        current = current->next;
    }

     return -1;
}

int search_improved_v2(T Value) {

   Node<T>* current = head;
   Node<T>* prev = head;
    int counter = 0;

    while(current != nullptr){
         
        
        if(current->value == Value){
           
           swap(prev->value, current->value);
           return counter;
        }
        
        counter++;
        prev = current;
        current = current->next;
    }

     return -1;
		
}


/*Problem #4: Insert front
● We implemented insert_end in the lecture
● We want to be able to insert front */

void insert_front(){
    

}

/*Problem #5: Delete front
● The opposite of insert front*/

void delete_front(){

}

/*Problem #6: Get nth from back
● We already implemented Node* get_nth(int n)
● Now implement: Node* get_nth_back(int n)
● Given 1-based position, find it from the back
● E..g. if list is 1 2 3 4 5 6
● get_nth_back(1) should point to node with value 6*/

get_nth_back(int n){

}

/*Problem #5: Is Same list’s data?
● Develop function to check if lists
are data-equal:
○ Same length - each node and its
corresponding one has same value
○ bool is_same(const LinkedList
&other)
● Provide 2 codes
○ One code assumes a variable
length is maintained
That tells us how many nodes so far
■ E.g. in each insert, length is increased
○ Another that doesn’t use it and don’t compute length*/


/*Problem #1: Destructor
● Our code used to create dynamic data, but never released
● This creates a memory leak
● Implement destructor: ~LinkedList()
● It should free all the created nodes*/
~clsLinkedList(){

}

};