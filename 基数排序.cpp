/*
时间复杂度：平均情况O(d(r+n)) 最好情况O(d(n+rd)) 最坏情况O(d(r+n))
空间复杂度：O(rd+n)
稳定性：稳定
注：基数排序的复杂度中，r代表关键字的基数，d代表长度，n代表关键字的个数
*/
#include<iostream>
#include<vector>
using namespace std;
void countSort(vector<int>& vec, int exp)
{
	vector<int> range(10, 0);
	int length = vec.size();
	vector<int> tmpVec(length, 0);
	for (int i = 0; i < length; ++i)
	{
		range[(vec[i] / exp) % 10]++;
	}
	for (int i = 1; i < range.size(); ++i)
	{
		range[i] += range[i - 1];//统计本应该出现的位置
	}
	for (int i = length - 1; i >= 0; --i)
	{
		tmpVec[range[(vec[i] / exp) % 10] - 1] = vec[i];
		range[(vec[i] / exp) % 10]--;
	}
	vec = tmpVec;
}
void radixSort(vector<int>& vec)
{
	int length = vec.size();
	int max = -1;
	for (int i = 0; i < length; ++i)//提取出最大值
	{
		if (vec[i] > max)
			max = vec[i];
	}

	//提取每一位并进行比较，位数不足的高位补0
	for (int exp = 1; max / exp > 0; exp *= 10)
		countSort(vec, exp);
}
//int main()
//{
//	vector<int> vec = { 49, 38, 65, 97, 76, 13, 27, 49, 10 };
//	for (auto x : vec)
//	{
//		cout << x << " ";
//	}
//	cout << endl;
//	radixSort(vec);
//	for (auto x : vec)
//	{
//		cout << x << " ";
//	}
//	cout << endl;
//	return 0;
//}