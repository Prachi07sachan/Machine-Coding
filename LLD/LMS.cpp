#include <bits/stdc++.h>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool avail;

    Book(int i, string t, string a) {
        id = i;
        title = t;
        author = a;
        avail = true;
    }
};

class Member {
public:
    int id;
    string name;
    unordered_set<int> issued;

    Member(int i, string n) {
        id = i;
        name = n;
    }
};

class Library {
public:
    unordered_map<int, Book*> books;
    unordered_map<int, Member*> members;

    void addBook(Book* b) {
        books[b->id] = b;
    }

    void addMember(Member* m) {
        members[m->id] = m;
    }

    void issueBook(int bid, int mid) {
        if (!books.count(bid) || !members.count(mid)) return;

        Book* b = books[bid];
        Member* m = members[mid];

        if (!b->avail) {
            cout << "Book not available\n";
            return;
        }

        b->avail = false;
        m->issued.insert(bid);
    }

    void returnBook(int bid, int mid) {
        if (!books.count(bid) || !members.count(mid)) return;

        Book* b = books[bid];
        Member* m = members[mid];

        if (!m->issued.count(bid)) return;

        b->avail = true;
        m->issued.erase(bid);
    }
};
