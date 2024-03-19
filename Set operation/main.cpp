#include <iostream>
#include <vector>
using namespace std;


vector<int> merging(vector<int>& A, vector<int>& B) {
	vector<int> C;
	int j = 0, k = 0, i = 0;
	for (; i < A.size() + B.size(); i++) {
		if (A.at(j) <= B.at(k))
			C.push_back(A.at(j++));
		else
			C.push_back(B.at(k++));
		if (j == A.size() || k == B.size())
			break;
	}
	for (; j < A.size(); j++)
		C.push_back(A.at(j));
	for (; k < B.size(); k++)
		C.push_back(B.at(k));
	return C;
}
int main() {
	vector<int> A{ 1,5,7,9 };
	vector<int> B{ 2,4,8,10,20 };
	vector<int> res = merging(A, B);
	for (int num : res) {
		cout << num << " ";
	}
	return 0;
}