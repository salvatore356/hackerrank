//
//  BirthdayCakeCandles.hpp
//  HackerRank
//
//  Created by Salvatore on 28/3/24.
//

#ifndef BirthdayCakeCandles_hpp
#define BirthdayCakeCandles_hpp

#include <stdio.h>

namespace BirthdayCakeCandles {
    int birthdayCakeCandles(vector<int> candles) {
        unordered_map<int, int> candlesCount;
        int maxCandle = 0;
        
        for(int i = 0; i < candles.size(); ++i) {
            ++candlesCount[candles[i]];
            
            if(candlesCount[candles[i]] > candlesCount[maxCandle])
                maxCandle = candles[i];
        }
        
        return candlesCount[maxCandle];
    }
}

#endif /* BirthdayCakeCandles_hpp */
