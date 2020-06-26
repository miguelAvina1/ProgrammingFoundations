#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

#if defined(__GNUC__)
#define PACKED  __attribute__((packed))
#else 
#define PACKED
#endif

// This could be easily done in python by having a dictionary ID:LastPackageID

typedef struct PACKED { 
	uint16_t ID;
	uint8_t lastPackageID;
} Barrel;


typedef struct {
	Barrel * array;
	size_t used;
	size_t size;
} DynamicArray;

bool initBarrelArray(DynamicArray *a, size_t initialSize) {	// Initializing the Array structure
	// Provide actual pointer where the array will be saved, allocating dynamic storage
	a->array = (Barrel *) malloc(initialSize * sizeof(Barrel));	
	if (a->array == NULL) {
		printf("Failed to initialized Array");
		return false;
	}
	a->used = 0;
	a->size = initialSize;
	return true;
}

bool insertBarrel(DynamicArray *a, uint16_t barrel_ID, uint8_t lastPkgID) {
	a->array[a->used].ID = barrel_ID;
	a->array[a->used].lastPackageID = lastPkgID;
	// Or use memcpy from a barrel struct passed by reference
	a->used += 1;

	if (a->used >= a->size) {
		a->size *= 2;	// Double array size
		a->array = (Barrel *) realloc(a->array, a->size*sizeof(Barrel));
		if (a->array == NULL) {
			printf("Failed to reallocate Array");
			return false;
		}
	}
	return true;
}

void freeBarrelArray(DynamicArray *a) {
	free(a->array);
	a->array = NULL;
	a->used = 0;
	a->size = 0;

}

DynamicArray Barrel_data;
int i;

int main() {
	
	initBarrelArray(&Barrel_data, 10);

	for (i = 0; i < 100; i++) {
		insertBarrel(&Barrel_data, i, i*2);	// Will automatically resize: 10->20->40->80->160.
	}
	printf("Used: %d\n", Barrel_data.used);
	printf("Size: %d\n", Barrel_data.size);
	for(i = 3000; i < 30000; i += 200) { // 135 new barrels, ID 3000, 3135, 3270
		insertBarrel(&Barrel_data, i, i+1);
	}
	printf("ID of entry 10: %d\n", Barrel_data.array[10].ID);
	printf("Package of entry 10: %d\n", Barrel_data.array[10].lastPackageID);
	printf("ID of entry 101: %d\n", Barrel_data.array[100].ID);
	printf("Package of entry 101: %d\n", Barrel_data.array[101].lastPackageID);
	printf("Used: %d\n", Barrel_data.used);
	printf("Size: %d\n", Barrel_data.size);
	printf("Barrel size: %d\n", sizeof(Barrel)); 

	freeBarrelArray(&Barrel_data);
	
	return 1;
}