#include<stdio.h>

#define nameLength 50
#define maxLength 10
#define maxColumn 101

int vowelChecker(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

int stringLength(char *str){
    int len=0;
    while(str[len] != '\0')
        len++;
    return len;
}

void copyString(char *str1, char *str2){
    int i=0;
    while(str2[i] != '\0'){
        str1[i]=str2[i];
        i++;
    }
    str1[i]= '\0';
}

int main(){
    int r, c;
    char student[maxLength][maxColumn][nameLength];
    printf("Enter number of rows: ");
    scanf("%d", &r);
    while(r<1 || r>10){
        printf("Invalid: Enter between 1-10\n");
        scanf("%d", &r);
    }

    printf("Enter number of cols: ");
    scanf("%d", &c);
    while(c<1 || c>101){
        printf("Invalid: Enter between 1-101\n");
        scanf("%d", &c);
    }

    int vowelStarting = 0;
    char longestName[50] = " ";

    printf("Enter the name of students: \n");
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printf("Student name at (%d, %d): ", i, j);
            scanf("%s", &student[i][j]);

            if(vowelChecker(student[i][j][0]))
                vowelStarting++;

            if(stringLength(student[i][j]) > stringLength(longestName))
                copyString(longestName, student[i][j]);
        }
    }

    printf("\nName of Students: \n");
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            printf("%s ", &student[i][j]);
        }
        printf("\n");
    }

    printf("\nNumber of names starting with vowels: %d\n", vowelStarting);

    printf("Student with longest name: %s\n", longestName);

    return 0;
}