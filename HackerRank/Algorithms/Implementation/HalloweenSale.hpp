//
//  HalloweenSale.hpp
//  HackerRank
//
//  Created by Salvatore on 22/4/24.
//

#ifndef HalloweenSale_hpp
#define HalloweenSale_hpp

#include <stdio.h>

namespace HalloweenSale {

    int howManyGames(int p, int d, int m, int s) {
        // Return the number of games you can buy
        
        int games = 0;
        while(s >= p){
            s -= p;
            ++games;
            p -= d;
            p = max(m, p);
        }
        return games;
    }

    void test() {
        string path = "Tests/Algorithms/Implementation/HalloweenSale/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        string first_multiple_input_temp;
        getline(input, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int p = stoi(first_multiple_input[0]);

        int d = stoi(first_multiple_input[1]);

        int m = stoi(first_multiple_input[2]);

        int s = stoi(first_multiple_input[3]);

        int result = howManyGames(p, d, m, s);

        string out1;
        getline(output, out1);
        
        assert(result == stoi(out1), to_string(result) + " == " + out1);

    }

}

#endif /* HalloweenSale_hpp */
