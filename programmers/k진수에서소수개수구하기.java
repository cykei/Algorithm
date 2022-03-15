// https://programmers.co.kr/learn/courses/30/lessons/92335
// 10시 5분~ 10시 53분
// 생각보다 오래걸렸던 문제... 소수 구할때 i*i < limit 으로 하면 시간초과가 난다... ㅋㅋㅋㅋㅋ
// 그리고 계산하다보면 long범위를 넘나보다. 최대 13자리가 나오니까 그럴 수 있을듯
import java.util.*;
class Solution {
   public boolean checkPrime(long k) {
        if(k==1) return false;
        else if(k==2) return true;
        int limit = (int) Math.sqrt(k);
        for(int i=2; i<=limit; ++i) {
            if(k % i == 0) {
                return false;
            }
        }
        return true;
    }

    public int solution(int n, int k) {
        int answer = 0;

        List<Integer> jinsu = new ArrayList<Integer>();

        while(n > 0) {
            jinsu.add(n%k);
            n=n/k;
        }
        // 최대로 나올 수 있는 긴 길이의 진수 = 13자리
        // System.out.println(jinsu.size());
        // for (int i=0; i<jinsu.size(); i++) {
        //     System.out.print(jinsu.get(i)) ;
        // }

        long temp=0;
        long ten =1;
        boolean flag=false;
        for (int i=0; i<jinsu.size(); i++) {
            int cur = jinsu.get(i);
            if(cur > 0 && !flag) {
                flag=true;
            }
            if(cur>0 && flag) {
                temp+=(cur * ten);
                ten*=10;
            }
            else if(cur == 0 && flag){
                flag = false;
                if(checkPrime(temp)) answer++;
                temp=0;
                ten=1;
            }
        }
        if(temp>0 && checkPrime(temp)) answer++;
        return answer;
    }
}
