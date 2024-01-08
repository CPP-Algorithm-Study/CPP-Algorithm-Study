#include <string>
#include <vector>
#include<algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    
    int a=0;
    
    for(int i=0;i<B.size();i++){
        if(A[a]<B[i]){ 
            answer++;
            a++;
        }
    }
    
    return answer;
}

