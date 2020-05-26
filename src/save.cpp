#include "headers/save.h"

int Saver::Save(std::string path, Config conf, std::string name){
    std::vector<std::string> file_buffer;
    std::ifstream origin(path);
    if (origin.is_open()){
        while(!origin.eof()){
            std::string line;
            getline(origin, line);
            file_buffer.push_back(line);
        }
    }
    else{
        return -2;
    }
    origin.close();
    std::ofstream code(conf.path + name);
    if (code.is_open()){
        for(int x = 0; x != file_buffer.size(); x++){
            code << file_buffer[x] << std::endl;
        }
    }
    else{
        return -3;
    }
    code.close();
    return 1;
}