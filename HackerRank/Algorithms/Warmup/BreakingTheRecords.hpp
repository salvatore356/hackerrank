//
//  BreakingTheRecords.hpp
//  HackerRank
//
//  Created by Salvatore on 29/3/24.
//

#ifndef BreakingTheRecords_hpp
#define BreakingTheRecords_hpp

#include <stdio.h>

namespace BreakingTheRecords {

vector<int> breakingRecords(vector<int> scores) {
    vector<int> ans (2);
    int maxScore = scores[0], minScore = scores[0];
    
    for(int i = 1; i < scores.size(); ++i) {
        if(scores[i] > maxScore) {
            ++ans[0];
            maxScore = scores[i];
        }else if(scores[i] < minScore) {
            ++ans[1];
            minScore = scores[i];
        }
    }
    return ans;
}
}

#endif /* BreakingTheRecords_hpp */
