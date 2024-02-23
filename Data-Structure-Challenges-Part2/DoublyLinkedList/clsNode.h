#pragma once
#include <iostream>
using namespace std;

template <typename T>
class clsNode {
   
   public:

   T value;
   clsNode* next;
   clsNode* prev;

   clsNode(T Value){

    value = Value;

   }

   static void print(clsNode* head){

    if(head == nullptr)
          return;
    
    cout << head->value << " ";
    head = head->next;

    print(head);

   }

   static void print_reversed(clsNode* tail){
     
      if(tail == nullptr)
          return;

     cout << tail->value << " ";
     tail = tail->prev;
     print_reversed(tail);
      

   }
};