//
//  SpecialPythagoreanTriplet.hpp
//  HackerRank
//
//  Created by Salvatore on 16/5/24.
//

#ifndef SpecialPythagoreanTriplet_hpp
#define SpecialPythagoreanTriplet_hpp

#include <stdio.h>

namespace SpecialPythagoreanTriplet {

    int specialPythagoreanTriplet(int n) {
            
        int m = -1;
        for (int a = 1; a <= (n/3); a++) {
            int b = (n*(n - 2*a))/(2*(n - a));
            int c = n - a - b;
            if ((a * a + b * b == c * c) && (a * b * c > m))
                m = a * b * c;
        }
        return m;
    }

    void test() {
        string path = "Tests/ProjectEuler+/SpecialPythagoreanTriplet/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");
        
        string t_temp, t_out;
        getline(input, t_temp);

        int t = stoi(ltrim(rtrim(t_temp)));

        for (int t_itr = 0; t_itr < t; t_itr++) {
            string n_temp;
            getline(input, n_temp);

            int n = stoi(ltrim(rtrim(n_temp)));
            int result = specialPythagoreanTriplet(n);
            
            getline(output, t_out);
            assert(result == stol(t_out), to_string(result) + " == " + t_out);
        }
    }
}

#endif /* SpecialPythagoreanTriplet_hpp */
