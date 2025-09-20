" Enable line numbers
set number

" Use spaces instead of tabs
set expandtab

" Set the number of spaces for each tab
set tabstop=4
set shiftwidth=4
set softtabstop=4
set scrolloff=10

" Enable auto-indentation
set autoindent
set smartindent
set relativenumber

" Enable syntax highlighting
syntax on

set termguicolors

set background=dark
colorscheme rosepine_moon

set laststatus=2  " Always show the statusline

" Lightline basic config
let g:lightline = {
      \ 'colorscheme': 'wombat',
      \ }
let g:lightline = { 'colorscheme': 'rosepine_moon' }

filetype plugin indent on

" Toggle key to switch between custom and default bracket behavior
let g:bracket_toggle = 0

function! ToggleBrackets()
    if g:bracket_toggle == 0
        " Enable custom bracket behavior
        inoremap ( ()<Left>
        inoremap { {}<Left>
        inoremap [ []<Left>
        inoremap {<CR> {<CR>}<Esc>O
        inoremap ) <Right>
        inoremap } <Right>
        inoremap ] <Right>
        let g:bracket_toggle = 1
    else
        " Disable custom bracket behavior (restore default behavior)
        inoremap ( (
        inoremap { {
        inoremap [ [
        inoremap {<CR> {<CR>
        inoremap ) )
        inoremap } }
        inoremap ] ]
        let g:bracket_toggle = 0
    endif
endfunction

:call ToggleBrackets()
" Map F2 to toggle bracket behavior
nnoremap <F2> :call ToggleBrackets()<CR>
inoremap <F2> <Esc>:call ToggleBrackets()<CR>a

highlight Visual guifg=#3c3836 guibg=#ebdbb2

" Comment the selected lines with // and keep the selection
vnoremap <C-z> :s/^/\/\//<CR>gv
nnoremap <C-z> I//<Esc>

" Uncomment the selected lines by removing // and keep the selection
vnoremap <C-u> :s/^\/\///<CR>gv
nnoremap <C-u> ^xx

" Build command
nnoremap <F5> :w<CR>:!g++ -Dlocal % -o %:r <CR>
inoremap <F5> <Esc>:w<CR>:!g++ -Dlocal % -o %:r <CR>a

inoremap jj <Esc>

" Generate new cpp files with template
autocmd BufNewFile *.cpp 0r ~/Documents/Code/Online Submissions/Library/tp.cpp

" Map Ctrl-a to select all text in normal mode
nnoremap <C-a> ggVG

" Map Ctrl-c to copy selected text to clipboard in visual mode
vnoremap <C-c> "+y

