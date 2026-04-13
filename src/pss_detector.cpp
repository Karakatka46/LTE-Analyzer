#include "pss_detector.hpp"

void pss_detection(std::vector<comfl32> data, std::vector<std::vector<comfl32>>& etalonPSS){
    // N_ID0 = 25, N_ID1 = 29, N_ID2 = 34
    
    float theta = 0;
    int len = etalonPSS.size();

    std::vector<comfl32> ZC_seqs[3]{std::vector<comfl32>(len, {0,0})};

    int N = len / 2;
    int lenSEQ = 62;

    int u[3] {25,29,34};

    for(int i = 0; i < 3; ++i){
        for(int n = 0; n < lenSEQ; ++n){

            if(n <= 30){
                theta = -M_PI * u[i] * n*(n + 1)/63.0f;
            }
            else if (n >= 31)    
                theta = -M_PI * u[i] * (n + 1)*(n + 2)/63.0f;
            
            comfl32 value (cos(theta), sin(theta));

            if(n <= 30){
                ZC_seqs[i][len - 31 + n] = value;
            }    
            else if(n >= 31){
                ZC_seqs[i][n - 30] = value;
            }    

        }
    }

}