#include <iostream>

int main(int argc, char ** argv){

    if(argc<2){
        std::cout << "Es wurde keine Zahl uebergeben!" << std::endl;
        return 0;
    }

    int input = std::strtol(argv[1], nullptr, 10) + 1;
    std::cout << (input-1) << " + 1 = " << input << std::endl;
}