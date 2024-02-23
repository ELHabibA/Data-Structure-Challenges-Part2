#pragma once
#include <iostream>
using namespace std;

template <typename T>
class Node {
   
   public:

   T value;
   Node* next;

   Node(T Value){

    value = Value;

   }

   static void print(Node* head){

    if(head == nullptr)
          return;
    
    cout << head->value << " ";
    head = head->next;

    print(head);

   }

   static void print_reversed(Node* head){
     
      if(head == nullptr)
          return;

      print_reversed(head->next);
      cout << head->value << " ";
      

   }
};