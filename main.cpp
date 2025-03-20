/* Nue Lopez
 * CPSC-25
 * March 25, 2025
 * Assignment: Password Hashing & Cracking with a Hash Table
*/

#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// Hash function from ZyBooks
int HashString(const string& value) {
   int hashCode = 0; //Nue's Note: start at zero because we want to add to it.
   for (int character : value) {
      hashCode += character; //Nue's Note: for "password", it will be 112 + 97 + 2(115) + 119 + 111 + 114 + 100 = 883
   }
   return (int)(hashCode & 0x7fffffff); //Ensure positive value /* Nue's Note: Remember that the f's are just 1's. So convert 883 to binary, which is 0b1101110011*/
}


int main() {
    unordered_map<int, vector<string>> passwordTable; // Handles collisions using a vector
    ifstream passwordFile("10-million-password-list-top-10000.txt"); // Replace with the actual password file

    if (!passwordFile) {
        cerr << "Error: Password file not found!" << endl;
        return 1;
    }

    string password;

    int collisionCount = 0; // Counting number of collisions

    cout << "Reading passwords and hashing...\n";
    while (getline(passwordFile, password)) {
        int hashValue = HashString(password);
        int originalHash = hashValue; // Store the original hash value
        int tableSize = 10000; // Define the size of the hash table
        int c1 = 1, c2 = 1; // Quadratic probing coefficients
        int i = 0;

        while (true) {
            int newIndex = (originalHash + c1 * i + c2 * i * i) % tableSize;
            // Check if the slot is empty
            if (passwordTable[newIndex].empty()) {
                passwordTable[newIndex].push_back(password); // Insert the password
                if (i > 0) {
                    collisionCount++; 
                    cout << "Collision resolved for password: " << password << " after " << i << " probes." << endl;
                }
                break; 
            }
            i++; 
        }
    }
    cout << "Total collisions during hashing: " << collisionCount << endl;
    passwordFile.close();
    

    cout << "Hashing complete. Enter a hashed password to find the original: ";
    
    int userHash;
    while (true) {
        cout << "\nEnter hashed value (or -1 to exit): ";
        cin >> userHash;

        if (userHash == -1) break;

        if (passwordTable.find(userHash) != passwordTable.end()) {
            cout << "Possible original passwords:\n";
            for (const string& pass : passwordTable[userHash]) {
                cout << " - " << pass << endl;
            }
        } else {
            cout << "Password not found in database." << endl;
        }
    }

    cout << "Goodbye!" << endl;
    return 0;
}