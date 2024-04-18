//
//  ModifiedKaprekarNumbers.hpp
//  HackerRank
//
//  Created by Salvatore on 18/4/24.
//

#ifndef ModifiedKaprekarNumbers_hpp
#define ModifiedKaprekarNumbers_hpp

#include <stdio.h>

namespace ModifiedKaprekarNumbers {

    string kaprekarNumbers(int p, int q) {
        
        string ans;
        
        for(long i = p; i <= q; ++i){
            
            long p2 = i * i;
            
            string n = to_string(p2);
            
            long middle = max(1, (int)(n.size() / 2));
            
            long left = stol(n.substr(0, middle));
            long right = 0;

            if(middle < n.size()) right = stol(n.substr(middle));
            
            long sum = left + right;
            
            if(sum == i) ans += to_string(i) + " ";
        }
        
        if(ans == "") return ("INVALID RANGE");
        return ans;
    }

    int test(){
        string path = "Tests/Algorithms/Implementation/ModifiedKaprekarNumbers/";
        std::ifstream input(path  +  "input06.txt");
        std::ifstream output(path + "output06.txt");
        
        string p_temp;
        getline(input, p_temp);

        int p = stoi(ltrim(rtrim(p_temp)));

        string q_temp;
        getline(input, q_temp);

        int q = stoi(ltrim(rtrim(q_temp)));

        string result = kaprekarNumbers(p, q);
        
        string out1;
        getline(output, out1);
        
        assert(trim(result) == out1, result + " == " + out1);
        
        return 0;
    }
}

#endif /* ModifiedKaprekarNumbers_hpp */
