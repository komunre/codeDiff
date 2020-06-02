#include "headers/save.h"
#include "headers/compare.h"

void help(){
    printf("save <file> <name_in_codeDiff_dir> - save file in data\n");
    printf("compare <file> <name_in_codeDiff_dir> - compare files\n");
}
int main(int argc, char **argv){
    if (argc == 1){
        help();
        return 0;
    }
    Config conf;
    conf.LoadConf();
    Saver saver;
    Comparer comparer;
    if (std::string(argv[1]) == "save"){
        int err = saver.Save(argv[2], conf, argv[3]);
        if (err < 0){
            if (err == -2){
                printf("Error of reading origin file\n");
            }
            if (err == -3){
                printf("Error of opening save file\n");
            }
            return -1;
        }
    }
    else if (std::string(argv[1]) == "compare"){
        int err = comparer.Compare(argv[2], conf, argv[3]);
        if (err < 0){
            if (err == -2){
                printf("Error of reading saved file\n");
            }
            if (err == -3){
                printf("Error of reading comparing file\n");
            }
            return -1;
        }
    }
    else{
        printf("Enter codeDiff help to view help\n");
    }
    return 0;
}