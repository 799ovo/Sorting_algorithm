/*
时间复杂度：平均情况O(N*logN) 最好情况O(N*logN) 最坏情况O(N^2)。
空间复杂度：O(logN)
稳定性：不稳定
*/
#include<iostream>
using namespace std;
int getPartition(int arr[], int i, int j)
{
	int key = arr[i];
	while (i < j)
	{
		while (i < j && arr[j] >= key)
			j--;
		if (i < j)
			arr[i] = arr[j];
		while (i < j && arr[i] <= key)
			i++;
		if (i < j)
			arr[j] = arr[i];
	}
	arr[i] = key;
	return i;
}
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int partition = getPartition(arr, low, high);
		quickSort(arr, low, partition - 1);
		quickSort(arr, partition + 1, high);
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
//	quickSort(arr, 0, length - 1);
//	for (auto a : arr)
//	{
//		cout << a << " ";
//	}
//	return 0;
//}