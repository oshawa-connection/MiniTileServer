#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main() {
    char currentChar = '\n';
    char * myString = "HELLO THERE";
    FILE *f = fopen("hello.png", "r");
    while (1) {
        currentChar = getc(f);
        if (currentChar == EOF) {
            break;
        }
        putc(currentChar,stdout);
        char fn[15];
        strcpy( fn, "HELLO THERE" );
        strcat(fn,"AN");
        
        printf("%s\n",fn);
        
    }
    return 0;
}