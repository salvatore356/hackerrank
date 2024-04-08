//
//  PickingNumbers.hpp
//  HackerRank
//
//  Created by Salvatore on 30/3/24.
//

#ifndef PickingNumbers_hpp
#define PickingNumbers_hpp

#include <stdio.h>

namespace PickingNumbers {

int pickingNumbers(vector<int> a) {
    sort(a.begin(), a.end());
    int ans = 0, temp = 1;
    
    int currentElement = a[0];
    
    for(int i = 1; i < a.size(); ++i) {
        if(a[i] - currentElement <= 1) {
            ++temp;
        }else {
          ans = max(temp, ans);
          temp = 1;
          currentElement = a[i];
        }
    }
    return max(ans, temp);
}
}

#endif /* PickingNumbers_hpp */
