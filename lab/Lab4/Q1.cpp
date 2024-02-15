#include<iostream>

using namespace std;

class book{
private:
   string name;
   string author;
   int ISBN;
   int totalpages;
   int currentpagesread;
   
public:
//default c
book() {
name="";
author="";
ISBN=0;
totalpages=0;
currentpagesread=0;
}

//parameterized c
book(string aname, string aauthor, int aisbn, int total, int current) {
name=aname;
author=aauthor;
ISBN=aisbn;
totalpages=total;
currentpagesread=current;
}

//function to update pages and to check if book is finished
void read() 
{
    if(currentpagesread<totalpages) {
    currentpagesread++;
    cout<<"you have read the page "<< currentpagesread<<endl;
} 
    else {
    cout<<"book is finished"<<endl;
}

}

};

int main () {

//initializing a object
book Book("beauty of war","J.stalin",420420,9,0);

//attempted to read 10 pages
for(int i=0;i<11;i++){

Book.read();
}



}
