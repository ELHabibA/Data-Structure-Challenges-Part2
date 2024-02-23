# Data Structure Challenges (Part2)

The Data Structures Challenges Repository contains C++ solutions for various data structure challenges. Each challenge is encapsulated in its class, providing a template for solving specific problems related to data structures. Each class is dedicated to constructing and implementing diverse data structures along with their associated operations. Additionally, it includes supplementary challenges aimed at deepening comprehension of data structure concepts and refining problem-solving skills.

## Challenges Included:

1. **Vector**
    - Folder: `Vector`
    - File: `clsVector.h`
    - Challenges:
         - `right_rotate` - Shifts every element one step towards the right, with the rightmost element moving to the first index.
         - `left_rotate` - Rotates the entire array one step to the left, with the leftmost element wrapping around to the back of the array.
         - `right_rotate(int times)` - Applies the right rotation a specified number of times (times).
         - `pop(int idx)` - Removes an element at the specified index (idx) and returns its value.
         - `find_transposition(int value)` - Improves search speed by shifting the found value one step to the left, bringing frequently queried values closer to the beginning of the array.

2. **Singly Linked List**
    - Folder: `SinglyLinkedList`
    - Files: `clsLinkedList.h` & `clsNode.h`
    - Challenges:
      
        **Basic Operations**
        - `get_Length()`: Returns the length of the linked list.
        - `get_Head()`: Returns the value of the head node.
        - `get_Tail()`: Returns the value of the tail node.
        - `print()`: Prints the values of all nodes in the linked list.
        - `delete_first_node()`: Deletes the first node in the linked list.
        - `delete_last_node()`: Deletes the last node in the linked list.
        - `delete_nth(int n)`: Deletes the node at the specified position in the linked list.
        - `insert_end(T Value)`: Inserts a new node with the given value at the end of the linked list.
        
        **Search and Manipulation**
        - `get_nth(int pos)`: Returns the node at the specified position in the linked list.
        - `search(T Value)`: Returns the index of the first occurrence of the specified value in the linked list.
        - `search_improved_v2(T Value)`: Similar to `search`, but also swaps the found node with its previous node.
        - `insert_front(T Value)`: Inserts a new node with the given value at the beginning of the linked list.
        - `delete_front()`: Deletes the first node in the linked list.
        - `get_nth_back(int n)`: Returns the node at the nth position from the end of the linked list.
        
        **List Manipulation**
        - `is_same(const clsLinkedList &other)`: Checks if two linked lists are data-equal.
        - `is_same_without_length(const clsLinkedList &other)`: Checks if two linked lists are data-equal without using the length variable.
        - `delete_node_with_key(T Value)`: Deletes the first occurrence of a node with the specified value.
        - `swap_pairs()`: Swaps each pair of consecutive nodes in the linked list.
        - `reverse()`: Reverses the order of nodes in the linked list.
        - `delete_even_positions()`: Deletes nodes at even positions in the linked list.
        - `insert_sorted(T Value)`: Inserts a new node with the given value in a sorted manner.
        
        **Additional Operations**
        - `Swap_head_and_tail()`: Swaps the head and tail nodes of the linked list.
        - `Left_Rotate()`: Left rotates the linked list by a specified number of steps.
        - `Remove_duplicates()`: Removes duplicate values from the linked list.
        - `Remove_last_occurance()`: Removes the last occurrence of a specified value from the linked list.
        - `Move_to_back()`: Moves all occurrences of a specified value to the end of the linked list.
        - `Recursive_max()`: Finds the maximum value in the linked list using recursion.
        - `Arrange_odd_and_even_nodes()`: Arranges odd and even positioned nodes in the linked list.
        
        **Advanced Operations**
        - `insert_alternate(clsLinkedList &another)`: Inserts values from another linked list in an alternating way.
        - `Adding_Huge_Numbers()`: Adds two linked lists representing huge numbers.
        - `Remove_all_repeated()`: Removes all nodes with repeated values from the sorted linked list.
        - `reverse_chains(int k)`: Reverses each consecutive k nodes in the linked list.

3. **Doubly Linked List**
    - Folder: `DoublyLinkedList`
    - Files: `clsDoublyLinkedList.h` & `clsNode.h`
    - Challenges:

## Usage

To explore and utilize the project, navigate to each class inspect the provided implementations, and tackle the challenges. You can also invoke the classes in the main function to experiment with their functionality.

