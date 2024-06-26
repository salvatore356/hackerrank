//
//  PrimeDates.hpp
//  HackerRank
//
//  Created by Salvatore on 26/6/24.
//

#ifndef PrimeDates_hpp
#define PrimeDates_hpp

#include <stdio.h>
#include <sstream>


namespace PrimeDates {

    int month[15];

    void updateLeapYear(int year) {
        if(year % 400 == 0) {
            month[2] = 29;
        } else if(year % 100 == 0) {
            month[2] = 28;
        } else if(year % 4 == 0) {
            month[2] = 29;
        } else {
            month[2] = 28;
        }
    }

    void storeMonth() {
        month[1] = 31;
        month[2] = 28;
        month[3] = 31;
        month[4] = 30;
        month[5] = 31;
        month[6] = 30;
        month[7] = 31;
        month[8] = 31;
        month[9] = 30;
        month[10] = 31;
        month[11] = 30;
        month[12] = 31;
    }

    int findLuckyDates(int d1, int m1, int y1, int d2, int m2, int y2) {
        storeMonth();
        
        int result = 0;

        while(true) {
            int x = d1;
            x = x * 100 + m1;
            x = x * 10000 + y1;
            
            if(x % 4 == 0 || x % 7 == 0) {
                result = result + 1;
            }
            if(d1 == d2 && m1 == m2 && y1 == y2) {
                break;
            }
            updateLeapYear(y1);
            d1 = d1 + 1;
            if(d1 > month[m1]) {
                m1 = m1 + 1;
                d1 = 1;
                if(m1 > 12) {
                    y1 =  y1 + 1;
                    m1 = 1;
                }
            }
        }
        return result;
    }

    void test() {
        
        string test_case = "01";
        string path = format_file_path_test(__FILE__);
        
        TestIO io = TestIO(path, test_case);
        
        string t_out;
        
        string str;
        int d1, m1, y1, d2, m2, y2;
        getline(io.input, str);
        
        printf("str %s\n", str.c_str());
        
        for(int i = 0; i < str.size(); i++) {
            if(str[i] == '-') {
                str[i] = ' ';
            }
        }
        stringstream ss;
        ss << str;
        ss >> d1 >> m1 >> y1 >> d2 >> m2 >> y2;

        int result = findLuckyDates(d1, m1, y1, d2, m2, y2);
        
        getline(io.output, t_out);
        assert(result == stoi(t_out), to_string(result) + " == " + t_out);
    }


}

#endif /* PrimeDates_hpp */
