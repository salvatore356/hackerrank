//
//  SherlockAndSquares.hpp
//  HackerRank
//
//  Created by Salvatore on 2/4/24.
//

#ifndef SherlockAndSquares_hpp
#define SherlockAndSquares_hpp

#include <stdio.h>

namespace SherlockAndSquares {

    int squares(int a, int b) {
        int start = ceil(sqrt(a)), fin = floor(sqrt(b));
        return fin - start + 1;
    }


    int test() {
        std::ifstream input("Tests/Algorithms/Implementation/SherlockAndSquares/input08.txt");
        std::ifstream output("Tests/Algorithms/Implementation/SherlockAndSquares/output08.txt");

        if (!input.is_open()) {
            std::cerr << "Failed to open the file." << std::endl;
            return 1;
        }
        
        string q_temp;
        getline(input, q_temp);

        int q = stoi(ltrim(rtrim(q_temp)));

        for (int q_itr = 0; q_itr < q; q_itr++) {
            string first_multiple_input_temp;
            getline(input, first_multiple_input_temp);

            vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

            int a = stoi(first_multiple_input[0]);

            int b = stoi(first_multiple_input[1]);

            int result = squares(a, b);

            getline(output, q_temp);
            assert(result == stoi(q_temp), to_string(result) + " == " + q_temp);

        }

        

        return 0;
    }
}

#endif /* SherlockAndSquares_hpp */
