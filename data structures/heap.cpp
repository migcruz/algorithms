#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

class minIntHeap{

	public:

		int getLeftChildIndex(int parentIndex){
			return 2*parentIndex + 1;
		}

		int getRightChildIndex(int parentIndex){
			return 2*parentIndex + 2;
		}

		int getParentIndex(int childIndex){
			return (childIndex-1)/2;
		}

		bool hasLeftChild(int index){
			if (getLeftChildIndex(index) < size){
				return true;
			}
			return false;
		}

		bool hasRightChild(int index){
			if (getRightChildIndex(index) < size){
				return true;
			}
			return false;
		}

		bool hasParent(int index){
			if (getParentIndex(index) >= 0){
				return true;
			}
			return false;
		}

		int leftChild(int index){
			return items[getLeftChildIndex(index)];
		}

		int rightChild(int index){
			return items[getRightChildIndex(index)];
		}

		int parent(int index){
			return items[getParentIndex(index)];
		}

		void swap(int indexOne, int indexTwo){
			int temp = items[indexOne];
			items[indexOne] = items[indexTwo];
			items[indexTwo] = temp;
		}

		void resize(){
			if (size == capacity){
				int *temp = items;
				int *newarray = new int[2*capacity];
				for (int i = 0; i < capacity; i++){
					newarray[i] = items[i];
				} 
				capacity *= 2;
				items = newarray;
				delete[] temp; //deletes old array
			}
		}

		// Start of actual code
		int peek(){
			if (size == 0){
				invalid_argument( "ERROR" ); //invalid
			}
			return items[0]; //returns root
		}

		int poll(){
			if (size == 0){
				invalid_argument( "received negative value" );; //invalid
			}
			int item = items[0];
			items[0] = items[size - 1];
			size--;
			heapifyDown();
			return item;
		}

		void add(int item){
			resize(); //ensure there is enough space
			items[size] = item;
			size++;
			heapifyUp();
		}

		void heapifyUp(){
			int index = size - 1;
			while (hasParent(index) && (parent(index) > items[index])){//walks up if there is a parent and if parent is bigger
				//therfore out of order
				swap(getParentIndex(index), index);
				index = getParentIndex(index);
			}
		}

		void heapifyDown(){
			int index = 0; //start at root
			while (hasLeftChild(index)){// only check left child bc no left child means no right child
				int smallerChildIndex = getRightChildIndex(index);
				if (hasRightChild(index) && (rightChild(index) < leftChild(index))){
					smallerChildIndex = getRightChildIndex(index);
				}

				if (items[index] < items[smallerChildIndex]){
					break; //in order therfore get out of while loop
				}
				else { //still out of order
					swap(index, smallerChildIndex);
				}
				index = smallerChildIndex;
			}
		}

		void printHeap(){
			for (int i = 0; i < size; i++){
				cout << items[i] << endl;
			}
			cout << endl;
		}


	private:
		int capacity = 10;
		int size = 0;
		int *items = new int[capacity];

};

int main(){
	minIntHeap test;

	test.add(10);
	test.add(15);
	test.add(20);
	test.add(17);
	test.printHeap();

	test.add(25);
	test.printHeap();
	
	test.add(8); 
    test.printHeap();

	return 0;
}


