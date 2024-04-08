//
//  DayOfTheProgrammer.hpp
//  HackerRank
//
//  Created by Salvatore on 30/3/24.
//

#ifndef DayOfTheProgrammer_hpp
#define DayOfTheProgrammer_hpp

#include <stdio.h>

namespace DayOfTheProgrammer {


    string dayOfProgrammer(int year) {

        int day = 13;
        if (year == 1918) day = 26;
        else if (year % 4 == 0){
            day = 12;
            day += (year > 1918 && year % 100 == 0 && year % 400 != 0);
        }
        
        return to_string(day) + ".09." + to_string(year);
    }

}

#endif /* DayOfTheProgrammer_hpp */
