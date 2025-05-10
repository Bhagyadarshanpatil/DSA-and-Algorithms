//C program to convert an infix expression to an postfix expression.
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int prec(char c, int in){
    switch(c){
        case '#': return -1;
        case '(': return in==1? 9:0;
        case ')': return 0;
        case '+':
        case '-': return in==1? 2:3;
        case '*':
        case '%': 
        case '/': return in==1? 4:5;
        case '^': 
        case '$': return in==1? 7:6;
        default: return in==1? 8:9;
    }
}
void push(char stack[],int* top, char c){
    stack[++(*top)]=c;
}
char pop(char stack[],int* top){
    return stack[(*top)--];
}
void compare(char c,char stack[], int *top, char postfix[], int* n){
    if (prec(c,1)>prec(stack[*top],0)){
        push(stack,top,c);
    }
    else if(prec(c,1)<prec(stack[*top],0)){
        postfix[++(*n)]=pop(stack,top);
        compare(c,stack,top,postfix,n);
    }
    else if(prec(c,1)==prec(stack[*top],0)){
        pop(stack,top);
    }
}
void main(){
    char infix[50],postfix[50],stack[50];
    int top=-1,n=-1,i=0;
    push(stack,&top,'#');
    printf("Enter infix expression: \n");
    scanf("%s",infix);
    for (i=0;i<strlen(infix);i++){
        char c=infix[i];
        compare(c,stack,&top,postfix,&n);    
    }
    while(top>0){
        postfix[++n]=pop(stack,&top);
    }
    postfix[++n]='\0';
    printf("postfix expression= %s \n",postfix);
}