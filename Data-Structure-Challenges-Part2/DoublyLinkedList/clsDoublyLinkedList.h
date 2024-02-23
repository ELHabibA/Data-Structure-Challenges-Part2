#pragma once
#include <iostream>
#include "clsNode.h"

using namespace std;

template <class T>
class clsDoublyLinkedList
{
private:

    clsNode<T>* head;
    clsNode<T>* tail;
    int length = 0;

public:


int get_Length(){

    return length;
}

T get_head(){

    return head->value;
}

T get_tail(){
     return tail->value;
}


void print(){

    clsNode<T>* temp = head;

    while(temp != nullptr){

        cout << temp->value << " ";
        temp = temp->next;

    }

    cout << "\n";

}


/*Problem #1: Insert end
● Implemented insert_end function */

void insert_end(T Value) {
    clsNode<T>* new_Node = new clsNode<T>(Value); 

    if (head == nullptr && tail == nullptr) {
        head = new_Node;
        tail = new_Node;
        new_Node->next = nullptr;
        new_Node->prev = nullptr;
    } 
    
    else {
        
        tail->next =  new_Node;
        new_Node->next = nullptr;
        new_Node->prev = tail;
        tail = new_Node;
    }

    length++;
}


/*Problem #2: Insert front
● Implemented insert_front function */

void insert_front(T Value) {
    clsNode<T>* new_Node = new clsNode<T>(Value); 

    if (head == nullptr && tail == nullptr) {
        head = new_Node;
        tail = new_Node;
        new_Node->next = nullptr;
        new_Node->prev = nullptr;
    } 
    
    else {
        
        new_Node->next = head;
        new_Node->prev = nullptr;
        head = new_Node;
    }

    length++;
}

/*Problem #3: Insert sorted
● Implement: void insert_sorted(T value)
● It will always insert the value in position so that list is sorted
● Let’s insert values: 10 2 30 4 1
● insert(10) ⇒ {10}
● insert(2) ⇒ {2, 10}
● insert(30) ⇒ {2, 10, 30}
● insert(4) ⇒ {2, 4, 10, 30}
● insert(1) ⇒ {1, 2, 4, 10, 30}*/

void insert_sorted(T Value){

    if (head == nullptr || head->value >= Value)
    {
        insert_front(Value);
    }
    
    else {

     clsNode<T> * new_Node = new clsNode<T>(Value);
     clsNode<T> * cur = head->next;

    while (cur)
    {
        if (cur->value >= Value)
        {
            new_Node->prev = cur->prev;
            cur->prev->next = new_Node;
            new_Node->next = cur;
            ++length;
            return;
        }

        cur = cur->next;
    }

     insert_end(Value);
    
   } 
}

/*Problem #4: delete first node
● Implemented delete_first_node function */

void delete_first_node(){

if(head != nullptr){

    clsNode<T>* tmp = head;
    
    head->next->prev = nullptr;
    
    head = head->next;

    delete tmp;

    if(head == nullptr)
       tail = head;

    --length;
}
}

/*Problem #5: delete last node
● Implemented delete_last_node function */

void delete_last_node(){
    
    if(head == nullptr){
    return;
    }

    if(length == 1){
        delete_first_node();
        return;
    }

    clsNode<T>* tmp = tail;
    
 
    tail->prev->next = nullptr;

    tail = tail->prev;

    delete tmp;

    --length;
}

/*Problem #6: delete and link
● remove given node, and connect its neighbors*/

clsNode<T>* delete_and_link(clsNode<T>* cur) {
        
        if (tail == cur)
        {
            delete_last_node();
        }
        if (head == cur)
        {
            delete_first_node();
        }
        
        
		clsNode<T>* ret = cur->prev;
		
        ret->next = cur->next;
        cur->next->prev = ret;
        
        --length;
		return ret;
}


/*Problem #7: delete node with key
● remove the node with the given key*/

void delete_node_with_key(T Value){

    if (length == 0)
    {
        return;
    }
    
    if (head->value == Value)
    {
        delete_first_node();
    }
    
	clsNode<T>* cur = head;
  
    while (cur)
    {
       if (cur->value == Value)
       {
         cur = delete_and_link(cur);

           if (cur->next == nullptr)
            {
                tail = cur;
            }
    
       }
       
              cur = cur->next;
    }

}

};