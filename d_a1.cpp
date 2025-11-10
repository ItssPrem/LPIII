#include<bits/stdc++.h>
using namespace std;

int recurFibo(int n){
    if(n<=1) return n;

    return recurFibo(n-1) + recurFibo(n-2);
}

int nonRecurFibo(int n){
    if(n<=1) return n;

    int a=0;
    int b=1;
    int c;
    for(int i=2;i<=n;i++){
        c=a+b;
        a=b;
        b=c;
    }
    return b;
}
int main(){
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Fibonacci(" << n << ") = " << nonRecurFibo(n) <<" "<<recurFibo(n) <<endl;
    return 0;
}