#include<stdio.h>
#include<ctype.h>


int isOperator(char val){
    if (val == '+' || val == '-' || val == '*' || val == '/')
        return 1;
    return 0;
}

int isSpace(char val){
    if (val == ' ' || val == '\n' || val == '\t')
        return 1;
    return 0;
}

int operationPerformer(int left, int right, char operation){
    switch (operation){
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '*':
        return left * right;
    case '/':
        if (right != 0)
            return left / right;
        return -1;
    default:
        return -1;
    }
}

int calculator(char *exp){
    int numbers[100];
    int operators[100];
    int num_index = -1;
    int op_index = -1;

    int i=0;

    while (exp[i] != '\0'){
        int val = exp[i];
        
        if(isSpace(val)){
            i++;
            continue;
        }

        if(isdigit(val)){
            int num=0;
            while(isdigit(exp[i])){
                num = num*10 + (exp[i] - '0');
                i++;
            }
            i--;
            numbers[++num_index]=num;
        }
        else if(isOperator(val)){
            
            if(val == '-' && (i == 0 || isOperator(exp[i-1]) )){
                i++;
                int num=0;
                while(isDigit(exp[i])){
                    num = num*10+(exp[i]-'0');
                    i++;
                }
                i--;
                numbers[++num_index] = -num;
            } else{
                
                while(op_index != -1 && ((operators[op_index] == '*' || operators[op_index] == '/') || (val == '+' || val == '-'))){
                    int right = numbers[num_index--];
                    int left = numbers[num_index--];
                    char op = operators[op_index--];

                    numbers[++num_index]=operationPerformer(left, right, op);
                }
                operators[++op_index]=val;
            }
        }
        else{
            return -1;
        }
        i++;
    }

    while(op_index != -1){
        int right = numbers[num_index--];
        int left = numbers[num_index--];
        char op = operators[op_index--];
        numbers[++num_index]=operationPerformer(left, right, op);
    }

    return numbers[num_index];
    
}

int main(){
    char exp[100];
    printf("Enter: ");
    scanf("%[^\n]", exp); 
    printf("Expression : %s \n", exp);

    int result = calculator(exp);

    if (result == -1)
        printf("Invalid Expression \n");
    else
        printf("Result %d ", result);

    return 0;
}