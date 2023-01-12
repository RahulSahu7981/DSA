#include<iostream>
// #include<bits/stdc++.h>
#include<vector>
using namespace std;
int prefixSum(vector<int> &v, int index){
    
    if(index==0){
        return v[0];
    }
    for(int i=1;i<=index;i++){
    v[i]=v[i-1]+v[i];
}
return v[index];
}

bool checkPrefixSuffixSum(vector<int> &v){
    int sum=0;
    for(int i=0;i<v.size();i++){
        sum+=v[i];
    }

    int pSum=0;
    for(int i=0;i<v.size();i++){
        pSum+=v[i];
        int sSum=sum-pSum;
        if(pSum==sSum){
            return true;
        }
    }
    return false;
}

int main(){
vector<int> v;
int n;
cin>>n;
int sum=0;
for(int i=0;i<n;i++){
    int ele;cin>>ele;
    sum+=ele;
    v.push_back(ele);
}
int check =checkPrefixSuffixSum(v);
cout<<check<<endl;
// for(int i=0;i<v.size();i++){
//     int pSum=prefixSum(v,i);
//     if(pSum==sum-pSum){
//         cout<<"Partition found at index:"<<i<<endl;
//     }
// }

// prefixSum(v);
// for(int i=0;i<v.size();i++){
//     cout<<v[i]<<" ";
// }

return 0;
}