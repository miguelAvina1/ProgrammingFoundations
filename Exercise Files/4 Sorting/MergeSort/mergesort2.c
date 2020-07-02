
#include <stdio.h>

void print_items(int* p_items, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", p_items[i]);
    }
    printf("\r\n");
    
}

void merge_sort(int* p_items, int size) {
    if (size > 1) {
        int middle;
        int i, j, k;
        int * leftpart;
        int * rightpart;
        leftpart = (int *) malloc(sizeof(int)*middle);
        rightpart = (int *) malloc(sizeof(int)*(size-middle));

      
        middle = size / 2;
        
        memcpy(leftpart, p_items, sizeof(int)*middle); // Filling left leftpart
        memcpy(rightpart, &p_items[middle], sizeof(int)*(size-middle));
        
        merge_sort(leftpart, middle);           
        merge_sort(rightpart, size-middle);
        i = 0;
        j = 0;
        k = 0;
        
        while ((i < middle) && (j < size-middle)) {
            if (leftpart[i] < rightpart[j]) {
                p_items[k] = leftpart[i];
                i += 1;
            } else {
                p_items[k] = rightpart[j];
                j += 1;
            }
            k += 1; 
        }
        
        if (i < middle) {
            for (i ; i < middle; i++) {
                p_items[k] = leftpart[i];
                k += 1;
            }
        }
        else if (j < size-middle) {
                for (j ; j < size-middle; j++) {
                p_items[k] = leftpart[j];
                k += 1;
            }
        }
            
    }
    
}

int main()
{
    printf("Hello World\n\r");
    
    int items[10] = {6, 20, 8, 19, 56, 23, 87, 41, 49, 53};
    print_items(items, 10);

    
    
    merge_sort(items, 10);
    print_items(items, 10);

    return 0;
}