/*
ʱ�临�Ӷȣ�ƽ�����O(N^2) ������O(N) ����O(N^2)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ��ȶ�
*/
#include<iostream>
using namespace std;
void insertSort(int arr[], int length)
{
	for (int i = 1; i < length; i++)
	{
		int end = i - 1;
		int tmp = arr[i];
		while (end >= 0)
		{
			if (arr[end] > tmp)
			{
				arr[end + 1] = arr[end];
				--end;
			}
			else
				break;
		}
		arr[end + 1] = tmp;
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
//	insertSort(arr, length);
//	for (auto a : arr)
//	{
//		cout << a << " ";
//	}
//	return 0;
//}