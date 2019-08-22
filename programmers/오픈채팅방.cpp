#include <string>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;
/*
* sstream : istringstream : string을 받으면 공백을 기준으로 자동으로 끊어서 반환해준다.
* unordered_map : key-value 구조의 해시배열. key는 중복되어서 존재할수 없다. 
*                 key의 value를 수정하는 방법은 모르겠어서, 해당 key가 이미 있으면 지우고 다시 insert해주는 방식을 쓰고 있다.
*/

struct line{
    char order;
    string id;
    string name;
};

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<line> lines; 
    unordered_map<string,string> map;
    
    for(auto i=0; i<record.size(); i++){
    
        // 1. 공백을 기준으로 한 줄을 split 해준다. split 된 건 items에 들어간다.
        istringstream iss(record[i]);
        vector<string> items;
        do {
            string st;
            iss >> st;
            items.push_back(st);
        }while(iss);
        
        // 2. items 를 뽑아내서 line 구조체에 넣어준다.
        line li;
        li.order = items[0][0];
        li.id = items[1];
        if(li.order!='L') li.name = items[2];
        lines.push_back(li);
       
        // 3. id와 name을 맵핑한다.
        if(li.order=='E'){
            if(map.find(li.id)!=map.end()) map.erase(map.find(li.id));
            map.insert(make_pair(li.id, li.name));
        }else if(li.order =='C'){
            map.erase(map.find(li.id));   
            map.insert(make_pair(li.id, li.name));
        }
    }
    
    // 4. 맵핑되어있는 이름으로 출력한다. 
    for (auto i=0; i<lines.size(); i++){
        string ans ="";
        string nm = map.find(lines[i].id)->second;
        if(lines[i].order == 'E'){
            ans+=nm;
            ans+="님이 들어왔습니다.";
        }else if(lines[i].order == 'L'){
            ans+=nm;
            ans+="님이 나갔습니다.";
        }
        if(ans!="") answer.push_back(ans);
    }
    
    return answer;
}
