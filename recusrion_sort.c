# include <stdio.h>

void spilt(int* arr, int len)
{
	int IN_len = len / 2 + (len % 2);
	int L_arr[IN_len];
	int R_arr[len];
	for(int i = 0; i < IN_len; i ++)
	{
		L_arr[i] = arr[i];
	}
	for(int i = IN_len; i < len; i ++)
	{
		R_arr[i] = arr[i];
	}

	int j = 0, k = IN_len, m = 0;
	while(j < IN_len && k < len)
	{
		if(L_arr[j] < R_arr[k])
		{
			arr[m] = L_arr[j];
			j ++;
			m ++;
			if(j == IN_len)
			{
				while(k < len)
				{
					arr[m] = R_arr[k];
					k ++;
					m ++;
				}		
			}
		}	
		else
		{
			arr[m] = R_arr[k];
			k ++;
			m ++;
			if(k == len)
			{
				while(j < IN_len)
 				{
					arr[m] = L_arr[j];
					j ++;
					m ++;
				}
			}
		}
	}
}

void sort(int* arr, int IN_len, int len)
{
	if(IN_len == 0 || len == IN_len)
	{
		return;	
	}

	sort(arr, len, IN_len --);
	sort(arr, IN_len, len --);	
	spilt(arr, len);
}

void merge_sort(int* arr, int len)
{
	int IN_len = len / 2 + (len % 2);
	sort(arr, IN_len, len);
}

int main(void)
{
	int arr[10] = {5, 1, 2, 7, 10, 3, 6, 9, 4, 8};
	merge_sort(arr, 10);

	for(int i = 0; i < 10; i ++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}

