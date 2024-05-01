//
//  BigSorting.hpp
//  HackerRank
//
//  Created by Salvatore on 1/5/24.
//

#ifndef BigSorting_hpp
#define BigSorting_hpp

#include <stdio.h>

namespace BigSorting {

    vector<string> bigSorting(vector<string> unsorted) {
        sort(unsorted.begin(), unsorted.end(), [ ]( const string& lhs, const string& rhs ) {
            if(rhs.size() == lhs.size()) {
                for(int i = 0; i < rhs.size(); ++i) {
                    if(rhs[i] == lhs[i]) continue;
                    return rhs[i] > lhs[i];
                }
            }
            return rhs.size()> lhs.size();
        });
        
        return unsorted;
    }

    int test() {
        string path = "Tests/Algorithms/Implementation/BigSorting/";
        std::ifstream input(path  +  "input00.txt");
        std::ifstream output(path + "output00.txt");

        string n_temp;
        getline(input, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<string> unsorted(n);

        for (int i = 0; i < n; i++) {
            string unsorted_item;
            getline(input, unsorted_item);

            unsorted[i] = unsorted_item;
        }

        vector<string> result = bigSorting(unsorted);
        string out;
        
        for (size_t i = 0; i < result.size(); i++) {
            getline(output, out);
            assert(result[i] == out, result[i] + " == " + out);
        }

        return 0;
    }
}

#endif /* BigSorting_hpp */
