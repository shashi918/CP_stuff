// The Poet And The Pendulum
// Scenario

// the rhythm of beautiful musical notes is drawing a Pendulum

// Beautiful musical notes are the Numbers !alt !alt
// Task

// Given an array/list [] of n integers , Arrange them in a way similar to the to-and-fro movement of a Pendulum

//     The Smallest element of the list of integers , must come in center position of array/list.
//         The Higher than smallest , goes to the right .

//     The Next higher number goes to the left of minimum number and So on , in a to-and-fro manner similar to that of a Pendulum.

// !alt 
#include <bits/stdc++.h>
#include <vector>
using namespace std;

vector<int> Pendulum(vector<int> values)
{
	sort(values.begin(), values.end());
	vector<int> ans(values.size(), 0);
	int left = (values.size() - 1) / 2;
	int right = left + 1;
	int i = 0;
	while (left > -1 || right < values.size()) {
		if (left > -1) {
			ans[left] = values[i];
			left--;
			i++;
		}
		if (right < values.size()) {
			ans[right] = values[i];
			right++;
			i++;
		}
	}
	return ans;
}
int main()
{
	{
		vector<int> a = { 4, 10, 9 };
		vector<int> ans = Pendulum(a);
		for (auto i : ans) {
			cout << i << "\t";
		}
		cout << "\n";
	}
	{
		vector<int> a = { 8, 7, 10, 3 };
		vector<int> ans = Pendulum(a);
		for (auto i : ans) {
			cout << i << "\t";
		}
		cout << "\n";
	}
	{
		vector<int> a = { 6, 6, 8, 5, 10 };
		vector<int> ans = Pendulum(a);
		for (auto i : ans) {
			cout << i << "\t";
		}
		cout << "\n";
	}
}