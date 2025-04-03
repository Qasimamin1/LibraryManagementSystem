# 📚 Library Management System (Console-based)

This is a simple console-based Library Management System written in C++. The system allows users to browse a list of available books, select books by their ID to purchase, apply discounts based on the total amount, and generate a final bill.

## 👨‍💻 About the Project

This project was built to practise basic C++ concepts including:
- Structures
- Vectors
- Functions
- I/O handling
- Looping and conditionals
- Basic billing logic

The idea is to simulate a small library/bookstore where a user can:
1. View available books.
2. Select multiple books by entering their IDs.
3. Get a final bill with discounts applied based on total cost.

## 🧾 Features

- Displays a list of 15 predefined books with IDs, titles, and prices.
- Users can add multiple books to their cart by typing in the Book IDs.
- The system supports continuous shopping (multi-round input).
- Applies tier-based discounts:
  - 5% for orders over $50
  - 10% for orders over $75
  - 14% for orders over $100
- Shows a clean bill summary with subtotal, discount, and final total.

## 🧠 Concepts Practised

- `struct` usage for storing book data.
- `vector<Book>` to manage book lists and shopping cart.
- Loops, conditions, and formatted output using `iomanip`.
- `getline()` and input validation using `cin.clear()` and `cin.ignore()`.

## 🖥️ How to Run

1. Open this project in any C++ IDE (like Visual Studio or Code::Blocks).
2. Compile and run the code.
3. Enter your name.
4. Select books by entering Book IDs (e.g., `101 102 105 -1` to stop).
5. Repeat the process if you want to add more books.
6. The system prints a final bill with a personalised thank-you message.

## 💡 Sample Discount Logic

| Total Amount | Discount Applied |
|--------------|------------------|
| > $100       | 14%              |
| > $75        | 10%              |
| > $50        | 5%               |
| ≤ $50        | No discount      |

## 📌 Example Output

