#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <chrono>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using namespace std::chrono;

#ifdef local
#include "../Library/debug.h"
#else
#define db(...) 42
#endif

#define pb push_back
#define pf(x, y) (x).insert((x).begin(), y) 
#define int long long
#define nosync() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) ((int)(x).size())
#define duck cerr << "Duck " << __LINE__ << endl;
#define __ << ' ' <<
#define endl '\n'
#define mp make_pair
#define f first
#define s second
#define cyn(x) cout << (x ? "YES" : "NO") << endl;

using str = string;
using pi = pair<int, int>;
using vi = vector<int>;
using vs = vector<str>;
using vpi = vector<pi>;
using si = set<int>;
using mi = map<int, int>;
using mc = map<char, int>;
using ms = map<str, int>;

void init()
{
    fclose(fopen("output.txt", "w"));
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "a", stdout);
    freopen("output.txt", "a", stderr);
}

void usaco(string filename) {
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
}

#define rep1(n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 0; i < (int)(n); i++)
#define rep3(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep4(i, a, b, c) for (int i = (int)(a); i < (int)(b); i += (int)(c))
#define cut4(a, b, c, d, e, ...) e
#define rep(...) cut4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)
#define per1(n) for (int i = ((int)n) - 1; i >= 0; i--)
#define per2(i, n) for (int i = ((int)n) - 1; i >= 0; i--)
#define per3(i, a, b) for (int i = ((int)a) - 1; i >= (int)(b); i--)
#define per4(i, a, b, c) for (int i = ((int)a) - 1; i >= (int)(b); i -= (int)(c))
#define per(...) cut4(__VA_ARGS__, per4, per3, per2, per1)(__VA_ARGS__)

template<typename T, typename S>
ostream& operator << (ostream& out, const pair<T, S>& p) {
    out << p.first << " " << p.second;
    return out;
}

template<typename T, typename S>
istream& operator >> (istream& in, pair<T, S>& p) {
    in >> p.first >> p.second;
    return in;
}

template<typename T>
istream& operator >> (istream& in, vector<T>& v) {
    for (auto& x : v) {
        in >> x;
    }
    return in;
}

template<typename T, typename S> 
pair<T,S> operator + (const pair<T,S> &a, const pair<T,S> &b) {
    return {a.first + b.first, a.second + b.second};
}

template<typename T> 
vector<T> operator += (vector<T> &a, int val) {
    for (auto &i: a) i += val; 
    return a;
}

istream& operator>>(istream& is, __int128 &x) {
    string s;
    is >> s;

    x = 0;
    bool neg = false;
    size_t i = 0;
    if (s[0] == '-') {
        neg = true;
        i = 1;
    }

    for (; i < s.size(); i++)
        x = x * 10 + (s[i] - '0');

    if (neg) x = -x;
    return is;
}

ostream& operator<<(ostream& os, __int128 x) {
    if (x == 0) return os << '0';
    if (x < 0) {
        os << '-';
        x = -x;
    }

    string s;
    while (x > 0) {
        s += '0' + (x % 10);
        x /= 10;
    }
    reverse(s.begin(), s.end());
    return os << s;
}

template<typename T> 
void print(const vector<T> x) { for(auto i: x) { cout << i << ' ';} cout << endl; }

template<typename T> 
void print(const set<T> x) { for(auto i: x) { cout << i << ' ';} cout << endl; }

template<typename T, typename S> 
void print(const map<T, S> x) { for(auto i: x) { cout << i << endl;} cout << endl; }


template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using ordered_set_inv = tree<T, null_type, greater<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T, typename S> 
constexpr bool chmin(T &a, const S b) { return b < a ? a = b, true : false; }

template<typename T, typename S> 
constexpr bool chmax(T &a, const S b) { return b > a ? a = b, true : false; }

template<typename T, typename S> 
constexpr T ifloor(const T a, const S b) { return a / b - (a % b && (a ^ b) < 0); }

template<typename T, typename S> 
constexpr T iceil(const T a, const S b) { return ifloor(a + b - 1, b); }

const int N    = 200000 + 5;
const int INF  = 1'000'000'000'000'000'000;
const int MOD  = 1'000'000'000 + 7; //998244353;
const int dx[] = {0, -1, 0, 1, -1, -1, 1, 1};
const int dy[] = {1, 0, -1, 0, 1, -1, -1, 1};

void solve(int tc) {
}

signed main() 
{
    nosync();
	
    #ifdef combinator 
        precompute();
    #endif
	
    #ifdef local
        //init();
        auto start = high_resolution_clock::now();
    #else
        #define cerr if(false) cerr
        //usaco("task_name");
    #endif	
	
    int t = 1;
    cin >> t;
    for (int c = 1; c <= t; c++) {
        cerr << "Case " << c << ":\n";
        solve(c); 
    }
	
    #ifdef local
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        cerr << "Execution time: " << duration.count() << " ms" << endl;
    #endif

    return 0;
}
