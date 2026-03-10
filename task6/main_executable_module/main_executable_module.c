#include <stdio.h>
#include <stdlib.h>
#include "data_io.h"
#include "data_process.h"
#include "data_sort.h"
#include "decision.h"

int main()
{
    double *data = NULL;
    int n = 0;
    
    printf("LOAD DATA...\n");
    
    // Ввод количества элементов
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("ERROR: Invalid input\n");
        return 1;
    }
    
    // Выделение памяти
    data = (double*)malloc(n * sizeof(double));
    if (data == NULL) {
        printf("ERROR: Memory allocation failed\n");
        return 1;
    }
    
    // Ввод данных
    input(data, n);

    printf("RAW DATA:\n\t");
    output(data, n);

    printf("\nNORMALIZED DATA:\n\t");
    if (normalization(data, n)) {
        output(data, n);
    } else {
        printf("Normalization failed\n");
        free(data);
        return 1;
    }
    
    printf("\nSORTED NORMALIZED DATA:\n\t");
    sort(data, n);
    output(data, n);
    
    printf("\nFINAL DECISION:\n\t");
    if (make_decision(data, n)) {
        printf("YES");
    } else {
        printf("NO");
    }
    printf("\n");
    
    // Освобождение памяти
    free(data);
    
    return 0;
}