/*
Matt Foster
CS 302
Assignment 6
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void deleteHeap();
void heapify();
void insert();
void delete();
void findMax();
void increaseKey();
void decreaseKey();
void removeElement();

int main(){
	char* prompt = "Please choose an option\n
					(1) Delete Heap\n
					(2) Build Heap\n
					(3) Insert Element\n
					(4) Delete Minimum Element\n
					(5) Find Maximum Element\n
					(6) Increase Key\n
					(7) Decrease Key\n
					(8) Remove Element"
	int* heap = (int*)malloc(sizeof(int));
	int length = 1;
	int currIndex = 0;
	char buffer[50];
	int input;
}
