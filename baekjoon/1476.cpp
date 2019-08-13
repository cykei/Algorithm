#include <iostream>

using namespace std;

int main() {
    int E, S, M;
	scanf("%d %d %d", &E, &S, &M);

	for (int i = 1; i < 7981; i++) {
	    if (E==15) E=0;
	    if (S==28) S=0;
	    if (M==19) M=0;
		if (i % 15 == E && i % 28 == S && i % 19 == M) {
			printf("%d", i);
			break;
		}
	}
}
