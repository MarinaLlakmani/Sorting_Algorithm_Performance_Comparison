#pragma once
#include <iostream>
#include <algorithm>
#include <chrono>
#include<random>
#include<vector>

using namespace std;
using namespace std::chrono;
#define TIME_UNIT milli

class TimedSorts
{
public:
	TimedSorts();
	TimedSorts(const vector<int>& data);
	void fillData(int size);
	void setData(const vector<int>& newData);
	void PrintData();
	void scramble(int seed);
	bool isSorted();
	duration<double,TIME_UNIT> getLatestSortTime();
	duration<double,TIME_UNIT> BubbleSort();
	duration<double,TIME_UNIT> InsertionSort();
	duration<double,TIME_UNIT> MergeSort();
	duration<double,TIME_UNIT> QuickSort();
	duration<double,TIME_UNIT> BuiltInSort();

private:
	duration<double, TIME_UNIT> Duration;
	int length;
	vector<int>data;

	void mergeSortRecurse(int l, int r);
	void merge(int l, int m, int r);
	void quickSortRecurse(int low, int high);
	int partition(int low, int high);
	void mySwap(int& xp, int& yp);
};
