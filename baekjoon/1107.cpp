#include<cstdio>
/*

1107 리모컨 - 브루트 포스  (최대 100만 * 6 = 600만번. 600만번 돌아간다.)

1. 이동할 채널 C를 정한다. (c)
2. C에 포함되어있는 숫자 중에 망가진 버튼이 있는지 확인한다. (possible())
3. 망가진 버튼이 없다면 |C-N| 을 계산해서 +나 -버튼을 총 몇번 눌러야 하는지 계산한다. (press)

*/
bool broken[10];   //0은 멀쩡. 1은 고장

int possible(int c){
    if (c == 0){
        if(broken[0]){
            return 0;
        }else{
            return 1;
        }
    }
    int len = 0;
    while (c>0){
        if(broken[c%10]){ // 누를 수 없는 버튼으로 이뤄진 숫자라면 
            return 0;     // 0을 반환한다.
        }
        len +=1;
        c /= 10;
    }
    return len;
}
int main(){
    int n,m;
    scanf("%d",&n);
    scanf("%d",&m);
    for (int i=0; i<m; i++){
        int x;
        scanf("%d",&x);
        broken[x]=true;
    }
    
    int ans = n-100; //목표번호에서 100을 뺀 숫자만큼 + / - 버튼을 누르면 목표번호에 도달.
    if(ans < 0) ans = -ans;
    
    for (int i=0; i<=1000000; i++){
        int c = i;             //0번 버튼부터 누르고 시작
        int len = possible(c); //c를 만들기위해 버튼을 누른 횟수.
        if (len > 0){          //c가 버튼을 눌러 만들 수 있는 숫자인 경우
            int press = n-c;       //목표번호에서 c만큼 뺀 횟수만큼 +/-버튼을 누른다.
            if (press < 0) press = -press;
            if (ans > len+press) ans = len+press;
        }
    }
    
    printf("%d",ans);
    return 0;
}
