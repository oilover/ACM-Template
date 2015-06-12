set tabstop=4
set nu
set cindent
set shiftwidth=4

map <C-A> ggVG"+y
map <F9> : call Run()<CR>
func! Run()
	exec "w"  
	exec "!g++ % -o %<"  
	exec "!./%<" 
endfunc
