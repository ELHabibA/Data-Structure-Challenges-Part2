#include <iostream>
#include "Vector/clsVector.h"
#include "SinglyLinkedList/clsNode.h"
#include "SinglyLinkedList/clsLinkedList.h"

using namespace std;

int main() {

	
	clsLinkedList<int>* List = new clsLinkedList<int>();

  List->insert_end(1);
	List->insert_end(2);
	List->insert_end(3);
	List->insert_end(8);
	List->insert_end(5);

   
	List->print();
  
 	clsLinkedList<int>* other = new clsLinkedList<int>();

	other->insert_end(1);
	other->insert_end(2);
	other->insert_end(5);
	other->insert_end(8);
	other->insert_end(5);


  other->print();


	cout << List->is_same_without_length(* other) << endl;
	

	return 0;
}
