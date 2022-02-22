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
