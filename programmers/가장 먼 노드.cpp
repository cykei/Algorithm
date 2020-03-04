/*
2020.03.04
https://programmers.co.kr/learn/courses/30/lessons/49189

그래프 bfs 

40분 +4 
*/

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    int visited[20001]={0};
    int answer[20001]={0};
    vector<int> v[20001];
    for (int i=0; i<edge.size(); i++){
        v[edge[i][0]].push_back(edge[i][1]);
        v[edge[i][1]].push_back(edge[i][0]);
    }

    queue<int> q;
    visited[1]=true;
    for (int i=0; i<v[1].size(); i++){
        q.push(v[1][i]);
        visited[v[1][i]]=true;
        answer[v[1][i]]=1;
    }

    while(!q.empty()){
        int cur = q.front();
        q.pop();

        for (int i=0; i<v[cur].size(); i++){
            if(!visited[v[cur][i]]){
                q.push(v[cur][i]);
                visited[v[cur][i]]=true;
                answer[v[cur][i]]= answer[cur]+1;
            }
        }
    }
    int max, cnt;
    max=cnt=0;
    for (int i=1 ;i<=n; i++){
        if(answer[i]>max){
            max= answer[i];
            cnt = 1;
        }else if( answer[i]==max){
            cnt++;
        }
    }
    return cnt;
}
