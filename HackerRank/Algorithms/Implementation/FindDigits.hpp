//
//  FindDigits.hpp
//  HackerRank
//
//  Created by Salvatore on 31/3/24.
//

#ifndef FindDigits_hpp
#define FindDigits_hpp

#include <stdio.h>

namespace FindDigits {

int findDigits(int n) {
    int divisor = 0;
    string temp = to_string(n);
    
    for(int i = 0; i < temp.size(); ++i){
        if(temp[i] != '0')
            divisor += n % (temp[i] - '0') == 0;
    }
    
    return divisor;
}
}

#endif /* FindDigits_hpp */
