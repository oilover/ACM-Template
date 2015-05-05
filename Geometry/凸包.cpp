// 点集凸包
// 如果不希望在凸包的边上有输入点,把两个 <= 改成 <
// 注意:输入点集会被修改
vector<Point> CovexHull(vector<Point>& p)
{
  sort(p.begin(),p.end());
  p.erase(unique(p.begin(),p.end()),p.end());
  int n=p.size();
  int m=0;
  vector<Point> ch(n+1);
  for(int i=0;i<n;i++)
    {
      while(m>1&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
      ch[m++]=p[i];
    }
  int k=m;
  for(int i=n-2;i>=0;i--)
    {
      while(m>k&&Cross(ch[m-1]-ch[m-2],p[i]-ch[m-2])<=0) m--;
      ch[m++]=p[i];
    }
  if(n>1) m--;
  ch.resize(m);
  return ch;
}
bool In(vector<P> p, P b)  /// 是否在凸包边界或者内部
{
	int n = p.size();
	int sign = 0;
	for (int i=0;i<n;i++) {
		int x = cmp(det(p[i] - b, p[(i+1)%n] - b) );
		if (x) {
			if (sign==0) sign = x;
			else if (sign - x)  return false;
		}
	}
	return true;
}
bool On(vector<P> p, P b)  /// 是否在凸包边界上
{
	int n = p.size();
	for (int i=0;i<n;i++) {
		int x = cmp(det(p[i] - b, p[(i+1)%n] - b) );
		if (x==0) return true;
	}
	return false;
}
