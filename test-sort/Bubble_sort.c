#include<stdio.h>
#include<malloc.h>
#define max 10000000 //自定义内存最大分配

int test(int* arr, int k){
    int i, j, h, t, s = 1;
    if(k > 1){
        for(i = 1; i < k; i ++){ 
            s *= 10;
            }
        }
        else if(k = 1){
            s = 9;
            }
        t = s;
        for(h = 0; h < s; h ++){
            arr[h] = t;
            t --;
            };

            return s;
    }

int testbit(int* arr){
    int i;
    printf("输入测试的位数: ");
    scanf("%d", &i);
    return test(arr, i);
    }

int main(void)
{
    char ch = 0;
	int len = 0;
	int s = 0;
	int* arr = (int*)malloc(sizeof(int) * max);
	/*printf("输入要进行排序的数字(间隔为空格)：");
	while(scanf("%d", &arr[s]) != EOF)
	{
		s ++;
		len ++;
		if(getchar() == '\n')
			break;
	}*/
    len = testbit(arr);
	if(len > 1)
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
		printf("%d  ", arr[i]);
	}
	printf("\n");

	return 0 ;
}
