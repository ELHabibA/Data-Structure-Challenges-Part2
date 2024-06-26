#pragma once
#include <iostream>
#include "Node.h"

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

void delete_first_node(){

if(head != nullptr){

    Node<T>* new_Node = head->next;

    delete head;
    
    head = new_Node;

    if(head == nullptr)
       tail = head;

    --length;
}
}

void delete_last_node(){

    if(length == 1){
        delete_first_node();
        return;
    }

    Node<T>* new_Node = head;
    
    while (new_Node->next->next != nullptr)
    {
       new_Node = new_Node->next;
    }

    delete new_Node->next;

    tail = new_Node;
    
    tail->next = nullptr;

    --length;
}

void delete_nth(int n){
    
    if (n < 1 || n > length)
    {
       return;
    }

    if(n == length){

      delete_last_node();

      return;  

    }

    if(n == 1){

      delete_first_node();

      return;  

    }
    
    int counter = 1;
    Node<T>* new_Node = head;
    
    while (counter < --n)
    {
       new_Node = new_Node->next;
       ++counter;
    }
    
    Node<T>* tmp = new_Node->next->next;

    delete new_Node->next;

    new_Node->next = tmp;
    
    

    --length;
}


/*Problem #1: Insert end
● Implemented insert_end function */

void insert_end(T Value) {
    Node<T>* new_Node = new Node<T>(Value); 

    if (head == nullptr && tail == nullptr) {
        head = new_Node;
        tail = new_Node;
        new_Node->next = nullptr;
    } else {
        
        Node<T> * cur = head;

        while (cur->next != nullptr)
        {
            cur = cur->next;
        }

        cur->next = new_Node;
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

void insert_front(T Value){
    Node<T>* current = new Node<T>(Value);

    current->next = head;

    head = current;

    if (length == 1)
    {
        tail = head;
    }
    

    length++;
   
}

/*Problem #5: Delete front
● The opposite of insert front*/

void delete_front(){
    
    Node<T>* tmp = head->next;

    delete head;

    head = tmp;

    length--;
}

/*Problem #6: Get nth from back
● We already implemented Node* get_nth(int n)
● Now implement: Node* get_nth_back(int n)
● Given 1-based position, find it from the back
● E..g. if list is 1 2 3 4 5 6
● get_nth_back(1) should point to node with value 6*/

Node<T>* get_nth_back(int n){

    if(n < 1 || n > length)
       return NULL;

    int pos = (length - n) +1;
    int counter = 1;

     Node<T>* tmp = head;

     while (tmp != nullptr)
     { 
        tmp = tmp->next;
        counter++;
        if(counter == pos){
           return tmp;
        }
     }

     
     return NULL;

}

/*Problem #7: Is Same list’s data?
● Develop function to check if lists
are data-equal:
    ○ Same length - each node and its
corresponding one has same value
    ○ bool is_same(const LinkedList &other)
● Provide 2 codes
    ○ One code assumes a variable
length is maintained
That tells us how many nodes so far
■ E.g. in each insert, length is increased
    ○ Another that doesn’t use it and don’t compute length*/

bool is_same(const clsLinkedList &other){

if((length != other.length))
      return false;

  Node<T>* tmp1 = head;
  Node<T>* tmp2 = other.head;

while (tmp1 != nullptr)
{
    if(tmp1->value != tmp2->value){
        return false;
    }

    tmp1 = tmp1->next;
    tmp2 = tmp2->next;
}

return true;

}

bool is_same_without_length(const clsLinkedList &other){

  Node<T>* tmp1 = head;
  Node<T>* tmp2 = other.head;

while (tmp1 != nullptr && tmp2 != nullptr)
{
    if(tmp1->value != tmp2->value){
        return false;
    }
    
    tmp1 = tmp1->next;
    tmp2 = tmp2->next;

}

return !tmp1 && !tmp2;

}



/*Problem #8: Delete with key
● Given a list, delete the first node with the given key value
● E.g. {1, 2, 3, 4, 2, 6}, key = 2 ⇒ {1, 3, 4, 2, 6}
● void delete_node_with_key(int value)*/

void delete_node_with_key(T Value){

    if (head == nullptr) {
        return;
    }

    if(head->value == Value){
        delete_first_node();
        return;
    }

    Node<T>* cur = head;
    Node<T>* tmp; 

    while (cur->next != nullptr)
    {
        if (cur->next->value == Value)
        {
            tmp = cur->next;
            cur->next = cur->next->next;
            
            delete tmp;

            --length;

            return;
        }
        
        cur = cur->next;

        if (cur->next->next == nullptr)
        {
            tail = cur;
        }
        
    }

    if (cur->value == Value)
    {
        delete_last_node();
    }

}

/*Problem #9: Swap each pair vales
● Given a list, swap each 2 consecutive values
● E.g. {1, 2, 3, 4} ⇒ {2, 1, 4, 3}
● E.g. {1, 2, 3, 4, 5} ⇒ {2, 1, 4, 3, 5}
● void swap_pairs()*/

void swap_pairs() {		

 Node<T>* cur = head;

 while (cur && cur->next)
 {
      swap(cur->value, cur->next->value);
      cur = cur->next->next;
 }
 
}

  

/*Problem #10: Reverse list nodes
● Given a list, reverse all its nodes (addresses)
● E.g. {1, 2, 3, 4, 5} ⇒ {5, 4, 3, 2, 1}
● void reverse()*/

void reverse() {	

		if (length <= 1)
			return;

		tail = head;
		Node<T> * prv = head;
		head = head->next;
		while (head) {
			Node<T> * next = head->next;
			head->next = prv;

			prv = head;
			head = next;
		}
		head = prv;
		tail->next = nullptr;

	}

/*Problem #11: Delete even positions
● Given a list, delete all nodes at even positions (2, 4, 6, etc)
● E.g. {1, 2, 3, 4, 10} ⇒ {1, 3, 10}
● E.g. {1, 2, 3, 4, 5, 6} ⇒ {1, 3, 5}
● Note: positions NOT values
● void delete_even_positions()*/

void delete_even_positions() {
    if (length == 0) {
        return;
    }

    while (head && head->value % 2 == 0) {
        delete_first_node();
    }

    Node<T> *cur = head;

    while (cur->next && cur->next->next) {
        if (cur->next->value % 2 == 0) {
            Node<T> *tmp = cur->next;
            cur->next = cur->next->next;
            delete tmp;
            --length;
        } 
        
        cur = cur->next;  
        
    }

    if (tail && tail->value % 2 == 0) {
        delete_last_node();
    }
}


/*Problem #12: Insert to be sorted
● Implement: void insert_sorted(int value)
● It will always insert the value in position so that list is sorted
● Let’s insert values: 10 2 30 4 1
● insert(10) ⇒ {10}
● insert(2) ⇒ {2, 10}
● insert(30) ⇒ {2, 10, 30}
● insert(4) ⇒ {2, 4, 10, 30}
● insert(1) ⇒ {1, 2, 4, 10, 30}*/

void insert_sorted(T Value){

    if (head == nullptr)
    {
        insert_front(Value);
    }
    else if (head->value >= Value)
    {
        insert_front(Value);
    }
    
    else {

     Node<T> * new_Node = new Node<T>(Value);
     Node<T> * prev = head;
     Node<T> * cur = head->next;

    while (cur)
    {
        if (cur->value >= Value)
        {
            prev->next = new_Node;
            new_Node->next = cur;
            ++length;
            return;
        }
        
        prev = cur;
        cur = cur->next;
    }

     insert_end(Value);
    
   } 
}

/*Problem #13: Swap head and tail
● Given a list, we would like swap the head node with the tail now
    ○ NODES swap (addresses) not just values swap
    ○ See the before and after before. Observe the addresses
● Tip: Draw step by step your procedure. This will save a lot of your time
● Make sure to print after the swap: once the values and also the addreses*/

void Swap_head_and_tail(){

    if (length == 1 || head == nullptr)
    {
       return;
    }

    Node<T>* cur = head;
    Node<T>* prev = head->next;

    while (cur->next->next != nullptr)
    {
        cur = cur->next;
    }
    
    cur->next->next = prev;
    cur->next = head;
    head->next = nullptr;

    head = tail;
    tail = cur->next;  


}

/*Problem #14: Left Rotate
● Given a list, we would like left rotate it k steps (k up to 200000000) 
    ○ Takes the first k elements and shift to back
● void left_rotate(int k): Your code should be O(n) time
● Below list rotated with k = 3 (nodes 6 10 8 shifted back)
    ○ If k = 1 ⇒ {10, 8, 15, 6}
    ○ If k = 2 ⇒ {8, 15, 6, 10}*/
void left_rotate(int k){

k %= length;

if(length == 0 || length == 1){
    return;
}

Node<T> * cur = head;
Node<T> * newHead = head->next;

while (k > 0)
{
    tail->next = cur;
    cur->next = nullptr;
    tail = cur;
    head = newHead;

    cur = head;
    newHead = head->next;
    --k;
}


}

/*Problem #15: Remove duplicates
● Given list of numbers (not sorted), for any repeated number, remove all except the first
● 1, 2, 1, 3, 2, 4, 3, 5, 2 ⇒ 1, 2, 3, 4, 5
● 1, 2, 3, 4, 5 ⇒ 1, 2, 3, 4, 5
● 1, 1, 1 ⇒ 1*/
void Remove_duplicates() {
    if (length == 0 || length == 1) {
        return;
    }

    vector<T> myVector;
    myVector.push_back(head->value);
    Node<T> *cur = head->next;
    Node<T> *prev = head;
    bool isDuplicate;

    while (cur != nullptr) {
        isDuplicate = false;

        for (T element : myVector) {
            if (element == cur->value) {
                isDuplicate = true;
                break;
            }
        }

        if (!isDuplicate) {
            myVector.push_back(cur->value);
            prev = cur;
            cur = cur->next;
        } else {
            Node<T> *tmp = cur;
            if(cur == tail)
            {
               tail = prev;
            }
            prev->next = cur->next;
            cur = cur->next;
            delete tmp;
        }
    }
}

/*Problem #16: Remove last occurance
● Given list of numbers (not sorted), and a key: remove the last occurrence for this key
● 1, 2, 3 - key = 1 ⇒ 2, 3
● 1, 2, 3, 4, 1 - key = 1 ⇒ 1, 2, 3, 4
● 1, 2, 3, 1, 4 - key = 1 ⇒ 1, 2, 3, 4
● 1, 2, 3, 4 - key = 7 ⇒ 1, 2, 3, 4*/

void Remove_last_occurance(T key){

    if (length == 0 || length == 1) {
            return;
    }

        Node<T> *cur = head;
        Node<T> *prev = nullptr;
        bool doesExist = false;

        while (cur != nullptr)
        {
             if (cur->value == key && doesExist == false)
             {
                doesExist = true;
                prev = cur;
                cur = cur->next;
             }

             else if (cur->value == key && doesExist == true)
             {
                Node<T> *tmp = cur;
                if(cur == tail)
                {
                tail = prev;
                }
                prev->next = cur->next;
                cur = cur->next;
                delete tmp;
             }

             else
             {
                prev = cur;
                cur = cur->next;
             } 
             
        }
        

}


/*Problem #17: Move to back!
● Given list of numbers (not sorted), and a key: move all the occurrence for this key to the end of the list
● 1, 2, 3, 2, 4, 1 - key = 1 ⇒ 2 3 2 4 1 1
● 1, 2, 3, 1, 2, 4, 1, 7, 1, 8, 1, 1 - key = 1 ⇒ 2 3 2 4 7 8 1 1 1 1 1 1*/

void Move_to_back(T key){

     if (length == 0 || length == 1) {
            return;
     }

     if (head->value == key)
     {
        tail->next = head;
        tail = head;
        head = head->next;
        tail->next = nullptr;
        
     }

      Node<T> *cur = head->next;
      Node<T> *prev = head;
      Node<T> *curTail = tail;

      while (cur != nullptr && cur != curTail)
      {
        if (key == cur->value)
        {
            prev->next = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            
            cur = prev->next;
        }

      else
      {
        prev = cur;
        cur = cur->next;
      }
      
    }
}


/*Problem #18: Recursive max
● Given a list, we would like to find the max value in it
● Consider the following coding constraints
    ○ You must use recursion
    ○ Don’t create more than a function
    ○ Function name: int max*/

int max(Node* head = nullptr, bool is_first_call = true) {		
		
		if (is_first_call)
			return this->max(this->head, false);

		if (head == nullptr)
			return INT_MIN;		// initial min value
            
		return std::max(head->data, this->max(head->next, false));
	}
};



/*Problem #19: Arrange odd & even nodes
● This problem is not about nodes values, but their positions (odd & even)
● Rearrange the nodes so that, odd nodes comes first and even nodes comes
last
● E.g. if list is 10, 20, 3, 7, 15: Nodes (10, 3, 15) are at odd positions
● 1, 2, 3, 4 ⇒ 1, 3, 2, 4
● 11 33 55 4 50 17 8 ⇒ 11 55 50 8 33 4 17*/

void Arrange_odd_and_even_nodes(){

    if (length == 0 || length == 1)
    {
        return;
    }

    Node<T> * even = head;
    Node<T> * odd = head->next;
    Node<T> * firstOdd = head->next;

    while (odd != nullptr || even->next != nullptr)
    {
        if (odd->next == nullptr)
        {
            even->next = firstOdd;
            tail = odd;
            odd = odd->next;
            break;
        }

        else if(odd->next->next == nullptr){
            even->next = odd->next;
            even->next->next = firstOdd;
            odd->next = nullptr;
            tail = odd;
            break;
        }
        
        even->next = odd->next;
        odd->next = odd->next->next;
        even = even->next;
        odd = odd->next;
    }
    

    

}

/*Problem #20: Insert alternating
● Implement void insert_alternate(LinkedList &another)
● The function insert the values from another in an alternating way with self
● E.g. if list1 = 1, 2, 3 and list2 = 4,5,6⇒ 1 4 2 5 3 6
● {1, 2, 3}, {4} ⇒ {1, 4, 2, 3}
● {1, 2, 3} {4, 5, 6, 7, 8}⇒ 1 4 2 5 3 6, 7, 8
● {}, {1, 2, 3} ⇒ {1, 2, 3}*/

void insert_alternate(clsLinkedList<T>* &another){

    if (length == 0 || another->get_Lengh() == 0)
    {
        return;
    }
    
    Node<T> * current = head;
    Node<T> *  pos = nullptr;
    Node<T> * anotherCurrent = another->head;
    Node<T> * anotherPos = nullptr;


    while (current != nullptr && anotherCurrent != nullptr)
    {

        anotherPos = anotherCurrent->next;
        anotherCurrent->next =  current->next;
        pos = current->next;
        current->next = anotherCurrent;

        current = pos;
        anotherCurrent = anotherPos;
    }

    
    if (anotherCurrent != nullptr)
    {
        tail->next = anotherCurrent;
        tail = another->tail;
    }
    
    


}

/*Problem #21: Adding 2 HUGE numbers
● Assume we want to represent number 157 as linked list
    ○ It is helpful to have list as 7 -> 5 -> 1
    ○ This makes it easy to build and use in math operations
● Implement method: void add_num(LinkedList &another)
● It adds another number to its current values
● Let’s say current list is {1, 2, 3} representing 321
● Another is: {4, 5, 3} representing 354
● After the addition the list became: 5 7 6 {represents 675}
● {9, 6, 5} + {8, 7, 6, 4, 5, 7, 8, 9} ⇒ {7, 4, 2, 5, 5, 7, 8, 9}
● Notice: numbers are huge. Don’t convert to integer*/

void add_num(clsLinkedList<T>* &another){

    if (length == 0 || another->length == 0)
    {
        return;
    }

    Node<T> * current = head;
    Node<T> * anotherCurrent = another->head;
    Node<T> * prev = nullptr;
    int reserve = 0;
    int newValue = 0;
    
    while (current != nullptr && anotherCurrent != nullptr)
    {
        newValue =0;
        newValue = current->value + anotherCurrent->value + reserve;
        reserve = 0;

        if (newValue > 10)
        {
            reserve = 1;
            newValue = newValue -10; 
        }
        
        current->value = newValue;

        prev = current;
        current = current->next;
        anotherCurrent = anotherCurrent->next;
    }

    if (current == nullptr && anotherCurrent != nullptr)
    {
        prev->next = anotherCurrent;
        tail = another->tail;

        while (reserve > 0 && anotherCurrent != nullptr)
        {
            anotherCurrent->value += reserve;
            reserve = 0;

                if (anotherCurrent->value > 10)
                {
                    reserve = 1;
                    anotherCurrent->value = anotherCurrent->value -10; 
                }
            
            anotherCurrent = anotherCurrent->next;
        }
        
    }
    
    
    if (current != nullptr && anotherCurrent == nullptr)
    {
        while (reserve > 0 && current != nullptr)
        {
            current->value += reserve;
            reserve = 0;

                if (current->value > 10)
                {
                    reserve = 1;
                    current->value = current->value -10; 
                }
            
            current = current->next;
        }
    }
    
    if (current == nullptr && anotherCurrent == nullptr && reserve > 0)
    {
            Node<T> * new_Node = new Node<T>(reserve);
            prev->next = new_Node;
            new_Node->next = nullptr;
            tail = new_Node;
    }



}

/*Problem #22: Remove all repeated
● Given linked list of sorted integers, keep only nodes that never repeated and remove everything else (duplicate nodes)
● Input: 1, 1, 2, 2, 2, 3, 5 ⇒ {3, 5} both 1 and 2 are repeated
● Input: 1, 1 ⇒ {}
● Input: 1, 1, 2, 2, 2 ⇒ {}
● Input: 1, 1, 2, 2, 2, 5 ⇒ {5}
● Input: 1, 2, 2, 2, 3 ⇒ {1, 3}
● Caution: Coding this problem may drain your time
    ○ Think about several test cases
    ○ Draw & verify!*/

void Remove_all_repeated(){

    if (length == 0 || length == 1)
    {
        return;
    }
    
    
    Node<T> * current = nullptr;
    Node<T> *  prev = nullptr;
    Node<T> *  actual = head;
    Node<T> * actualPrev = nullptr;
    bool isRepeated = false;

    while (actual->next != nullptr)
    {
        isRepeated = false;
        current = actual->next;
        prev = actual;

        while (current != nullptr)
        {
           if (actual->value == current->value)
           {
              isRepeated = true;
              Node<T> * tmp = current;

              if (current == tail)
              {
                tail = prev;
              }
              
              prev->next = current->next;
              current = current->next;
              delete tmp;
           }

           else{

                prev = prev->next;
                current = current->next;
           }
           
        }

        if (isRepeated)
        {
            if (head == actual)
            {
                actual = actual->next;
                delete_first_node();
            }

            else
            {
                Node<T> * tmp = actual;
                actualPrev->next = actual->next;
                actual = actual->next;
                delete tmp;
            }
            
        }

        else
        {
            actualPrev = actual;
            actual = actual->next;
        }
           
    }
}

/*Problem #23: Reverse Chains
● Implement: void reverse_chains(int k)
● Instead of reversing the whole list, you reverse only each consecutive k nodes
● {1,2,3,4,5,6}, k = 6 ⇒ 6 5 4 3 2 1 [normal reverse]
● {1,2,3,4,5,6}, k = 3 ⇒ 3 2 1 6 5 4
● {1,2,3,4,5,6, 7}, k = 2 ⇒ 2 1 4 3 6 5 7*/

void reverse_chains(int k){
    
    if (length == 0 || length == 1)
    {
        return;
    }
    
    if (k >= length)
    {
        reverse();
        return;
    }
    
     Node<T> * current = head->next;
     Node<T> * tmp = nullptr;
     Node<T> * prev = head;

     while (k > 1 && current != nullptr)
     {
        
        tmp = current->next ;
        current->next = prev;
     
        prev = current;
        current = tmp;

        --k;

        if (k == 1)
        {
            head->next = current;
            head = prev;
        }
        
     }
     
    
}

~clsLinkedList(){

		while(head){
			Node<T> * current = head->next;
			delete head;
			head = current;
        }

}

};