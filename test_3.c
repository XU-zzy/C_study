#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char *str = (char *)malloc(sizeof(char)*1000);
    
    fgets(str,100,stdin);
    printf("%s",str);
    getchar();
    
    char ch;
    scanf("%c",&ch);
    printf("[");
    char c;
    
    while(*str != '\0'){
        c = *str;
        
        while(c != ch && c != '\0' && c != '\n'){
            printf("%c",c);
            c = *++str;
        }
        
        if(c == '\n' || c == '\0'){
            break;
        }
        printf(",");
        
        ++str;
    }

    printf("]\n");

    return 0;
}
