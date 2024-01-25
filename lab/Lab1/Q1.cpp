#include<iostream>
using namespace std;
int main() {
int num;
int cnt=0;
int flag =0;
cout << "Enter a number: ";
cin >> num;
for(int i=2; i<=num; i++){
    if(i!=num){
        if(num%i == 0){
            flag = 1;
        }
    }
}
    if(flag){
        cout<<"Not a Prime number";
    }
    else{
        cout << "Prime Number";
    }
  return 0;
}


