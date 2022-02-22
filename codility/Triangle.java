// https://app.codility.com/demo/results/training6UWZDE-F4J/
import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public boolean check(long a, long b, long c) {
        if (a+b > c && b+c > a && a+c > b) return true;
        return false;
    }
    public int solution(int[] A) {
        Arrays.sort(A);
        for (int i=0; i<A.length-2; i++) {
            if(check(A[i], A[i+1], A[i+2])) return 1;
        }
        return 0;
    }
}

/*
10분 / 100점 / 완성

풀이
1. A[i]가 int 범위라서 두 수를 더하면 int를 초과할 수 있기때문에 long으로 변환해줌
2. 세 수가 연이어져 나오는 수 일수록 문제의 조건을 통과할 가능성이 높다.
*/
