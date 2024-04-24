//
//  FairRations.hpp
//  HackerRank
//
//  Created by Salvatore on 24/4/24.
//

#ifndef FairRations_hpp
#define FairRations_hpp

#include <stdio.h>

namespace FairRations {

    string fairRations(vector<int> B) {
        
        int even = 0, loaf = 0;
        for(int i = 0; i < B.size() - 1; ++i){
            if(B[i] % 2 != 0){
                ++B[i + 1];
                loaf += 2;
            }
            ++even;
        }
        
        even += B.back() % 2 == 0;
        
        return even == B.size() ? to_string(loaf) : "NO";
    }

    void test() {
        string path = "Tests/Algorithms/Implementation/FairRations/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        string N_temp;
        getline(input, N_temp);

        int N = stoi(ltrim(rtrim(N_temp)));

        string B_temp_temp;
        getline(input, B_temp_temp);

        vector<string> B_temp = split(rtrim(B_temp_temp));

        vector<int> B(N);

        for (int i = 0; i < N; i++) {
            int B_item = stoi(B_temp[i]);

            B[i] = B_item;
        }

        string result = fairRations(B);

        string out;
        getline(output, out);
        assert(result == out, result + " == " + out);

    }
}

#endif /* FairRations_hpp */
