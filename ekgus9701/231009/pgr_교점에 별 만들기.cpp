#include <string>
#include <vector>
#include<iostream>
#include<algorithm>
#include<climits>
#include<set>

using namespace std;

vector<string> solution(vector<vector<int>> line) {
    vector<string> answer;
    
    set<pair<long long, long long>> sets;
    
    //참고사항 이용해서 계산
    for(int i=0;i<line.size();i++){
        for(int j=i;j<line.size();j++){
           long long z = (long long)line[i][0] * line[j][1] - (long long)line[i][1] * line[j][0];
            
            if (z != 0) {
                double x = ((double)line[i][1] * line[j][2] - (double)line[i][2] * line[j][1]) / z;
                double y = ((double)line[i][2] * line[j][0] - (double)line[i][0] * line[j][2]) / z;

                if (x - (long long)x == 0 && y - (long long)y == 0) { //자연수인지 체크
                    sets.insert({ x, y });
                }
            }
        }
    }
    
    
    long long min_X=LLONG_MAX;
    long long min_Y=LLONG_MAX;
    long long max_Y=LLONG_MIN;
    long long max_X=LLONG_MIN;
    
    //X,Y 최대 최소 구하기
    for(const auto& s : sets){
        min_X=min(min_X,s.first);
        max_X=max(max_X,s.first);
        min_Y=min(min_Y,s.second);
        max_Y=max(max_Y,s.second);
    }
    
   //.으로 초기화
    for(long long i=min_Y;i<=max_Y;i++){
        string str="";
        for(long long j=min_X;j<=max_X;j++){
            str+=".";
        }
        answer.push_back(str);
    }
    
    //첫째 예시에서 (-4,1)이 배열에서는 (3,0)으로 바뀌어야함
     for (const auto& s : sets) {
        answer[abs(s.second - max_Y)][abs(s.first - min_X)] = '*';
    }
    
    
    return answer;
}
