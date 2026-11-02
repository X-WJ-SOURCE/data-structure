#define MAXSIZE 100
typedef struct{
	char data[MAXSIZE];
	int top;
}SqStack;
typedef struct{
	int data[MAXSIZE];
	int top;
}NumStack;
int calc(int x1,int x2,char op)
{
	switch(op)
	{
		case'+':return add(x1,x2);
		case'-':return sub(x1,x2);
		case'*':return mul(x1,x2);
		case'/':return divi(x1,x2);
		default:return 0;
	}
}
int Priority(char op)
{
    if(op=='-'||op=='+')
    {
    	return 1;
	}
	else if(op=='*'||op=='/')
	{
		return 2;
	}
	else{
		return 0;
	}
}
void InfixToPostfix(char infix[], char postfix[])
{
	int n=0;
	SqStack S;
	S.top=-1;
	int k=0;
	while(infix[n])
	{
		if(isalpha(infix[n])||isdigit(infix[n]))
		{
			postfix[k++]=infix[n];
			n++;
		}
		else if(infix[n]!=')'){
			if(infix[n]=='(')
			{
				Push(&S,infix[n]);
				n++;
			}
			else{
				while(S.top!=-1&&Priority(S.data[S.top])>=Priority(infix[n]))
				{
					char tempx;
					Pop(&S,&tempx);
					postfix[k++]=tempx;
				}
				Push(&S,infix[n]);
				n++;
			}
		}
		else{
			while(S.top!=-1&&S.data[S.top]!='(')
			{
				char tempx;
				Pop(&S,&tempx);
				postfix[k++]=tempx;
			}
			if(S.top==-1)
			{
				return;
			}
			char temp;
			Pop(&S,&temp);
			n++;
		}
	}
	while(S.top!=-1)
	{
		char tempx;
		Pop(&S,&tempx);
		postfix[k++]=tempx;
	} 
	postfix[k]='\0';
}
int EvaluatePostfix(char postfix[])
{
	int n=0;
	int isSpace=0;
	NumStack N;
	N.top=-1;
	while(postfix[n])
	{
		if(postfix[n]==' ')
		{
			isSpace=1;
		}
		n++;
	}
	if(isSpace==1)
	{
		n=0;
		while(postfix[n])
		{
			if(isdigit(postfix[n]))
			{
				Push(&N,postfix[n]-'0');
			}
			else if(postfix[n]==' ')
			{
				while()
			}
			n++;
		}
	}
	else{
		n=0;
		while(postfix[n])
		{
			if(isdigit(postfix[n]))
			{
				Push(&N,postfix[n]-'0');
			}
			else{
				char op;
				op=postfix[n];
				int x1,x2;
				Pop(&N,&x2);
				Pop(&N,&x1);
				int x;
				x=calc(x1,x2,op);
				Push(&N,x);
			}
			n++;
		}
	}
	return N.data[N.top];
}
