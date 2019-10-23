#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_LEN 500
typedef char element;
typedef struct{
    int top;
    element stack[MAX_LEN];
}StackType;

void init_stack(StackType * s)
{
    s->top=-1;
}

int is_empty(StackType *s)
{
    if(s->top==-1)
        return 1;
    return 0;
}

int is_full(StackType *s)
{
    if(s->top==MAX_LEN-1)
        return 1;
    return 0;
}

void insert_func(StackType *s, element e)
{
    if(is_full(s)){
        fprintf(stderr, "스택이 꽉찼음.");
        exit(1);
    }
    //s->top =s->top+1
    //s->stack[s->top]=e;
    s->stack[++s->top]=e;
}

element pop_func(StackType*s)
{
    if(is_empty(s)){
        fprintf(stderr,"스택이 비었음.");
        exit(1);
    }

    element pop_val= s->stack[s->top];
    s->top--;
    return pop_val;
}

element peek_func(StackType* s)
{
    if(is_empty(s)){
        fprintf(stderr,"스택이 비었음.");
        exit(1);
    }
    return s->stack[s->top];
}

int main(void)
{
    //스택 정의
    StackType S;

    //스택 초기화
    init_stack(&S);

    char str[]="(()())";
    for(int i=0; i<strlen(str); i++){
        insert_func(&S, str[i]);
        printf("%c",peek_func(&S));
    }
    printf("\n");

    printf("%c\n",pop_func(&S));
    printf("%c\n",peek_func(&S));
    for(int i=0; i<=S.top; i++){
        printf("%c", S.stack[i]);
    }
    printf("\n");
}
