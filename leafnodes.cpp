//number of leafnodes.... 

/* Author Anubhav Vats */

#include<bits/stdc++.h>
using namespace std;
typedef vector<vector<int>> vii;
bool visit[100];

int leafnodes(vii& tree) {
    int node,cnt =0;
    stack<int> st;
    for(int x:tree[1]) st.push(x);
    visit[1] = 1;
    while (!st.empty()) {
        node = st.top();
        st.pop();
        if(!visit[node]) {
            visit[node] = 1;
            for(int x:tree[node]) st.push(x);
            if( tree[node].size() == 1 ) {
                cnt++;
            } 
        }
    }
    return cnt;
}

int main() {
    int n,a,b;
    cin >> n;
    vii tree(n+1);
    for(int i=0;i<n-1;i++) {
        cin >> a >> b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    cout << endl << leafnodes(tree) << endl;
    return 0;
}
