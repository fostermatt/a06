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
int buildHeap(int*,int,char*);
int insertElement(int*, int, int);
void deleteMin();
void findMax();
void increaseKey();
void decreaseKey(int*,int,int);
void removeElement();
void printHeap(int*,int);
void percUp(int*,int);
void percDown(int*,int);

int main(){
	char* prompt1 = "Please choose an option\n(1) Delete Heap\n(2) Build Heap\n(3) Insert Element\n";
	char* prompt2 = "(4) Delete Minimum Element\n(5) Find Maximum Element\n(6) Increase Key\n";
	char* prompt3 = "(7) Decrease Key\n(8) Remove Element\n(9) Exit\n\nOption: ";
	int nextIndex = 1; /*current empty element*/
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
				nextIndex = deleteHeap(heap);
				break;
			case 2: /*Build Heap*/
				printf("\nPlease enter up to 32 numbers: ");
				fgets(inBuff,sizeof(inBuff),stdin);
				nextIndex = deleteHeap(heap);
				nextIndex = buildHeap(heap,nextIndex,inBuff);
				break;
			case 3: /*Insert Element*/
				printf("\nPlease enter value to be inserted: ");
				fgets(inBuff,sizeof(inBuff),stdin);
				sscanf(inBuff,"%d",&temp1);
				nextIndex = insertElement(heap,nextIndex,temp1);
				break;
			case 4: /*Delete Minimum Element*/
				deleteMin(heap,nextIndex);
				break;
			case 5: /*Find Maximum Element*/
				findMax(heap,nextIndex);
				break;
			case 6: /*Increase Key Value*/
				printf("\nPlease enter index of element to increase: ");
				printf("\nPlease enter amount to increase element: ");
				break;
			case 7: /*Decrease Key Value*/
				printf("\nPlease enter index of element to decrease: ");
				fgets(inBuff,sizeof(inBuff),stdin);
				sscanf(inBuff,"%d",&temp1);
				printf("\nPlease enter amount to decrease element: ");
				fgets(inBuff,sizeof(inBuff),stdin);
				sscanf(inBuff,"%d",&temp2);
				decreaseKey(heap,temp1,temp2);
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
		printHeap(heap,nextIndex);
	}
}
int deleteHeap(int heap[]){
	int i;
	for(i=0;i<32;i++){
		heap[i]=0;
	}
	return 0;
}
int buildHeap(int heap[], int nextIndex, char inBuff[]){
	int i, temp;
	char *myToken;
	myToken = strtok(inBuff," ");
	heap[nextIndex]=atoi(myToken);
	nextIndex++;
	while(myToken){
		temp = atoi(myToken);
		heap[nextIndex] = temp;
		nextIndex++;
		myToken = strtok(NULL," ");
	}
	/*
	percDown(heap,index);
	*/
	return nextIndex;
}

int insertElement(int heap[], int nextIndex, int value){
	heap[nextIndex] = value;
	if (heap[nextIndex]<heap[nextIndex/2] && nextIndex>0){
		percUp(heap,nextIndex);
	}
	nextIndex = nextIndex + 1;
	return nextIndex;
}

void deleteMin(int heap[], int nextIndex){
	printf("The minimum value of the heap was %d\n", heap[0]);
	heap[0]=heap[nextIndex-1];
}
void findMax(int heap[], int nextIndex){
	int i, maxVal = heap[nextIndex/2];
	for(i=nextIndex/2+1;i<nextIndex;i++){
		if(heap[i]>maxVal){
			maxVal=heap[i];
		}
	}
	printf("\nThe maximum value of this heap is %d\n", maxVal);
}
void increaseKey(){

}

void decreaseKey(int heap[],int index,int value){
	heap[index] = heap[index]-value;
	if (heap[index]<heap[index/2] && index>0){
		percUp(heap,index);
	}
}

void removeElement(){

}

void printHeap(int heap[],int nextIndex){
	int i,j,k=0;
	if(!nextIndex){
		return;
	}
	while(k<32){
		printf("Values:  ");
		for(i=1; i<9 && i+k < nextIndex; i++){
			printf("%6d",heap[i+k]);
		}
		printf("\nIndicies:");
		for(i=1; i<9 && i+k <nextIndex; i++){
			printf("%6d",i+k);
		}
		printf("\n\n");
		if(i+k>=nextIndex){
			k=100;
		}
		k+=8;
	}
	printf("\n\n");
}

void percUp(int heap[], int index){
	/* will only be called if parent and child are different */
	/* xor swap, update current index, call again if needed */
	heap[index/2] ^= heap[index];
	heap[index] ^= heap[index/2];
	heap[index/2] ^= heap[index];
	index = index/2;
	if (heap[index]<heap[index/2] && index>0){
		percUp(heap,index);
	}
}

void percDown(){
	/*int swapChild;
	int child1;
	int child2;
	while(1){
		child1 = 2*parent+1;
		child2 = 2*(parent+1);
		swapChild = child1;

		if(child1 >= index && child2 >=index)
			return;

		if(child2 == index)
			break;
		if(heap[child2] < heap[child1])
			swapChild = child2;

		if(heap[parent] > heap[swapChild]){
			heap[parent] ^= heap[swapChild];
			heap[swapChild] ^= heap[parent];
			heap[parent] ^= heap[swapChild];
		}
		parent = swapChild;
	}
	if(heap[parent] > heap[child1]){
		heap[parent] ^= heap[child1];
		heap[child1] ^= heap[parent];
		heap[parent] ^= heap[child1];
	}*/
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
	percolate down if needed
(7) Decrease Key
	prompt for index and amount to change
	percolate up if needed
(8) Remove element
	prompt for index
	swap with min child, remove once it is a leaf

After each action print the heap

Values:		  5	  8	  6	 10	 12	  7	100	 11
Indices:	  0	  1	  2	  3	  4	  5	  6	  7

Start heap with 1 element and resize as needed
*/
