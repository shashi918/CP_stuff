#include <stdlib.h>
#include <stdbool.h>

int *array_diff(const int *arr1, size_t n1, const int *arr2, size_t n2, size_t *z) {

    int* diffArr = (int*) malloc(n1 * sizeof(size_t));
    
    *z = 0;
        
    for (size_t i = 0; i < n1; i++) {
        bool inArr2 = false;
        
        for (size_t j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                inArr2 = true;
                break;
            }
        }
        
        
        if (!inArr2) {
            diffArr[*z] = arr1[i];
            *z += 1;
        }
    }


    return diffArr;
}