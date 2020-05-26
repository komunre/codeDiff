#pragma once

#include <iostream>
#include <fstream>
#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

class Config{
    public:
    int LoadConf();
    std::string path;
};