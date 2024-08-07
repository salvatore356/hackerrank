//
//  MaximumPalindromes.hpp
//  HackerRank
//
//  Created by Salvatore on 19/7/24.
//

#ifndef MaximumPalindromes_hpp
#define MaximumPalindromes_hpp

#include <stdio.h>

namespace MaximumPalindromes {

    const size_t MODULO = 1000000007;
    std::vector<size_t> factorials;
    std::vector<size_t> inverses;
    std::vector<std::unordered_map<char, int>> counts;

    size_t modPow(size_t base, size_t exponent){
        size_t result = 1;
        while (exponent > 0) {
            if (exponent & 1) {
                result = (result * base) % MODULO;
            }
            base = (base * base) % MODULO;
            exponent >>= 1;
        }
        return result;
    }
   
    void initialize(string s) {
        
        int n = (int)s.length();
        factorials.resize(n / 2 + 1, 1);
        inverses.resize(n / 2 + 1, 1);
        counts.resize(n + 1);
        
        for(int i = 2; i != factorials.size(); ++i){
            factorials[i] = (i * factorials[i - 1]) % MODULO;
            inverses[i] = modPow(factorials[i], MODULO - 2);
        }
        
        for(int i = 0; i < s.size(); ++i){
            counts[i + 1] = counts[i];
            ++counts[i + 1][s[i]];
        }
    }

    int answerQuery(int l, int r) {
        size_t pairs = 0;
        size_t odds = 0;
        size_t denominator = 1;
        
        for(auto const & [chr, count]: counts[r]){
            int charCount = count - counts[l - 1][chr];
            
            
            pairs += charCount / 2;
            odds += charCount % 2 == 1;
            
            if(charCount >= 2)
                denominator = (denominator * inverses[charCount / 2]) % MODULO;
            
            
        }
        
        size_t ans = (factorials[pairs] * denominator) % MODULO;
        if (odds > 1) ans *= odds;
        
        return ans % MODULO;
    }


    void test() {
        
        vector<string> cases = {"00", "01", "04", "12", "13", "27"};
        
        for (auto &c : cases) {
            string test_case = c;
            string path = format_file_path_test(__FILE__);
            
            TestIO io = TestIO(path, test_case);
            
            string t_out;
            
            string s;
            getline(io.input, s);
            
            initialize(s);
            
            string q_temp;
            getline(io.input, q_temp);
            
            int q = stoi(ltrim(rtrim(q_temp)));
            
            for (int q_itr = 0; q_itr < q; q_itr++) {
                string first_multiple_input_temp;
                getline(io.input, first_multiple_input_temp);
                
                vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));
                
                int l = stoi(first_multiple_input[0]);
                
                int r = stoi(first_multiple_input[1]);
                
                int result = answerQuery(l, r);
                
                getline(io.output, t_out);
                assert(result == stoi(t_out), to_string(result) + " == " + t_out);
            }
            
        }
    }
}

#endif /* MaximumPalindromes_hpp */
