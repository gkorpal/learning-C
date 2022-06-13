My C practice codes from the CSC 352 course (Systems Programming) taught by Ashiq Rahman during Summer 2021 (graduate @ UArizona).

All the codes were tested on Ubuntu 14.04 server ([gcc 4.8.4](https://gcc.gnu.org/onlinedocs/gcc-4.8.4/gcc/)) & openSUSE Leap 15.3 KDE ([gcc 7.5.0](https://gcc.gnu.org/onlinedocs/gcc-7.5.0/gcc/)) using:

`````shell
$ gcc -std=c99 -Wall -o program program.c
`````

Note that [UNIX is an IDE](https://blog.sanctum.geek.nz/series/unix-as-ide/), therefore, we will just need the following tools along with a graphical terminal emulator running [GNU Bash](https://www.gnu.org/software/bash/) shell to create C programs:

| Purpose | Program | Linux package name | 
|---------| ------- | ------------ |
| Text editor within Terminal with syntax highlighting| [Vim](https://www.vim.org/) | `vim` | 
| Compiler and code coverage [`gcov`](https://gcc.gnu.org/onlinedocs/gcc/Gcov.html) | [GNU Compiler Collection (GCC)](https://gcc.gnu.org/) | `gcc`|
| Build-automation utility | [GNU Make](https://www.gnu.org/software/make/) | `make` |
| Terminal multiplexer | [tmux](https://github.com/tmux/tmux/wiki) | `tmux` | 
| Debugger | [GNU Project Debugger (GDB)](https://www.gnu.org/software/gdb/) | `gdb` |
| Memory error detector | [Valgrind Memcheck](https://valgrind.org/docs/manual/quick-start.html) | `valgrind` |
| Source code package portability | [GNU Autotools](https://www.gnu.org/software/automake/faq/autotools-faq.html) ([Autoconf](https://www.gnu.org/software/autoconf/autoconf.html) and [Automake](https://www.gnu.org/software/automake/)) | `autoconf` and `automake`|
| Source Control Management (Version control system)| [Git](https://git-scm.com/) | `git` |

The reference texts (click on the images to visit their websites):

<p>
<center>
    <a href="http://knking.com/books/c2/index.html">
     <img alt="matplot" src="https://gkorpal.github.io/images/king.jpg"
       width="210" height="300" class="center">
  </a>
  <a href="http://csapp.cs.cmu.edu/3e/home.html">
     <img alt="hands-on" src="https://gkorpal.github.io/images/bryant.jpg"
       width="210" height="300" class="center">
  </a>
   </center>
 </p>

**Equivalent course:** [CS61C @ UCBerkeley](https://inst.eecs.berkeley.edu/~cs61c/archives.html). For example, Spring 2015 [videos](https://archive.org/details/ucberkeley-webcast-PL-XXv-cvA_iCl2-D-FS5mk0jFF6cYSJs_) and [notes](https://inst.eecs.berkeley.edu/~cs61c/sp15/).
