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
         
        if (cur == nullptr)
        {
            return nullptr;
        }
        
        if (tail == cur)
        {
            delete_last_node();
            return tail; 
        }
        if (head == cur)
        {
            delete_first_node();
            return nullptr; 
        }
        
        
		clsNode<T>* ret = cur->prev;
		
        ret->next = cur->next;

        if (cur->next != nullptr)
        {
            cur->next->prev = ret;
        }
                
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
  
    while (cur != nullptr)
    {
       if (cur->value == Value)
       {
         cur = delete_and_link(cur);

           if (cur->next == nullptr)
            {
                tail = cur;
                return;
            }
    
       }
       
              cur = cur->next;
    }

}

/*Problem #8: Delete even positions
● Given a list, delete all nodes at even positions (2, 4, 6, etc)
● E.g. {1, 2, 3, 4, 10} ⇒ {1, 3, 10}
● E.g. {1, 2, 3, 4, 5, 6} ⇒ {1, 3, 5}
● Note: positions NOT values
● void delete_even_positions()*/

void Delete_even_positions(){

    if (length <= 1)
    {
        return;
    }
    
    clsNode<T>* cur = head->next;

    while (cur)
    {
        cur = delete_and_link(cur);
        
        if (cur->next == nullptr)
        {
           return;
        }
        
        cur = cur->next->next;
    }
    
}

/*Problem #9: Delete odd positions
● Given a list, delete all nodes at odd positions (1, 3, 5, etc)
● E.g. {1, 2, 3, 4, 10} ⇒ {2, 4} 
● E.g. {1, 2, 3, 4, 5, 7} ⇒ {2, 4, 7}
● Note: positions NOT values
● void delete_odd_positions()*/

void Delete_odd_positions(){
     
    if (length == 0)
    {
        return;
    }
    if (length == 1)
    {
        delete_first_node();
        return;
    }
    
    
    clsNode<T>* cur = head->next->next;

    while (cur)
    {
        cur = delete_and_link(cur);
        
        if (cur->next == nullptr)
        {
           break;
        }
        
        cur = cur->next->next;
    }
    
    delete_first_node();

}

/*Problem #10: Is Palindrome
● A palindrome number is read the same backward as forward (1221, 131, 0)
● Implement: bool is_palindrome()
● It returns true if the current linked list is palindrome
● {1, 2, 2, 1} ⇒ True*/
bool is_palindrome(){

    if (length == 0)
    {
        return false;
    }
    if (length == 1)
    {
        return true;
    }

    clsNode<T>* cur = head;
    clsNode<T>* rev = tail;
    int count = length / 2;

     while (count != 0)
     {
        if (cur->value != rev->value)
        {
            return false;
        }
        
        cur = cur->next;
        rev = rev->prev;
        --count;
     }
     
    
    return true;

}

/*Problem #11: Find the middle
● Given a linked list, we would like to find its middle value
    ○ In odd length list, e.g. {1, 2, 3, 4, 5}, the middle value is 3
    ○ In even length list, e.g. {1, 2, 3, 4, 5, 6}, the middle values are {3, 4}. We need 2nd one {4}
● Provide 2 implementations, but consider:
    ○ You can’t iterate on the list more than once!
    ○ Don’t use the length variable!
● First: Use your doubly linked list
● Second: Solve it only with the next pointer. Don’t use the previous
    ○ ~5 lines of code.*/

string find_the_middle1(){
     
     if (head == tail)
     {
        return "";
     }
    
    clsNode<T>* cur = head;
    clsNode<T>* rev = tail;

    while (cur)
    {
       if (cur->next == rev)
       {
         return to_string(cur->value) + " " + to_string(rev->value);
       }

       else if (cur == rev)
       {
         return to_string(cur->value);
       }
       
        cur = cur->next;
        rev = rev->prev;
    }
}

//using only next pointer
//Using tortoise and hare algorithm
string find_the_middle2(){
     
     if (head == tail)
     {
        return "";
     }
    
    clsNode<T>* slow = head;
    clsNode<T>* fast = head;
    clsNode<T>* pre = nullptr;

    while (fast && fast->next)
    {
        pre = slow;
        slow = slow->next;
        fast = fast->next->next;
    } 
    
    if (fast)
    {
       return to_string(slow->value);
    }
    
    return to_string(slow->value) + " " + to_string(pre->value);
}

