//
//  SmartNumber.hpp
//  HackerRank
//
//  Created by Salvatore on 5/6/24.
//

#ifndef SmartNumber_hpp
#define SmartNumber_hpp

#include <stdio.h>

namespace SmartNumber {

    bool is_smart_number(int num) {
        int val = (int) sqrt(num);
        if(val * val == num)
            return true;
        return false;
    }

    void test() {
        string test_case = "00";
        string path = "Tests/Algorithms/Debugging/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");

        string t_out;
        int test_cases;
        input >> test_cases;
        int num;
        for(int i = 0; i < test_cases; i++) {
            input >> num;
            bool ans = is_smart_number(num);
            string result = ans ? "YES" : "NO";
            getline(output, t_out);
            assert(result == t_out, result + " == " + t_out);
        }
    }
}

#endif /* SmartNumber_hpp */
