# include <stdio.h>
# include <malloc.h>

void spilt(int* arr,int low, int lin, int len)
{
	int LIN = lin + 1;
	int* L_arr[lin - low];
	int* R_arr[len - lin];

	for (int i = low; i <= lin; i++)
	{
		L_arr[i - low] = arr[i];
	}
	for (int i = LIN; i <= len; i++)
	{
		R_arr[i - LIN] = arr[i];
	}

	int j = 0, k = 0, m = 0;
	while (j <= (lin-low) && k <= (len - LIN))
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
	while (j > (lin - low) || k > (len - LIN))
	{
		if (j > (lin - low))
		{
			while (k <= (len - LIN))
			{
				arr[m] = R_arr[k];
					k++;
					m++;
			}
		}
		else if(k > (len - LIN))
		{
			while (j <= (lin - low))
			{
				arr[m] = L_arr[j];
				j++;
				m++;
			}
		}
		break;
	}
	printf("%d | %d", arr[0], arr[1]);
}

void sort(int* arr,int LOW_len, int UP_len)
{
	if (LOW_len >= UP_len)
	{
		return;
	}

	int LIN_len = (LOW_len + UP_len) / 2;

	sort(arr, LOW_len, LIN_len);

	sort(arr, LIN_len+1, UP_len);
	
	spilt(arr, LOW_len, LIN_len, UP_len);
}

void merge_sort(int* arr, int len)
{	
	sort(arr, 0, len);
}

int main(void)
{
	int arr[10] = {100, 5, 20};
	merge_sort(arr, 3);

	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", arr[i]);
	}

	return 0;
}
