#include<stdio.h>
#include<ctype.h>

char array[30];
char stack[20];
char *element;
int top = -1;

int push(char element){
    top++;
    stack[top] = element;
}
char pop(){
    char x = stack[top];
    if (top == -1)
        printf("\nstack underflow");
    else
    {
        top--;
        //printf("\n%d", top);
    }
    return x;
}
int bodmas(char sign){
    if (sign == '(')
        return 0;
    if (sign == '-')
        return 1;
    if (sign == '+')
        return 2;
    if (sign == '*')
        return 3;
    if (sign == '$')
        return 4;
    if (sign == '/')
        return 5;
}

int main(int argc, char const *argv[])
{   
    char expression[20];
    printf("enter expression:👉️ ");
    scanf("%s", expression);
    printf("================\n");
    element = expression;
    while (*element != '\0')
    {   
        if (isalnum(*element))
            printf("%c",*element);
        else if (*element == '(') 
            push(*element);
        else if (*element == ')')
        {   
            do
            {
                printf("%c",pop()); 
            } while (stack[top] != '(');
            pop();
        }else if (ispunct(*element))
        {
            if (top == -1)
                push(*element);
            else if (bodmas(*element) < bodmas(stack[top] ))
            {
                printf("%c",pop());
                push(*element);
            }else
                push(*element);   
        }else
            printf("\ninvalid expression\n");
        element++;
    }
    while (top != -1) 
    {
        printf("%c",pop());
    }
    printf("\n");
    
    
    return 0;
}
