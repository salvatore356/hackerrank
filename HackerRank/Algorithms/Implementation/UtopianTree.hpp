//
//  UtopianTree.hpp
//  HackerRank
//
//  Created by Salvatore on 30/3/24.
//

#ifndef UtopianTree_hpp
#define UtopianTree_hpp

#include <stdio.h>

namespace UtopianTree {

    int utopianTree(int n) {
        int ans = 1;
        for(int i = 1; i <= n; i++){
            if(i % 2 != 1) ++ans;
            else ans *= 2;
        }
        return ans;
    }
}

#endif /* UtopianTree_hpp */
