#include<iostream>
#include<vector>
using namespace std;


class Book
{
public:
    string title;
    string author;
    bool issued;

    Book(string t, string a)
    {
        title = t;
        author = a;
        issued = false;
    }
};

class Library
{
public:
    vector<Book> books;   


    void addBook(string title, string author)
    {
        books.push_back(Book(title, author));
        cout << "Book added: " << title << endl;
    }


    void issueBook(string title)
    {
        for (auto &b : books)
        {
            if (b.title == title && b.issued == false)
            {
                b.issued = true;
                cout << "Book issued: " << title << endl;
                return;
            }
        }
        cout << "Book not available!\n";
    }

    
    void returnBook(string title)
    {
        for (auto &b : books)
        {
            if (b.title == title && b.issued == true)
            {
                b.issued = false;
                cout << "Book returned: " << title << endl;
                return;
            }
        }
        cout << "Book not found!\n";
    }

    
    void displayBooks()
    {
        cout << "\nLibrary Status:\n";

        for (auto &b : books)
        {
            if (b.issued)
                cout << b.title << " -> Issued\n";
            else
                cout << b.title << " -> Available\n";
        }
    }
};