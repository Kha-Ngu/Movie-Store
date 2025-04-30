# Self-Evaluation

## Name(s): Khanh Nguyen

Out of 25 points. Use output.txt created using 
`./create-output.sh > output.txt 2>&1` for guidance.

Complete all questions with "Q:"

Q: Does the program compile and run to completion: Yes

- If the program does not compile or gives a segmentation error when run, 
the maximum possible grade is 50%. No need to continue with the rest of self-evaluation

Q: All public functions have been implemented: 0

- -2 for each functionality not implemented

For each command, state Full, Partial or None to indicate 
if it has been fully, partially or not implemented at all.
Explain any partial implementations.

Inventory: fully
History: fully
Borrow: fully
Return: fullt


Q: -1 for each compilation warning, min -3: 0

- Check under *1. Compiles without warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-tidy warning, min -3: 0

- Check under *3. clang-tidy warnings*
- If the warning message is addressed in README.md, including how the programmer tried to address it, no deductions

Q: -1 for each clang-format warning, min -3: 0

- Check under *4. clang-format does not find any formatting issues*


Q: -2 for any detected memory leak: 0

- Check under *5. No memory leaks using g++*
- Check under *6. No memory leaks using valgrind*

Q: Do the tests sufficiently test the code: 0

- -1 for each large block of code not executed
- -2 for each function that is never called when testing
- Check under *7. Tests have full code coverage* paying attention to *The lines below were never executed*

Q: Are all functions in .h and .cpp file documents (min -3): 0

- -1 for each function not documented

## Location of error message or functionality

State the file and function where the information can be found

Invalid command code: commandFactory.cpp, line 21

Invalid movie type: movieFactory.cpp, line 22

Invalid customer ID: customerDb.cpp, line 25
 
Invalid movie: movieStore.cpp, line 24

Factory classes: movieFactory.h, movieFactory.cpp, commandFactory.h, commandFactory.cpp

Hashtable: hashTable.h, used in customerDb.cpp to track customers by ID.

Container used for comedy movies: movieStore.h, line 11: unordered_map<std::string, Movie *> inventory;

Function for sorting comedy movies: 
- movieStore.cpp, line 75: std::sort(movies.begin(), movies.end(), [](Movie *a, Movie *b) {});

Function where comedy movies are sorted: 
- movieStore.cpp, line 75: std::sort(movies.begin(), movies.end(), [](Movie *a, Movie *b) {});

Functions called when retrieving a comedy movie based on title and year: 
- movieStore.cpp, line 36: MovieStore::findMovie(const std::string &key) 
- comedy.cpp, line 17: Comedy::getKey()

Functions called for retrieving and printing customer history: 
- customer.h, line 39: Customer::displayHistory() (to print the history)
- customerDb.cpp, line 20: CustomerDB::getCustomer(int id) (to retrieve the customer)
- historyCommand.cpp, line 10: HistoryCommand::execute() (to process and display history)

Container used for customer history:
- customer.h, line 14: std::vector<std::string> history; 

Functions called when borrowing a movie: 
- BorrowCommand::execute() (Handles the borrowing process)
- CustomerDB::getCustomer(int id) (Finds the customer)
- MovieStore::findMovie(const std::string &key) (Finds the movie)
- Movie::borrowMovie() (Reduces stock if available)
- Customer::addTransaction(std::string transaction) (Records transaction in history)

Explain borrowing a movie that does not exist: 
- The system looks for the movie in the inventory using findMovie().
- If the movie is not found, it returns nullptr.
- An error message is printed via std::cerr: Movie not found: <movie_key>

Explain borrowing a movie that has 0 stock: 
- The system checks the movie's stock before allowing the borrow. 
- If movie->getStock() == 0, the borrow fails.
- An error message is printed via std::cerr: ERROR: <customer_name> could NOT borrow <movie_title>, out of stock.

explain returning a movie that customer has not checked out: 
- The system checks the customer's transaction history to verify if they have borrowed the movie.
- If the movie is not in the history, the return fails.
- An error message is printed via std::cerr: ERROR: Customer <name> cannot return <movie_title> because they never borrowed it.

any static_cast or dynamic_cast used: None.

## Bonus +5

Are there multiple files, of the form runit-without-XXX, where the same set of files will compile and run excluding some of the commands or genres? 
- runit-without-borrow.sh, runit-without-drama.sh, runit-without-return.sh

Q: Total points: 30