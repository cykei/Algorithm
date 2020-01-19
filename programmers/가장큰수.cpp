/*
2020.01.19

https://programmers.co.kr/learn/courses/30/lessons/42746#

푸는방법에는 2가지 정도 있는것 같다.
두 방법 모두 numbers의 숫자들을 전부 문자열로 바꾸고 시작한다.
1) 다 4자리수로 만들어서 정렬. 3->3333, 12->1212, 30->3030
2) 두개씩 더해서 비교하고 큰쪽을 먼저 배치하는 순서로 정렬 (내 풀이)


주의
"0000" -> "0" 으로 출력해야한다.
*/



#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool comp(string& a, string& b){
    return a+b > b+a;
}
string solution(vector<int> numbers) {
    string answer = "";
    int nsize = numbers.size();
    vector<string> stnums(nsize);
    for (int i=0; i<nsize; i++){
        string num = to_string(numbers[i]);
        stnums[i]= num;
    }

    sort(stnums.begin(), stnums.end(), comp);
    for (int i=0;i <nsize; i++){
        answer+=stnums[i];
    }

    if(answer[0]=='0') return "0";
    return answer;
}
