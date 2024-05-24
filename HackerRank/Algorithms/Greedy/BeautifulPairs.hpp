//
//  BeautifulPairs.hpp
//  HackerRank
//
//  Created by Salvatore on 24/5/24.
//

#ifndef BeautifulPairs_hpp
#define BeautifulPairs_hpp

#include <stdio.h>

namespace BeautifulPairs {


    int beautifulPairs(vector<int> A, vector<int> B) {
        unordered_map<int, int> countA, countB;
        
        for (auto &a: A)  ++countA[a];
        for (auto &b: B)  ++countB[b];
        
        int beauty = 0;
        
        for (auto &b : countB)
            beauty += min(countA[b.first], b.second);
        
        beauty += A.size() == beauty ? - 1 : 1;
        
        return beauty;
    }

    int beautifulPairs_v2(vector<int> A, vector<int> B) {
        int beauty = 0;
        for (int i = 0; i < B.size(); ++i) {
            auto pos = find(A.begin(), A.end(), B[i]);
            
            if (pos != A.end()) {
                A.erase(pos);
                ++beauty;
            }
        }
        beauty += A.size() == 0 ? - 1 : 1;
        return beauty;
    }

    void test() {
        string test_case = "04";
        string path = "Tests/Algorithms/Greedy/" + remove_extension(__FILE_NAME__) + "/";
        std::ifstream input(path  +  "input" + test_case + ".txt");
        std::ifstream output(path + "output" + test_case + ".txt");

        string n_temp, t_out;

        getline(input, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

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

        int result = beautifulPairs(A, B);

        getline(output, t_out);
        assert(result == stoi(t_out), to_string(result) + " == " + t_out);
    }
}

#endif /* BeautifulPairs_hpp */
