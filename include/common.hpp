#include <iostream>
#include <complex>

using comfl32 = std::complex<float>;
using comfl64 = std::complex<double>;

inline void info(const char* msg){
    std::cout << "[INFO] " << msg << '\n';   
}

inline void warning(const char* msg){
    std::cout << "[WARNING] " << msg << '\n';
}