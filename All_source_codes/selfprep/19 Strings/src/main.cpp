#include <stdio.h>
#include <string.h>
#include <stddef.h> //For size_t, it is an unsigned type used for length, size and count, sizeof returns in size_t 

size_t my_strlen(const char *src){
    size_t len = 0;
    while (src[len] != '\0'){
        len++;
    }
    return len;
}

void my_strcpy(char * dest, const char * src, size_t dest_size){
    size_t i = 0;
    while (i < dest_size - 1 && src[i] != '\0'){
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

int main() {
    char str[] = "HELLO";

    //strlen
    printf("Length of String = %zu\n", strlen(str)); 

    char src[] = "WORLD";
    char dest[10];

    //strcpy
    strcpy(dest,src);

    printf("Printing dest = %s\n", dest); //Use %s to print strings

    //strcmp
    if (strcmp(src,dest) == 0){
        printf("Equal");
    }


    //  Custom strlen and strcpy

    char src1[] = "Embedded";
    char dest1[10];

    printf("Length using my own function = %zu\n",my_strlen(src1));

    my_strcpy(dest1, src1, sizeof(dest1));
    printf("Copied string using my own function = %s\n", dest1);
    printf("Length using my own function = %zu\n",my_strlen(dest1));

    return 0;
}