#pragma once

#include <fstream>
#include <iostream>
#include <complex>
#include <vector>
#include "common.hpp"


struct IQ_data {
    std::vector<comfl32> samples;
    int NUM_samples = 0;
    float duration = 0;
};

IQ_data readfile(std::string filename, float Fs);