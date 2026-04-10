#include "fft.hpp"

std::vector<comfl32> fft_process(IQ_data& data){
    std::vector<comfl32> out(fft_size);
    out[0] = comfl32(0,0);

    for(int k = 0; k < fft_size/2; ++k){
            float angle = -2.0f * M_PI * k * k / fft_size;
            comfl32 W(cos(angle), sin(angle));
            if(k % 2 == 0)
                out[k] = out[k] + data.samples[k] * W;
            else
                out[k + fft_size/2] = out[k] - data.samples[k] * W;
    }

    return out;
}
// comfl32 fft_process(IQ_data& data){
//     comfl32 result;

//     for(auto i = 0; i < data.NUM_samples / 2 - 1; ++i){
//         double theta = 2* M_PI / fft_size;
//         double real_path = cos(theta);
//         double imag_path = -sin(theta);
//         comfl32 Wn(real_path, imag_path);
        
//         if(i % 2 == 0){
//             result += pow(Wn, i*i) * data.samples[2*i];
//         }

//         else if(i % 2 != 0){
//             result += pow(Wn, i* i) * data.samples[2*i + 1];
//         }
//     }

//     return result;
// }