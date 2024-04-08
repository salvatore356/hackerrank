//
//  SequenceEquation.hpp
//  HackerRank
//
//  Created by Salvatore on 31/3/24.
//

#ifndef SequenceEquation_hpp
#define SequenceEquation_hpp

#include <stdio.h>

namespace SequenceEquation {

vector<int> permutationEquation(vector<int> p) {
    vector<int> ans(p.size());
    
    for(int i = 0; i < p.size(); ++i)
        ans[p[p[i] - 1] - 1] = i + 1;
    
    return ans;
}
}

#endif /* SequenceEquation_hpp */
