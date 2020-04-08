# include <stdio.h>
# include <malloc.h>
# define max 10000000 //自定义最大内存分配

int test(int*, int);
int testbit(int*);

void spilt(int* arr,int low, int lin, int len)
{
	int L = lin - low;
	int R = len - lin + 1;//+1为递归时由于中间值为左半时需要加一跳至右半有时 lin 会等于 len 需要加一来完成数组长度的定义 而for循环右半时则需要 ++
//	int* L_arr[L];//定义大小为中间值减去初始值            *gcc环境可以如此定义 vc则需要动态数组malloc
//	int* R_arr[R];//定义大小为末尾值减去中间值+1 

    int* L_arr = (int*)malloc(sizeof(int) * L);
    int* R_arr = (int*)malloc(sizeof(int) * R);

	for (int i = low; i < lin; i++)
	{
		L_arr[i - low] = arr[i];
	}
	for (int i = lin; i <= len; i++)//因为6行注释原因需要 <= 来完成
	{
		R_arr[i - lin] = arr[i];
	}

	int j = 0, k = 0, m = low;
	while (j < L && k < R)//进行比大小排序
	{
		if (L_arr[j] < R_arr[k])
		{
			arr[m] = L_arr[j];
			j++;
			m++;
		}
		else
		{
			arr[m] = R_arr[k];
			k++;
			m++;
		}
	}
	if (k < R)//如果有未排完的值则直接把未排完的值全部直接添加与其尾部（因为在有序的前提下后面的一定比前面的 大 或等于）
	{
		while (k < R)
		{
			arr[m] = R_arr[k];
				k++;
				m++;
		}
	}
	else if(j < L)
	{
		while (j < L)
		{
			arr[m] = L_arr[j];
			j++;
			m++;
		}
	}
}

void sort(int* arr,int LOW_len, int UP_len)//把数组元素对半处理
{
	if (LOW_len >= UP_len)//出口
	{
		return;
	}

	int LIN_len = (LOW_len + UP_len) / 2;//用于定位中间值来进行对半

	sort(arr, LOW_len, LIN_len);//处理左半

	LIN_len++;
	
	sort(arr, LIN_len, UP_len);//处理右半 ++让位于左半尾部的中间值位于右半的起始
	
	spilt(arr, LOW_len, LIN_len, UP_len);//进行归并排序 ++可以在函数内部进行也可以外部带参++
}

void merge_sort(int* arr, int len)// 用于减少参数
{	
	len--;
	sort(arr, 0, len);
}

int main(void)
{
	int* arr = (int *)malloc(sizeof(int) * max);
    int test = testbit(arr);
	merge_sort(arr, test);

	for (int i = 0; i < test; i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}

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
            else{
                printf("\n!操作停止!\n");
                return 0;
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
