#include <string>
#include <vector>

using namespace std;
/*

2020.05.04
https://programmers.co.kr/learn/courses/30/lessons/42898

DP로 풀면 된다는거 알고 푸니까 겁나 쉽네... 이래서 유형을 판별할 줄 아는게 중요한 거구나.

3시 20분~ 3시 52분 : 22분

시작점 (1,1)
도착점 (m,n)
d[i][j] = (i,j) 까지 오는 방법의 수

푸들 X,Y 좌표 반대로 넣어서 오래걸렸다... 으으ㅠㅠ

*/

int map[101][101];
int d[101][101];
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 1;
    for (int i=0; i<puddles.size(); i++){
        map[puddles[i][1]][puddles[i][0]] = 1;
    }


    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            if( i==1 && j==1) d[i][j] =1;
            else if(map[i][j]==0){
                 d[i][j] =(d[i-1][j] + d[i][j-1])%1000000007;
            }
        }
    }

    answer = d[n][m];


    return answer;
}
