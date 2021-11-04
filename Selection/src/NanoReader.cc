#include "../interface/NanoReader.hh"
#include <string>
void printpdgID(int num)
{
    if(num == 1) std::cout<< "d";
    else if(num == 2) std::cout<< "u";
    else if(num == 3) std::cout<< "s";
    else if(num == 4) std::cout<< "c";
    else if(num == 5) std::cout<< "b";
    else if(num == 6) std::cout<< "t";
    else if(num == 7) std::cout<< "b'";
    else if(num == 8) std::cout<< "t'";
    else if(num == -1) std::cout<< "anti-d";
    else if(num == -2) std::cout<< "anti-u";
    else if(num == -3) std::cout<< "anti-s";
    else if(num == -4) std::cout<< "anti-c";
    else if(num == -5) std::cout<< "anti-b";
    else if(num == -6) std::cout<< "anti-t";
    else if(num == -7) std::cout<< "anti-b'";
    else if(num == -8) std::cout<< "anti-t'";
    else if(num == 9) std::cout<< "9";
    else if(num == 10) std::cout<< "10";
    else if(num == 11) std::cout<< "e-";
    else if(num == -11) std::cout<< "e+";
    else if(num == 13) std::cout<< "mu-";
    else if(num == -13) std::cout<< "mu+";
    else if(num == 12) std::cout<< "Ve";
    else if(num == 14) std::cout<< "Vmu";
    else if(num == 16) std::cout<< "Vtau";
    else if(num == -12) std::cout<< "anti-Ve";
    else if(num == -14) std::cout<< "anti-Vmu";
    else if(num == -16) std::cout<< "anti-Vtau";
    else if(num == 15) std::cout<< "tau-";
    else if(num == -15) std::cout<< "tau+";
    else if(num == 17) std::cout<< "tau-'";
    else if(num == -17) std::cout<< "tau+'";
    else if(num == 18) std::cout<< "Vtau'";
    else if(num == 21) std::cout<< "g";
    else if(num == 22) std::cout<< "gamma";
    else if(num == 23) std::cout<< "Z0";
    else if(num == 24) std::cout<< "W+";
    else if(num == -24) std::cout<< "W-";
    else if(num == 25) std::cout<< "H01";
    else if(num == 35) std::cout<< "H02";
    else if(num == 211) std::cout<< "Pion+";
    else if(num == -211) std::cout<< "Pion-";
    else if(num == 111) std::cout<< "Pion0";
    else if(num == 411) std::cout<< "D+";
    else if(num == 411) std::cout<< "D+";
    else std::cout <<num;
}
