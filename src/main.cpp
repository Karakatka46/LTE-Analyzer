#include <iostream>
#include "readerIQ.hpp"
#include "fft.hpp"

int main(){
    IQ_data data = readfile("../lte_band3.iq", 15.36e6);
    info("Мощность сигнала", powerCalc(data));

    fft_process(data);

    return 0;
}