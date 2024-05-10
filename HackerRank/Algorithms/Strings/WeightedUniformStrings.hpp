//
//  WeightedUniformStrings.hpp
//  HackerRank
//
//  Created by Salvatore on 10/5/24.
//

#ifndef WeightedUniformStrings_hpp
#define WeightedUniformStrings_hpp

#include <stdio.h>

namespace WeightedUniformStrings {

    vector<string> weightedUniformStrings(string s, vector<int> queries) {
        unordered_map<char, vector<int>> weights;
        vector<string> ans;
        
        int similarCount = 1;
        
        auto w = weights[s.front()];
        
        
        weights[s.front()].push_back((s.front() - 'a') + 1);
        
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != s[i-1]) similarCount = 0;
            ++similarCount;
            
            if (weights[s[i]].size() < similarCount)
                weights[s[i]].push_back(((s[i] - 'a') + 1) * similarCount);
        }
        
        unordered_map<int, bool> flatten;
        
        for (auto &w: weights) {
            for (auto &v: w.second) {
                flatten[v] = true;
            }
        }
            
            
        for (int &q : queries)
            ans.push_back( flatten[q] ? "Yes" : "No" );
        
        return ans;
    }

    void test() {
        string path = "Tests/Algorithms/Strings/WeightedUniformStrings/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        string s;
        getline(input, s);

        string queries_count_temp;
        getline(input, queries_count_temp);

        int queries_count = stoi(ltrim(rtrim(queries_count_temp)));

        vector<int> queries(queries_count);

        for (int i = 0; i < queries_count; i++) {
            string queries_item_temp;
            getline(input, queries_item_temp);

            int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

            queries[i] = queries_item;
        }

        vector<string> result = weightedUniformStrings(s, queries);
        string t_out;
        
        for (size_t i = 0; i < result.size(); i++) {
            getline(output, t_out);
            
            assert(result[i] == t_out, result[i] + " == " + t_out);
            
        }
    }
}

#endif /* WeightedUniformStrings_hpp */
