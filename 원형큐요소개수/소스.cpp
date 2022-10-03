#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QUEUE_SIZE 5

typedef struct DequeType 
{
    char data[MAX_QUEUE_SIZE];
    int front, rear;
}DequeType;

void init_deque(DequeType* s) 
{
    s->front = 0;
    s->rear = 0;
}

int get_count(DequeType* q)
{
    int count = q->rear;
    if (q->front > count) 
        count = count + MAX_QUEUE_SIZE;
    return  count - (q->front);
}

void add_rear(DequeType* s, char ch) 
{
    s->data[++s->rear] = ch;
}

char get_front(DequeType* s) 
{
    return (s->data[++s->front]);
}

char get_rear(DequeType* s) 
{
    return (s->data[s->rear--]);
}

int main(void)
{
    DequeType queue;
    char s[100] = "abcd";
    init_deque(&queue);
    for (int i = 0; i < strlen(s); i++) 
    {
        add_rear(&queue, s[i]);
    }

    printf("요소의 개수 %d개\n", get_count(&queue));

    int equal = 1;
    while (get_count(&queue) > 1 && equal != 0) 
    {
        char first = get_front(&queue);
        char last = get_rear(&queue);
        if (first != last)
            equal = 0;
    }
    if (equal == 1)
        printf("회문입니다.\n");
    else
        printf("회문이 아닙니다.\n");

}