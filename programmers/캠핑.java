import java.util.*;
class Solution {
    public int solution(int n, int[][] data) {
        int answer = 0;
        Arrays.sort(data, (a,b)-> {if(a[0]==b[0]) return a[1]-b[1]; else return a[0]-b[0]; });
     
        for (int i=0; i<data.length; i++) {
            int x = data[i][0];
            int y = data[i][1];
            for (int j=i+1; j<data.length; j++) {
                int xx= data[j][0];
                int yy= data[j][1];
               
                if(x==xx  || y== yy ) continue;
                boolean flag=true;
                for (int k=i+1; k<j; k++){
                    int a = data[k][0];
                    int b = data[k][1];
                    if(x<a && a<xx && Math.min(y,yy)<b && b<Math.max(y,yy)){
                         flag=false;   
                         break;
                    }
                }
                if(flag) answer++;
            }
        }
        return answer;
    }
}
