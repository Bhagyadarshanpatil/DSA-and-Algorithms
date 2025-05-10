#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void push(int stack[],int* top, int val){
    stack[++(*top)]= val;
}
int pop(int stack[],int* top){
    return stack[(*top)--];
}
void main(){
    char str[50], s;
    int i=0,stack[50],op1,op2,res,top=-1;
    printf("enter postfix expression: ");
    scanf("%s",str);
    while(str[i]!='\0'){
        s=str[i++];
        switch(s){
            case '+':
                op1=pop(stack,&top);
                op2=pop(stack,&top);
                res=op2+op1;
                push(stack,&top,res);
                break;
            case '-':
                op1=pop(stack,&top);
                op2=pop(stack,&top);
                res=op2-op1;
                push(stack,&top,res);
                break;
            case '*':
                op1=pop(stack,&top);
                op2=pop(stack,&top);
                res=op2*op1;
                push(stack,&top,res);
                break;
            case '/':
                op1=pop(stack,&top);
                op2=pop(stack,&top);
                res=op2/op1;
                push(stack,&top,res);
                break;
            case '%':
                op1=pop(stack,&top);
                op2=pop(stack,&top);
                res=op2%op1;
                push(stack,&top,res);
                break;
            case '^':
                op1=pop(stack,&top);//op1==power
                op2=pop(stack,&top);//op2==base
                res=pow(op2,op1);
                push(stack,&top,res);
                break;
            default:
                push(stack,&top,s-'0');
                //printf("pushed %d",s-'0');
        }
    }
    printf("the value of the postfix expression=%d ",stack[top]);
}