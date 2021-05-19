/*
时间复杂度：平均情况O(N^2) 最好情况O(N^2) 最坏情况O(N^2) 
空间复杂度：O(1)
稳定性：不稳定
*/
#include<iostream>
using namespace std;
void Swap(int arr[], int i, int j)
{
	int tmp = arr[i];
	arr[i] = arr[j];
	arr[j] = tmp;
}
void selectSort(int arr[], int length)
{
	if (arr==nullptr || length == 0)
		return;
	for (int i = 0; i < length; i++)
	{
		int min = i;
		for (int j = i + 1; j < length; j++)
		{
			if (arr[min] > arr[j])
				min = j;
		}
		if (i != min)
			Swap(arr, i, min);
	}
}
//int main()
//{
//	int arr[] = { 5,3,9,1,7,10,2 };
//	int length = sizeof(arr)/sizeof(int);
//	for (auto i : arr)
//	{
//		cout << i << " ";
//	}
//	cout << endl;
//	selectSort(arr, length);
//	for (auto i : arr)
//	{
//		cout << i <<" ";
//	}
//	return 0;
//}
