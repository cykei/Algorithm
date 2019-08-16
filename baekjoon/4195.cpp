#include <iostream>
#include <map>
#include <string>
using namespace std;
/*
* 4195 - 친구 네트워크
* 문제 유형 : union-find, disjoint set, hash...
* 풀이 : https://gmlwjd9405.github.io/2018/08/31/algorithm-union-find.html
* 이상한 점 : 
* - Find() 에서 return Find(set[x]) 로 바꾸면 552ms 가 걸린다. (지금시간의 3배)
* - ios_base::sync_with_stdio(false) 안쓰면 시간초과로 틀린다.
* 4352KB 116ms
*/

int set[200001];
int friend_num[200001];
int Find(int x){
    if( x == set[x]) return x;
   return set[x] = Find(set[x]);
    
}

int Union(int f1, int f2){
    f1= Find(f1); //f1의 루트노드를 찾는다.
    f2= Find(f2); //f2의 루트노드를 찾는다.
    if( f1!=f2 ){
        // f1과 f2가 친구관계가 아니었다면
        set[f1]=f2;
        friend_num[f2]+=friend_num[f1];
    }
    return friend_num[f2];
}



int main() {
    ios_base::sync_with_stdio(false);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        
        // 초기화
        for (int i=0; i<n+n; i++){
            set[i]=i;
            friend_num[i]=1;
        }
        
        // 이름을 번호로 맵핑한다.
        int count = 0; //번호는 0번부터 시작한다.
        map<string, int> friend_map;
        for (int i=0; i<n; i++){
            string me, other;
            cin >> me >> other;
            if(friend_map.count(me)==0)
                friend_map[me]=count++;
            if(friend_map.count(other)==0)
                friend_map[other]=count++;
            
            printf("%d\n", Union(friend_map[me],friend_map[other]));
        }
    }
}
