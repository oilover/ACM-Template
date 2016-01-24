set tabstop=4
set nu
set cindent
set shiftwidth=4

map <C-A> ggVG"+y  ///现场赛提交文件的话不需要
map <F9> : call Run()<CR>
func! Run()
	exec "w"  
	exec "!g++ % -o %<"  
	exec "!./%<" 
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
