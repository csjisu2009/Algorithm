//time   : 0h 10m

/*review : code fast!! it's a basic to implement merge sort!!
*/

#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> v;

void merge(vector<int>& L, vector<int>& R, vector<int>& A) {
	int nL = L.size();
	int nR = R.size();
	int i = 0, j = 0, k = 0;
	while (i < nL && j < nR) {
		if (L[i] <= R[j]) {
			A[k] = L[i];
			++i;
		}
		else {
			A[k] = R[j];
			++j;
		}
		++k;
	}
	while (i < nL) {
		A[k] = L[i];
		++i; ++k;
	}
	while (j < nR) {
		A[k] = R[j];
		++j; ++k;
	}
}

void mergeSort(vector<int>& A) {
	int n = A.size();
	if (n < 2) return;
	int mid = n / 2;
	vector<int> left(A.begin(), A.begin() + mid);
	vector<int> right(A.begin() + mid, A.end());
	mergeSort(left);
	mergeSort(right);
	merge(left, right, A);
}

int main() {
	cin >> n;
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		v.push_back(temp);
	}
	mergeSort(v);
	int size = v.size();
	for (int i = 0; i < size; i++) {
		cout << v[i];
		if (i == size - 1) cout << '\n';
		else cout << ' ';
	}

	return 0;
}