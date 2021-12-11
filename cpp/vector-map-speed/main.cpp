#include <random>
#include <string>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <chrono>
#include <iostream>
#include <limits>

using namespace std;
using Key = unsigned;

string random_string()
{
	 string str("0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz");

	 random_device rd;
	 mt19937 generator(rd());

	 shuffle(str.begin(), str.end(), generator);

	 return str.substr(0, 32);    // assumes 32 < number of characters in str
}

void main_str()
{
	size_t hit_cnt = 0;
	for(unsigned n : {10, 100, 1000, 10000, 100000}) {
		cout << "=========== string count: " << n << "============" << endl;
		vector<string> vector;
		map<string, unsigned> tree_map;;
		unordered_map<string, unsigned> hash_map;
		for (unsigned i = 0; i < n; ++i) {
			vector.push_back(random_string());
		}
		auto keys = vector;
		sort(keys.begin(), keys.end());
		for(const string &s : vector) {
			tree_map[s];
			hash_map[s];
		}
		{
			auto start = chrono::steady_clock::now();
			for(const string &s1 : keys) {
				for(const string &s2 : vector) {
					if(s1 == s2)
						hit_cnt++;
				}
			}
			auto end = chrono::steady_clock::now();
			cout << "Vector:   " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / n << "[ns]" << endl;
		}
		{
			auto start = chrono::steady_clock::now();
			for(const string &s1 : keys) {
				auto it = tree_map.find(s1);
				if(it != tree_map.end())
					hit_cnt++;
			}
			auto end = chrono::steady_clock::now();
			cout << "Tree map: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / n << "[ns]" << endl;
		}
		{
			auto start = chrono::steady_clock::now();
			for(const string &s1 : keys) {
				auto it = hash_map.find(s1);
				if(it != hash_map.end())
					hit_cnt++;
			}
			auto end = chrono::steady_clock::now();
			cout << "hash map: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / n << "[ns]" << endl;
		}
	}
	cout << "hit cnt: " << hit_cnt << endl;
}

void main_int()
{
	random_device rd;
	mt19937 generator(rd());
	size_t hit_cnt = 0;
	for(unsigned n : {10, 100, 1000, 10000, 50000}) {
		cout << "=========== key count: " << n << "============" << endl;
		vector<Key> vector;
		map<Key, unsigned> tree_map;;
		unordered_map<Key, unsigned> hash_map;
		for (unsigned i = 0; i < n; ++i) {
			vector.push_back(generator());
		}
		auto keys = vector;
		sort(keys.begin(), keys.end());
		for(const Key &s : vector) {
			tree_map[s];
			hash_map[s];
		}
		{
			auto start = chrono::steady_clock::now();
			for(const Key &s1 : keys) {
				for(const Key &s2 : vector) {
					if(s1 == s2)
						hit_cnt++;
				}
			}
			auto end = chrono::steady_clock::now();
			cout << "Vector:   " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / n << "[ns]" << endl;
		}
		{
			auto start = chrono::steady_clock::now();
			for(const Key &s1 : keys) {
				auto it = tree_map.find(s1);
				if(it != tree_map.end())
					hit_cnt++;
			}
			auto end = chrono::steady_clock::now();
			cout << "Tree map: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / n << "[ns]" << endl;
		}
		{
			auto start = chrono::steady_clock::now();
			for(const Key &s1 : keys) {
				auto it = hash_map.find(s1);
				if(it != hash_map.end())
					hit_cnt++;
			}
			auto end = chrono::steady_clock::now();
			cout << "hash map: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() / n << "[ns]" << endl;
		}
	}
	cout << "hit cnt: " << hit_cnt << endl;
}

int main()
{
	main_str();
	main_int();
	return 0;
}
