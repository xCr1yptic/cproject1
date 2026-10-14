#include <iostream> //Library being imported into C
#include <cmath> //Mathamatical functions that are available within this library
#include <fstream> // Read and write from external files
#include <string> // Calls for the string function

using namespace std;

int main() {
    // Variable Init
    char userInput {};
    string username;
    string password;

    // Method Init
    void viewGrades(string name);
    bool verification(string user, string pass);

    cout << "Welcome to the Student Grade Point Average Calculator!" << endl; 

    while (userInput != 'Q') {

        cout << "Please select one of the follow menu options:\n(A) View Grades * Verification Required \n(B) Enter Grades\n(C) What If Grades \n(D) Calculate Grades\n(E) Report Card Generator\n(Q) Quit" << endl;
        cin >> userInput;
        userInput = toupper(static_cast<unsigned char>(userInput));

        if (userInput == 'A') {
            cout << "Please enter your username followed by your password: ";
            cin >> username >> password;

            if (verification(username, password)) { // Verifies user before allowing access to view grades
                viewGrades(username);
                break;
            }
            else {
                cout << "Invalid username or password." << endl; 
            }
        }

        else if(userInput == 'B') {

        }

        else if(userInput == 'C') {

        }

        else if(userInput == 'D') {

        }
        else if(userInput == 'E') {

        }
        else if(userInput == 'Q'){
            cout << "Thank you!";
            break;

        }
        else {
            cout << "Not a valid input";

        }

    }
    


    
}

bool verification (string user, string pass) { 
    ifstream file("users.txt");

    if(!file.is_open()) {
        cout << "Could not open verification file" << endl;
        return false;
    }
    
    string fileUser, filePass; 
    while(file >> fileUser >> filePass) { //Reads a username and password against input
        if(fileUser == user && filePass == pass) {
            return true; // Match was found!
        }
    }
    return false; // Reaches the end of the file with no match
}

void viewGrades(string name) { 
   string path = "grades/" + name + ".txt";
    ifstream file(path);

   if(!file.is_open ()) {
    cout << "Could not open view grades file" << endl; 
   }

   cout << file.rdbuf();
   file.close();


}



