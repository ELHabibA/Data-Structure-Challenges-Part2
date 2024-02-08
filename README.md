# Data Structure Challenges (Part2)

The Data Structures Challenges Repository contains C++ solutions for various data structure challenges. Each challenge is encapsulated in its own class, providing a template for solving specific problems related to data structures. Each class is dedicated to constructing and implementing diverse data structures along with their associated operations. Additionally, it includes supplementary challenges aimed at deepening comprehension of data structure concepts and refining problem-solving skills.

## Challenges Included:

1. **Vector**
    - Folder: `Vector`
    - File: `clsVector.h`
    - Challenges:
         1. `right_rotate` - Shifts every element one step towards the right, with the rightmost element moving to the first index.
         1. `left_rotate` - Rotates the entire array one step to the left, with the leftmost element wrapping around to the back of the array.
         1. `right_rotate(int times)` - Applies the right rotation a specified number of times (times).
         1. `pop(int idx)` - Removes an element at the specified index (idx) and returns its value.
         1. `find_transposition(int value)` - Improves search speed by shifting the found value one step to the left, bringing frequently queried values closer to the beginning of the array.

1. **Singly Linked List**
    - Folder: `SinglyLinkedList`
    - Files: `clsLinkedList.h` & `clsNode.h`
    - Challenges:
         1. `get_Lengh()`: Returns the length (number of nodes) of the linked list.
         2. `get_Head()`: Returns the value of the head node.
         3. `get_Tail()`: Returns the value of the tail node.
         4. `print()`: Prints the values of all nodes in the linked list.
         5. `delete_first_node()`: Deletes the first node in the linked list.
         6. `delete_last_node()`: Deletes the last node in the linked list.
         7. `delete_nth(int n)`: Deletes the node at the specified position in the linked list.
         8. `insert_end(T Value)`: Inserts a new node with the given value at the end of the linked list.
         9. `get_nth(int pos)`: Returns the node at the specified position in the linked list.
         10. `search(T Value)`: Returns the 0-based index of the first occurrence of the specified value in the linked list.
         11. `search_improved_v2(T Value)`: Similar to `search`, but also swaps the found node with its previous node.
         12. `insert_front(T Value)`: Inserts a new node with the given value at the beginning of the linked list.
         13. `delete_front()`: Deletes the first node in the linked list.
         14. `get_nth_back(int n)`: Returns the node at the nth position from the end of the linked list.
         15. `is_same(const clsLinkedList &other)`: Checks if two linked lists are data-equal (same values and lengths).
         16. `is_same_without_length(const clsLinkedList &other)`: Checks if two linked lists are data-equal without using the length variable.
         17. `delete_node_with_key(T Value)`: Deletes the first occurrence of a node with the specified value.
         18. `swap_pairs()`: Swaps each pair of consecutive nodes in the linked list.
         19. `reverse()`: Reverses the order of nodes in the linked list.
         20. `delete_even_positions()`: Deletes nodes at even positions in the linked list.
         21. `insert_sorted(T Value)`: Inserts a new node with the given value in a sorted manner.
         22. `Swap_head_and_tail()`: Swaps the head and tail nodes (addresses) of the linked list.
         23. `Left_Rotate()`: Left rotates the linked list by a specified number of steps.
         24. `Remove_duplicates()`: Removes duplicate values from the linked list.
         25. `Remove_last_occurance()`: Removes the last occurrence of a specified value from the linked list.
         26. `Move_to_back()`: Moves all occurrences of a specified value to the end of the linked list.
         27. `Recursive_max()`: Finds the maximum value in the linked list using recursion.
         28. `Arrange_odd_and_even_nodes()`: Arranges odd and even positioned nodes in the linked list.
         29. `insert_alternate(LinkedList &another)`: Inserts values from another linked list in an alternating way.
         30. `Adding_Huge_Numbers()`: Adds two linked lists representing huge numbers.
         31. `Remove_all_repeated()`: Removes all nodes with repeated values from the sorted linked list.
         32. `reverse_chains(int k)`: Reverses each consecutive k nodes in the linked list.


## Usage

To explore and utilize the project, navigate to each class inspect the provided implementations, and tackle the challenges. You can also invoke the classes in the main function to experiment with their functionality.

