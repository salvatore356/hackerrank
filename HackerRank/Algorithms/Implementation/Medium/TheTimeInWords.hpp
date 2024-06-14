//
//  TheTimeInWords.hpp
//  HackerRank
//
//  Created by Salvatore on 14/6/24.
//

#ifndef TheTimeInWords_hpp
#define TheTimeInWords_hpp

#include <stdio.h>

namespace TheTimeInWords {
    unordered_map<int, string> words = {
        {0, "o' clock"}, {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"},
        {6, "six"}, {7, "seven"}, {8, "eight"}, {9, "nine"}, {10, "ten"},
        {11, "eleven"}, {12, "twelve"}, {13, "thirteen"},  {15, "quarter"},
        {20, "twenty"}, {30, "half"}
    };

    string convert(int h, int m, string relative) {
        
        
        if (m == 0) return words[h] + " " + words[m];
        else if (m == 15 || m == 30)
            return words[m] + " "+ relative+ " " + words[h];
        else if (m < 14)
            return words[m] + " minute" + (m == 1?"":"s") + " " + relative + " " + words[h];
        else if (m < 20)
            return words[m%10] + "teen minutes " + relative + " " + words[h];
        
        return words[20] + (m%10 != 0?" " +words[m%10]:"") + " minutes " + relative + " " + words[h];
    }

    string timeInWords(int h, int m) {
        if (m <= 30)
            return convert(h, m, "past");
        
        m = 60 - m;
        h += 1;
        if (h > 12) h = 1;
        return convert(h, m, "to");
    }


    void test() {
        string test_case = "01";
        string path = format_file_path_test(__FILE__);
        
        TestIO io = TestIO(path, test_case);
        
        string t_out;

        string h_temp;
        getline(io.input, h_temp);

        int h = stoi(ltrim(rtrim(h_temp)));

        string m_temp;
        getline(io.input, m_temp);

        int m = stoi(ltrim(rtrim(m_temp)));

        string result = timeInWords(h, m);
        getline(io.output, t_out);
        assert(result == t_out, result + " == " + t_out);
    }
}

#endif /* TheTimeInWords_hpp */
