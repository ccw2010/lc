#include<iostream>
#include<ctime>
using namespace std;

/*
从S中抽取首k项放入「水塘」中
对于每一个S[j]项（j ≥ k）：
    随机产生一个范围从0到j的整数r
    若 r < k 则把水塘中的第r项换成S[j]项
*/

/* ReservoirSample(S[1..n], R[1..k])
// fill the reservoir array
for i = 1 to k
  R[i] = S[i]

// replace elements with gradually decreasing probability
for j = k+1 to n
    r = random(1, j)   // important: inclusive range
    if r <= k
        R[r] := S[i]
*/

// O(n) algorithm
int main(){
    vector<int> S{0,1,2,3,4,5,6,7,8,9};
    const int k = 4;
    vector<int> R(k);
    int i, j;
    for (i=0; i<k; i++){
        R[i] = S[i];
    }

    for(j=k; j<S.size(); j++){
        srand(time(NULL));
        r = rand() % j;
        if(r < k) R[r] = S[j];
    }
    
    for(int i=0; i<k; i++){
        cout << R[i] << endl;
    }
}