/*
ʱ�临�Ӷȣ�ƽ�����O(NlogN) ������O(NlogN) ����O(NlogN)
�ռ临�Ӷȣ�O(1)
�ȶ��ԣ����ȶ�
*/
#include<iostream>
using namespace std;
//����Ϊһ����
void Heap_Adjust(int* arr, int s, int m)
{
    int temp = arr[s];
    for (int j = 2 * s + 1; j <= m; j = 2 * j + 1)
    {
        if (arr[j] < arr[j + 1] && j < m)
        {
            j++;
        }
        if (temp > arr[j])
            break;
        arr[s] = arr[j];
        s = j;
    }
    arr[s] = temp;
}
//������
void Heap_Sort(int* arr, int length)
{
    //����һ���󶥶�
    for (int s = length / 2 - 1; s >= 0; s--)
    {
        Heap_Adjust(arr, s, length - 1);
    }

    //����
    for (int i = length - 1; i >= 1; i--)
    {
        swap(arr[0], arr[i]);
        Heap_Adjust(arr, 0, i - 1);
    }
}
//int main()
//{
//	int arr[] = { 49, 38, 65, 97, 76, 13, 27, 49, 10 };
//	int lengthgth = sizeof(arr) / sizeof(int);
//	for (auto x : arr)
//	{
//		cout << x << " ";
//	}
//	cout << endl;
//    Heap_Sort(arr, lengthgth);
//	for (auto a : arr)
//	{
//		cout << a << " ";
//	}
//	return 0;
//}