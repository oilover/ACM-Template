set cindent autoindent number sts=4 sw=4 ts=4 et
set backspace=indent,eol,start
colorscheme rainbow_neon
syntax on
set smarttab

set history=1000000
" 设置编辑时制表符占用空格数
set tabstop=4
" 设置格式化时制表符占用空格数
set shiftwidth=4
set smarttab
set cindent
set guifont=monaco

" 禁止光标闪烁
set gcr=a:block-blinkon0
" 禁止显示滚动条
set guioptions-=l
set guioptions-=L
set guioptions-=r
set guioptions-=R
" 禁止显示菜单和工具条
set guioptions-=m
set guioptions-=T

map <C-A> ggVG"+y
map <F6> :call CR()<CR>
func! CR()
exec "w"
exec "!g++ -std=c++11 -O2 -g  % -o %<"
exec "! %<"
endfunc
map <F8> :call JAVA()<CR>
func! JAVA()
exec "w"
exec "!javac %"
exec "!java %<"
endfunc
map <F9> :call Python()<CR>
func! Python()
	exec "w"
	exec "!python  % "
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
