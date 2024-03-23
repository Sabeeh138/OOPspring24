/*
Name: Muhammad Sabeeh
ID:23k-0002
*/
#include <iostream>

using namespace std;

//inline function to calculate batting average
inline double calcBattingAvg(int runs, int dismissals) {
    if (dismissals == 0) {
    	//to remove division by zero error
        return 0; 
    }
    //typecasts integer values to double for finding the answer in double
    return static_cast<double>(runs) / dismissals;
}

//inline function to calculate strike rate
inline double calcStrikeRate(int runs, int balls) {
    if (balls == 0) {
    	//removing division by zero error
        return 0; 
    }
    return static_cast<double>(runs) / balls * 100;
}

int main() {
	cout<<"Muhammad Sabeeh\n23k-0002\n\n"<<endl;
	
    int Runs, Dismissals, Balls;

    cout<<"Enter total runs scored: ";
    cin>>Runs;
    cout<<"Enter total payer dismissals ";
    cin>> Dismissals;
    cout<<"Enter num of balls faced: ";
    cin>>Balls;

    double battingAverage = calcBattingAvg(Runs, Dismissals);
    cout<<"Batting Average: "<<battingAverage<<endl;


    double strikeRate = calcStrikeRate(Runs, Dismissals);
    cout<<"Strike Rate: "<<strikeRate<<endl;

    return 0;
}
