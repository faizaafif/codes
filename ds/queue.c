#include <stdio.h>

struct data
{
	int id;
	char name[30];
};

struct data d[5];
int f = -1, r = -1;

int isfull()
{
	if (r == 4)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int isempty()
{
	if (f == r)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void enq()
{
	if (isfull())
	{
		printf("The Queue is full\n");
	}
	else
	{
		r++;
		printf("Enter id: ");
		scanf("%d", &d[r].id);
		printf("Ener name: ");
		scanf("%s", d[r].name);
	}
}
void dq()
{
	if (isempty())
	{
		printf("The Queue is empty\n");
	}
	else
	{
		f++;
	}
}

void view()
{
	printf("Queue\n");
	for (int i = f + 1; i <= r; i++)
	{
		printf("%d\t%s\n", d[i].id, d[i].name);
	}
}

int main()
{
	int ch;
	do
	{
		printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
		printf("Enter choice: ");
		scanf("%d", &ch);
		switch (ch)
		{
		case 1:
			enq();
			break;
		case 2:
			dq();
			break;
		case 3:
			view();
			break;
		case 4:
			printf("Thank you\n");
			break;
		default:
			printf("Enter valid choice\n");
		}
	} while (ch != 4);

	return 0;
}