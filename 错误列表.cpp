http://blog.csdn.net/oilover/article/details/45335531
HDU 1011 Starship Troopers
没有bug的房间也要派一个trooper占领
当m为0时，没有trooper，不能占领任何房间，输出0

GCJ 2015 Round 1B A. Counter Culture
http://blog.csdn.net/oilover/article/details/45486047
当这题不知道怎么做时，可以记录路径，输出最短路径上的数什么时候翻转，就找到规律了。。

(13杭州)
ftiasch on November 15, 2013 at 11:58 pm said:
K的主要问题是fb太晚，导致大家都没有发现这个大水题……
这种情况我感觉还是挺常见的，所以比赛的时候应该有个人对现在的题目状况（过了什么题，
还有什么题，什么题有算法，什么题有想法etc）有所把握，就能减少这种情况发生了。

又想起上一年final回来，shi哥他们说的，每道题写之前如果不是很水，至少两个人知道算法和题目。
如果没有这么做，WA了后20分钟或者花了好久写的还不清不楚的，再没人讨论基本就注定悲剧了。

 GCJ 2015 Round 1A C. Logging
 http://blog.csdn.net/oilover/article/details/45560057
 极角排序时，注意精度，最好用long double保存极角，eps设小一些，如1e-15
 
 极角排序后扫描线，这样把一个圆圈上的点转化为一条直线上的点：
 for(int i=0; i<an; i++)
     a[i + an] = a[i] + 2 * PI;
其实很多与环有关的题目，都可以这样转换。
如这题，把环状的区间DP转化为链上的区间DP：
http://blog.csdn.net/oilover/article/details/41251555
atan2的范围是(-π, π]

取模时不能直接写(a-b)%mod, 应该写(a-b+mod)%mod。
还有两个long long 直接相乘会爆，最好这样：
ll mul(ll a, ll n, ll m)
{
    ll r = 0;
    for (; n>0; n>>=1,a=(a+a)%m) if(n&1) r = (r + a) % m;
    return r;
}
DP可以正推和倒推，有时候一种不行可以换另一种（有可能有很多组数据）。
注意编译开C++ 11和-Wall（防止函数没有return）
