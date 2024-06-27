//
//  ZigZagSequence.hpp
//  HackerRank
//
//  Created by Salvatore on 27/6/24.
//

#ifndef ZigZagSequence_hpp
#define ZigZagSequence_hpp

#include <stdio.h>

namespace ZigZagSequence {

    void print(vector<int> &v) {
        for (int i = 0; i < v.size(); ++i)
            printf("%d ", v[i]);
        printf("\n");
    }

    vector<int> findZigZagSequence(vector < int > a, int n){
        sort(a.begin(), a.end());
        int mid = (n + 1)/2 - 1;
        swap(a[mid], a[n-1]);
        int st = mid + 1;
        int ed = n - 2;
        while(st <= ed){
            swap(a[st], a[ed]);
            st = st + 1;
            ed = ed - 1;
        }
        
        return a;
    }

    void test() {
        string test_case = "00";
        string path = format_file_path_test(__FILE__);
        
        TestIO io = TestIO(path, test_case);
        
        string t_out;
        
        int n, x;
        int test_cases;
        
        io.input >> test_cases;

        for(int cs = 1; cs <= test_cases; cs++){
            io.input >> n;
            
            vector < int > a;
            for(int i = 0; i < n; i++){
                io.input >> x;
                
                a.push_back(x);
            }
            vector <int> result = findZigZagSequence(a, n);
            
            string s_result = vector_to_string(result);
            getline(io.output, t_out);
            assert(s_result == t_out, s_result + " == " + t_out);
        }
    }
}

#endif /* ZigZagSequence_hpp */
