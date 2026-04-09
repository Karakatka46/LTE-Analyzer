#pragma once

#include <fstream>
#include <iostream>
#include <complex>
#include <vector>
#include "common.hpp"


struct IQ_data {
    std::vector<comfl32> samples;
    size_t NUM_samples = 0;
    float duration = 0;
};

IQ_data readfile(std::string filename, float Fs);


inline float powerCalc(IQ_data data){
    float total_power = 0;
    
    for(const auto& i : data.samples){
        total_power += std::norm(i); // I^2 + Q^2
    }

    return 10.0f*log10((total_power)/data.NUM_samples);

}