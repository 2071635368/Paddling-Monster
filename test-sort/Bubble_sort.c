#include<stdio.h>
#include<malloc.h>

void test(int* arr, int s){
        int t,h;
        t = s;
        for(h = 0; h < s; h ++){  //让数字以倒的方式存入数组进行排序
            arr[h] = t;
            t --;
            };
            return;
    }

int testbit(void){
    int k;
    printf("输入测试的位数: ");
    scanf("%d", &k);
    int i, s = 1;
    if(k > 1){
        for(i = 1; i < k; i ++){  //输入位数进行进位，为数组的分配内存大小 
            s *= 10;
            }
        }
        else if(k = 1){
            s = 9;
            }
            else{
                printf("\n!操作停止!\n");
                return 0;
                }
                return s;
    }
int main(void)
{
    char ch = 0;
	int len = testbit();
	int s = 0;
	int* arr = (int*)malloc(sizeof(int) * len);
	/*printf("输入要进行排序的数字(间隔为空格)：");
	while(scanf("%d", &arr[s]) != EOF)
	{
		s ++;
		len ++;
		if(getchar() == '\n')
			break;
	}*/
    test(arr, len);
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
