// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <openssl/hmac.h>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
#include <assert.h>
typedef unsigned long long uint;
#define prt(k) cout<<#k" = "<<k<<endl
typedef long long LL;
using namespace std;

typedef unsigned long long uint;
//#include "HMAC.h"
#include "LZW_encipher.h"
#include <openssl/ssl.h>
#include <openssl/rc4.h>
#include "LZW_decipher.h"
int main()
{
	string text, key;
	unsigned char *mac = NULL; unsigned int len;
	text = "message"; key = "password";
	auto t = LZW_encipher("text");
	cout << "Result:\n";
	for (auto x : t) cout << x << endl;
	auto ret = LZW_decipher(t);
	cout << "decrypt:\n";
	cout << ret << endl;
	/**HMAC(text, key, mac, len);
	prt(len); //prt(strlen(mac));
	for (int i = 0; mac[i]; i++) printf("%5d", mac[i]); cout << endl;
	return 0;
	//auto ret = RC4_PRBS("key", 10);
	//for (auto x : ret) printf("%I64u ", x); cout << endl;
	char code[64] = { 0 };
	cout << "before encrypt :" << code << endl;
	unsigned char *outbuffer = new unsigned char[sizeof(code)];
	RC4_KEY rc4_key;
	RC4_set_key(&rc4_key, 3, (unsigned char *)"key");
	RC4(&rc4_key, sizeof(code), (unsigned char *)code, outbuffer);
	cout << "after encrypt :\n";  
	for (int i = 0; i < 64; i++) printf("%u ", outbuffer[i]);  */
    return 0;
}

