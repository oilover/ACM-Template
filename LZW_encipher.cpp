#include <vector>
#include <algorithm>
#include <iostream>
#include <string>
#include <cstdio>
#include <assert.h>
#include<set>
#include <cmath>
#define prt(k) cout<<#k" = "<<k<<endl
typedef long long LL;
using namespace std;
typedef unsigned long long uint;
#include "RC4_PRBS.h"
#include "add_dict_entry.h"
#include "bit2num.h"
#include "get_dict_index.h"
#include "permute_dict.h"
vector<uint> LZW_encipher(string S, string key = "password", int b = 12, set<char> A = set<char>())
{
	vector<uint> B,K;
	int b_2 = b / 2;
	int N = 1 << b;  prt(S);  prt(N);
	int M = 1<<(b/2);
	if (A.empty()) {
		for (int i=0;i<=126;i++) A.insert(char(i));
		//for (auto x:S) A.insert(x);
	}
	//int A_n = A.size();
	int S_n = S.size();
	vector<string> dict;
	dict.resize(1<<b);
	for (auto x : A) 
	{
		string word(1, x);
		(add_dict_entry(dict, word, key, b));
	}
	vector<uint> PRBS = RC4_PRBS(key, S_n * 5 * b);
	vector<uint> PRNS = bit2num(PRBS, b_2);
	//for (int i = 0; i < min((int)PRNS.size(), 5); i++) prt(PRNS[i]);
	int S_i = 0;
	int PRNS_i = 0;
	string I = "";
	for (auto x: S) {
		string Ix = I + string(1, x);
		int id = get_dict_index(Ix, dict);
		if (id != -1) I = Ix;
		else {
			B.push_back(get_dict_index(I, dict));
			uint high = PRNS[PRNS_i++];
			uint low = PRNS[PRNS_i++];
			K.push_back(high << b_2 | low);
			B[B.size() - 1] ^= K[K.size() - 1];
			int ret = add_dict_entry(dict, Ix, key, b);
			int c1, c2, r1, r2;
			c1 = PRNS[PRNS_i++];
			c2 = PRNS[PRNS_i++];
			r1 = PRNS[PRNS_i++];
			r2 = PRNS[PRNS_i++];
			if (ret == -2) {  // 如果字典满了，我们就清空词典
				for (auto &tmp : dict) tmp = "";
			}
			else permute_dict(dict, c1, c2, r1, r2);	
			I = string(1, x);
		}
	}
	if (I != "") {
		auto tmp = get_dict_index(I, dict);
		B.push_back(tmp);
		uint high = PRNS[PRNS_i++];
		uint low = PRNS[PRNS_i++];
		K.push_back(high << b_2 | low);
		B[B.size() - 1] ^= K[K.size() - 1];
	}
	return B;
}
