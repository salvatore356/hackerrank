//
//  MiniMaxSum.hpp
//  HackerRank
//
//  Created by Salvatore on 28/3/24.
//

#ifndef MiniMaxSum_hpp
#define MiniMaxSum_hpp

#include <stdio.h>

namespace MiniMaxSum {

void miniMaxSum(vector<int> arr) {
    long minSum = 0, maxSum = 0;
    sort(arr.begin(), arr.end());
    
    for(int i = 0; i < arr.size() - 1; ++i){
        minSum += arr[i];
        maxSum += arr[i + 1];
    }
    
    printf("%ld %ld\n", minSum, maxSum);
    
}
}

#endif /* MiniMaxSum_hpp */
