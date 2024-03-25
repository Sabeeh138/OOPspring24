/*
    Name: Mohammad Yesaullah Sheikh
    Roll no: 23k-0019
*/
#include <iostream>
using namespace std;

class Character{
    protected:
    int Health, Damage;
    public: 
    // constructor
    Character(){}
    Character(int health, int damage){
        Health = health;
        Damage = damage;
    }
    // display method
    void DisplayCharacter(){
        cout<<"Character Details: "<<endl;
        cout<<" Health: "<<Health<<endl;
        cout<<" Damage: "<<Damage<<endl;
    }
};

class Enemy: public Character{
    public:
    Enemy(int health, int damage){
        Health = health;
        Damage = damage;
    }
    void DisplayEnemy(){
        cout<<"Enemy Details: "<<endl;
        cout<<" Health: "<<Health<<endl;
        cout<<" Damage: "<<Damage<<endl;
    }
};

class Player: public Character{
    public:
    Player(){}
    Player(int health, int damage){
        Health = health;
        Damage = damage;
    }
    void DisplayPlayer(){
        cout<<"Player Details: "<<endl;
        cout<<" Health: "<<Health<<endl;
        cout<<" Damage: "<<Damage<<endl;
    }
};

class Wizard : public Player{
    int MagicPower;
    string Spells; // assuming max number of spells are 5
    public: 
    Wizard(int health, int damage, int magicpower, string spells){
        Health = health;
        Damage = damage;
        MagicPower = magicpower;
        Spells = spells;
    }
    void DisplayWizard(){
        cout<<"Wizard Details: "<<endl;
        cout<<" Health: "<<Health<<endl;
        cout<<" Damage: "<<Damage<<endl;
        cout<<" Magic Power: "<<MagicPower<<endl;
        cout<<"	Spells: "<<Spells<<endl;
    }
};
int main(){
  cout<<"Muhammad Sabeeh\n23k-0002\n"<<endl;
  Wizard wizard(70, 60, 80, "Fireball and ice sparks");

  wizard.DisplayWizard();
}
