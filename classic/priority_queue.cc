#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct HeapStruct {
    int size;
    int cap;
    int *elem;
};

typedef struct HeapStruct* PriorityQueue;

bool pqIsFull(PriorityQueue hp)
{
    return hp->size >= hp->cap;
}

bool pqIsEmpty(PriorityQueue hp)
{
    return hp->size == 0;
}

// 初始化堆，使用数组实现
PriorityQueue initHeap(int max)
{
    PriorityQueue hp = (PriorityQueue)malloc(sizeof(struct HeapStruct));
    hp->size = 0;
    hp->cap = max;
    hp->elem = (int*)malloc(sizeof(int) * (max+1));
    hp->elem[0] = INT_MIN;

    return hp;
}

void insert(PriorityQueue hp, int val)
{
    if (pqIsFull(hp))
    {
        printf("priority queue is full\n");
        return;
    }

    // 上溯, 默认小堆
    int i = 0;
    for (i = ++hp->size; hp->elem[i/2] > val; i /= 2)
    {
        hp->elem[i] = hp->elem[i/2];
    }
    hp->elem[i] = val;
}

int deleteMin(PriorityQueue hp)
{
    if (pqIsEmpty(hp))
    {
        printf("priority queue is empty\n");
        return -1;
    }

    // 下溯
    int min = hp->elem[1];
    int last = hp->elem[hp->size--];
    int i = 1, child;
    for (; i*2 <= hp->size; i=child)
    {
        child = i*2;
        if (child < hp->size && hp->elem[child] > hp->elem[child+1])
            child++;
        if (hp->elem[child] < last)
            hp->elem[i] = hp->elem[child];
        else
            break;
    }
    hp->elem[i] = last;

    return min;
}


int main()
{
    int a[] = {4,3,2,6,1};
    int len = sizeof(a)/sizeof(int);

    PriorityQueue hp = initHeap(5);
    for (int i = 0; i < len; ++i)
    {
        insert(hp, a[i]);
    }
    for (int i = 1; i <= 5; ++i)
    {
        printf("%d ", deleteMin(hp));
    }
    printf("\n");
    return 0;
}
