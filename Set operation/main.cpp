#include <iostream>
#include <vector>
using namespace std;


vector<int> union_operation(vector<int>& A, vector<int>& B) {
	vector<int> C;
	int j = 0, k = 0;
	while (true) {
		if (A.at(j) < B.at(k))
			C.push_back(A.at(j++));
		else if (A.at(j) > B.at(k))
			C.push_back(B.at(k++));
		else {
			C.push_back(A.at(j++));
			k++;
		}
		if (j == A.size() || k == B.size())
			break;
	}
	for (; j < A.size(); j++)
		C.push_back(A.at(j));
	for (; k < B.size(); k++)
		C.push_back(B.at(k));
	return C;
}

vector<int> intersection_operation(vector<int>& A, vector<int>& B) {
	vector<int> C;
	int j = 0, k = 0, i = 0;
	while(true) {
		if (A.at(j) == B.at(k)) {
			C.push_back(A.at(j++));
			k++;
		}else if (A.at(j) < B.at(k))
			j++;
		else if (A.at(j) > B.at(k))
			k++;
		if (j == A.size() || k == B.size())
			break;
	}
	return C;
}
int main() {
	vector<int> A{2,3,4,5,9,10,12,29 };
	vector<int> B{ 1,3,9,12 };
	vector<int> res = intersection_operation(A, B);
	for (int num : res) {
		cout << num << " ";
	}
	return 0;
}