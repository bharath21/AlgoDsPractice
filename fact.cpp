 #include<iostream>
 #include<vector>
 using namespace std;
 
 vector<long long int> f(101,0);

long long int fact(int n){

return fact[n];
}
 int main(){
       int tc,n;
       cin >> tc;
       fact[0]=fact[1]=1;
for(int i =2;i<=100;i++){
	fact[i]=fact[i-1]*i;
}
       while(tc--){
             cin>>n;
             cout<<fact(n)<<endl;
       }
 }