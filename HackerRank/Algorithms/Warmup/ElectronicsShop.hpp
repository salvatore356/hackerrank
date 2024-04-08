//
//  ElectronicsShop.hpp
//  HackerRank
//
//  Created by Salvatore on 30/3/24.
//

#ifndef ElectronicsShop_hpp
#define ElectronicsShop_hpp

#include <stdio.h>

namespace ElectronicsShop {
    int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {

        int maxSpend = -1;
        
        for(int i = 0; i < keyboards.size(); ++i)
            for(int j = 0; j < drives.size(); ++j){
                int temp = keyboards[i] + drives[j];
                if(temp <= b) maxSpend = max(maxSpend, temp);
            }
        return maxSpend;
    }
}
#endif /* ElectronicsShop_hpp */
