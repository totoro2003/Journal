#ifndef CHOICE_H
#define CHOICE_H

class choice {
    public:
        choice(std::string choice1_file, std::string choice2_file);
        std::tuple<std::string, char> which_option(std::string message);
    private:
        std::string choice1_file, choice2_file;
};

#endif // CHOICE_H
