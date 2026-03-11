#include "documentation_module.h"
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

int validate(char* data)
{
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

int* check_available_documentation_module(int (*validate) (char*), int document_count, ...)
{
    if (document_count <= 0 || document_count > 16) return NULL;
    
    int* availability_mask = (int*)malloc(document_count * sizeof(int));
    if (!availability_mask) return NULL;
    
    va_list args;
    va_start(args, document_count);
    
    for (int i = 0; i < document_count; i++) {
        char* document = va_arg(args, char*);
        availability_mask[i] = validate(document);
    }
    
    va_end(args);
    
    return availability_mask;
}