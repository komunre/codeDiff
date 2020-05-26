#include "headers/config.h"

int Config::LoadConf(){
    struct passwd *pw = getpwuid(getuid());

    path = std::string(pw->pw_dir) + "/codeDiff/";
}