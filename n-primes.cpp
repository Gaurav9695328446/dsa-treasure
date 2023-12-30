// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

vector<int> primeN;

bool isPrime(int n){
    for(int i = 0;i<primeN.size();i++){
        if(n%primeN[i]==0)
            return false;
    }
    return true;
}

int main(){
    int n =1;
    int i=2;
    while(primeN.size()<n){
        if(isPrime(i)){
            primeN.push_back(i);
            cout << i << (primeN.size() == n ? "" : ", ");
        }
        i++;
    }
    return 0;
}