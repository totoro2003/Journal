#ifndef TEXT_MANAGEMENT_H
#define TEXT_MANAGEMENT_H
#include <fstream>

class text_management {
    public:
        text_management(std::string file);
        ~text_management();
        std::string get_text_from_file();
        void set_new_file(std::string new_file);
    private:
        std::string* file;
        std::ifstream* read_stream = new std::ifstream(*file);
};

#endif // TEXT_MANAGEMENT_H
