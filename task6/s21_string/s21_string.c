#include <stdlib.h> 
#include "s21_string.h"

unsigned long long s21_strlen(const char *str)
{
    unsigned long long length = 0;
    
    if (str != NULL) {
        while (str[length] != '\0') {
            length++;
        }
    }
    
    return length;
}