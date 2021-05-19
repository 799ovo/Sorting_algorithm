/*
时间复杂度：平均情况O(NlogN) 最好情况O(NlogN) 最坏情况O(NlogN)
空间复杂度：O(1)
稳定性：不稳定
*/
#include<iostream>
using namespace std;
//调整为一个堆
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
//堆排序
void Heap_Sort(int* arr, int length)
{
    //创建一个大顶堆
    for (int s = length / 2 - 1; s >= 0; s--)
    {
        Heap_Adjust(arr, s, length - 1);
    }

    //排序
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