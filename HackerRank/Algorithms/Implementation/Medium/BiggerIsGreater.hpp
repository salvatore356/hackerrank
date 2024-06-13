//
//  BiggerIsGreater.hpp
//  HackerRank
//
//  Created by Salvatore on 13/6/24.
//

#ifndef BiggerIsGreater_hpp
#define BiggerIsGreater_hpp

#include <stdio.h>

namespace BiggerIsGreater {

    string biggerIsGreater(string w) {
        
        int rIndex = -1;
        for (int i = (int)w.size() - 1; i >= 0; --i)
            if (w[i] < w[i+1]){
                rIndex = i;
                break;
            }
            
        if (rIndex == -1) return "no answer";
        
        for(int i = (int)w.size() - 1; i >= 0; --i)
            if(w[i] > w[rIndex]) {
                swap(w[rIndex], w[i]);
                break;
            }
        
        reverse(w.begin() + rIndex + 1, w.end());

        return w;
    }

    void test() {
        string test_case = "01";
        string path = format_file_path_test(__FILE__);
        
        TestIO io = TestIO(path, test_case);
        
        string t_out;

        string T_temp;
        getline(io.input, T_temp);

        int T = stoi(ltrim(rtrim(T_temp)));

        for (int T_itr = 0; T_itr < T; T_itr++) {
            string w;
            getline(io.input, w);

            string result = biggerIsGreater(w);
            getline(io.output, t_out);
            assert(result == t_out, result + " == " + t_out);

        }

    }
}

#endif /* BiggerIsGreater_hpp */
