#include <iostream>
using namespace std;

class LibraryItem {
protected:
    string title, author, dueDate;

public:
    virtual void checkOut() = 0;
    virtual void returnItem() = 0;
    virtual void display() = 0;
};

class Book : public LibraryItem {
public:
    void setData(string t, string a, string d) {
        title = t;
        author = a;
        dueDate = d;
    }

    void checkOut() {
        cout << "Book Issued\n";
    }

    void returnItem() {
        cout << "Book Returned\n";
    }

    void display() {
        cout << title << " " << author << " " << dueDate << endl;
    }
};

int main() {
    LibraryItem* item;
    Book b;

    int ch;

    do {
        cout << "1.Add Book 2.Show 3.Exit\n";
        cin >> ch;

        if (ch == 1) {
            string t, a, d;
            cin >> t >> a >> d;
            b.setData(t, a, d);
            item = &b;
            item->checkOut();
        }

        else if (ch == 2) {
            item = &b;
            item->display();
        }

    } while (ch != 3);

    return 0;
}