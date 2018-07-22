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

void primzerlegung(unsigned int n){
    if(n <= 1){
        std::cout << n << std::endl;
    }else{
        bool mal_zeichen = false;
        for(unsigned int i = 2; n>=i; ){
            if(ist_prim(i) && (n%i==0)){
                if(mal_zeichen) std::cout << " * ";
                std::cout << i;
                n/=i;
                mal_zeichen=true;
            }else{
                i++;
            }
        }
    }
    std::cout << std::endl;
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
    std::cout << i << " = ";
    primzerlegung(i);

}