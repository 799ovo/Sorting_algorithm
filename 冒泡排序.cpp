/*
ʱ�临�Ӷȣ�ƽ�����O(N^2) ������O(N) ����O(N^2)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ��ȶ�
*/
#include<iostream>
using namespace std;
void bubbleSort(int arr[], int length)
{
	for (int i = 0; i < length-1; i++)
	{
		for (int j = 0; j < length-1-i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
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
//	bubbleSort(arr, length);
//	for (auto a : arr)
//	{
//		cout << a << " ";
//	}
//	return 0;
//}