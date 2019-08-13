#include <iostream>

using namespace std;

int main() {
    int E, S, M; // target
    int e, s, m; // counter
    e=s=m=0;
    scanf("%d %d %d",&E,&S,&M);
    int i;
    for (i=1; i<=15*28*19; i++){
        e++;
        s++;
        m++;
        
        if(e==E && s==S && m==M) break;
        if(e==15){
            e=0;
        }
        if (s==28){
            s=0;
        }
        if(m==19){
            m=0;
        }
    }
    
    printf("%d",i);
}
