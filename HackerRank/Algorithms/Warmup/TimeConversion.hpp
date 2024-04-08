//
//  TimeConversion.hpp
//  HackerRank
//
//  Created by Salvatore on 29/3/24.
//

#ifndef TimeConversion_hpp
#define TimeConversion_hpp

#include <stdio.h>

namespace TimeConversion {
    string timeConversion(string s) {
        s.pop_back();
        char ampm = s.back();
        s.pop_back();
        
        string hh;
        hh.push_back(s[0]);
        hh.push_back(s[1]);
        
        if(hh == "12"){
          if(ampm == 'A') s[0] = '0', s[1] = '0';
        } else if(ampm == 'P') {
            int temp = stoi(hh) + 12;
            int rest = temp % 10;
            s[1] = '0' + rest;
            s[0] = '0' + (temp / 10);
        }
        
        
        return s;
    }
}

#endif /* TimeConversion_hpp */
