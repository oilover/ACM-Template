set cindent autoindent number sts=4 sw=4 ts=4 et
set backspace=indent,eol,start
syntax on

map <F6> : call CR()<CR>
func! CR()
    exec "w"
    exec "!g++ -O2 -std=c++11 % -o %<"
    exec "!./%<"
endfunc
	
map <F8> : call Java()<CR>
func! Java()
    exec "w"
    exec "!javac %"
    exec "!java %<"
endfunc 

map <F9> : call Python()<CR>
func! Python()
    exec "w"
    exec "!python %"
endfunc

map <F2> :call SetTitle()<CR>
func SetTitle()
let l = 0
let l = l + 1 | call setline(l,'/* ***********************************************')
let l = l + 1 | call setline(l,'Author        :oilover')
let l = l + 1 | call setline(l,'Created Time  :'.strftime('%c'))
let l = l + 1 | call setline(l,'File Name     :'.expand('%'))
let l = l + 1 | call setline(l,'************************************************ */')
let l = l + 1 | call setline(l,'')

let l = l + 1 | call setline(l,'#include <bits/stdc++.h>')
let l = l + 1 | call setline(l,'#define prt(k) cout<<#k" = "<<k<<endl')
let l = l + 1 | call setline(l,'typedef long long LL;')
let l = l + 1 | call setline(l,'void read(int &re) { scanf("%d", &re); }')
let l = l + 1 | call setline(l,'using namespace std;')
let l = l + 1 | call setline(l,'')
let l = l + 1 | call setline(l,'int main()')
let l = l + 1 | call setline(l,'{')
let l = l + 1 | call setline(l,'    ')
let l = l + 1 | call setline(l,'    return 0;')
let l = l + 1 | call setline(l,'}')
endfunc
