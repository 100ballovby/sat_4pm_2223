#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
protected:
    string title;
    string author;
    int year;
public:
    Book(const string &title, const string &author, const int year) : title(title), author(author), year(year) {}
    virtual void printDetails() const {
        cout << "title: " << title << endl;
        cout << "author: " << author << endl;
        cout << "year: " << year << endl;
    }
};

class FictionBook : public Book {
private:
    string genre;
public:
    FictionBook(const string &title, const string &author, const int &year, const string &genre)
    : Book(title, author, year), genre(genre) {}  // здесь я указываю, что часть данных дает book, часть дочерний класс

    void printDetails() const override {
        Book::printDetails();  // унаследованный от book метод можно вызвать
        cout << "Genre: " << genre << endl;
    }
};

class NonFictionBook : public Book {
private:
    string subject;

public:
    NonFictionBook(const string &title, const string &author, const int year, const string &subject)
    : Book(title, author, year), subject(subject) {}

    void printDetails() const override {
        Book::printDetails();
        cout << "Subject: " << subject << endl;
    }
};

class BookManager {
private:
    vector<Book*> books;
public:
    ~BookManager() {
        for (Book* book : books) {
            delete book;
        }
    }

    void addBook(Book *book) {
        books.push_back(book);
    }

    void displayAllBooks() const {
        for (const Book *book : books) {
            book->printDetails();
            cout << endl;
        }
    }
};

int main() {
    Book *book1 = new FictionBook("The Great Gatsby", "F. Scott Fitzgerald", 1925, "Novel");
    Book *book2 = new FictionBook("Idiot", "F.Dostoevski", 1835, "Novel");
    Book *book3 = new NonFictionBook("Chelovek: Nauka o durakah", "Umniy Psikholog", 2019, "Antropology");
    Book *book4 = new NonFictionBook("Criminal woirld", "J.P.James", 2000, "Business");

    // создадим менеджера книг
    BookManager oleg;
    oleg.addBook(book1);
    oleg.addBook(book2);
    oleg.addBook(book3);
    oleg.addBook(book4);

    oleg.displayAllBooks();

    // освободим память
    delete book1;
    delete book2;
    delete book3;
    delete book4;
    return 0;
}
