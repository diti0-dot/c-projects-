#include <limits>
#include <iostream>
#include <cstdlib>  
#include <ctime>    


using namespace std; 

int main() {
    cout << "WELCOME TO THE NUM HANGMAN GAME" << endl;

    srand(time(0));  // Seed the random number generator
    int randomNum = rand() % 101;  
    int guess; 
    int count = 0;  

    bool odd = false;
    bool even = false;

    if (randomNum % 2 == 0) {
        even = true;
    } else { 
        odd = true;
    }

    do {
        cout << "Input Guess:  \n";

        if(!(cin>>guess)){
            cout<<"invalid input!!  \n" ;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        } 

        count++;  // Increment count before checking for hints

        if (count == 4) {
            if (even) {
                cout << "It's even!" << endl;
            } else {
                cout << "It's odd!" << endl;
            }
        }

        if (guess == randomNum) {
            cout << "Yay! You guessed it!" << endl;
            break;  // Exit loop if guessed correctly
        }

        int diff = abs(guess - randomNum);

        if (diff < 20) {
            cout << "omg! super close" << endl;
        } else if (diff < 40) {
            cout << "ummm kinda close" << endl;
        } else if (diff < 60) {
            cout << "far bro" << endl;
        } else if (diff < 80) {
            cout << "oh no so farrrrrrr" << endl;
        } else {
            cout << "Beep Beep... You input a non-number. What, you egg!" << endl;
        }

    } while (true);  // Infinite loop until `break;`

    return 0;
}
