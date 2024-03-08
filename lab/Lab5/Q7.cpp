/*
    Name: Muhammad Sabeeh
    Roll no: 23k-0002
*/
#include <iostream>
using namespace std;

class menu{
    string FoodName[5];
    float price[5];
    public:
    menu(){}
    int i;
    menu(string names[], float prices[]){
        for(i=0; i<5; i++){
            FoodName[i] = names[i];
            price[i] = prices[i];
        }
    }
    float getprice(int n){
        return price[n-1];
    }
    void setName(string names[]){
        for(i=0; i<5; i++){
            FoodName[i] = names[i];
        }
    }
    void setPrice(float prices[]){
        for(i=0; i<5; i++){
            price[i] = prices[i];
        }
    }
    void displaymenu(){
        cout<<"**********MENU************* "<<endl;
        for(i=0; i<5; i++){
            cout<<"     "<<i+1<<") Dish Name is : "<<FoodName[i]<<"\n        Price is: "<<price[i]<<endl;
        }
    }
};

class payments{
    float total;
    public:
    payments(){total = 0;}
    void updateTotal(float p){
        total += p;
    }
    float getTotal(){return total;}
};

class orders{
    menu m1;
    // menu m2;
    payments pay;

    public:
    orders(){}
    // orders(menu *m){
    //     m1 = m;
    // }
    void placeorder(menu m){
        m1 = m;
        cout<<"*******Menu 1******** "<<endl;
        m1.displaymenu();
        // cout<<"*********Menu 2********* "<<endl;
        // m2.displaymenu();
        string choice;
        cout<<"\nWhat would you like to order sire? "<<endl;
        cin>>choice;
        if(choice == "yes"){
            int c;
            int qty;
            int i;
            cout<<"\nEnter the number of items you would like to order monsueir : ";
            cin>>qty;
            for(i=0; i<qty; i++){
                cout<<"\nEnter the number of the specified item in the menu: ";
                cin>>c;
                if(c>=1  && c<=5){
                    pay.updateTotal(m1.getprice(c));
                }
                else{
                    cout<<"Enter a valid number of the item you want to order."<<endl;
                    i--;
                    continue;
                }
                
            }
        }
    }
    void bill(){
        cout<<"Total Amount you have to pay is = "<<pay.getTotal()<<endl;
    }
};

class System{
    menu m1;
    orders o1;
    public:
    System(){}
    void additems(string names[]){
        m1.setName(names);
    }
    void setprice(float prices[]){
        m1.setPrice(prices);
    }
    void Display(){
        m1.displaymenu();
    }
    void takeorder(){
        o1.placeorder(m1);
    }
    void total(){
        o1.bill();
    }  
};

int main(){
    
    string menu[5] = {"buffalo ranch ", "medium rare wagyu", "pina colada", "turkey cuts", "babar pasta"};
    float prices[5] = {50, 100, 75, 150, 20};

    System s1;

    
    s1.setprice(prices);
    s1.additems(menu);
    cout<<"\n"<<endl;
    s1.Display();
    cout<<"\n"<<endl;
    s1.takeorder();
    cout<<"\n"<<endl;
    s1.total();

    return 0;
}
