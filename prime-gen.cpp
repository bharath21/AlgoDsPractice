#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

#define MAX_N 1000001
bool prime[MAX_N] ={1};

void SieveOfEratosthenes(int n) 
{ 
    memset(prime,true,sizeof(prime));
    prime[0]=prime[1]=false;
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
} 

int main() {

    int t;
    long long int m,n;
    cin>>t;
    

    while(t--){
        cin>>m>>n;
		bool seg_prime[n-m+1];
        memset(seg_prime,true,sizeof(seg_prime));
        long long int sq = sqrt(n);
        SieveOfEratosthenes(sq);
        for (int i=2;i*i<=n;i++){
            if(prime[i]){ 
                long long int k = m/i;
                long long int q = k*i;
                if(q<m){
                    q+=i;
                }
                while(q<=n){
                    seg_prime[q-m]=false;
                    q+=i;
                }
            }
        }
     for(int i =0;i<(n-m)+1;i++){
        if(seg_prime[i]){
            cout<<m+i<<endl;
        }
    }
        cout<<endl;
    }

}