import java.util.*;
class Solution {
    //오전 11시 57분~ 12시 31분
    public int solution(int[][] triangle) {
        int answer = 0;
        int[][] dp = new int[triangle.length][triangle.length];
        // dp[i][j] = (i,j) 에 도달했을때의 최댓값 
        //          = max((i-1, j-1), (i-1, j)) + triangle[i][j]  // j-1이 0 미만인경우 예외처리
        dp[0][0] = triangle[0][0];
        for (int i=1; i<triangle.length; i++) {
            for (int j=0; j<i+1; j++) {
                if(j==0) dp[i][j] = dp[i-1][j] + triangle[i][j];
                else dp[i][j] = Math.max(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
            }
        }

        for (int i=0; i<triangle.length; i++){
           answer =  (dp[triangle.length-1][i] > answer )?  dp[triangle.length-1][i] : answer;
        }
        return answer;
    }
}
