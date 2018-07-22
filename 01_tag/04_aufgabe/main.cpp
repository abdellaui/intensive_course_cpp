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
        bool got_a_faktor = false;
        unsigned last_potenz = 0;
        unsigned int i = 2;
        while(n>=i){
            if(ist_prim(i) && (n%i==0)){
                if(mal_zeichen){
                    std::cout << " * ";
                    mal_zeichen = false;
                    }
                if(last_potenz == 0 ) std::cout << i;
                n/=i;
                last_potenz++;
                got_a_faktor = true;
            }else{
                if(last_potenz>1) std::cout<<" ^ " << last_potenz;
                last_potenz = 0;
                if(got_a_faktor) mal_zeichen=true;
                i++;
            }
        }
        if(last_potenz>1) std::cout<<" ^ " << last_potenz;
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