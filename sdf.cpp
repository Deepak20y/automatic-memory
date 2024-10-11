

 #include<bits/stdc++.h>
 using namespace std;

  class Solution {
public:
    int lsp(vector<int>& heights) {

        int n = heights.size();
        stack<int> a;

        vector<int> pref(n), suff(n);
        for (int i = 0; i < n; i++) {
            while (!a.empty() && heights[a.top()] >= heights[i])
                a.pop();

            if (a.empty())
                pref[i] = -1;
            else
                pref[i] = a.top();
            a.push(i);
        }

        while (!a.empty())
            a.pop();

    

        for (int i = n - 1; i >= 0; i--) {
            while (!a.empty() && heights[a.top()] >= heights[i])
                a.pop();

            if (a.empty())
                suff[i] = n;
            else
                suff[i] = a.top();
            a.push(i);
        }
        

        int ans =0;

        for (int i = 0; i < n; i++) {
            int cnt = 1;
            while (i + 1 < n && heights[i] == heights[i + 1]) {
                i++;
                cnt++;
            }
            ans = max(ans, cnt * heights[i]);
        }

        for (int i = 0; i < n; i++) {

            if (pref[i] == -1 && suff[i] == n) {
                ans = max(ans, n * heights[i]);
            } else if (pref[i] == -1) {
                ans = max(ans, (i + 1) * heights[i]);
                ans = max(ans, (suff[i] + 1) * heights[suff[i]]);
            } else if (suff[i] == n) {
                ans = max(ans, (n - i) * heights[i]);
                ans = max(ans, (n - pref[i]) * heights[pref[i]]);
            } else {
                ans = max(ans, (i - pref[i] + 1) * heights[pref[i]]);
                ans = max(ans, (suff[i] - i + 1) * heights[suff[i]]);
        ans=max(ans,(suff[i]-pref[i]+1)*min(heights[suff[i]],heights[pref[i]]));
            }
        }

        return ans;
    }


int main()
{
    int n;cin>>n;
    vector<int>a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    

    cout<<largestRectangleArea(a)<<endl;
    return 0; 
}