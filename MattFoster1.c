/*
Matt Foster
CS 302
Assignment 6
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int deleteHeap(int*);
int buildHeap(int*, int, char*);
int insertElement(int*, int, int);
int deleteMin(int*, int);
void findMax(int*, int);
void increaseKey(int*, int, int, int);
void decreaseKey(int*, int, int);
int removeElement(int*, int, int);
void printHeap(int*,int);
void percUp(int*,int);
void percDown(int*,int,int);
void swapValues(int*,int,int);

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

	while(1){ /*repeat until exit option received*/
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
				printf("nextIndex is %d right now\n", nextIndex);
				nextIndex = buildHeap(heap,nextIndex,inBuff);
				break;
			case 3: /*Insert Element*/
				printf("\nPlease enter value to be inserted: ");
				fgets(inBuff,sizeof(inBuff),stdin);
				sscanf(inBuff,"%d",&temp1);
				nextIndex = insertElement(heap,nextIndex,temp1);
				break;
			case 4: /*Delete Minimum Element*/
				nextIndex = deleteMin(heap,nextIndex);
				break;
			case 5: /*Find Maximum Element*/
				findMax(heap,nextIndex);
				break;
			case 6: /*Increase Key Value*/
				printf("\nPlease enter index of element to increase: ");
				fgets(inBuff,sizeof(inBuff),stdin);
				sscanf(inBuff,"%d",&temp1);
				printf("\nPlease enter amount to increase element: ");
				fgets(inBuff,sizeof(inBuff),stdin);
				sscanf(inBuff,"%d",&temp2);
				increaseKey(heap,temp1,temp2,nextIndex);
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
				fgets(inBuff,sizeof(inBuff),stdin);
				sscanf(inBuff,"%d",&temp1);
				nextIndex = removeElement(heap,temp1,nextIndex);
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
	/* input: heap aray */
	/* output: empty heap and next empty index */
	/* function reintializes array and counter */
	int i;
	for(i=0;i<32;i++){
		heap[i]=0;
	}
	return 1;
}

int buildHeap(int heap[], int nextIndex, char inBuff[]){
	/* input: heap array, next empty index, input buffer */
	/* output: heapified array, next empty index */
	/* function puts integers from input buffer in array, then heapifies the array */
	int i, temp;
	char *myToken;
	myToken = strtok(inBuff," ");
	while(myToken){
		temp = atoi(myToken);
		heap[nextIndex] = temp;
		nextIndex++;
		myToken = strtok(NULL," ");
	}
	for(i=(nextIndex-1)/2; i>0;i--){
		percDown(heap,i,nextIndex);
	}
	return nextIndex;
}

int insertElement(int heap[], int nextIndex, int value){
	/* input: heap array, next empty index, value to insert */
	/* output: heap array with element added, next empty index */
	/* function puts new value on bottom of heap and percolates up if needed */
	heap[nextIndex] = value;
	percUp(heap,nextIndex);
	nextIndex = nextIndex + 1;
	return nextIndex;
}

int deleteMin(int heap[], int nextIndex){
	/* input: heap array, next empty index */
	/* output: heap array, next empty index */
	/* function displays min value, removes it, puts last element at root, then perc down as needed */
	if(nextIndex==1){
		printf("\nNo heap available.\n");
		return nextIndex;
	}
	else{
		printf("\nThe minimum value of the heap was %d\n", heap[1]);
		heap[0]=heap[nextIndex-1];
		percDown(heap,0,nextIndex);
		return nextIndex-1;
	}
}

void findMax(int heap[], int nextIndex){
	/* input: heap array, next empty index */
	/* output: heap array, output of max value found */
	/* function searches leaves for max value */
	int i, maxVal = heap[nextIndex/2];
	if(nextIndex==1){
		printf("\nNo heap available.\n");
		return;
	}
	else{
		for(i=nextIndex/2+1;i<nextIndex;i++){
			if(heap[i]>maxVal){
				maxVal=heap[i];
			}
		}
		printf("\nThe maximum value of this heap is %d\n", maxVal);
	}
}

void increaseKey(int heap[], int index, int value, int nextIndex){
	/* input: heap array, index of element to change, amount to increase element, next empty element */
	/* output: heap array */
	/* function increases specified element by specified value and then percolates down as needed */
	heap[index] = heap[index] + value;
	percDown(heap,index,nextIndex);
}

void decreaseKey(int heap[],int index,int value){
	/* input: heap array, index of value to change, amount to change specified value */
	/* output: updated heap array */
	/* function decreases specified element by specified value and then percolates up as needed */
	heap[index] = heap[index]-value;
	if (heap[index]<heap[index/2] && index>0){
		percUp(heap,index);
	}
}

int removeElement(int heap[], int index, int nextIndex){
	/* input: heap array, index of element to remove, next empty index */
	/* output: updated heap array, updated next empty index */
	/* function will decrease specified value by 9999 and then delete the minimum value */
	decreaseKey(heap,index,9999);
	return deleteMin(heap,nextIndex);
}

void printHeap(int heap[],int nextIndex){
	/* input: heap array, next empty index */
	/* output: prints formated heap to console */
	/* function prints heap to screen, 8 elements per row, stops when max value or final value is reached */
	int i,j,k=0;
	if(nextIndex<2){
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
	printf("\n");
}

void percUp(int heap[], int index){
	/* input: heap array, index to manipulate */
	/* output: updated heap array */
	/* function will compare  */
	if(heap[index]<heap[index/2] && index/2 > 0){
		swapValues(heap,index/2,index);
		index = index/2;
		if (heap[index]<heap[index/2] && index/2>0){
			percUp(heap,index);
		}
	}
}

void percDown(int heap[], int parInd, int nextIndex){
	int leftInd, rightInd, swapInd;
	leftInd = parInd * 2;
	rightInd = parInd * 2 + 1;
	if(leftInd >= nextIndex && rightInd >= nextIndex){
		return; /* children don't exist */
	}
	if(heap[parInd] < heap[leftInd] && heap[parInd] < heap[rightInd]){
		return; /* children are larger than parent */
	}
	if(heap[leftInd] < heap[rightInd]){
		swapInd = leftInd;
	}
	else if (heap[leftInd]>heap[rightInd] && rightInd >= nextIndex)
		swapInd = leftInd;
	else
		swapInd = rightInd;
	swapValues(heap,parInd,swapInd);
	parInd = swapInd;
	percDown(heap, swapInd,nextIndex);
}

void swapValues(int heap[], int a, int b){
	if(heap[a]==heap[b]){
		return;
	}
	heap[a] ^= heap[b];
	heap[b] ^= heap[a];
	heap[a] ^= heap[b];
}
