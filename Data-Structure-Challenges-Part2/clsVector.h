#pragma once

#include <iostream>
using namespace std;

template <class T>
class clsVector {
private:
	T* arr = nullptr;
	int size = 0;
	int capacity;


	void swap(T*& ptr1, T*& ptr2) {

		T* temp;

		temp = ptr1;
		ptr1 = ptr2;
		ptr2 = temp;

	}

	void appandCapacity() {

		capacity = capacity * 2;

		T* arr2 = new T[capacity];

		for (int i = 0; i < size; i++) {
			arr2[i] = arr[i];
		}

		swap(arr, arr2);


		delete[] arr2;
	}

public:
	clsVector(int Size) {

		if (Size < 0)
			Size = 1;

		size = Size;
		capacity = size + 10;

		arr = new int[capacity];
	}

	~clsVector() {
		delete[] arr;
		arr = nullptr;
	}

	void push_back(T Value) {

		if (size == capacity) {

			appandCapacity();
		}

		arr[size++] = Value;
	}



	int get_size() {
		return size;
	}

	int get(int idx) {
		if (0 <= idx && idx < size) {
			return arr[idx];
		};

	}

	void set(int idx, T val) {

		if (0 <= idx && idx < size) {
			arr[idx] = val;
		};
	}

	void insert(int index, T value) {

		if (size == capacity) {

			appandCapacity();
		}

		T* arr2 = new T[++size];


		for (int i = 0; i < index; i++) {
			arr2[i] = arr[i];
		}

		arr2[index] = value;


		for (int i = index; i < size - 1; i++) {
			arr2[i + 1] = arr[i];
		}

		swap(arr2, arr);

		delete[] arr2;
	}

	T front() {

		return arr[0];
	};

	T back() {

		return arr[size - 1];
	};

	void print() {
		for (int i = 0; i < size; ++i)
			cout << arr[i] << " ";
		cout << "\n";
	}

	int find(T value) {
		for (int i = 0; i < size; ++i)
			if (arr[i] == value)
				return i;
		return -1;	
	}


	/*Problem #1: Right rotation
	
      ● Consider our Vector class. Add the member function: void right_rotate()
      ● The function shifts every element 1 step towards the right.
            ○ The rightmost element? It goes to the first index
      ● Example
      ● Assume the array content is: 0 1 2 3 4
      ● After a right rotation it will be: 4 0 1 2 3
    */

	void right_rotate() {

		T temp = arr[size - 1];

		for (int i = size - 2; i >= 0; i--)
		{
			 arr[i + 1] = arr[i];
		}

		arr[0] = temp;

	}

	/*Problem #2: Left rotation
	
	● Consider our Vector class. Add the member function: void left_rotate()
	● The function rotates the whole array 1 step to the left
	        ○ However, in this case, the leftmost element will be 'rotated' around to the back of the array!
	● Example
	● Assume the array content is: 0 1 2 3 4
	● After a left rotation, it will be: 1 2 3 4 0
	*/

	void left_rotate() {

		T temp = arr[0];

		for (int i = 0; i < size - 1; i++)
		{
			arr[i] = arr[i + 1];
		}

		arr[size - 1] = temp;

	}

	/*Problem #3: Right rotation with steps
	
	● Implement void right_rotate(int times)
	● This one applies the right rotation times time
	● Assume array content is: 0 1 2 3 4
	● right_rotate(2) ⇒ it will be: 3 4 0 1 2
	● The challenge: times can be up to: 2000000000
	● Your code should be efficient to some extent
	*/

	void right_rotate(int times) {

	}

	/*Problem #4: Deleting a position
	
	● Implement method int pop(int idx) in the vector class
	● It returns the deleted value
	● Remove this element from the array
	● Assume array is: 4 0 1 2 3
	● pop(2)
		○ Return value 1
		○ New array: 4 0 2 3
	*/

	T pop(int index){

		T value = arr[index];

		for (int i = index; i < size - 1; i++)
		{
			arr[i] = arr[i + 1];
		}

		size--;

		return value;

	}

	/*Problem #5: Improved search
	
	● Assume our vector is huge and we do many find() calls for almost a few small repetitive values
	● One way to improve the code speed is: each time you find the value, you shift it one step to the left
	● Eventually, the values that are queried a lot, will move to the head of array
	● Implement method: int find_transposition(int value)
		○ It returns the found position, but consider moving it one step to the left
	● Example: 10 20 30 40 50. find_transposition(3)
		○ New array 10 30 20 40 50
		○ Return 1
	*/

	int find_transposition(T value) {

		int pos = find(value);

		if ((pos == -1) || (pos == 0))
		{
			return pos;
		}

		T temp = arr[pos];

		arr[pos] = arr[pos - 1];
		arr[pos - 1] = temp;

		return --pos;
	
	}

};