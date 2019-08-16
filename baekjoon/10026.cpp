#include<iostream>
#include<cstring>
using namespace std;
/*
* 10026 - 적록색약
* dfs or bfs로 풀 수 있는 문제. 난 간만에 dfs로 풀었다.
* 풀이: 색깔같아? 그럼 체크하고 4방향 탐색. 안 같아? 리턴. map에서 G를 R로 바꾸고 이하동문.
* 이상한 점 : 이거 n제한 100이라서 처음엔 map[100][100]으로 했었는데 틀렸다고 함. 그것만 고치니까 맞힘.
* dx+1로 dfs를 돈다고 해도 맨 처음 if 문에서 100 초과되면 컷할텐데... 그래서 index범위 안넘을텐데..?
* 아냐 인덱스 범위 넘으면 런타임에러가 뜨지, 틀렸습니다가 뜨진 않을것 같아.
* 뭐가 문제지.
* 여튼 밑에꺼는 돌아간다.
* 2008KB 0ms
*/

char map[101][101];
bool check[101][101];
int n;
int result =0;
int result2= 0;
void dfs(char color, int dx, int dy){
    if(dx<0 || dy<0|| dy>n || dx>n) return;
    if(check[dx][dy]) return;
    
    if(color==map[dx][dy]) {
        //map[dx][dy]=result; 
        check[dx][dy]=1;
        dfs(color,dx+1,dy+0);
        dfs(color,dx-1,dy+0);
        dfs(color,dx+0,dy+1);
        dfs(color,dx+0,dy-1);
    }else{
        return;
    }
}


int main() {
    
    cin >> n;
	
	for (int i=0; i<n; i++){
	    for (int j=0; j<n; j++){
	        cin >> map[i][j];
	    }
	}
	
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if(!check[i][j]){
                result++; 
                dfs(map[i][j],i,j);
            }
        }
    }

	memset(check,0,sizeof(check));
	
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if(map[i][j]=='G') map[i][j]='R';
        }
    }
    
       for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if(!check[i][j]){
                result2++; 
                dfs(map[i][j],i,j);
            }
        }
    }
	
	cout << result<<" "<<result2;
	
	return 0;
}
