#include <iostream>
#include <string.h>
using namespace std;
int n;
int main() {
    scanf("%d",&n);
    int s = 0;
    for (int i=0; i<n; i++){
        char order[7]; 
        int x;
        scanf("%s",order);
        
        if (strcmp(order,"add")==0){
            scanf("%d",&x);
            s = s|(1<<x);
        }else if (strcmp(order,"remove")==0){
            scanf("%d",&x);
            s = s & ~(1<<x);
            
        }else if (strcmp(order, "check")==0){
            scanf("%d",&x);
            if( s & (1<<x) ) {
                printf("1\n");
            }else{
                printf("0\n");
            }
        
        }else if (strcmp(order, "toggle")==0){
             scanf("%d",&x);
            if( s & (1<<x) ) {
                s = s & ~(1<<x);
            }else{
                s = s|(1<<x);
            }
            
        }else if (strcmp(order, "all")==0){
            s = ~0;
        }else if(strcmp(order, "empty")==0){
            scanf("%d",&x);
            s = 0;
            
        }
        
        memset(order,0,sizeof(order));
 
    }
    
}
