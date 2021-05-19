/*
ʱ�临�Ӷȣ�ƽ�����O(N^1.3) ������O(N) ����O(N^2)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ����ȶ�
*/
#include<iostream>
using namespace std;
void Shell_Sort(int array[], int n)  
{
	int i, j, step;
	for (step = n / 2; step > 0; step = step / 2)  
	{
		for (i = 0; i < step; i++) 
		{
			for (j = i + step; j < n; j = j + step)  
			{
				if (array[j] < array[j - step])
				{
					int temp = array[j]; 
					int k = j - step;
					while (k >= 0 && temp < array[k])
					{
						array[k + step] = array[k];  
						k = k - step;
					}
					array[k + step] = temp; 
				}
			}
		}
	}
}
//int main()
//{
//	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49, 10 };
//	int length = sizeof(arr) / sizeof(int);
//	for (auto x : arr)
//	{
//		cout << x << " ";
//	}
//	cout << endl;
//	Shell_Sort(arr, length);
//	for (auto a : arr)
//	{
//		cout << a << " ";
//	}
//	return 0;
//}