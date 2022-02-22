// https://app.codility.com/demo/results/trainingYPYC55-W5V/
// you can also use imports, for example:
import java.util.*;

// you can write to stdout for debugging purposes, e.g.
// System.out.println("this is a debug message");

class Solution {
    public int solution(int[] A) {
        int temp1=0;
        int temp2;
        Arrays.sort(A);
        if(A[1] <0) temp1 = A[0] * A[1] * A[A.length-1];
        temp2 = A[A.length-1] * A[A.length-2] * A[A.length-3];
        if( temp1==0 ) return temp2;
        else if( temp1> temp2) return temp1;
        else return temp2;
    }
}

/*
풀이 : 3개를 곱해서 나올 수 있는 제일큰수는 다음의 두가지 밖에 없다
1. 양 * 양 * 양 
2. 음 * 음 * 양 
고로 정렬해서 제일 큰 양수 3개 곱하던가 제일 작은 음수 3개 곱한거에 제일 큰 양수 곱해주면 된다.
근데 코드가 안 깔금해보인다... (훌쩍)
*/
