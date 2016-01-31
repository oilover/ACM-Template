#include <bits/stdc++.h>
#define prt(k) cout<<#k" = "<<k<<endl
typedef long long LL;
void read(int &re) { scanf("%d", &re); }
using namespace std;
string s;
vector<int> LZW(string text)
{
    map<string, int> dict;
    vector<int> ret;
    for (int i=0;i<256;i++) dict[string(1,i)] = i;
    int p = 256;
    string s = "";
    for (char z : text) {
        string sz = s + string(1, z);
        if (dict.count(sz)) s = sz;
        else {
            ret.push_back(dict[s]);
            dict[sz] = p++;
            s = string(1, z);
        }
    }
    if (!s.empty()) ret.push_back(dict[s]);
    return ret;
}
string rLZW(vector<int> vec)
{
    int Size = 256;
    map<int, string> dict;
    for (int i=0;i<Size;i++) dict[i] = string(1, i);
    string ret = "", S, entry;
    Size--;
    for (int x : vec) {
        if (dict.count(x)) entry = dict[x];
        else {
            if (x == Size) entry = S + S[0];
            else throw "Bad compression code.";
        }
        ret += entry;
        dict[Size++] = S + entry[0];
        S = entry;
    }
    return ret;
}
int main()
{
    //freopen("b.txt", "w", stdout);
    s = "the/rain/in/Spain/falls/mainly/on/the/plain";
    vector<int> ret = LZW(s);
    for (int x:ret) printf("%d\n", x);
    cout<<rLZW(ret)<<endl;
}
