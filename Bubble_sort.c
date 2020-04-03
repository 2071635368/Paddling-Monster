#include<stdio.h>

int main(void)
{
        char ch = 0;
	int len = 0;
	int s = 0;
	int arr[9999] = {0};
	printf("输入一些数字(以空格隔开)：");
	while(scanf("%d", &arr[s]))
	{
		printf("<");
		if(getchar() == '\n')
			break;
		s ++;
		len ++;
	}
	if(len >= 2)
	{
		for(int i = 0; i < len; i ++)
		{
			for(int k = 0; k < len - i; k ++)
			{
				if(arr[k] > arr[k+1])
				{
					int t = arr[k+1];
					arr[k+1] = arr[k];
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
		printf("%d", arr[i]);
	}

	return 0 ;
}
