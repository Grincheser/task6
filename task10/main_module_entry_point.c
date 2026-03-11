#include <stdio.h>
#include <stdlib.h>
#include "print_module.h"
#include "documentation_module.h"

int main()
{
    print_log(print_char, Module_load_success_message);
    
    char* documents[] = {Documents};
    int document_count = Documents_count;
    
    int* availability_mask = check_available_documentation_module(validate, document_count, 
                                                                  documents[0], documents[1], 
                                                                  documents[2], documents[3]);
    
    if (availability_mask) {
        for (int i = 0; i < document_count; i++) {
            print_char('[');
            
            int len = 0;
            for (int j = 0; documents[i][j] != '\0'; j++) {
                print_char(documents[i][j]);
                len++;
            }
            for (int j = len; j < 15; j++) {
                print_char(' ');
            }
            
            print_char(' ');
            print_char(':');
            print_char(' ');
            
            if (availability_mask[i]) {
                print_char('a');
                print_char('v');
                print_char('a');
                print_char('i');
                print_char('l');
                print_char('a');
                print_char('b');
                print_char('l');
                print_char('e');
            } else {
                print_char('u');
                print_char('n');
                print_char('a');
                print_char('v');
                print_char('a');
                print_char('i');
                print_char('l');
                print_char('a');
                print_char('b');
                print_char('l');
                print_char('e');
            }
            
            print_char(']');
            print_char('\n');
        }

        free(availability_mask);
    }
    
    return 0;
}