#pragma once
#include "my_list_node.h"

template<typename T>
void print(set<T> & vec) {
	for (auto i:vec)
		std::cout << i << " ";
	std::cout<< "\n";
}
template<typename T>
void print(vector<T> & vec) {
	for (auto i:vec)
		std::cout << i << " ";
	std::cout<< "\n";
}

template<typename T>
void print(vector<T> & vec, int low, int high) {
	for (int i = low; i <= high; i++)
		std::cout << vec[i] << " ";
	std::cout<< "\n";
}

template<typename T>
void print(T arr[], int size)
{
	for (int i = 0; i < size; ++i)
		std::cout << arr[i] << " ";
	std::cout << "\n";
}

void print(ListNode * res) {
	ListNode * cur = res;
	while(cur != NULL) {
		std::cout << cur->val << " ";
		cur = cur->next;
	}
	std::cout << "\n";
}

template<typename T>
void print(deque<T> &res) {
	for(auto iter = res.begin(); iter != res.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << "\n";
}

template<typename T1, typename T2>
void print(unordered_map<T1, T2> res) {
	std::cout << "{ ";
	for(auto iter = res.begin(); iter != res.end(); ++iter)
		std::cout << iter->first << ":" << iter->second << ", ";
	std::cout << "} \n";
}

template<typename T1, typename T2>
void print(map<T1, T2> res) {
	std::cout << "{ ";
	for(auto iter = res.begin(); iter != res.end(); ++iter)
		std::cout << iter->first << ":" << iter->second << ", ";
	std::cout << "} \n";
}

#define MY_LOG_PAIR(key, value) \
	std::cout<< key << " : " << value << std::endl;

#define MY_LOG(x) \
	std::cout<< x << std::endl;

