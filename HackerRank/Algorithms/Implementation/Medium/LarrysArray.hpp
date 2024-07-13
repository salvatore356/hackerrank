//
//  LarrysArray.hpp
//  HackerRank
//
//  Created by Salvatore on 13/7/24.
//

#ifndef LarrysArray_hpp
#define LarrysArray_hpp

#include <stdio.h>

namespace LarrysArray {

    string larrysArray(vector<int> A) {
        int count = 0;
        
        for (int i = 0; i < A.size(); ++i) {
            for (int j = i + 1; j < A.size(); ++j) {
                if (A[i] > A[j]) count ^= 1;
            }
        }
        
        return count == 0 ? "YES" : "NO";
    }

    void test()
    {
        string test_case = "00";
        string path = format_file_path_test(__FILE__);
        
        TestIO io = TestIO(path, test_case);
        
        string t_out;

        string t_temp;
        getline(io.input, t_temp);

        int t = stoi(ltrim(rtrim(t_temp)));

        for (int t_itr = 0; t_itr < t; t_itr++) {
            string n_temp;
            getline(io.input, n_temp);

            int n = stoi(ltrim(rtrim(n_temp)));

            string A_temp_temp;
            getline(io.input, A_temp_temp);

            vector<string> A_temp = split(rtrim(A_temp_temp));

            vector<int> A(n);

            for (int i = 0; i < n; i++) {
                int A_item = stoi(A_temp[i]);

                A[i] = A_item;
            }

            string result = larrysArray(A);
            
            getline(io.output, t_out);
            assert(result == t_out, result + " == " + t_out);
        }
    }
}

#endif /* LarrysArray_hpp */
