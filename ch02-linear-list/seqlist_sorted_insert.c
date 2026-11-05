typedef int Elemtype;
#define LIST_INIT_SIZE 20
#define LISTINCREMENT 10
typedef struct List{
	Elemtype *elem;
	int length;
	int listsize;
}SqList; 
void InitList(SqList *L)
{
	L->elem=(Elemtype*)malloc(sizeof(Elemtype)*LIST_INIT_SIZE);
	L->length=0;
	L->listsize=LIST_INIT_SIZE;
}
void CreatList(SqList *L,int n)
{
	InitList(L);
	for(int i=0;i<n;i++)
	{
		int temp;
		int flag=0;
		scanf("%d",&temp);
		if(L->length==0)
		{
			L->elem[L->length]=temp;
			L->length++;
			continue;
		}
		for(int j=0;j<L->length;j++)
		{
			if(temp<L->elem[j])
			{
				for(int m=L->length;m>j;m--)
				{
					L->elem[m]=L->elem[m-1];
				}
				L->elem[j]=temp;
				L->length++;
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			L->elem[L->length]=temp;
			L->length++;
			
		}
	}
}
