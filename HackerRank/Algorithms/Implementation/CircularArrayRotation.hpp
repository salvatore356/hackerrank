//
//  CircularArrayRotation.hpp
//  HackerRank
//
//  Created by Salvatore on 31/3/24.
//

#ifndef CircularArrayRotation_hpp
#define CircularArrayRotation_hpp

#include <stdio.h>

namespace CircularArrayRotation {

/**
 1  2   3
 3  1   2
 2  3   1
 ========
 
 2  3   1
 
 0  1   2 -> 2 ->   2   3   4
 2  0   1
 1  2   0
 */

vector<int> circularArrayRotation(vector<int> a, int k, vector<int> queries) {
    vector<int> ans(queries.size());
    
    int rotation = (int) (a.size() - (k % a.size()));
    int index;
    
    for(int i = 0; i < queries.size(); ++i){
        index = (rotation  + queries[i] );
        
        if(index >= a.size())
            index -= a.size();
        ans[i] = a[index];
    }
    
    return ans;
}

int test() {

    std::ifstream input("Tests/Algorithms/Implementation/CircularArrayRotation/input00.txt");
    std::ifstream output("Tests/Algorithms/Implementation/CircularArrayRotation/output00.txt");
    
    if (!input.is_open()) {
        std::cerr << "Failed to open the file." << std::endl;
        return 1;
    }
    
    string first_multiple_input_temp;
    getline(input, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    int q = stoi(first_multiple_input[2]);

    string a_temp_temp;
    getline(input, a_temp_temp);

    vector<string> a_temp = split(rtrim(a_temp_temp));

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        int a_item = stoi(a_temp[i]);

        a[i] = a_item;
    }

    vector<int> queries(q);

    for (int i = 0; i < q; i++) {
        string queries_item_temp;
        getline(input, queries_item_temp);

        int queries_item = stoi(ltrim(rtrim(queries_item_temp)));

        queries[i] = queries_item;
    }

    vector<int> result = circularArrayRotation(a, k, queries);

    string t_temp;
    for (size_t i = 0; i < result.size(); i++) {
        getline(output, t_temp);
        assert(result[i] == stoi(t_temp), to_string(result[i]) + " == " + t_temp);
        
    }

    cout << "\n";

    //getline(output, t_temp);
    //assert(result == stoi(t_temp), to_string(result) + " == " + t_temp);

    return 0;
}
}

#endif /* CircularArrayRotation_hpp */
