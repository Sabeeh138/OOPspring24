/*
Name:Muhammad Sabeeh
ID:23K-0002
Purpose:a program to create cons with diff pages and then change it using setters.
*/

#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int pageCount;
    int pagesRead;

public:
    // Default Constructor
    Book() : pageCount(1000), pagesRead(0) {}

    // Setter methods
    void setTitle(const string& t) {
        title = t;
    }

    void setAuthor(const string& a) {
        author = a;
    }

    void setPageCount(int pc) {
        pageCount = pc;
    }

    void setPagesRead(int pr) {
        pagesRead = pr;
    }

    // Method to display book information
    void showBookInfo() {
        cout << "Title: " << title <<endl;
        cout << "Author: " << author <<endl;
        cout << "Page Count: " << pageCount <<endl;
        cout << "Pages Read: " << pagesRead <<endl;
    }
};

int main() {
    Book myBook;
    myBook.setTitle("warzone");
    myBook.setAuthor("rick rhymes");
    myBook.setPageCount(218);
    myBook.setPagesRead(50);

    myBook.showBookInfo();

    return 0;
}
