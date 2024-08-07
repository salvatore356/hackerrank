//
//  HighestValuePalindrome.hpp
//  HackerRank
//
//  Created by Salvatore on 18/7/24.
//

#ifndef HighestValuePalindrome_hpp
#define HighestValuePalindrome_hpp

#include <stdio.h>

namespace HighestValuePalindrome {

    string highestValuePalindrome(string s, int n, int k) {
        int mid = (int)s.size() / 2;
        
        vector<int> diff;
        int index = (int)s.size() - 1;
        
        for (int i = 0; i < mid; ++i)
            if (s[i] != s[index - i])
                diff.push_back(i);
        
        if (diff.size() > k) return "-1";
        
        for (int i = 0; i < diff.size(); ++i) {
            int ch = max(s[diff[i]], s[index - diff[i]]);
            s[diff[i]] = ch;
            s[index - diff[i]] = ch;
            --k;
        }
        printf("s: %s k: %d\n", s.c_str(), k);
        for(int i=0; i<s.size() && (k > 0); ++i) {
            if(s[i] != '9') {
                auto iter = std::find(diff.begin(), diff.end(), i);
                
                if (iter != diff.end()) --k;
                else if (k < 2) break;
                else k -= 2;
                s[i] = '9';
                s[index - i] = '9';
            }
            //printf("s: %s k: %d i: %d\n", s.c_str(), k, i);
        }
        
        //printf("k: %d\n", k);
        if (k > 0 && s.size() % 2 != 0) s[mid] = '9';
        
        return s;
    }

    void test() {
        string test_case = "00";
        string path = format_file_path_test(__FILE__);
        
        TestIO io = TestIO(path, test_case);
        
        string t_out;

        string first_multiple_input_temp;
        getline(io.input, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int k = stoi(first_multiple_input[1]);

        string s;
        getline(io.input, s);

        string result = highestValuePalindrome(s, n, k);

        getline(io.output, t_out);
        assert(result == t_out, result + " == " + t_out);
    }
}

#endif /* HighestValuePalindrome_hpp */
