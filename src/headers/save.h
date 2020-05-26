#include <fstream>
#include <stdio.h>
#include <iostream>
#include <vector>
#include "config.h"

class Saver{
    public:
    int Save(std::string path, Config conf, std::string name);
    int SaveConf();
};