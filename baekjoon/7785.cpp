#include <iostream>
#include <string>
#include <set>

/*
* set : binary search tree (탐색, 삽입, 삭제 = O(logN))
* 추가, 삭제가 빈번히 일어날 때 쓴다. (doubled linked list 구현해서 풀수도 있지만 귀찮으니깐)
*/

using namespace std;
int main() {

	int n;
	cin >> n;

	set<string> bst;
	for (int i = 0; i < n; i++) {
		string name, attend;
		cin >> name >> attend;
		if (attend.compare("enter")==0) {
			bst.insert(name);
		}
		else {
			bst.erase(name);
		}
	}

	for (auto i = bst.rbegin(); i!=bst.rend(); i++) {
		cout << *i << '\n';
	}
	return 0;
}
