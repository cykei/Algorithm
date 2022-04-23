#include <string>
#include <vector>

using namespace std;
int answer;
vector<vector<int>> m_board;
int N=0;
int visited[26][26][4];
int dx[]={0,1,0,-1}; // -> , 아래, 
int dy[]={1,0,-1,0};
void dfs(int x, int y, int cost, int d ) {
    if(x==N-1 && y==N-1) {
        if(cost < answer) answer = cost;
        return;
    }
    if( cost >= answer) return;
    visited[x][y][d]=cost;
    for (int i=0; i<4; i++) {
        int nx = x+dx[i];
        int ny= y+dy[i];
        if(nx<0 || ny <0 || nx>=N || ny>=N || m_board[nx][ny]==1) continue;
        int curCost = 0;
        if(i==d || (x==0&&y==0&& i==1)) {
            curCost = 100;
        }
        else {
            curCost = 600;
        }

        if(cost+curCost < visited[nx][ny][i]){
            dfs(nx, ny, cost+curCost, i);
        } 



    }
}
int solution(vector<vector<int>> board) {
    answer = 987654321;
    N = board.size();
    m_board = board;
    for (int i=0; i<N; i++) {
        for (int j=0; j<N;j++){
            for (int k=0; k<4; k++) {
                visited[i][j][k]=987654321;
            }
        }
    }
    dfs(0,0,0,0);
    return answer;
}
