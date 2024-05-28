//
//  PermutingTwoArrays.hpp
//  HackerRank
//
//  Created by Salvatore on 28/5/24.
//

#ifndef PermutingTwoArrays_hpp
#define PermutingTwoArrays_hpp

#include <stdio.h>

namespace PermutingTwoArrays {

    string twoArrays(int k, vector<int> A, vector<int> B) {
        sort(A.begin(), A.end());
        sort(B.begin(), B.end(), greater<int>());
        
        for (int i = 0; i < A.size(); ++i)
            if (A[i] + B[i] < k) return "NO";
                
        return "YES";
    }

    void test() {
        
        string test_case = "01";
        string path = "Tests/Algorithms/Greedy/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");

        string t_out;

        string q_temp;
        getline(input, q_temp);

        int q = stoi(ltrim(rtrim(q_temp)));

        for (int q_itr = 0; q_itr < q; q_itr++) {
            string first_multiple_input_temp;
            getline(input, first_multiple_input_temp);

            vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

            int n = stoi(first_multiple_input[0]);

            int k = stoi(first_multiple_input[1]);

            string A_temp_temp;
            getline(input, A_temp_temp);

            vector<string> A_temp = split(rtrim(A_temp_temp));

            vector<int> A(n);

            for (int i = 0; i < n; i++) {
                int A_item = stoi(A_temp[i]);

                A[i] = A_item;
            }

            string B_temp_temp;
            getline(input, B_temp_temp);

            vector<string> B_temp = split(rtrim(B_temp_temp));

            vector<int> B(n);

            for (int i = 0; i < n; i++) {
                int B_item = stoi(B_temp[i]);

                B[i] = B_item;
            }

            string result = twoArrays(k, A, B);
            getline(output, t_out);
            assert(result == t_out, result + " == " + t_out);
        }
    }
}

#endif /* PermutingTwoArrays_hpp */
