#include <iostream>
#include <chrono>
#include <thread>
#include "text_management.h"
#include "choice.h"

void print_text(std::string &text, int time_to_wait = 50, int pause = 1000) {

    for (auto let : text) {
        std::this_thread::sleep_for(std::chrono::milliseconds(let == '@' ? pause : time_to_wait));
        if (let != '@') std::cout << let << std::flush;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(pause));
}
inline void set_new_text(text_management &management, std::string &text) {
    text = management.get_text_from_file();
}
std::string get_new_directory(std::string current_directory, char choice_number) {
    return current_directory + choice_number + '/';
}
std::tuple<std::string, char> choose(std::string &text, text_management &management, std::string file1, std::string file2, std::string choice_message = "(Type 1 or 2)") {
    std::tuple<std::string, char> player_choice;
    choice* choice_to_make = new choice(file1, file2);
    player_choice = choice_to_make->which_option(choice_message);
    management.set_new_file(std::get<0>(player_choice));
    set_new_text(management, text);
    print_text(text);
    return player_choice;
}
int main() {

    int paths = 3;
    std::string current_directory = "scripts/";
    std::string text;
    int choice_number;
    text_management management(std::string(current_directory + "script.txt"));

    for (; paths > 0; paths--) {
        set_new_text(management, text);

        print_text(text);

        choice_number = std::get<1>(choose(text, management, current_directory + "1.txt", current_directory + "2.txt"));

        current_directory = get_new_directory(current_directory, choice_number);

        management.set_new_file(current_directory + "script.txt");

    }
    set_new_text(management, text);
    print_text(text);
    std::cout << "End";
    std::cin.get();
}

