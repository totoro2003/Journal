#include <iostream>
#include <tuple>
#include "choice.h"

choice::choice(std::string choice1_file, std::string choice2_file)
:choice1_file(choice1_file), choice2_file(choice2_file){}
std::tuple<std::string, char> choice::which_option(std::string message) {
    char choice;
    while (true) {
        std::cin >> choice;
        switch (choice) {
            case '1':
                //returns the filename and the which
                //choice was made
                return std::make_tuple(choice1_file, '1');
                break;
            case '2':
                return std::make_tuple(choice2_file, '2');
                break;
        }
        std::cout << message << '\n';
    }
}
