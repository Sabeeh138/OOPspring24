/*
Name: Muhammad Abbas
ID:23K-0068
Purpose: code to show multiple inheritance between attributes of a character in a game
*/


#include <iostream>

using namespace std;

//base-class 1
class Position {
	protected:
    	double x;
    	double y;
    	double z;

	public:
    	//constructor with initializer list
    	Position(double ax, double ay, double az) : x(ax), y(ay), z(az) {}

    	//function to display position
    	void displayPosition() const {
        	cout<<"Position: ("<<x<<", "<<y<<", "<<z<<")"<<endl;
    	}
};

//base-class 2
class Health {
	protected:
    	int health;

	public:
    	Health(int ahealth) : health(ahealth) {}

    //utility to display health
    void displayHealth() const {
        cout<<"Health: "<<health<< endl;
    }
};

//derived class with mulitple inheritance
class Character : public Position, public Health {
	private:
    	string name;
    	int level;

	public:
    //constructor with initializer list
    Character(double ax, double ay, double az, int ahealth,string aname, int alevel) : Position(ax, ay, az), Health(ahealth), name(aname), level(alevel) {}

    //utility to display character deets
    void displayCharacter() const {
        cout<<"Character Name: "<<name<<endl;
        cout<<"Character Level: "<<level<<endl;
        //display functions from both inherited classes
		displayPosition(); 
        displayHealth();   
    }
};

int main() {
	cout<<"Muhammad Sabeeh\n23k-0002\n"<<endl;
	
    //instace of a Character object
    Character player(9.9, 10.7, 4.5, 100, "Player1", 1);
    player.displayCharacter();

    return 0;
}
