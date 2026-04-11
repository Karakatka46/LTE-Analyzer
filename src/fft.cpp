#include "fft.hpp"

void bitReverse(std::vector<comfl32>& input){
    int n = input.size();
    int j = 0;

    for(int i = 0; i < n; ++i){
        if(i < j){
            std::swap(input[i], input[j]);
        //    std::cout << "j: " << j << '\n' << "i: " << i << '\n';
        }
        int m = n >> 1;
        while(m >= 1 && j >= m){
            j -= m;
            m >>= 1;
        }

        j += m;
    }
}

void fft_forward(std::vector<comfl32>& input){
    int n = input.size();
    bitReverse(input);
    
    for(int len = 2; len <= n; len <<= 1){
        float angle = -2.0f * M_PI / len;
        comfl32 wlen(cos(angle), sin(angle));
        
        for(int i = 0; i < n; i += len){
            comfl32 w(1,0); // e^(j0) = cos(0) + jsin(0) = 1 + j0 Поворачивающий коэффициент
            
            for(int j = 0; j < len/2; ++j){
                int upper = i + j;          // 0; 1;
                int lower = i + j + len/2;  // 1; 2;
                
                auto u = input[upper];      // (0,0)
                auto v = input[lower]*w;    // (4,2)*w

                input[upper] = u + v;       // (0,0) + (4,2)*w
                input[lower] = u - v;       // (0,0) - (4,2)*w

                w *= wlen;                  // w * wlen
            }
        }
    }

    // for(int i = 0; i < n; ++i){
    //     input[n] /= static_cast<float>(n);
    // }
}