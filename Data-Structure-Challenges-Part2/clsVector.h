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
		return -1;	// -1 for NOT found
	}
};