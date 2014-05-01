/*
Matt Foster
CS 302
Assignment 6
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
/*
void buildHeap();*/
void insertElement(int*,int*,int*,int);/*
void deleteMin();
void findMax();
void increaseKey();
void decreaseKey();
void removeElement();
*/
void printHeap(int*,int);

int main(){
	char* prompt = "Please choose an option\n(1) Delete Heap\n(2) Build Heap\n(3) Insert Element\n(4) Delete Minimum Element\n(5) Find Maximum Element\n(6) Increase Key\n(7) Decrease Key\n(8) Remove Element\n(9) Exit\n\nOption: ";
	int* heap = (int*)malloc(sizeof(int));
	int heapSize = 1,currIndex = 0, userSelect, temp1, temp2;
	char inBuff[50];

	while(true){ /*repeat until exit option received*/
		printf("\n%s", prompt);
		fgets(inBuff,sizeof(inBuff),stdin);
		sscanf(inBuff,"%d",&userSelect);

		switch(userSelect){
			case 1: /*Delete Heap*/
				printf("\nDelete Heap Selected\n");
				free(heap);
				heap = (int*)malloc(sizeof(int));
				heapSize = 1;
				currIndex = 0;
				break;
			case 2: /*Build Heap*/
				printf("\nBuild Heap selected\n");
				break;
			case 3: /*Insert Element*/
				printf("Please enter value to be inserted: ");
				fgets(inBuff,sizeof(inBuff),stdin);
				sscanf(inBuff,"%d",&temp1);
				insertElement(heap,&heapSize,&currIndex,temp1);
				break;
			case 4: /*Delete Minimum Element*/
				printf("\nDelete Min Element selected\n");
				break;
			case 5: /*Find Maximum Element*/
				printf("\nFind Max Element selected\n");
				break;
			case 6: /*Increase Key Value*/
				printf("\nIncrease Key Value selected\n");
				break;
			case 7: /*Decrease Key Value*/
				printf("\nDecrease Key Value selected\n");
				break;
			case 8: /*Remove elment*/
				printf("\nRemove Element\n");
				break;
			case 9: /*Exit*/
				printf("\nExit selected\n");
				return 0;
			default: /*Invalid Input*/
				printf("Please choose a valid option\n");
		}
		printHeap(heap,heapSize);
	}
}

void insertElement(int *heap,int *heapSize,int *currIndex,int value){
	heap[*currIndex]=value;
	heapSize++;
	currIndex++;
}

void printHeap(int *heap, int heapSize){
	int i, j=0;
	printf("Values:    %d\n", heap[0]);
	printf("Indicies:  %d\n",0);
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
