//
//  BearAndSteadyGene.hpp
//  HackerRank
//
//  Created by Salvatore on 7/8/24.
//

#ifndef BearAndSteadyGene_hpp
#define BearAndSteadyGene_hpp

#include <stdio.h>

namespace BearAndSteadyGene {

    vector<int>::iterator lower_b(vector<int> &v, int i, int appear) {
        return lower_bound(v.begin()+i, v.end(), v.back()+v[i-1] - appear);
    }

    int steadyGene(string gene) {
        int appear = (int)gene.size() / 4;
        vector<int> count(gene.size());
        unordered_map<char, vector<int>> letters {
            {'A', count}, {'C', count}, {'G', count}, {'T', count}
        };
        
        for (int i = 0; i < gene.size(); ++i){
            auto &key = gene[i];
            for (auto &letter : letters) {
                
                letter.second[i] += letter.second[max(0, i - 1)] + (key == letter.first);
            }
        }
       
        bool count_complete = true;
        
        for (auto &letter : letters) {
            if (letter.second.back() != appear) {
                count_complete = false;
                break;
            }
        }
        
        if (count_complete)  return 0;
        
        int result = (int)gene.size();
        for (int i=1; i <= gene.size(); i++) {
            
            int max_dist = 0;
            bool max_break = false;
            
            for (auto &letter : letters) {
                auto it = lower_b(letter.second, i, appear);
                if (it == letter.second.end()) {
                    max_break = true;
                    break;
                }
                int dist = (int)distance(letter.second.begin(), it);
                max_dist = max( max_dist, dist);
            }
            
            if (max_break) break;
            
            result = min(result, max_dist-i+1);
        }
            
        return result;
    }

    void test(){
        vector<string> cases = {"00", "01"};
        
        for (auto &c : cases) {
            string test_case = c;
            string path = format_file_path_test(__FILE__);
            
            TestIO io = TestIO(path, test_case);
            
            string t_out;
            
            string n_temp;
            getline(io.input, n_temp);
            
            //int n = stoi(ltrim(rtrim(n_temp)));
            
            string gene;
            getline(io.input, gene);
            
            int result = steadyGene(gene);
            
            getline(io.output, t_out);
            assert(result == stoi(t_out), to_string(result) + " == " + t_out);
        }

    }
}

#endif /* BearAndSteadyGene_hpp */
