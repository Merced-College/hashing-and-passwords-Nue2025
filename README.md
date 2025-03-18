[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=18748427)
For this lab we will:

* Read a password file (e.g., rockyou.txt) containing common passwords.
* Hash each password using the provided hash function.
* Store the hashed passwords in a hash table (unordered_map).
* Handle hash collisions properly by storing multiple passwords under the same hash.
* Simulate a hacker scenario: Given a hashed password, search the hash table and retrieve possible matches.
  
Part 1: Understanding Hash Functions & Collisions

A hash function converts a password into a numerical value. However, hash collisions occur when different passwords generate the same hash. We need to handle this by storing multiple passwords per hash value.

We will use the hash function given to us in our zybook.

📌 Part 2: Starter Code with Collision Handling

The C++ starter code will:

Reads passwords from a file (rockyou.txt).
Hashes each password and stores it in a hash table with collision handling.
Allows the user to input a hashed value and retrieves all possible passwords.
🛠 Part 3: Challenge Steps
Step 1: Load and Hash Passwords
Read a large list of common passwords from rockyou.txt.
Hash each password and store it in a hash table with collision handling.
Step 2: Test Hashing
Print the first 10 passwords and their hashes to verify the function.
Modify the hash function slightly and observe how it affects collision rates.
Step 3: Reverse Lookup & Handle Collisions
Ask the user to enter a hashed password value.
Search the hash table and display all possible original passwords.
Step 4: Understand Hash Collisions
Modify the program to count how often collisions occur.
Implement a better hash function to reduce collisions. It should change the hash function in some way to reduce the collisions.
🔎 Discussion Questions, Answer at least two of the following discussion questions:
Why do we hash passwords instead of storing them in plain text?
How do collisions affect the accuracy of our password lookup?
Why do different passwords sometimes produce the same hash?
How can we improve our hash function to reduce collisions?
What hashing algorithms do real systems use to prevent easy password cracking?
What is a rainbow table, and how does it make cracking passwords easier?
How do real-world password security systems handle collisions?

Turn in your code to the github classroom and the discussion questions to this assignment in canvas.
