/*
name: Muhammad Abbas
ID: 23k-0068
purpose: Book database management system
*/

#include <iostream>
#include <string> //header file for string
#include <unistd.h> // header file for sleep function used in the code to pause the program
#include <cstdlib>  // header file for the system() function that we will use to clear the command console

using namespace std;

//a structure that defines a book data type
struct book {
    string title;
    string author;
    int publicationyr;
    string genre;
};


int main() {
    int choice, numBooks = 0/*variable that will hold the number of books present in the database*/;

    cout << "\n\n\n\n\t\t\t\t      Welcome to the Book Management System" << endl;
    book books[100];//array of the structure books to hold all the data

    while (true) {
    	//custom menu to show the user all the options and functionalities of the program
        cout << "\n\n\t\t\t\t********Choose from the following options:*******\n\n" << endl;
        cout << "\t\t\t\t|-----------------------------------------------|" << endl;
        cout << "\t\t\t\t|-----------------------------------------------|" << endl;
        cout << "\t\t\t\t|    1) Find a book from the database           |" << endl;
        cout << "\t\t\t\t|    2) Add a book to the database              |" << endl;
        cout << "\t\t\t\t|    3) Update data of an existing book record  |" << endl;
        cout << "\t\t\t\t|    4) Exit                                    |" << endl;
        cout << "\t\t\t\t|-----------------------------------------------|" << endl;
        cout << "\t\t\t\t|-----------------------------------------------|" << endl;
        cout << "Enter your choice:" << endl;
        cin >> choice;
        
        //main switch statement that will execute program based on user choice
        switch (choice) {
            //code for updating an already present book record
			case 3: {
                string search2;
                cout << "Enter the title of the book that you want to update" << endl;
                cin.ignore();//clearing the input buffer
                getline(cin, search2); //getline() used for string input
                  
                for (int i = 0; i < numBooks; i++) {
                    if (books[i].title == search2) {
                        cout << "Book found. Enter new data:" << endl;
                        cout << "Add new author:" << endl;
                        getline(cin, books[i].author);
                        cout << "Add new year of publication:" << endl;
                        cin >> books[i].publicationyr;
                        cout << "Add new genre:" << endl;
                        cin.ignore();//clearing the buffer
                        getline(cin, books[i].genre);
                        break;
                    }
                }
                break;
            }
            
            //code for entering new book data in the array
            case 2: {
                cout << "Enter data for the book:" << endl;
                cout << "Enter the title:" << endl;
                cin.ignore();//clearing buffer
                getline(cin, books[numBooks].title);
                cout << "Enter the author name:" << endl;
                getline(cin, books[numBooks].author);
                cout << "Enter the year of publication:" << endl;
                cin >> books[numBooks].publicationyr;
                cout << "Enter the genre:" << endl;
                cin.ignore();
                getline(cin, books[numBooks].genre);
                numBooks++; // Increment the number of books after adding a new book
                cout << "Book added successfully!" << endl;
                break;
            }
            
            //code for searching for a book based on title or author
            case 1: {
                int choice2;
                string search;
                while (true) {
                    cout << "Will you be searching with the title or author? Choose from below:" << endl;
                    cout << "1) Search by title" << endl;
                    cout << "2) Search by author" << endl;
                    cout << "Enter your choice:" << endl;
                    cin >> choice2;

                    cout << "Enter search value:" << endl;
                    cin.ignore(); //clearing the input buffer
                    getline(cin, search);
                    
                    //switch statement that will search based on title or author whatever the user wants
                    switch (choice2) {
                        case 1:
                            for (int i = 0; i < numBooks; i++) {
                                if (books[i].title == search) {
                                    cout << "Book found:" << endl;
                                    cout << "Title: " << books[i].title << endl;
                                    cout << "Author: " << books[i].author << endl;
                                    cout << "Year of publication: " << books[i].publicationyr << endl;
                                    cout << "Genre: " << books[i].genre << endl;
                                    break;
                                }
                            }
                            cout << "No relevant book record found" << endl;
                            break;

                        case 2:
                            for (int i = 0; i < numBooks; i++) {
                                if (books[i].author == search) {
                                    cout << "Book found:" << endl;
                                    cout << "Title: " << books[i].title << endl;
                                    cout << "Author: " << books[i].author << endl;
                                    cout << "Year of publication: " << books[i].publicationyr << endl;
                                    cout << "Genre: " << books[i].genre << endl;
                                    break;
                                }
                            }
                            break;

                        default:
                            cout << "Wrong choice. Please enter again." << endl;
                            continue;
                    }
                    break;
                }
                break;
            }
            
            //code to exit the program when the user wants
            case 4:
                cout << "Thank you! Use us again soon :)" << endl;
                exit(0); //exit function

            default:
                cout << "Wrong choice. The program will pause for a few seconds, then try again." << endl;
                sleep(3); //function to pause the program for 3 seconds
                system("cls");//function to clear the command console
                continue; //keyword to continue to next iteration of the loop
        }
    }

    return 0;
}
