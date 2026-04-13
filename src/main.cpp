#include <iostream>
#include "readerIQ.hpp"
#include "pss_detector.hpp"
#include "fft.hpp"

int main(){
    float Fs = 15.36e6;
    IQ_data data = readfile("../lte_band3.iq", Fs);
    info("Мощность сигнала", powerCalc(data));
    
    int N = fft_size; // 1024
    std::vector<comfl32> buffer(N);
    int cp = 72;
    int sym_len = N + cp;
    int n_symb = data.NUM_samples / sym_len;
    std::vector<comfl32> ZC_seqs[3]{std::vector<comfl32>(N, {0,0})};

    for(int sym = 0; sym <= n_symb - N; ++sym){
        int start = sym * sym_len + cp;

        for(int n = 0; n < N; n++){
            buffer[n] = data.samples[start + n];
        }
        
        fft_forward(buffer);
        
    }    

    return 0;
}