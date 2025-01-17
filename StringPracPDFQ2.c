#include <stdio.h>
#include<ctype.h>
#include<string.h>

int main() {
    // Write C code here
    char str[100],s[4]=" ";
    char *tok;
    int count=0;
    scanf("%[^\n]",str);
    tok = strtok(str,s);
    while(tok!=NULL){
    count++;
    tok = strtok(NULL,s);
}
printf("%d",count);
    return 0;
}
