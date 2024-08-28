#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;

/*
Design Dynamic Array (Resizable Array)
Neetcode easy
https://neetcode.io/problems/dynamicArray
time: 15 minutes
*/

class DynamicArray
{
public:
	int *arr;
	int capacity;
	int size;

	DynamicArray(int capacity)
	{
		this->capacity = capacity;
		this->size = 0;
	}

	int get(int i)
	{
		if (i < 0 || i >= size)
		{
			throw runtime_error("Index out of bounds");
		}
		return arr[i];
	}

	void set(int i, int n)
	{
		if (i < 0 || i >= size)
		{
			throw runtime_error("Index out of bounds");
		}

		arr[i] = n;
	}

	void pushback(int n)
	{
		if (size == capacity)
		{
			resize();
		}
		arr[size] = n;
		size++;
	}

	int popback()
	{
		size--;
		return arr[size];
	}

	void resize()
	{
		capacity *= 2;
		int *newArr = new int[capacity];
		for (int i = 0; i < size; i++)
		{
			newArr[i] = arr[i];
		}
	}

	int getSize()
	{
		return size;
	}

	int getCapacity()
	{
		return capacity;
	}
};
