// Problem Statement:
// Given an array A of non-negative integers, arrange them such that they form the largest number.
// Note: The result may be very large, so you need to return a string instead of an integer.


bool comp(string s1, string s2){
    return (s1+s2)>(s2+s1);
}

string Solution::largestNumber(vector<int> &A) {
    vector<string> s;
    for(int i=0;i<A.size();i++)
    s.push_back(to_string(A[i]));
    sort(s.begin(),s.end(),comp);
    string strNum = "";
    for(string num:s){
        if(strNum.empty() && num=="0")
        continue;
        strNum+=num;
    }
    if(strNum=="")
    return "0";
    return strNum;
}