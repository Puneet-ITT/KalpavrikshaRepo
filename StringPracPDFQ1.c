#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    char str[100],opt[101];
    int i,index=0,flag=0,len;
    scanf("%s",str);
    len=strlen(str);
    for(int i=0;i<len;i++){
        if(i==0){
                opt[index++]=str[i];
                continue;
            }
        for(int j=0;j<strlen(opt);j++){
            if(str[i]==opt[j] && i!=j){
                flag=0;
                break;
            }
            else{
                flag=1;
            }
            }
            if(flag==1){
                opt[index++]=str[i];
            }
        }
    
    i=0;
    opt[index++]='\0';
    while(opt[i]!='\0'){
        printf("%c",opt[i]);
        i++;
    }
    
    return 0;
}
