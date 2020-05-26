#pragma once
#include <iostream>
#include <stdio.h>
#include <vector>
#include "config.h"

class Comparer{
    public:
    int Compare(std::string path, Config conf, std::string name);
};