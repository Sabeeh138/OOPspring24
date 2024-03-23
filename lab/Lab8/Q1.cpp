/*
Name: Muhammad Sabeeh
ID:23K-0002
*/

#include <iostream>
#include <string>

using namespace std;

//base class 
class Book {
	protected:
    	string title;
    	string author;
    	string publisher;

	public:
    	//parameterized constructor with initializer list
    Book(string atitle, string aauthor, string apublisher)
        : title(atitle), author(aauthor), publisher(apublisher) {}

    //display function
    void display() const {
    	cout<<"information about the book"<<endl;
        cout<<"Title: "<<title<<endl;
        cout<<"Author: "<<author << endl;
        cout<<"Publisher: "<<publisher<<endl;
    }
};

//derived or subclass 
class FictionBook : public Book {
	private:
    	string genre;
    	string protagonist;

	public:
    	//parameterized constructor with initializer list for inheritance
    	FictionBook(string atitle, string aauthor, string apublisher, string agenre, string aprotagonist)
        : Book(atitle, aauthor, apublisher), genre(agenre), protagonist(aprotagonist) {}

    //second implemenyain of display function (function overriding)
    void display() const {
        //get existing implementation of the display
        Book::display();
        //define additional implementation
        cout<<"Genre: "<<genre<<endl;
        cout<<"Protagonist: "<<protagonist<<endl;
    }
};

int main() {
	cout<<"Muhammad Sabeeh\n23k-0002"<<endl;
    //instance of the derived class
    FictionBook book("it ends with us", "Collen Hoover", "oxford", "Romantic-Fiction", "lily Bloom");
    book.display();

    return 0;
}
