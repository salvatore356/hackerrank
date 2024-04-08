//
//  SaveThePrisioner.hpp
//  HackerRank
//
//  Created by Salvatore on 30/3/24.
//

#ifndef SaveThePrisioner_hpp
#define SaveThePrisioner_hpp

#include <stdio.h>

namespace SaveThePrisioner {
    int saveThePrisoner(int n, int m, int s) {

        if(n == m) {
            int ans = s - 1;
            return ans == 0 ? m : ans;
        }
        int temp = (m % n) + s - 1;
        
        if(temp == 0) temp = n;
        if(temp > n) temp = temp - n;
        
        return temp;
    }

int test() {
    
    std::ifstream input("Tests/Algorithms/Implementation/SaveThePrisioner/input05.txt");
    std::ifstream output("Tests/Algorithms/Implementation/SaveThePrisioner/output05.txt");
    
    if (!input.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }
    
    string t_temp;
    getline(input, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(input, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int s = stoi(first_multiple_input[2]);

        int result = saveThePrisoner(n, m, s);

        getline(output, t_temp);
        assert(result == stoi(t_temp), to_string(result) + " == " + t_temp);
    }

    

    return 0;
}
}

#endif /* SaveThePrisioner_hpp */
