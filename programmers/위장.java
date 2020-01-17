/*

2020.01.17
https://programmers.co.kr/learn/courses/30/lessons/42578

해시 + 경우의 수 문제

3가지 안경, 4가지 옷, 2가지 하의 중 
하나이상 걸치고
겹치지 않게 입는
조합의 수는?

= 4 * 5 * 3 -1

*/

import java.util.HashMap;
import java.util.Iterator;
class Solution {
    public int solution(String[][] clothes) {
        int answer = 1;
        HashMap<String, Integer> map = new HashMap<>();

        for (int i=0; i<clothes.length; i++){
            String key = clothes[i][1];
            if(!map.containsKey(key))
                map.put(key,1);
            else 
                map.put(key,map.get(key)+1);
        }

        Iterator<Integer> itr = map.values().iterator();
        while(itr.hasNext()){
            answer = answer * (itr.next().intValue() +1 );
        }
        answer--;
        return answer;
    }
}
