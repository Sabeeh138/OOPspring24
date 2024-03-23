/*
    Name:Muhammad Sabeeh
    Roll no:23k-0002    
*/
#include <iostream>
using namespace std;

class Appointments{
    string name;
    string day; // day of the appointment
    static int AppointmentsCount;
    static float TotalEarnings;
    public:
    //constructor
    Appointments(string name, string day, float cost){
        AppointmentsCount++;
        this->name = name;
        this->day = day;
        TotalEarnings += cost;
    }
    //getters
    int getAppointmentCount(){
        return AppointmentsCount;
    }
    float getTotalEarnings(){
        return TotalEarnings;
    }
    string getName(){
        return name;
    }
    string getDay(){
        return day;
    }
    //setters
    void setName(string name){
        this->name = name;
    }
    void setDay(string day){
        this->day = day;
    }
    void setAppointmentsCount(int count){
        AppointmentsCount += count;
    }
    void setTotalEarnings(float earnings){
        TotalEarnings += earnings;
    }
    static float AverageCostPerAppointment(){
        if(AppointmentsCount == 0){
            return 0;
        }
        else{
            return  (TotalEarnings / AppointmentsCount);
        }
    }
};

// initialization of static data members
int Appointments::AppointmentsCount = 0;
float Appointments::TotalEarnings = 0;

int main(){
    Appointments a1("Sabeeh", "Monday", 500);
    Appointments a2("arnold", "Wednesday", 1000);
    Appointments a3("Mandem", "Friday", 200.5);
    Appointments a4("Homie", "Tuesday", 300);

    cout<<"The average cost of all the appoinments is: "<<a1.AverageCostPerAppointment()<<endl;
}
