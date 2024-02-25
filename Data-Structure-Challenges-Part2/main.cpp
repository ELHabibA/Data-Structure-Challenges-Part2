#include <iostream>
#include "Vector/clsVector.h"
#include "DoublyLinkedList/clsNode.h"
#include "DoublyLinkedList/clsDoublyLinkedList.h"

using namespace std;

int main() {

	
	clsDoublyLinkedList<int>* List = new clsDoublyLinkedList<int>();

  List->insert_end(1);
	List->insert_end(2);
	List->insert_end(3);
	List->insert_end(9);
	List->insert_end(3);
	List->insert_end(2);
	List->insert_end(1);
  


	
	List->print();
	/*clsLinkedList<int>* other = new clsLinkedList<int>();

	other->insert_end(4);
	other->insert_end(5);
	other->insert_end(3);

  other->print();*/

  if (List->is_palindrome())
	{
		cout << " YES !!"<<endl;
	}

	else
	{
	cout << " NO !!"<<endl;

	}
	
		

  List->print();

 cout << "Length: " << List->get_Length() << endl;
 cout << "Head: " << List->get_head() << endl;
 cout << "Tail: " << List->get_tail() << endl;

	return 0;
}

 	/*clsLinkedList<int>* other = new clsLinkedList<int>();

	other->insert_end(1);
	other->insert_end(2);
	other->insert_end(3);
	other->insert_end(8);



  other->print();*/
