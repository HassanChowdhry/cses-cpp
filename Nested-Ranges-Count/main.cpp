#include <bits/stdc++.h>
# define ll long long
# define pb push_back
# define fs first 
# define sc second 
# define all(a) a.begin(),a.end()
# define flash ios_base::sync_with_stdio(false);cin.tie(NULL);
# define test int t;cin>>t;while(t--)
# define loop(n) for(int i=0;i<n;++i)
# define input(arr,n);for(int i=0;i<n;++i)cin>>arr[i];
# define nline "\n"
using namespace std;
int MOD=1000000007;
bool valid(int x,int y,int n,int m){return x>=0 && x<n && y>=0 && y<m;}
int powMod(int a,int n){ ll ans=1;for(int i=1;i<=n;i++){ ans=(ans*a)%MOD;}return ans%MOD; }


// ! Not Implemeneted
struct Interval {
  int start;
  int end;
  int index;

  bool operator<(const Interval &other) const {
    if (start != other.start) {
      return start < other.start;
    }
    if (end != other.end) {
      return end > other.end;
    }
    return index < other.index;
  }
};

void solve() {
  int n, s, e; cin >> n;
  vector<Interval> intervals(n); 
  vector<int> contains(n, 0), contained(n, 0);
  loop(n) 
    { cin >> s >> e; intervals[i].start = s; intervals[i].end = e; intervals[i].index = i; }
  sort(intervals.begin(), intervals.end());

  multiset<int> max_ends, min_ends;

  loop(n) {
    // bin search

    auto x = lower_bound(max_ends.begin(), max_ends.end(), intervals[i].end);
    cout << *x << nline;

    // if (intervals[i].end <= MAX_END) 
    //   { contained[intervals[i].index] = 1; }

    max_ends.insert(intervals[i].end);
  }


  for (int i = n-1; i >= 0; --i) {
    // bin search

    // if (intervals[i].end >= MIN_END) 
      // { contains[intervals[i].index] = 1; }

    min_ends.insert(intervals[i].end);
  }

  loop(n) { cout << contains[i] << " "; } cout << nline;
  loop(n) { cout << contained[i] << " "; } cout << nline;
}

int main() {
  flash
  solve();
  return 0;
}