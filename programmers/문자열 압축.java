package programmers;
/*
문자열 압축
걸린 시간 : 2시 15분 ~ 3시 51분 
문제 링크 : https://programmers.co.kr/learn/courses/30/lessons/60057
문제 풀이 : 완전탐색
- 단위개수를 1 ~ n/2 개까지 모두 잘라본 후, 최종적으로 가장 작은 길이가 되는 것을 고른다.
- 주의 : 문자열은 반드시 첫번째 문자부터 정해진 길이만큼 잘라야할 것!!
*/    
public class CompressionString {
    public static int solution(String s) {
        int answer = 987654321;
        int size = s.length();
        if( size== 1 ) return 1;
        for (int c=1; c<=size/2; c++){
            String result="";
            String before="";
            int count=0;

            for (int i=0; i+c <=size; i=i+c){
                // c = 자르는 단위, i = 문자위치
                String cur = s.substring(i,i+c);

                // 1. 처음 시작할때 초기화
                if( i==0 ) {
                    before = cur;
                    count=1;
                    continue;
                }

                // 2. 압축할 수 있는지 체크 후, 압축
                if(before.equals(cur)) count++;
                else {
                    if(count==1){
                        result+=before;
                    }else{
                        result+=count+before;
                    }
                    before = cur;
                    count=1;
                }
            }
            // 3. 마지막 조각 더해줌
            result = (count==1)? result+before : result+count+before;

            // 4. 단위개수로 딱 잘리지 않는 경우, 단위개수 초과한 부분은 그냥 더해줌.
            if(size % c !=0) {
                before = s.substring(size-(size % c));
                result+=before;
            }
            // 5. 최종적으로 압축한 문자열의 길이를 이전과 비교
            if(answer > result.length()) answer = result.length();

        }
        return answer;
    }

    public static void main(String[] args) {
        int a = solution("aac");
        System.out.println(a);
    }
}

