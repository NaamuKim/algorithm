#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define SIZE 10001

typedef struct
{
	int queue[SIZE];
	int front, rear;
}QueueType;

void Queue_init(QueueType* q)
{
	q->front = q->rear = 0;
}

int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

int is_full(QueueType* q)
{
	return (q->front == (q->rear + 1) % SIZE);
}

void enqueue(QueueType* q, int e)
{
	if (is_full(q))
		return;

	q->rear = (q->rear + 1) % SIZE;
	q->queue[q->rear] = e;
}

int dequeue(QueueType* q)
{
	if (is_empty(q))
		return -1;

	q->front = (q->front + 1) % SIZE;
	return q->queue[q->front];
}

int front(QueueType* q)
{
	if (is_empty(q))
		return -1;
	return q->queue[q->front + 1];
}

int back(QueueType* q)
{
	if (is_empty(q))
		return -1;
	return q->queue[q->rear];
}

int size(QueueType* q)
{
	if (q->front < q->rear)
		return q->rear - q->front;
	else
		return SIZE - q->front + q->rear;
}

int main()
{
	QueueType queue;
	Queue_init(&queue);

	int i, n, e;
	char op[6];

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf(" %s", op);

		if (strcmp(op, "push") == 0)
		{
			scanf(" %d", &e);
			enqueue(&queue, e);
		}
		else if (strcmp(op, "pop") == 0)
		{
			e = dequeue(&queue);
			printf("%d\n", e);
		}
		else if (strcmp(op, "front") == 0)
		{
			e = front(&queue);
			printf("%d\n", e);
		}
		else if (strcmp(op, "back") == 0)
		{
			e = back(&queue);
			printf("%d\n", e);
		}
		else if (strcmp(op, "empty") == 0)
		{
			e = is_empty(&queue);
			printf("%d\n", e);
		}
		else if (strcmp(op, "size") == 0)
		{
			e = size(&queue);
			printf("%d\n", e);
		}
	}

	return 0;
}