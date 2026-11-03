#define MAXSIZE 100
typedef struct{
	char data[MAXSIZE];
	int top;
}SqStack;
int IsPalindrome(char str[])
{
	int n=0;
	SqStack S;
	S.top=-1;
	while(str[n])
	{
		n++;
	}
	if(n%2==0)
	{
		int temp=n/2;
		for(int i=0;i<temp;i++)
		{
			Push(&S,str[i]);
		}
		for(int j=temp;j<n;j++)
		{
			char x;
			Pop(&S,&x);
			if(x!=str[j])
			{
				return 0;
			}
		}
		return 1;
	}
	else{
		int temp=(n+1)/2;
		for(int i=0;i<temp-1;i++)
		{
			Push(&S,str[i]);
		}
		for(int j=temp;j<n;j++)
		{
			char x; 
			Pop(&S,&x);
			if(x!=str[j])
			{
				return 0;
			}
		}
		return 1;
	}
}
