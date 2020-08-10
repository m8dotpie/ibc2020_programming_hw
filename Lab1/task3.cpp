
#include <iostream>
#include <string>

int TRIES_ALLOWED = 3;
std::string LOGIN = "login";
std::string PASSWORD = "password";

int main() {
    
    bool logged_in = false;

    // While tries left and user did not provide right credentials.
    while (TRIES_ALLOWED-- && !logged_in) {
        std::string input_login;
        std::string input_password;
        
        std::cin >> input_login >> input_password;

        // Check if credentials are correct and mark as logged if yes.
        if (input_login == LOGIN && input_password == PASSWORD) {
            logged_in = true;
        } else {
            std::cout << "Access has restricted.\n";
        }
    }

    // If logged in, then grant access, exit otherwise
    if (logged_in) {
        std::cout << "Access has granted.\n";
    } else {
        std::cout << "No more tries.\n";
    }
}
