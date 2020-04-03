#include<stdio.h>

int main(void)
{
        char ch = 0;
	int len = 0;
	int s = 0;
	int arr[999] = {0};
	while(1)
	{
		if(scanf("%d", &arr[s]) == EOF)
			break;
		printf("<A> ");
		s ++;
		len ++;
		if(getchar() == '\n')
			break;
	}
	if(len >= 2)
	{
		for(int i = 0; i < len -1; i ++)
		{
			for(int k = 0; k < len -1 -i; k ++)
			{
				if(arr[k] > arr[k +1])
				{
					int t = arr[k +1];
					arr[k +1] = arr[k];
					arr[k] = t;
				}
				else
				{
					continue;
				}
			}
		}
	}
	for(int i = 0; i < len; i ++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");

	return 0 ;
}
