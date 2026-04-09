#include <iostream>
#include "readerIQ.hpp"

int main(){
    IQ_data data = readfile("../lte_band3.iq", 15.36e6);
    std::cout << data.NUM_samples << std::endl;

    info("Мощность сигнала", powerCalc(data));

    return 0;
}