#include <iostream>
/* 1072 - 게임
* 다 해도 되는 줄 알았는데 아니었음. 더하는 수(mid)가 10억이되면 for문이 10억번 돌아야하는데 그럼 시간초과 뜸. 이분탐색 ㄱㄱ 
* 1988KB 0ms
*/
using namespace std;

int main() {
   long long x,y;
   cin >> x >> y;
   
   long long ret = (y * 100)/x;
   long long nret = -1;
   long long left=1; 
   long long right=1000000000;
   long long mid = -1;
   if(ret >= 99) { cout<<-1; return 0;}
   while(left <= right){
       mid = (left+right)/2;
       nret = (y+mid) * 100 / (x+mid);
       //cout<<mid <<" "<<nret <<endl;
       if(nret > ret) {
           right = mid-1;
       }else{
           left = mid+1;
       }
   }
   
   // mid 로 출력하니까 계속 틀림
   // 웃긴건 left =0부터여도 맞는다는 거. ㅅㅂ
   // 맨처음에 double로 했다. 병신인가 long long은 긴 정수니까 당연히 이걸로 해야하
   // 이것도 소수점 인줄 알고 ㅎㅎㅎㅎㅎㅎ
   
   cout<<left;
   return 0;
}
