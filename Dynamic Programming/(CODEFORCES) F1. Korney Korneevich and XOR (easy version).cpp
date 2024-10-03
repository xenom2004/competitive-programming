
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long int

template<typename T>
T maxt(T a,T b){return (a>b)?a:b;}
template<typename T>
T mint(T a,T b){return (a<b)?a:b;}

int main() {

ll test_case_number=1;

for(ll test=0;test<test_case_number;test++){

    ll n;
    cin>>n;
    vector<ll>arr(n+1);// take input 1 - indexed
    for(ll i=1;i<=n;i++)cin>>arr[i];

    vector<vector<ll>>dp(n+1,vector<ll>(513,-1));  // dp[i][x] represent the
    // minimum value of the last picked element in the subsequence formed from first i
    // elements of array such that the xor of all of them equals to x.
    
    
    for(ll i=1;i<=n;i++){ 
        for(ll x=0;x<=512;x++){

            if(arr[i]>=dp[i-1][x] && dp[i-1][x]!=-1){  // if we can take the element

                if(dp[i][x^arr[i]]==-1)dp[i][x^arr[i]]=arr[i];  //checks if the value is -1, if so we just add the new number else
                else dp[i][x^arr[i]]=mint<ll>(dp[i][x^arr[i]],arr[i]); // we take the minimum of the two values

            }


            if(dp[i-1][x]!=-1){ // if we cannot take the element

                if(dp[i][x]==-1)dp[i][x]=dp[i-1][x]; // value remains same if it is -1 else
                else dp[i][x]=mint<ll>(dp[i-1][x],dp[i][x]); // take the minimum of the two values

            }


            if(dp[i][arr[i]]==-1)dp[i][arr[i]]=arr[i]; // if we are starting a new subsequence from i th position.
            else dp[i][arr[i]]=mint<ll>(dp[i][arr[i]],arr[i]); // take the minimum of the two values

        }
    }
    set<ll>ans;
    ans.insert(0); // base case
    
    for(ll i=1;i<=n;i++){
        for(ll x=0;x<=512;x++){
            if(dp[i][x]!=-1){
                ans.insert(x);  // take all possible values.
            }
        }
    }
    // output
    cout<<ans.size()<<endl;
    for(auto nei:ans){
        cout<<nei<<" ";
    }
    cout<<endl;
    
}
return 0;
}