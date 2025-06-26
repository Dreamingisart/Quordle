#include <iostream>
#include <string>
#include <algorithm>
#define RESET   "\033[0m"
#define GREEN   "\033[42m\033[30m"  // Green background, black text
#define YELLOW  "\033[43m\033[30m"  // Yellow background, black text
#define GRAY    "\033[47m\033[30m"  // Light gray background, black text

using namespace std;

int main() {
    string box1 = "BEGIN";
    string box2 = "BOXER";
    string box3 = "FLUID";
    string box4 = "FOUND";

    string userInputLower;  // user input
    string mode;            // game mode
    int tries;              // number of attempts

    bool solved1 = false, solved2 = false, solved3 = false, solved4 = false;

    cout << "Welcome to Quordle" << endl;

    cout << "Choose mode\n" 
         << "1. Classic (Number of tries = 9)\n"
         << "2. Chill (Number of tries = 12)\n"
         << "3. Extreme (Number of tries = 8)" << endl;

    cin >> mode;

    if (mode == "Classic" || mode == "classic") {
        tries = 9;
    } else if (mode == "Chill" || mode == "chill") {
        tries = 12;
    } else if (mode == "Extreme" || mode == "extreme") {
        tries = 8;
    } else {
        cout << "Invalid mode. Defaulting to Classic.\n";
        tries = 9;
    }

    while (tries > 0) {
        cout << "\nEnter a 5-letter word: ";
        cin >> userInputLower;
        string userInputUpper;

        // Convert to uppercase
        for (auto x : userInputLower) {
            userInputUpper += toupper(x);
        }

        // BOX 1
        if (!solved1) {
            if (userInputUpper == box1) {
                
                solved1 = true;
            } else {
                for (int i = 0; i < 5; i++) {
                    char Letter1 = userInputUpper[i];
                    if (box1.find(Letter1) != string::npos) {
                        if (box1[i] == Letter1) {
                            cout << GREEN << " " << Letter1 << " " << RESET;
                        } else {
                            cout << YELLOW << " " << Letter1 << " " << RESET;
                        }
                    } else {
                        cout << GRAY << " " << Letter1 << " " << RESET;
                    }
                }
                cout << endl;
            }
        } else {
            cout << "Box 1 already solved!\n";
        }

        // BOX 2
        if (!solved2) {
            if (userInputUpper == box2) {
                solved2 = true;
            } else {
                for (int i = 0; i < 5; i++) {
                    char Letter2 = userInputUpper[i];
                    if (box2.find(Letter2) != string::npos) {
                        if (box2[i] == Letter2) {
                            cout << GREEN << " " << Letter2 << " " << RESET;
                        } else {
                            cout << YELLOW << " " << Letter2 << " " << RESET;
                        }
                    } else {
                        cout << GRAY << " " << Letter2 << " " << RESET;
                    }
                }
                cout << endl;
            }
        } else {
            cout << "Box 2 already solved!\n";
        }

        // BOX 3
        if (!solved3) {
            if (userInputUpper == box3) {
                solved3 = true;
            } else {
                for (int i = 0; i < 5; i++) {
                    char Letter3 = userInputUpper[i];
                    if (box3.find(Letter3) != string::npos) {
                        if (box3[i] == Letter3) {
                            cout << GREEN << " " << Letter3 << " " << RESET;
                        } else {
                            cout << YELLOW << " " << Letter3 << " " << RESET;
                        }
                    } else {
                        cout << GRAY << " " << Letter3 << " " << RESET;
                    }
                }
                cout << endl;
            }

        } else {
            cout << "Box 3 already solved!\n";
        }

        // BOX 4
        if (!solved4) {
            if (userInputUpper == box4) {
                solved4 = true;
            } else {
                for (int i = 0; i < 5; i++) {
                    char Letter4 = userInputUpper[i];
                    if (box4.find(Letter4) != string::npos) {
                        if (box4[i] == Letter4) {
                            cout << GREEN << " " << Letter4 << " " << RESET;
                        } else {
                            cout << YELLOW << " " << Letter4 << " " << RESET;
                        }
                    } else {
                        cout << GRAY << " " << Letter4 << " " << RESET;
                    }
                }
                cout << endl;
            }
        } else {
            cout << "Box 4 already solved!\n";
        }

        tries--;

        // Check for win
        if (solved1 && solved2 && solved3 && solved4) {
            cout << "\nYou guessed all 4 words correctly!\n";
            break;
        }

        cout << "Tries left: " << tries << "\n";

        if (tries == 0) {
            cout << "\nGame Over! The correct words were:\n";
            cout << "Box 1: " << box1 << "\n";
            cout << "Box 2: " << box2 << "\n";
            cout << "Box 3: " << box3 << "\n";
            cout << "Box 4: " << box4 << "\n";
        }
    }

    cout << "\033[0m\033[49m\033[39m" << endl;
    return 0;
}
