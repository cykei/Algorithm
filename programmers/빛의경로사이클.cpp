#include <string>
#include <vector>
#include <algorithm>
using namespace std;
// https://programmers.co.kr/learn/courses/30/lessons/86052
// 완전탐색
int visited[501][501][4];// 오른 , 아래, 왼 , 위
int dx[]= {0,1,0,-1};
int dy[] = {1,0,-1,0};
vector<string> _grid;
vector<int> answer;
int xlen,ylen;
int dfs(int x, int y, int dir, int cnt){
    if(x>=xlen ) x = 0;
    if(y>=ylen ) y = 0;
    if(x<0) x=xlen-1;
    if(y<0) y=ylen-1;

    if(visited[x][y][dir]==1){
        return cnt;
    }
    visited[x][y][dir]=1;
    int ndir;
    if(_grid[x][y]=='S') {
        ndir = dir;
    }else if(_grid[x][y]=='L') {
        ndir = (dir+3)%4;
    }else if(_grid[x][y]=='R'){
        ndir = (dir+1)%4;
    }

    return dfs( x+dx[ndir],y+dy[ndir], ndir, cnt+1);
}

vector<int> solution(vector<string> grid) {

    xlen= grid.size();
    ylen = grid[0].size();
    _grid=grid;
    for (int i=0; i<xlen; i++){
        for (int j=0; j<ylen; j++){
            for (int k=0; k<4; k++) {
                int len = dfs(i,j,k,0);
                if(len>0) answer.push_back(len);
            }
        }
    }
    sort(answer.begin(), answer.end());
    return answer;
}
