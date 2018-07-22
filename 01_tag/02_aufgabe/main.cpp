#include <iostream>

bool ist_prim(unsigned int n){
    if(n==1) return false;
    for(int i = 2; i*i<=n; i++){
        if(ist_prim(i)){
            if(n%i==0) return false;
        }
    }
    return true;
}

int main(int argc, char ** argv){

    if(argc<2){
        std::cout << "Uebergebe einen Argument!" << std::endl;
        return 0;
    }
    int i = std::strtol(argv[1], nullptr, 10);
    if(i < 1){
        std::cout << "Bitte nur naturliche Zahlen."<<std::endl;
        return 0;
    }
    std::cout << i << " ist " << ((!ist_prim(i))?"k":"") << "eine Primzahl."<< std::endl;

}

