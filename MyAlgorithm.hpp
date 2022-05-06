#pragma once
//#include<iostream>
//using namespace std;

/*
	@brief	   交换函数
	@param     
	@note      只进行简单类型交换
	@Sample usage: 
*/
template<class T>
void mySwap(T& a, T& b) {
	T tmp = a;
	a = b;
	b = tmp;
}

/***************************************   各类排序算法  ***************************************************/

/*
	@brief     快排1.0
	@param     start为开始位置，end为结束位置
	@note      能对string、数组、vector排序
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
 	@brief     快排2.0
	@param     start为开始位置，end为结束位置
	@note      能对string、数组、vector排序，通过荷兰国旗问题延申，对重复数据多的效率比1.0高
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
