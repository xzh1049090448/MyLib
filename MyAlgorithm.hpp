#pragma once
//#include<iostream>
//using namespace std;

/*
	@brief	   ��������
	@param     
	@note      ֻ���м����ͽ���
	@Sample usage: 
*/
template<class T>
void mySwap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

/***************************************   ���������㷨  ***************************************************/

/*
	@brief     ����1.0
	@param     startΪ��ʼλ�ã�endΪ����λ��
	@note      �ܶ�string�����顢vector����
	@Sample usage: 
*/
template<class T> 
void quickSort1(T& vec, long start, long end) {
	if (start >= end) return;
	long left = start;
	long right = end;
	long key = rand() % (end - start + 1) + start;
	mySwap(vec[key], vec[left]);
	key = left;
	
	while (left < right) {
		while (left < right && vec[right] >= vec[left]) right--;
		if (vec[left] < vec[right]) {
			mySwap(vec[left], vec[right]);
			key = right;
		}
		while (left < right && vec[left] <= vec[right]) left++;
		if (vec[right] < vec[left]) {
			mySwap(vec[left], vec[right]);
			key = left;
		}
	}
	quickSort1(vec, start, key - 1);
	quickSort1(vec, key + 1, end);
}


/*
 	@brief     ����2.0
	@param     startΪ��ʼλ�ã�endΪ����λ��
	@note      �ܶ�string�����顢vector����ͨ�����������������꣬���ظ����ݶ��Ч�ʱ�1.0��
	@Sample usage: 
*/
template<class T>
void quickSort2(T& vec, long start, long end) {
	if (start >= end) return;
	long left = start;
	long right = end;
	long key = rand() % (end - start + 1) + start;
	auto keyVal = vec[key];
	key = start;
	while (key <= right) {
		if (vec[key] < keyVal) {
			mySwap(vec[key], vec[left]);
			left++;
			key++;
		}
		else if (vec[key] > keyVal) {
			mySwap(vec[key], vec[right]);
			right--;
		}
		else {
			key++;
		}
	}
	quickSort2(vec, start, left);
	quickSort2(vec, key, end);
}
