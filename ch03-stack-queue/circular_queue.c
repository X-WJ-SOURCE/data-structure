#define MAXSIZE 100
typedef struct{
	int data[MAXSIZE];
	int rear;
	int front;
}SqQueue;
int EnQueue(SqQueue *Q,int x)
{
	if(Q->rear>=MAXSIZE)
	{
		return 0;
	}
	else{
		Q->data[Q->rear]=x;
		Q->rear++;
		return 1;
	}
}
int DEQueue(SqQueue *Q,int *x)
{
	if(Q->front==Q->rear)
	{
		return 0;
	}
	else{
		*x=Q->data[Q->front];
		Q->front++;
		return 1;
	}
} 
int EnQueue(SqQueue *Q,int x)
{
	if((Q->rear+1)%MAXSIZE==Q->front)
	{
		return 0;
	}
	else{
		Q->data[Q->rear]=x;
		Q->rear=(Q->rear+1)%5;
		return 1;
	}
}
int DeQueue(SqQueue *Q, int *x)
{
	if(Q->front==Q->rear)
	{
		return 0;
	}
	*x=Q->data[Q->front];
	Q->front=(Q->front+1)%MAXSIZE;
	return 1;
}