/*Problem #12: Swap forward with backward
● Given K, find the kth node from forward and backward
    ○ Swap them (address not values)
    ○ For example: for k = 1, we swap head (0x1) and tail (0x3)
    ○ For example: for k = 2, we swap nodes 0x2 and 0x3 ⇒ (6/0x1), (8/0x3), (10/0x2), (15/0x7)
    ○ Trick cases. Think and consider
*/

void swap_two_nodes(clsNode<T>* node1, clsNode<T>* node2){
    
    if (!node1 || !node2)
    {
        return;
    }
    
     clsNode<T>* tmp = node1->next; 
     
     node1->next->prev = node2;
     node2->next->prev = node1;
     node1->prev->next = node2;
     node2->prev->next = node1;   

     node1->next = node2->next;
     node2->next = tmp;

     tmp = node1->prev;

     node1->prev = node2->prev;
     node2->prev = tmp;

}

void swap_two_neighbor_nodes(clsNode<T>* node1, clsNode<T>* node2){
    
    if (!node1 || !node2)
    {
        return;
    }
    
     clsNode<T>* tmp = node1->prev; 

     node1->prev->next = node2;
     node2->next->prev = node1;   

     node1->prev = node2;
     node1->next = node2->next;

     node2->prev = tmp;
     node2->next = node1;

}

void swap_head_and_tail(){

     if (head == tail)
    {
        return;
    }

    clsNode<T>* tmp = head->next; 
    clsNode<T>* old_head = head;

    head->next->prev = tail;
    tail->prev->next = head;
    head->prev = tail->prev;
    head->next = nullptr;
    tail->next = tmp;
    tail->prev = nullptr; 

    head = tail;
    tail = old_head;

}


void swap_forward_with_backward(int k){

    if (head == tail)
    {
        return;
    }

    if (k > length)
    {
        return;
    }

    if (k == 1 || k == length)
    {
       swap_head_and_tail();
       return;
    }

    clsNode<T>* cur = head;
    clsNode<T>* rev = tail;
    int count = k;
    int k_back = length - k +1;
    
    while (count>1)
    {
        cur = cur->next;
        rev = rev->prev;
        --count;
    }
    
    if (cur == rev)
    {
        return;
    }

    if (cur->next == rev)
    {
        swap_two_neighbor_nodes(cur, rev);
        return;
    }
    
    if (rev->next == cur)
    {
        swap_two_neighbor_nodes(rev, cur);
        return;
    }
    
    if (k < k_back)
    {
        swap_two_nodes(cur, rev);
        return;
    }

    if (k > k_back)
    {
         swap_two_nodes(rev, cur);
        return;
    }
     
}

/*Problem #13: Reverse list nodes
● Given a list, reverse all its nodes (addresses)
● E.g. {1, 2, 3, 4, 5} ⇒ {5, 4, 3, 2, 1}
● void reverse()*/

void reverse(){

for (int i = 1; i < length/2; i++)
{
    swap_forward_with_backward(i);
}
};


/*Problem #14: Merge lists
● Assume we have 2 sorted linked lists, of sizes n and m
● We would like to merge them together in O(n+m) but remain sorted
● void merge_2sorted_lists(LinkedList &other)
● E.g. list1 {10,20,30,40,50} and list2 {15,17,22,24,35}
    ○ ⇒ 10 15 17 20 22 24 30 35 40 50
● Consider the different cases!*/

void merge_2sorted_lists(clsDoublyLinkedList * &other){


    if (other->head == nullptr)
    {
        return;
    }

    if (head == nullptr)
    {
        head = other->head;
        tail = other->tail;
        other->head = nullptr;
        other->tail = nullptr;
        return;
    }

    clsNode<T>* cur = head;
    clsNode<T>* other_cur = other->head;
    clsNode<T>* tmp = nullptr;

    while (cur && other_cur)
    {
       if (cur->value >= other_cur->value)
       {
            tmp = other_cur->next;

            other_cur->next = cur;
            other_cur->prev = cur->prev;

            if (cur->prev) {
                cur->prev->next = other_cur;
            } else {
                head = other_cur;
            }
            
            cur->prev = other_cur;
            other_cur = tmp;
       }

       else
       {
        cur = cur->next; 
       }
       
    }

    if (other_cur)
    {
       tail->next = other_cur;
       other_cur->prev = tail;

       tail = other->tail;
    }
    

    other->head = nullptr;
    other->tail = nullptr;
}

};