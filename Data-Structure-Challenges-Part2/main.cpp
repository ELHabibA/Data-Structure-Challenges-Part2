#include <iostream>
#include "clsVector.h"
#include "SinglyLinkedList/clsNode.h"

using namespace std;

int main() {

	
	Node<int>* node1 = new Node<int>(6);
	Node<int>* node2 = new Node<int>(10);
	Node<int>* node3 = new Node<int>(8);
	Node<int>* node4 = new Node<int>(15);
	

  node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = nullptr;
	
	Node<int>::print_reversed(node1);

	return 0;
}
