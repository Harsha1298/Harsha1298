// Problem Statement:
// We have a list A of points (x, y) on the plane. Find the B closest points to the origin (0, 0).
// Here, the distance between two points on a plane is the Euclidean distance.
// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in.)
// NOTE: Euclidean distance between two points P1(x1, y1) and P2(x2, y2) is sqrt( (x1-x2)2 + (y1-y2)2 ).


vector<vector<int> > Solution::solve(vector<vector<int> > &A, int B) {
  vector<pair<int,int>> vec;
    int n = A.size();

    for(int i =0; i<n; i++)
        {
        int x = A[i][0];
        int y = A[i][1];

        vec.push_back({(x*x + y*y),i});
    }
    sort(vec.begin(), vec.end());

    vector<vector<int>> ans;
    for(int i =0; i<B; i++){
        ans.push_back(A[vec[i].second]);
    }
    return ans;
}
