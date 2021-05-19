/*
时间复杂度：平均情况O(NlogN) 最好情况O(NlogN) 最坏情况O(NlogN)
空间复杂度：O(N)
稳定性：稳定
*/
#include<iostream>
using namespace std;
void merge(int* a, int* temp, int begin, int middle, int end)
{
	int i = begin;
	int j = middle + 1;
	int k = 0;

	while (i <= middle && j <= end)//比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置  
	{
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while (i <= middle)//若第一个序列有剩余，直接拷贝出来粘到合并序列尾  
		temp[k++] = a[i++];
	while (j <= end)//若第二个序列有剩余，直接拷贝出来粘到合并序列尾  
		temp[k++] = a[j++];

	for (i = 0; i < k; i++)//将排序好的序列拷贝回数组中  
		a[begin + i] = temp[i];
}
void merge_sort(int* a, int* temp, int begin, int end)
{
	int middle = (begin + end) >> 1;
	if (begin < end)
	{
		merge_sort(a, temp, begin, middle);//左边有序  
		merge_sort(a, temp, middle + 1, end);//右边有序  
		merge(a, temp, begin, middle, end);//再将两个有序数列合并  
	}
}
//int main()
//{
//	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49, 10 };
//	int tmp[1001];
//	int length = sizeof(arr) / sizeof(int);
//	for (auto x : arr)
//	{
//		cout << x << " ";
//	}
//	cout << endl;
//	merge_sort(arr,tmp,0,length-1);
//	for (auto a : arr)
//	{
//		cout << a << " ";
//	}
//	return 0;
//}
