/*
* 9251 - LCS
* DP 문제
* LCS(i, j) = max(LCS(i-1, j), LCS(i, j-1))    (xi != yj)
*             LCS(i-1, j-1) + 1                (xi == yj)
*/

#include <iostream>

using namespace std;

int main()
{
    char a[1005];
    char b[1005];
    int d[1005][1005];
    int i,j;
    
    scanf("%s", a+1);
    scanf("%s", b+1);
    
    for (i=1; a[i]; i++){
        for (j=1; b[j]; j++){
            if(a[i]==b[j]) d[i][j] = d[i-1][j-1]+1;
            else d[i][j]= max(d[i-1][j], d[i][j-1]);
        }
    }
    
    printf("%d",d[i-1][j-1]);
    return 0;
}
