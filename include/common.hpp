#include <iostream>
#include <complex>
#include <cmath>

using comfl32 = std::complex<float>;
using comfl64 = std::complex<double>;

template<typename... Args>
inline void info(const char* msg, Args&&... args){
    std::cout << "[INFO] " << msg << '\n';   
    ((std::cout << " " << args), ...);
    std::cout << '\n';
}

inline void warning(const char* msg){
    std::cout << "[WARNING] " << msg << '\n';
}
