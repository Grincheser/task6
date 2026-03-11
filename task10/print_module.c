#include <stdio.h>
#include <time.h>

#include "print_module.h"

int print_char(char ch) 
{
    return putchar(ch);
}

void print_log(char (*print) (char), char* message)
{
    time_t raw_time;
    struct tm *time_info;
    char time_buffer[9];
    
    time(&raw_time);
    time_info = localtime(&raw_time);
    strftime(time_buffer, sizeof(time_buffer), "%H:%M:%S", time_info);
    
    char* prefix = Log_prefix;
    
    for (int i = 0; prefix[i] != '\0'; i++) {
        print(prefix[i]);
    }

    print(' ');
    
    for (int i = 0; time_buffer[i] != '\0'; i++) {
        print(time_buffer[i]);
    }
    
    print(' ');
    
    for (int i = 0; message[i] != '\0'; i++) {
        print(message[i]);
    }
}