//
//  DivisibleSumPairs.hpp
//  HackerRank
//
//  Created by Salvatore on 30/3/24.
//

#ifndef DivisibleSumPairs_hpp
#define DivisibleSumPairs_hpp

#include <stdio.h>

namespace DivisibleSumPairs {

    int divisibleSumPairs(int n, int k, vector<int> ar) {
        int ans = 0;
        for(int i = 0; i < ar.size(); ++i) {
            for(int j = i + 1; j < ar.size(); ++j) {
                ans += (ar[i] + ar[j]) % k == 0;
            }
        }
        return ans;
    }
}

#endif /* DivisibleSumPairs_hpp */
