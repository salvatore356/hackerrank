//
//  BeautifulDaysAtTheMovies.hpp
//  HackerRank
//
//  Created by Salvatore on 30/3/24.
//

#ifndef BeautifulDaysAtTheMovies_hpp
#define BeautifulDaysAtTheMovies_hpp

#include <stdio.h>

namespace BeautifulDaysAtTheMovies {

    int beautifulDays(int i, int j, int k) {
        int beautyfulDays = 0;
        string temp;
        for(; i <= j; ++i) {
            temp = to_string(i);
            reverse(temp.begin(), temp.end() );
            
            float n = (float)(i - stoi(temp)) / k;
            beautyfulDays += (n - (int)n) == 0;
        }
        return beautyfulDays;
    }
}

#endif /* BeautifulDaysAtTheMovies_hpp */
