//
//  BetweenTwoSets.hpp
//  HackerRank
//
//  Created by Salvatore on 29/3/24.
//

#ifndef BetweenTwoSets_hpp
#define BetweenTwoSets_hpp

#include <stdio.h>

namespace BetweenTwoSets {

int getTotalX(vector<int> a, vector<int> b) {
    int ans = 0;
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    
    for(int i = a.front(); i <= b.back(); ++i){
        bool valid = true;
        
        for(int j = 0; j < a.size(); ++j)
            if(i%a[j] != 0) {
                valid = false;
                break;
            }
        
        if(!valid) continue;
        
        for(int j = 0; j < b.size(); ++j)
            if(b[j]%i != 0) {
                valid = false;
                break;
            }
        ans += valid;
    }
    
    return ans;
}
}

#endif /* BetweenTwoSets_hpp */
