#include <iostream>
#include <iomanip> 
using namespace std;

class MinHeap
{
private:
	int arrLen = 0;
	int size = 0;
	double* arr;

	int parent(int index)
	{
		return (index - 2) / 2;
	}

	int leftChild(int index)
	{
		return (index * 2 + 1);
	}

	int rightChild(int index)
	{
		return (index * 2 + 2);
	}

	bool isRightChild(int index)
	{
		return (index * 2 + 2) < size;
	}

	bool isLeftChild(int index)
	{
		return (index * 2 + 1) < size;
	}

	void swap(int indexOne, int indexTwo)
	{
		double temp = arr[indexOne];
		arr[indexOne] = arr[indexTwo];
		arr[indexTwo] = temp;
	}

	void heapifyUp(int index)
	{
		if (index == 0)
		{
			return;
		}

		if (arr[parent(index)] > arr[index])
		{
			swap(parent(index), index);
			heapifyUp(parent(index));
		}
		else
		{
			return;
		}
	}

	void heapifyDown(int index)
	{
		if (index < 0 || index > size - 1)
		{
			return;
		}

		int smallerChild = 0;
		if (isLeftChild(index) && isRightChild(index))
		{
			smallerChild = leftChild(index);
			if (arr[smallerChild] > arr[rightChild(index)])
			{
				smallerChild = rightChild(index);
			}
		}
		else if(isLeftChild(index))
		{
			smallerChild = leftChild(index);
		}
		else if (isRightChild(index))
		{
			smallerChild = rightChild(index);
		}
		else
		{
			return;
		}

		if (arr[index] > arr[smallerChild])
		{
			swap(index, smallerChild);
			heapifyDown(smallerChild);
		}
		else
		{
			return;
		}

	}

	
public:
	MinHeap(int arrLen)
	{
		this->arrLen = arrLen;
		arr = new double[arrLen];
	}

	void insert(double data)
	{
		arr[size] = data;
		heapifyUp(size);
		size++;
	}

	int getSize()
	{
		return this->size;
	}

	double getTop()
	{
		return arr[0];
	}

	double pop()
	{
		double temp = arr[0];
		swap(0, size - 1);
		size--;
		heapifyDown(0);
		return temp;
	}

	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << endl;
		}
	}

};

class MaxHeap
{
private:
	int size = 0;
	int arrLen = 0;
	double* arr;

	int parent(int index)
	{
		return ((index - 2) / 2);
	}

	int leftChild(int index)
	{
		return (index * 2 + 1);
	}

	int rightChild(int index)
	{
		return (index * 2 + 2);
	}

	bool isLeftChild(int index)
	{
		return (index * 2 + 1) < size;
	}

	bool isRightChild(int index)
	{
		return (index * 2 + 2) < size;
	}

	void swap(int indexOne, int indexTwo)
	{
		double temp = arr[indexOne];
		arr[indexOne] = arr[indexTwo];
		arr[indexTwo] = temp;
	}

	void heapifyUp(int index)
	{
		if (index == 0)
		{
			return;
		}

		if (arr[parent(index)] < arr[index])
		{
			swap(parent(index), index);
			heapifyUp(parent(index));
		}
		else
		{
			return;
		}
	}

	void heapifyDown(int index)
	{
		if (index < 0 || index > size - 1)
		{
			return;
		}

		int biggerChild = 0;
		if (isLeftChild(index) && isRightChild(index))
		{
			biggerChild = leftChild(index);
			if (arr[biggerChild] < arr[rightChild(index)])
			{
				biggerChild = rightChild(index);
			}
		}
		else if (isLeftChild(index))
		{
			biggerChild = leftChild(index);
		}
		else if (isRightChild(index))
		{
			biggerChild = rightChild(index);
		}
		else
		{
			return;
		}

		if (arr[index] < arr[biggerChild])
		{
			swap(index, biggerChild);
			heapifyDown(biggerChild);
		}
		else
		{
			return;
		}

	}

public:

	MaxHeap(int arrLen)
	{
		this->arrLen = arrLen;
		arr = new double[arrLen];
	}

	void insert(double data)
	{
		arr[size] = data;
		heapifyUp(size);
		size++;
	}

	int getSize()
	{
		return size;
	}

	double getTop()
	{
		return arr[0];
	}

	double pop()
	{
		double temp = arr[0];
		swap(0, size - 1);
		size--;
		heapifyDown(0);
		return temp;
	}

	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << "~" << endl;
		}
	}
};

int main()
{
	int N = 0;
	cin >> N;

	MinHeap big(N);
	MaxHeap small(N);

	double med = 0;
	cin >> med;
	cout << med << endl;

	for (int i = 1; i < N; i++)
	{
		double K;
		cin >> K;

		if (small.getSize() > big.getSize())
		{
			if (K < med)
			{
				big.insert(small.getTop());
				small.pop();
				small.insert(K);
			}
			else
			{
				big.insert(K);
			}

			med = (double)(small.getTop() + big.getTop()) / 2.0;
		}

		else if (small.getSize() == big.getSize())
		{
			if (K < med)
			{
				small.insert(K);
				med = (double)small.getTop();
			}
			else
			{
				big.insert(K);
				med = (double)big.getTop();
			}
		}
		else
		{
			if (K > med)
			{
				small.insert(big.getTop());
				big.pop();
				big.insert(K);
			}
			else
			{
				small.insert(K);
			}

			med = (double)(small.getTop() + big.getTop()) / 2;
		}
		printf("%.2f \n", med);
	}

	int bra;
	cin >> bra;
	return 0;
}
