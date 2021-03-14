#include<iostream>
#include<math.h>
using namespace std;


int rev_number (int p) {
    int rev_p,rem,count;
    rem = 0;
    count = 0;
    rev_p = 0;
    while(p) {
        rem = p%10;
        rev_p = rev_p*10 + rem;
        count++;
        p/=10;
    }
    return rev_p;
}

int main() {
    int N,p,q,rev_p,rev_q,rem,count;
    cin>>N;

    while(N--) {
        cin>> p >> q;
        rev_p = rev_number(p);
        rev_q = rev_number(q);
        // cout<<p<<" "<<q<<" "<<rev_p<<" "<<rev_q<<endl;
        cout<< rev_number(rev_p+rev_q)<<endl;
    }
}