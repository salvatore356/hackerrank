//
//  TheFullCountingSort.hpp
//  HackerRank
//
//  Created by Salvatore on 16/7/24.
//

#ifndef TheFullCountingSort_hpp
#define TheFullCountingSort_hpp

#include <stdio.h>

namespace TheFullCountingSort {

    string countSort(vector<vector<string>> arr) {
        string sentence = "";
        vector<string> words;
        int mid = (int)arr.size() / 2;
        for (int i = 0; i < arr.size(); ++i) {
            int index = stoi(arr[i][0]);
            if (words.size() < index + 1) words.resize(index + 1);
            words[index] += i < mid ? "- " : arr[i][1] + " ";
        }
        
        for (int i = 0; i < words.size(); ++i)
            sentence += words[i];
        
        return sentence;
    }

    void test() {
        string test_case = "00";
        string path = format_file_path_test(__FILE__);
        
        TestIO io = TestIO(path, test_case);
        
        string t_out;
        
        string n_temp;
        getline(io.input, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<vector<string>> arr(n);

        for (int i = 0; i < n; i++) {
            arr[i].resize(2);

            string arr_row_temp_temp;
            getline(io.input, arr_row_temp_temp);

            vector<string> arr_row_temp = split(rtrim(arr_row_temp_temp));

            for (int j = 0; j < 2; j++) {
                string arr_row_item = arr_row_temp[j];

                arr[i][j] = arr_row_item;
            }
        }

        string result = countSort(arr);

        getline(io.output, t_out);
        assert(result == t_out, result + " == " + t_out);
    }
}

#endif /* TheFullCountingSort_hpp */
