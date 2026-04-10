#pragma once

#include <iostream>
#include <complex>
#include <cmath>
#include <vector>

#define CARRIER = 15000;
const int fft_size = 1024;

using comfl32 = std::complex<float>;
using comfl64 = std::complex<double>;

struct IQ_data {
    std::vector<comfl32> samples;
    size_t NUM_samples = 0;
    float duration = 0;
};

template<typename... Args>
inline void info(const char* msg, Args&&... args){
    std::cout << "[INFO] " << msg;   
    ((std::cout << " " << args), ...);
    std::cout << '\n';
}

inline void warning(const char* msg){
    std::cout << "[WARNING] " << msg << '\n';
}
