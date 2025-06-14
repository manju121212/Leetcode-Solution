#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> results;
        if (expression.find('+') == string::npos &&
            expression.find('-') == string::npos &&
            expression.find('*') == string::npos) {
            
            // Convert the string number to int and return it as the only result
            results.push_back(stoi(expression));
            return results;
        }

        for (int i = 0; i < expression.length(); i++) {
            char c = expression[i];

            if (c == '+' || c == '-' || c == '*') {
                // Divide the expression at the operator
                string leftPart = expression.substr(0, i);
                string rightPart = expression.substr(i + 1);

                // Recursively compute all possible results for left and right parts
                vector<int> leftResults = diffWaysToCompute(leftPart);
                vector<int> rightResults = diffWaysToCompute(rightPart);

                // Combine the results with the operator
                for (int l : leftResults) {
                   
                    for (int r : rightResults) {
                     
                        if (c == '+') results.push_back(l + r);
                        else if (c == '-') results.push_back(l - r);
                        else if (c == '*') results.push_back(l * r);
                    }
                    
                }
            }
        }

      

        return results;
    }
};
