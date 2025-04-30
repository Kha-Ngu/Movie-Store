<h1>🎬 Movie Rental Inventory System</h1>

<p>This project is a fully object-oriented movie rental system implemented in C++, designed to manage inventory and customer transactions using <strong>polymorphism</strong> and the <strong>factory design pattern</strong>. It supports multiple movie genres (Comedy, Drama, Classics), and handles customer actions such as borrowing, returning, viewing inventory, and transaction history. The system is built to be extensible and maintainable, allowing new commands or movie types to be added without modifying existing logic.</p>

<hr>

<h2>🧠 Key Concepts</h2>
<ul>
  <li><strong>Polymorphism</strong>: Used to handle different movie genres and customer commands dynamically</li>
  <li><strong>Factory Pattern</strong>: Enables flexible and scalable object creation for movies and commands</li>
  <li><strong>Custom Hash Table</strong>: Implemented for efficient customer ID lookup</li>
  <li><strong>Object-Oriented Design</strong>: Over 10 modular classes used with clean separation of concerns</li>
</ul>

<hr>

<h2>📄 Features</h2>
<ul>
  <li>Parses input data from files for movies, customers, and commands</li>
  <li>Supports movie types: <code>F</code> (Comedy), <code>D</code> (Drama), <code>C</code> (Classics)</li>
  <li>Supports commands: <code>B</code> (Borrow), <code>R</code> (Return), <code>I</code> (Inventory), <code>H</code> (History)</li>
  <li>Handles invalid commands, customers, and movies with user-friendly error messages</li>
  <li>Inventory output is sorted by genre and genre-specific sorting rules</li>
  <li>Customer history is printed in chronological order</li>
</ul>

<hr>

<h2>📂 Project Structure</h2>
<pre><code>
├── main.cpp              # Entry point and command processing
├── movie.h / movie.cpp   # Abstract base class for movies
├── comedy.h / drama.h / classic.h  # Genre-specific movie subclasses
├── command.h / commandfactory.h    # Polymorphic command structure
├── hashtable.h           # Custom hash table for customer storage
├── customer.h / customer.cpp       # Customer class with history tracking
├── store.h / store.cpp   # Coordinates movie and customer operations
├── data4movies.txt       # Input file for inventory
├── data4customers.txt    # Input file for customers
├── data4commands.txt     # Input file for commands
</code></pre>

<hr>

<h2>📎 Sample Command Formats</h2>

<pre><code>
B 1234 D F Pirates of the Caribbean, 2003       # Borrow comedy
R 1234 D C 9 1938 Katherine Hepburn             # Return classic
H 1234                                          # View customer history
I                                              # View inventory
</code></pre>

<hr>

<h2>✅ Design Highlights</h2>
<ul>
  <li>Highly modular, extensible system with minimal if/else logic</li>
  <li>Self-registering design allows selective compilation of commands and genres</li>
  <li>Uses a factory and inheritance-based structure for scalability</li>
  <li>Follows best practices in class design and data encapsulation</li>
</ul>
