//
//  ManasaAndStones.hpp
//  HackerRank
//
//  Created by Salvatore on 25/4/24.
//

#ifndef ManasaAndStones_hpp
#define ManasaAndStones_hpp

#include <stdio.h>
#include <set>

namespace ManasaAndStones {

    vector<int> stones(int n, int a, int b) {
        set<int> ans;
        int rocksA, rocksB;
        for(int i = 0; i < n; ++i){
            rocksA = (n - (i + 1)) * a;
            rocksB = i*b;
            ans.insert( rocksA + rocksB);
        }
        return vector<int>(ans.begin(), ans.end());
    }

    void test() {
        string path = "Tests/Algorithms/Implementation/ManasaAndStones/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        string T_temp;
        getline(input, T_temp);

        int T = stoi(ltrim(rtrim(T_temp)));
        
        string out;
        
        for (int T_itr = 0; T_itr < T; T_itr++) {
            string n_temp;
            getline(input, n_temp);

            int n = stoi(ltrim(rtrim(n_temp)));

            string a_temp;
            getline(input, a_temp);

            int a = stoi(ltrim(rtrim(a_temp)));

            string b_temp;
            getline(input, b_temp);

            int b = stoi(ltrim(rtrim(b_temp)));

            vector<int> result = stones(n, a, b);
            
            getline(output, out);
            vector<string> ans = split(out);
            for (size_t i = 0; i < result.size(); i++) {
                
                assert(result[i] == stoi(ans[i]), to_string(result[i]) + " == " + ans[i]);
            }

        }


    }
}

#endif /* ManasaAndStones_hpp */
