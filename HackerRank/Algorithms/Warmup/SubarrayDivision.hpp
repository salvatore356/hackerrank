//
//  SubarrayDivision.hpp
//  HackerRank
//
//  Created by Salvatore on 30/3/24.
//

#ifndef SubarrayDivision_hpp
#define SubarrayDivision_hpp

#include <stdio.h>

namespace SubarrayDivision {

    int birthday(vector<int> s, int d, int m) {
        int ans = 0;
        int sum = 0;
        for(int i = 0; i < s.size(); ++i) {
            sum += s[i];
            if (i > m - 1)
                sum -= s[i - m];
            
            if(i >= m - 1)
                ans += sum == d;
        }
        return ans;
    }
}

#endif /* SubarrayDivision_hpp */
