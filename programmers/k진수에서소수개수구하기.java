// https://programmers.co.kr/learn/courses/30/lessons/92335
// 10시 5분~ 10시 53분
// 생각보다 오래걸렸던 문제... 소수 구할때 i*i < limit 으로 하면 시간초과가 난다... ㅋㅋㅋㅋㅋ
// 그리고 계산하다보면 long범위를 넘나보다. 최대 13자리가 나오니까 그럴 수 있을듯
// 자바에서 십진수를 이진수로 변경하는 새로운 방법을 알아내서 추가한다.
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

        String temp[] = Integer.toString(n, k).split("0");
        for (int i=0; i<temp.length; i++) {
            if(temp[i].length() > 0 && checkPrime(Long.parseLong(temp[i]))) answer++;
        }
         return answer;
    }
}
