//
//  GradingStudents.hpp
//  HackerRank
//
//  Created by Salvatore on 29/3/24.
//

#ifndef GradingStudents_hpp
#define GradingStudents_hpp

#include <stdio.h>

namespace GradingStudents {

    vector<int> gradingStudents(vector<int> grades) {
        
        for(int i = 0; i < grades.size(); ++i) {
            int temp = grades[i] % 5;
            if(grades[i] >= 38 && temp >= 3)
                grades[i] += 5 - temp;
        }
        
        return grades;
    }
}

#endif /* GradingStudents_hpp */
