
#include <string.h> // memcpy
#include <stdlib.h> // srand()
#include <time.h> 
#include <stdio.h>
#define BIG 50000
int* rng();

int bubbleSort(int* unsorted);
int selectionSort(int* unsorted);
int insertionSort(int* unsorted);


int main( ) {
	unsigned int mySeed = 133760126
	srand(mySeed);
	
	int* raw;
	// Bubble-Linear
	*raw = rng();
	*raw = Bubble(raw);
	
	// Bubble-Binary
	raw
	// Selection-Linear (to be implemented)
	
	// Selection-Binary (to be implemented)
	
	// Insertion-Linear (to be implemented)
	
	// Insertion-Binary (to be implemented)
	
	printf("Hello World \n");
	return;
}

int* rng( ) { // generates "randomized" data to be sorted
	int* unsortedPureArray = (int*)malloc(BIG * sizeof(int)); // tries to allocate space for the array
	
	if (unsortedPureArray == NULL) {
		printf(" Mem Alloc Fail, exiting \n");
		exit(1);
	}
	
	for (int i = 0; i < BIG; i++) {
		unsortedPureArray[i] = rand();
	}
	return unsortedPureArray;
}
