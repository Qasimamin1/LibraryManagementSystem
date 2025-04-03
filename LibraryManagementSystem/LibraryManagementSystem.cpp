#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

// Book structure to hold book details
struct Book {
    int id;
    string title;
    double price;
};

// Function to display available books
void showBooks(const vector<Book>& books) {
    cout << "\nAvailable Books:\n";
    cout << "--------------------------------------------------\n";
    cout << left << setw(10) << "ID" << setw(30) << "Title" << "Price (USD)\n";
    cout << "--------------------------------------------------\n";

    for (const auto& book : books) {
        cout << left << setw(10) << book.id << setw(30) << book.title << "$" << fixed << setprecision(2) << book.price << "\n";
    }

    cout << "--------------------------------------------------\n";
}

// Function to calculate total with discount
double calculateTotalWithDiscount(double total) {
    if (total > 100) {
        return total * 0.86; // 14% discount
    }
    else if (total > 75) {
        return total * 0.90; // 10% discount
    }
    else if (total > 50) {
        return total * 0.95; // 5% discount
    }
    return total;
}

int main() {
    // Create a list of 15 books
    vector<Book> books = {
        {101, "C++ Programming", 25.50},
        {102, "Data Structures", 20.00},
        {103, "Operating Systems", 30.25},
        {104, "Computer Networks", 28.75},
        {105, "Database Systems", 27.40},
        {106, "Software Engineering", 24.99},
        {107, "Artificial Intelligence", 32.80},
        {108, "Machine Learning", 35.60},
        {109, "Web Development", 22.00},
        {110, "Mobile App Dev", 23.50},
        {111, "Linux Basics", 19.99},
        {112, "Cloud Computing", 31.25},
        {113, "Big Data Concepts", 29.99},
        {114, "Cyber Security", 26.50},
        {115, "Python Essentials", 21.70}
    };

    string customerName;
    vector<Book> cart;
    char moreBooks = 'y';

    // Input customer name
    cout << "Welcome to the Library!\n";
    cout << "Please enter your name: ";
    getline(cin, customerName);

    // Shopping loop
    while (tolower(moreBooks) == 'y') {
        showBooks(books);

        cout << "Enter Book ID(s) you want to buy (separated by space, type -1 to stop):\n";
        int id;
        while (cin >> id && id != -1) {
            bool found = false;
            for (const auto& book : books) {
                if (book.id == id) {
                    cart.push_back(book);
                    cout << "Added \"" << book.title << "\" to your cart.\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                cout << "Book with ID " << id << " not found.\n";
            }
        }

        cin.clear(); // clear input buffer
        cin.ignore(10000, '\n');

        cout << "Do you want to buy more books? (y/n): ";
        cin >> moreBooks;
        cin.ignore(); // clear newline character
    }

    // Calculate total
    double total = 0;
    cout << "\n------------------- Bill Summary -------------------\n";
    for (const auto& item : cart) {
        cout << item.title << " - $" << fixed << setprecision(2) << item.price << "\n";
        total += item.price;
    }

    double finalAmount = calculateTotalWithDiscount(total);
    double discount = total - finalAmount;

    cout << "-----------------------------------------------------\n";
    cout << "Subtotal: $" << fixed << setprecision(2) << total << "\n";
    if (discount > 0) {
        cout << "Discount: -$" << fixed << setprecision(2) << discount << "\n";
    }
    cout << "Total Due: $" << fixed << setprecision(2) << finalAmount << "\n";
    cout << "Customer: " << customerName << "\n";
    cout << "Thank you for shopping with us!\n";

    return 0;
}
