/*
Matt Foster
CS 302
Assignment 6
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int deleteHeap(int*);
void buildHeap();
int insertElement(int*, int, int);
void deleteMin();
void findMax();
void increaseKey();
void decreaseKey();
void removeElement();
void printHeap(int*,int);
void percUp(int*,int);
void percDown(int*,int);

int main(){
	char* prompt1 = "Please choose an option\n(1) Delete Heap\n(2) Build Heap\n(3) Insert Element\n";
	char* prompt2 = "(4) Delete Minimum Element\n(5) Find Maximum Element\n(6) Increase Key\n";
	char* prompt3 = "(7) Decrease Key\n(8) Remove Element\n(9) Exit\n\nOption: ";
	int currIndex = 1; /*current empty element*/
	int userSelect, temp1, temp2,i;
	char inBuff[200];
	int heap[33];
	for(i=0; i<32; i++){
		heap[i]=0;
	}

	while(true){ /*repeat until exit option received*/
		printf("\n%s%s%s", prompt1,prompt2,prompt3);
		fgets(inBuff,sizeof(inBuff),stdin);
		sscanf(inBuff,"%d",&userSelect);

		switch(userSelect){
			case 1: /*Delete Heap*/
				printf("\nHeap deleted\n");
				currIndex = deleteHeap(heap);
				break;
			case 2: /*Build Heap*/
				printf("\nPlease enter numbers: ");
				break;
			case 3: /*Insert Element*/
				printf("\nPlease enter value to be inserted: ");
				fgets(inBuff,sizeof(inBuff),stdin);
				sscanf(inBuff,"%d",&temp1);
				currIndex = insertElement(heap,currIndex,temp1);
				break;
			case 4: /*Delete Minimum Element*/
				break;
			case 5: /*Find Maximum Element*/
				break;
			case 6: /*Increase Key Value*/
				printf("\nPlease enter index of element to increase: ");
				printf("\nPlease enter amount to increase element: ");
				break;
			case 7: /*Decrease Key Value*/
				printf("\nPlease enter index of element to decrease: ");
				printf("\nPlease enter amount to decrease element: ");
				break;
			case 8: /*Remove element*/
				printf("\nPlease enter index of element to remove: ");
				break;
			case 9: /*Exit*/
				printf("\nGoodbye\n");
				return 0;
			default: /*Invalid Input*/
				printf("Please choose a valid option\n");
		}
		printf("\n");
		printHeap(heap,currIndex);
	}
}
int deleteHeap(int heap[]){
	int i;
	for(i=0;i<32;i++){
		heap[i]=0;
	}
	return 0;
}
void buildHeap(){

}

int insertElement(int heap[], int currIndex, int value){
	heap[currIndex] = value;
	percUp(heap,currIndex);
	currIndex = currIndex + 1;
	return currIndex;
}

void deleteMin(int heap[], int currIndex){
	int child1 = heap[1];
	int child2 = heap[2];
	/*Place last element at top!*/
	heap[0] = heap[index];
	/*Percolate number to next possible spot*/
	percolateDown(heap,0,index);
}
void findMax(){

}
void increaseKey(){

}
void decreaseKey(){

}
void removeElement(){

}

void printHeap(int heap[],int currIndex){
	int i=1,j,k=1;
	while(i<5 && k<currIndex){
		printf("Values:  ");
		for(j=1;j<9;j++){
			printf("%6d", heap[i*j]);
			k++;
			if(i*j==currIndex-1){
				j=10;
			}
		}
		printf("\n");
		printf("Indicies:");
		for(j=1;j<=k;j++){
			printf("%6d", i*j);
			if((i*j)==k-1){
				break;
			}
		}
		printf("\n\n");
		i++;
	}
}
void percUp(int* heap, int child){
	int parent=1;
	while(parent){
		parent = (child-1)/2;
		if(heap[parent] > heap[child]){
			heap[parent] ^= heap[child];
			heap[child] ^= heap[parent];
			heap[parent] ^= heap[child];
		}
		child = parent;
	}
}

void percDown(){
	int swapChild;
	int child1;
	int child2;
	while(1){
		child1 = 2*parent+1;
		child2 = 2*(parent+1);
		swapChild = child1;
		/*If childrens out of bounds, we have reached the end*/
		if(child1 >= index && child2 >=index)
			return;
		/*If child2 is out of boundaries*/
		if(child2 == index)
			break;
		if(heap[child2] < heap[child1])
			swapChild = child2;
		/*Swap appropriate child*/
		if(heap[parent] > heap[swapChild]){
			heap[parent] ^= heap[swapChild];
			heap[swapChild] ^= heap[parent];
			heap[parent] ^= heap[swapChild];
		}
		parent = swapChild;

	}
	/*Special case where only 1 child to compare*/
	if(heap[parent] > heap[child1]){
		heap[parent] ^= heap[child1];
		heap[child1] ^= heap[parent];
		heap[parent] ^= heap[child1];
	}
}

/*
prompt for user input

(1) Delete Heap
	erase the current heap, start new one
(2) Build Heap
	erase current heap, prompt for line of integers
	insert values into an array
	heapify the array
(3) Insert Element
	percolate up if min
(4) Delete Min Element
	print element to the screen
	remove from heap
(5) Find Max Element
	compare leaves, return largest value
(6) Increase Key
	prompt for index and amount to change
	percolate if needed
(7) Decrease Key
	prompt for index and amount to change
	percolate if needed
(8) Remove element
	prompt for index
	swap with min child, remove once it is a leaf

After each action print the heap

Values:		  5	  8	  6	 10	 12	  7	100	 11
Indices:	  0	  1	  2	  3	  4	  5	  6	  7

Start heap with 1 element and resize as needed
*/
