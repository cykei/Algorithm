#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
int N;
bool answer;
vector<int> tree[200001];
int visited[200001];
unordered_set<int> s;
int before[200001];
int after[200001];


// 선행조건이 있는 노드면 q에넣고 대기
// q에 있었던 노드면 빼서 방문하고 q에 넣는다 -> 이제 방문가능함. 계속 방문못하면 가는길 없는 거임

void bfs(int cur) {
    queue<int> q;
    q.push(cur);
    visited[cur]=1;
    while(!q.empty()){
        int cur = q.front();
        //printf("cur: %d\n",cur);
        q.pop();
        before[after[cur]]=0; 
        if(s.find(after[cur])!=s.end()){
            s.erase(after[cur]);
            visited[after[cur]]=1;
            q.push(after[cur]);
          //  printf("set : %d %d\n", cur, after[cur]);
        }
        for (int i=0; i<tree[cur].size(); i++){
            int next = tree[cur][i];
            if(visited[next]) continue;

              // 선행조건이 있는 노드인가
            if(before[next]!=0){
               // printf("before next: %d %d\n", next, before[next]);
                s.insert(next);
                continue;
            }
            // 선행조건이 없는 노드 였다.
            visited[next]=1;
            q.push(next);
        }
    }
}
bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    answer = true;
    N=n;
    
    for (int i=0; i<path.size(); i++) {
        tree[path[i][0]].push_back(path[i][1]);
        tree[path[i][1]].push_back(path[i][0]);
    }
    for (int i=0; i<order.size(); i++) {
        after[order[i][0]] = order[i][1];
        before[order[i][1]] = order[i][0];
    }
    if(before[0]!=0) return false;
    bfs(0);
    for (int i=0; i<n; i++){
        if(visited[i]==0) answer = false;
    }
    return answer;
}
