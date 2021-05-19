/*
ʱ�临�Ӷȣ�ƽ�����O(NlogN) ������O(NlogN) ����O(NlogN)
�ռ临�Ӷȣ�O(N)
�ȶ��ԣ��ȶ�
*/
#include<iostream>
using namespace std;
void merge(int* a, int* temp, int begin, int middle, int end)
{
	int i = begin;
	int j = middle + 1;
	int k = 0;

	while (i <= middle && j <= end)//�Ƚ�����ָ����ָ���Ԫ�أ�ѡ�����С��Ԫ�ط��뵽�ϲ��ռ䣬���ƶ�ָ�뵽��һλ��  
	{
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}

	while (i <= middle)//����һ��������ʣ�ֱ࣬�ӿ�������ճ���ϲ�����β  
		temp[k++] = a[i++];
	while (j <= end)//���ڶ���������ʣ�ֱ࣬�ӿ�������ճ���ϲ�����β  
		temp[k++] = a[j++];

	for (i = 0; i < k; i++)//������õ����п�����������  
		a[begin + i] = temp[i];
}
void merge_sort(int* a, int* temp, int begin, int end)
{
	int middle = (begin + end) >> 1;
	if (begin < end)
	{
		merge_sort(a, temp, begin, middle);//�������  
		merge_sort(a, temp, middle + 1, end);//�ұ�����  
		merge(a, temp, begin, middle, end);//�ٽ������������кϲ�  
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
