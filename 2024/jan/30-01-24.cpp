/*
Title: Evaluate Reverse Polish Notation
URL: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/?envType=daily-question&envId=2024-01-30


You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

	The valid operators are '+', '-', '*', and '/'.
	Each operand may be an integer or another expression.
	The division between two integers always truncates toward zero.
	There will not be any division by zero.
	The input represents a valid arithmetic expression in a reverse polish notation.
	The answer and all the intermediate calculations can be represented in a 32-bit integer.

 
Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

 
Constraints:

	1 <= tokens.length <= 104
	tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    bool isNumber(const string& s){
        cout << s << endl;
        if(s.size()>0 && (isdigit(s[0]) || (s[0] == '-' && isdigit(s[1])))){
            return true;
        }
        return false;
    }

public:
    int res = 0;
    stack<int> st;
    int evalRPN(vector<string>& tokens) {
       for(int i = 0;i<tokens.size();i++){
           if(isNumber(tokens[i])){
               st.push(stoi(tokens[i]));
           }else{
               int num2 = st.top();
               st.pop();
               int num1 = st.top();
               st.pop();
               if(tokens[i]=="+"){
                   res = num1+num2;
               }
                if(tokens[i]=="-"){
                   res = num1-num2;
               }
                if(tokens[i]=="*"){
                   res = num1*num2;
               } if(tokens[i]=="/"){
                   res = num1/num2;
               } 
               st.push(res);            
           }
            
       }
        return st.top();
    }
};