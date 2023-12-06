// Problem Statement :
// The gray code is a binary numeral system where two successive values differ in only one bit.
// Given a non-negative integer A representing the total number of bits in the code, print the sequence of gray code.
// A gray code sequence must begin with 0.

vector<int> Solution::grayCode(int A) {
    if(A==1){
        return vector<int>{0,1};
    }
    vector<int> tempList;
    tempList = grayCode(A-1);
    vector<int> ans_list;
    for(int i=0;i<tempList.size();i++)
    ans_list.push_back(tempList[i]);
    for(int i=tempList.size()-1;i>=0;i--)
    ans_list.push_back(tempList[i]+pow(2,A-1));
    return ans_list;
}
