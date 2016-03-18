#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <assert.h>
#define prt(k) cout<<#k" = "<<k<<endl
typedef long long LL;
using namespace std;
typedef unsigned long long uint64_t;
typedef unsigned long long uint64;
typedef unsigned long long uint;

vector<uint> RC4(vector<uint> K, int len) //生成密钥流
{
	uint S[333], T[456];
	vector<uint> keystream;
	int keylen = K.size();
	for (int i = 0; i < 256; i++) {
		S[i] = i;
		T[i] = K[i % keylen];
	}
	int j = 0;
	for (int i = 0; i < 255; i++) {
		j = (j + S[i] + T[i]) & 255;
		swap(S[i], S[j]);
	}
	int i = 0;
	for (int r = 0; r < len; r++) {
		i = (i + 1) % 256;
		j = (j + S[i]) % 256;
		swap(S[i], S[j]);
		int t = (S[i] + S[j]) % 256;
		keystream.push_back(S[t]);
	}
	return keystream;
}

vector<uint> RC4(string s, int len)
{
	vector<uint> t;
	for (char c : s) t.push_back(uint(c));
	return RC4(t, len);
}
