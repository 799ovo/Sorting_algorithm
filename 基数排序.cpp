/*
ʱ�临�Ӷȣ�ƽ�����O(d(r+n)) ������O(d(n+rd)) ����O(d(r+n))
�ռ临�Ӷȣ�O(rd+n)
�ȶ��ԣ��ȶ�
ע����������ĸ��Ӷ��У�r����ؼ��ֵĻ�����d�����ȣ�n����ؼ��ֵĸ���
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
		range[i] += range[i - 1];//ͳ�Ʊ�Ӧ�ó��ֵ�λ��
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
	for (int i = 0; i < length; ++i)//��ȡ�����ֵ
	{
		if (vec[i] > max)
			max = vec[i];
	}

	//��ȡÿһλ�����бȽϣ�λ������ĸ�λ��0
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