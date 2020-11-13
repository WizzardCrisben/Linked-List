// C++ program for building Heap from Array 

#include <iostream> 
#include <conio.h>
#include <vector>
#include <algorithm>

#include <stdlib.h>
#include <math.h>
#include <iomanip>

using namespace std;
int n;
int MinHeap[] = {9,20,30,1,2,3,4,11,25,37};
// To heapify a subtree rooted with node i which is 
// an index in arr[]. 
void heapify(int arr[], int i)
{
	int smallest = i; // Initialize smallest as root 
	int l = 2 * i + 1; // left child
	int r = 2 * i + 2; // right child 

	// If left child is less than root 
	if (l < n && arr[l] > arr[smallest])
		smallest = l;

	// If right child is less than smallest so far 
	if (r < n && arr[r] > arr[smallest])
		smallest = r;

	// If smallest is not root 
	if (smallest != i) {
		swap(arr[i], arr[smallest]);

		// Recursively heapify the affected sub-tree 
		heapify(arr, smallest);
	}
}

// Function to build a Max-Heap from the given array 
void buildHeap(int arr[])
{
	// Index of last non-leaf node 
	int startIdx = (n / 2) - 1;

	// Perform reverse level order traversal 
	// from last non-leaf node and heapify 
	// each node 
	for (int i = startIdx; i >= 0; i--) {
		heapify(arr, i);
	}
}

int parent(int i)
{
	return (i - 1) / 2;
}
int leftChild(int i)
{
	return (2 * i) + 1;
}
int rightChild(int i)
{
	return (2 * i) + 2;
}
int deleteRoot()
{
	if (n == 0)
	{
		cout << "SORRY! HEAP EMPTY" << endl;
		return -1;
	}
	else if (n == 1)
	{
		n--;
		return MinHeap[0];
	}
	else
	{
		// Store the root
		int root = MinHeap[0];

		// Maintain heap shape and then order
		MinHeap[0] = MinHeap[n - 1];
		n--;
		heapify(MinHeap,0);

		// Return min element
		return root;
	}
}
// A utility function to print the array 
// representation of Heap 
void printHeap(int arr[])
{
	cout << "Min Heap representation is:\n";

	int power = 0;
	int value = 1;
	for (int i = 0; i < n; i++){
		if (i == value){
			cout << endl;
			power += 1;
			value += (1 << power);
		}
		cout << arr[i] << "  ";
	}
	cout << endl;
}

// Driver Code 
int main()
{
	int i = 0;
	int value = 11;
	n = sizeof(MinHeap) / sizeof(MinHeap[0]);

	buildHeap(MinHeap);
	printHeap(MinHeap);

	while (i < n)
	{
		if (MinHeap[i] == value)
		{
			cout << "\nParent index of " << value << " = " << parent(i) << endl;
			cout << "\nArray index of the left child node of the node with value  " << value << " = " << leftChild(i) << endl;
			cout << "Array index of the right child node of the node with value " << value << " = " << rightChild(i)<< endl;
			break;
		}
		i++;
	}
	if (i < n)
	{
		cout << "\nElement " << value << " is at array index " << i << endl;
	}
	else{
		cout << "Element not found!!!!!";
	}
	
	int minimum = deleteRoot();

	cout << endl;
	cout << "Root Element deleted. ";
	printHeap(MinHeap);
	_getch();
	return 0;
}
