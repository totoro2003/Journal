#include <iostream>
#include <fstream>
#include "text_management.h"

text_management::text_management(std::string file)
:file(&file){}
text_management::~text_management() {
    delete read_stream;
}
std::string text_management::get_text_from_file() {
    std::string text;
    std::string line;
    while (std::getline(*read_stream, line)) {
        text += line + '\n';
    }
    return text;
}
void text_management::set_new_file(std::string new_file) {
    read_stream->close();
    read_stream->open(new_file);
}
