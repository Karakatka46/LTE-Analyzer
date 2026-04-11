#include <iostream>
#include "readerIQ.hpp"
#include "fft.hpp"

int main(){
    IQ_data data = readfile("../lte_band3.iq", 15.36e6);
    info("Мощность сигнала", powerCalc(data));
    
    int N = fft_size;
    std::vector<comfl32> buffer(N);
    int cp = 72;
    int sym_len = N + cp;
    int n_symb = data.NUM_samples / sym_len;

    for(int sym = 0; sym <= n_symb - N; ++sym){
        int start = sym * sym_len + cp;

        for(int n = 0; n < N; n++){
            buffer[n] = data.samples[start + n];
        }
        
        fft_forward(buffer);
        
    }    

    return 0;
}