#include "headers/compare.h"

int Comparer::Compare(std::string path, Config conf, std::string name){
    std::vector<std::string> file_buffer;
    std::ifstream saved(conf.path + name);
    if (saved.is_open()){
        while(!saved.eof()){
            std::string line;
            getline(saved, line);
            file_buffer.push_back(line);
        }
    }
    else{
        return -2;
    }
    saved.close();
    std::ifstream comparedFile(path);
    if (comparedFile.is_open()){
        for(int x = 0; !comparedFile.eof(); x++){
            std::string line;
            getline(comparedFile, line);
            if (x > file_buffer.size()){
                std::cout << "[+] " << line << '\n';
            }
            else if (line != file_buffer[x]){
                std::cout << "[-] " << file_buffer[x] << '\n';
                std::cout << "[+] " << line << '\n';
            }
        }
    }
    else{
        return -3;
    }
    comparedFile.close();
}