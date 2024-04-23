//
//  ChocolateFeast.hpp
//  HackerRank
//
//  Created by Salvatore on 23/4/24.
//

#ifndef ChocolateFeast_hpp
#define ChocolateFeast_hpp

#include <stdio.h>

namespace ChocolateFeast {

    int chocolateFeast(int n, int c, int m) {
        int bars = floor(n / c);
        int wrappers = bars;
        
        while(wrappers >= m){
            int newBars = floor(wrappers / m);
            wrappers = wrappers - (newBars * m) + newBars;
            bars += newBars;
        }
        return bars;
    }

    void test() {
        string path = "Tests/Algorithms/Implementation/ChocolateFeast/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        string t_temp;
        getline(input, t_temp);

        int t = stoi(ltrim(rtrim(t_temp)));

        for (int t_itr = 0; t_itr < t; t_itr++) {
            string first_multiple_input_temp;
            getline(input, first_multiple_input_temp);

            vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

            int n = stoi(first_multiple_input[0]);

            int c = stoi(first_multiple_input[1]);

            int m = stoi(first_multiple_input[2]);

            int result = chocolateFeast(n, c, m);

            string out1;
            getline(output, out1);
            
            assert(result == stoi(out1), to_string(result) + " == " + out1);
        }

    }
}

#endif /* ChocolateFeast_hpp */
