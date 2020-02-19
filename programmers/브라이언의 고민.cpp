/*
https://programmers.co.kr/learn/courses/30/lessons/1830
이런 문제는 코딩테스트에 안나왔으면.... 제발....

풀이시간 : 8시간
+22
*/
#include <string>
#include <cstring>
#include <unordered_set>
using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

string solution(string sentence) {
	string answer = "";
	int i = 0;
	unordered_set<char> set;
	int startPos[26];
	int endPos[26];
	int alpha[26] = { 0 };
	memset(startPos, -1, sizeof(startPos));
	memset(endPos, -1, sizeof(endPos));

	// 소문자를 센다.
	for (int i = 0; i < sentence.length(); i++) {
		int c = sentence[i] - 'a';
		if (c >= 0) { //소문자인데
			if (alpha[c] == 0) { //한번도 안나왔었으면
				startPos[c] = i; //그때가 그 문자의 시작점.
				endPos[c] = i;
				alpha[c]++;
			}
			else {
				endPos[c] = i;
				alpha[c]++;
			}
		}
		else if (c == ' ') {//공백이 있으면
			return "invalid";
		}
	}
  
    // 길이가 1~3일때는 나올수 있는 패턴 전부 체크해서 return 한다.
	if (sentence.length() == 1 && sentence[0] <'a') {
		return sentence;
	}
	else if (sentence.length() == 2) {
		if (sentence[0] >= 'a' || sentence[1] >= 'a') return "invalid";
		else {
			return sentence;
		}
	}
	else if (sentence.length() == 3) {
		if (sentence[0] >= 'a'&& sentence[1] < 'a' && sentence[2] == sentence[0]) {
			//aBa
			return answer+sentence[1];
		}
		else if (sentence[0] < 'a'&& sentence[1] >= 'a' && sentence[2] < 'a') {
			//AaA
			return answer+sentence[0] + sentence[1];
		}
		else if (sentence[0] < 'a'&& sentence[1] < 'a' && sentence[2] < 'a') {
			//ABC
			return sentence;
		}
		else {
			return "invalid";
		}
	}


	// 길이가 4이상일 때부터는 탐색한다.
	while (i < sentence.length()) {
		if (sentence[i] < 'a') { // 0번이 대문자고 (AaBaCaD, AB)
			if (i + 1 != sentence.length()) {
				if (sentence[i + 1] >= 'a' && alpha[sentence[i+1]-'a'] !=2) { // 1번이 소문자면 (AaBaCaD, AaBC)
					char cur = sentence[i + 1];

					//해당 소문자의 중복검사를 실시한다.
					if (set.find(cur) == set.end()) {
						set.insert(cur);
					}
					else return "invalid";

					answer += sentence[i]; i++;  // A를 더한다.
					while (i != endPos[cur - 'a']) {
						//HaEaLaLObWORLDb = HELL O WORLD
						if (sentence[i] != cur) return "invalid";
						if (sentence[i + 1] < 'a') answer += sentence[i + 1]; //B,C를 더한다.
						else return "invalid"; //AaAab
						i += 2;
					}
					if (i+1 == sentence.length()) {
						return "invalid";
					}
					else {
						if (sentence[i + 1] < 'a') { //D를 더한다.
							answer += sentence[i + 1];
							answer += ' '; //한단어가 끝났으므로 공백을 더한다.
							i += 2;
						}
					}
				}
				else { // 1번이 대문자면 (AB,AaBaCDC)
					answer += sentence[i]; //D를 더한다.
					answer += ' ';
					i++;
				}
			}
			else { //이게 마지막이면 
				answer += sentence[i];
				answer += ' ';
				i++;
			}
		}
		else if(sentence[i] >= 'a' && alpha[sentence[i]-'a']==2){ // 0번이 소문자고 2번룰 적용이면(aBBa or aBbBbBa)
			char two = sentence[i];

			//해당 소문자의 중복검사를 실시한다.
			if (set.find(two) == set.end()) {
				set.insert(two);
			}
			else return "invalid";
			
			//aa, ab 
			if (sentence[i] >= 'a' &&sentence[i + 1] >= 'a') return "invalid";
			
			//aBa
			if (sentence[i + 2] == two) {
				answer += sentence[i + 1];
				answer += ' ';
				i += 3;
			}
			else if (sentence[i + 2] < 'a') {
				//aBBa, aBBBa
				i++;
				while (i < endPos[two - 'a']) {
					if (sentence[i] < 'a') answer += sentence[i];
					else return "invalid";
					i++;
				}
				answer += ' ';
				i++;
			}
			else if (sentence[i + 2] >= 'a' && sentence[i + 2] != two && (endPos[two-'a']-i)%2==0) {
				//aBca aBcBa aAbAba(x)
				char three = sentence[i+2];

				//해당 소문자의 중복검사를 실시한다.
				if (set.find(three) == set.end()) {
					set.insert(three);
				}
				else return "invalid";
			
				i++;
				//printf("three: %c\n", three);
				while (i+1 < endPos[two - 'a']) {//cAbBbAc
					//printf("%d: ", i);
					if (sentence[i] < 'a') answer += sentence[i];
					else return "invalid";
					i++;
					if (sentence[i] == three) {
						i++;
					}
					else return "invalid";
				}
				answer += sentence[i];
				answer += ' ';
				i+=2;

			}

		}
		else return "invalid";
	}
    answer.erase(answer.length()-1,1);  //마지막에 붙인 공백을 삭제한다.
	return answer;
	
}
