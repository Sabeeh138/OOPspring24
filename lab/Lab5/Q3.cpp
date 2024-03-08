/*
    Name: Muhammad Sabeeh
    Roll no: 23k-0002
*/
#include <iostream>
#include <cctype>
using namespace std;

class ValidateString{
    string str;
    public:
    ValidateString(string str){
        this->str = str;
    }
    string isValid() const{
        int length = str.length(); 
        int i;
        for(i=0; i<length; i++){
            if(isalpha(str[i])){
                continue;
            }
            else{
                return "no"; // whenever a non-alphabetic character is found, it returns false;
            }
        }
        return "yes";
    }
};

int main(){
    ValidateString s1("Sabeeh"); 
    ValidateString s2("I am from Islamabad."); 
    ValidateString s3("1) I study in FAST-NUCES"); 

    cout<<"Is string 1 valid? "<<s1.isValid()<<endl;
    cout<<"Is string 2 valid? "<<s2.isValid()<<endl;
    cout<<"Is string 3 valid? "<<s3.isValid()<<endl;

    return 0;
}
