/*
Name:Muhammad Sabeeh
ID:23k-0002
purpose: a program to swap values of 2 variables with recursion
*/

#include<iostream>


using namespace std;

//defining the recursive function
void recursiveSwap(int& x, int& y) {
	//if values are same so no swap required
	if(x==y) {
		cout<<"no swap required"<<endl;
	} else {
		int temp = x;
        x = y;
        y = temp;
//        recursiveSwap(x, y);
	}
}

int main() {
	int a,b;
	cout<<"enter the value of the first variable: "<<endl;
	cin>>a;
	cout<<"enter the value of the second variable"<<endl;
    cin>>b;
    cout<<"the values before the swap are a="<<a<<" and b="<<b<<endl;
    recursiveSwap(a,b);
    cout<<"the values after the swap are a="<<a<<" and b="<<b<<endl;
    return 0;
}
