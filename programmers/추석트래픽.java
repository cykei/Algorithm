/*
https://programmers.co.kr/learn/courses/30/lessons/17676
이미 정렬되있어서 조건보고 체크해주기만 하면됨.
*/

import java.util.*;
import java.text.SimpleDateFormat;
class Solution {
    class Point{
        long start, end;
        Point(long st,long ed){
            start = st;
            end =ed;
        }
    }
    public int solution(String[] lines) {
    
        int answer = 0;
        try{    
            ArrayList<Point> arr = new ArrayList<>();
            for (int i=0; i<lines.length; i++) {
                String[] items = lines[i].split(" ");
                SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd HH:mm:ss.SSS");
                Date date = sdf.parse(items[0]+" "+items[1]);
                long end = date.getTime();
                long start = end+1-(long)((Double.parseDouble(items[2].substring(0,items[2].length()-1)) * 1000));
                arr.add(new Point(start, end));
            }
            
            for (int i=0; i<arr.size(); i++ ){
                long iend = arr.get(i).end;
                int cnt =1;
                for (int j=i+1; j<arr.size(); j++){
                    if(iend >= arr.get(j).start && iend <= arr.get(j).end ||
                      iend >= arr.get(j).start && iend-999 <= arr.get(j).end ||
                      iend + 999 >= arr.get(j).start) cnt++;
                }
                answer = answer < cnt ? cnt : answer;
            }
        }catch(Exception e) {}
        return answer;
    }
}
