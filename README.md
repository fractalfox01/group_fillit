# Fillit

<h2>A group project at 42:</h2>
<h3><i>Written By: <a href="https://github.com/katezhu">katezhu</a> and <a href="https://github.com/fractalfox01">Tommy V.</a></i></h3>
<h3>                          Using This Program:</h3>
 <p>
    <h4>First clone the repo:</h4>
    <pre>
    $> git clone https://github.com/fractalfox01/group_fillit.git fillit
    </pre>
    <h4>Change directory into your cloned directory</h4>
    <pre>
    $> cd filllit; ls
    libft/    author        fillit_utils.c  mapping.c
    tests/    backtrack.c   free_utils.c    solve.c
    Makefile  fillit.c      initialize.c    validate.c
    README.md fillit.h      main.c
    $>
    </pre>
    <h4>Compile the program and run against included tests ( Located in tests/      directory )</h4>
    <pre>
    $> make all
    $> compiling...
    $> ./fillit tests/valid2.fillit
    DDAA
    CDDA
    CCCA
    BBBB
    $>
    </pre>
    </pre>
 </p>
</pre>
<pre>
<p>
<h2>Intro - </h2>
Fillit is a project that let you discover and/or familiarize yourself with a recurring
  problematic in programming: searching the optimal solution among a huge set of 
  possibilities, in a respectable timing. In this particular project,
  you will have to find a way to assemble a given Tetriminos set altogether in the 
  smallest possible square.
  A Tetriminos is a 4-blocks geometric figure you probably already heard of, 
  thanks to the popular game Tetris.
</p>
<p>
<h2>
Goals:
</h2>
Fillit is not about recoding Tetris, even if it’s still a variant of this game. 
  Your program will take a file as parameter, which contains a list of Tetriminos, 
  and arrange them in order to create the smallest square possible.
  Obviously, your main goal is to find the smallest square in the minimal 
  amount of time, despite an exponentially growing number of possibilities each
  time a piece is added.
  You should think carefully about how you will structure your data and how to 
  solve this problem, if you want your program answers before the next millenium.
</p>
<p>
<h2>
General instructions
</h2>
• Your project must be written in C and must respect the Norme coding standard.
• The allowed functions are : exit, open, close, write, read, malloc and free.
• Your Makefile must compile your code without relinks.
• It must contain the following rules : all, clean ,fclean and re.
• You must compile your binary with the Wall, Wextra and Werror flags. Any other 
  flag are forbidden , especially those for optimising purposes.
• The binary must be named fillit and located in the root directory of your repository.
<pre>
$>cat -e author
xlogin$
ylogin$
</pre>
• You must submit a file called author containing your username followed by a ’\n’ 
    at the root of your repository:
• Your project cannot contain leaks.
</p>
<p>
<h2>Program entry - </h2>
Your executable must take only one parameter, a file which contains a list of 
Tetriminos to assemble. This file has a very specific format: 
every Tetrimino must exactly fit in a 4 by 4 chars square and all Tetrimino 
are separated by an newline each.
If the number of parameters sent to your executable is not 1, 
your program must display its usage and exit properly. If you don’t know 
what a usage is, execute the command cp without arguments in your Shell. 
It will give you an idea. Your file should contain between 1 and 26 Tetriminos.
The description of a Tetriminos must respect the following rules :
• Precisely 4 lines of 4 characters, each followed by a new line (well... a 4x4 square).
• A Tetrimino is a classic piece of Tetris composed of 4 blocks.
• Each character must be either a block character(’#’ ) or an empty character (’.’).
• Each block of a Tetrimino must touch at least one other block on any of his 
4 sides (up, down, left and right).
A few examples of valid descriptions of Tetriminos:
<pre>
....    ....    ####    ....    .##.    ....    .#..    ....    ....
..##    ....    ....    ....    ..##    .##.    ###.    ##..    .##.
..#.    ..##    ....    ##..    ....    ##..    ....    #...    ..#.
..#.    ..##    ....    ##..    ....    ....    ....    #...    ..#.
</pre>
A few examples of invalid descriptions of Tetriminos
<pre>
####    ...#    ##...   #.      ....    ..##    ####    ,,,,    .HH.
...#    ..#.    ##...   ##      ....    ....    ####    ####    HH..
....    .#..    ....    #.      ....    ....    ####    ,,,,    ....
....    #...    ....            ....    ##..    ####    ,,,,    ....
</pre>
Because each Tetrimino fills only 4 of the 16 available boxes, it is possible to 
describe the same Tetrimino in multiple ways. However, a rotated Tetrimino
describes a different Tetrimino from the original, in the case of this project. 
This means no rotation is possible on a Tetrimino, when you will arrange it with 
the others.Those Tetriminos are then perfectly equivalents on every aspect :
<pre>
##..    .##.    ..##    ....    ....    ....
#...    .#..    ..#.    ##..    .##.    ..##
#...    .#..    ..#.    #...    .#..    ..#.
....    ....    ....    #...    .#..    ..#.
</pre>
These 5 Tetriminos are, for their part, 5 distincts Tetriminos on every aspect :
<pre>
##..    .###    ....    ....    ....
#...    ...#    ...#    ....    .##.
#...    ....    ...#    #...    .##.
....    ....    ..##    ###.    ....
</pre>
Finally, here is an example of a valid file your program must resolve:
<pre>
$> cat -e valid_sample.fillit
...#$ 
...#$
...#$ 
...#$
$ 
....$
....$ 
....$
####$ 
$
.###$ 
...#$
....$ 
....$
$ 
....$
..##$ 
.##.$
....$ 
$>
</pre>
...and an example of invalid file your program must reject for multiple reasons:
<pre>
$> cat -e invalid_sample.fillit
...#$
...#$ 
...#$
...#$ 
....$
....$ 
....$
####$ 
$
$ 
.###$
...#$ 
....$
....$ 
$
....$ 
..##$
.##.$ 
....$
$>
</pre>
<p>
<h2>The smallest square</h2>
The goal of this project is to arrange every Tetriminos with each others in order 
to make the smallest possible square. But in some cases, this square should 
contains holes when some given pieces won’t fit in perfectly with others.
Even if they are embedded in a 4x4 square, each Tetrimino is defined by its 
minimal boundaries (their ’#’). The 12 remaining empty characters will be ignored 
for the Tetriminos assemble process.
Tetriminos are ordered by they apparition order in the file. Among all the 
possible candidates for the smallest square, we only accept the one where 
Tetriminos is placed on their most upper-left position.

__Example :__

Considering the two following Tetriminos (’#’ will be replaced by digits for 
understanding purposes):
<pre>
1...     ....
1...     ....
1... AND ..22
1...     ..22
</pre>
The smallest square you can make with those 2 pieces is 4-char wide, but there is 
many possible versions that you can see right below:
<pre>
a)      b)      c)      d)      e)      f)
122.    1.22    1...    1...    1...    1...
122.    1.22    122.    1.22    1...    1...
1...    1...    122.    1.22    122.    1.22
1...    1...    1...    1...    122.    1.22
g)      h)      i)      j)      k)      l)
.122    .1..    .1..    221.    ..1.    ..1.
.122    .122    .1..    221.    221.    ..1.
.1..    .122    .122    ..1.    221.    221.
.1..    .1..    .122    ..1.    ..1.    221.
m)      n)      o)      p)      q)      r)
22.1    .221    ...1    ...1    ...1    ...1
22.1    .221    22.1    .221    ...1    ...1
...1    ...1    22.1    .221    22.1    .221
...1    ...1    ...1    ...1    22.1    .221
</pre>
According to the rule above, the right solution is then a)
</p>
<p>
<h2>Program output -</h2>
Your program must display the smallest assembled square on the standard output. To 
identify each Tetrimino in the square solution, you will assign a capital letter 
to each Tetrimino, starting with ’A’ and increasing for each new Tetrimino.
If the file contains at least one error, your program must display error on the 
standard output followed by a newline and have to exit properly.

__Example :__

<pre>
$> cat sample.fillit | cat -e
....$
##..$ 
.#..$
.#..$ 
$
....$ 
####$
....$ 
....$
$ 
#...$
###.$ 
....$
....$ 
$ 
....$
##..$ 
.##.$
....$
$> ./fillit sample.fillit | cat -e
DDAA$ 
CDDA$
CCCA$ 
BBBB$
$>
</pre>

__Another example :__

<pre>
$> cat sample.fillit | cat -e
....$
....$ 
####$
....$ 
$
....$ 
...$
..##$ 
..##$
$> ./fillit sample.fillit | cat -e
error$
$>
</pre>

__Last Example :__

<pre>
$> cat sample.fillit | cat -e
...#$
...#$ 
...#$
...#$ 
$
....$ 
....$
....$ 
####$
$ 
.###$
...#$ 
....$
....$ 
$
....$ 
..##$
.##.$ 
....$
$ 
....$
.##.$ 
.##.$
....$ 
$
....$ 
....$
##..$ 
.##.$
$ 
##..$
.#..$ 
.#..$
....$ 
$
....$ 
###.$
.#..$ 
....$
$> ./fillit sample.fillit | cat -e
ABBBB.$
ACCCEE$
AFFCEE$
A.FFGG$
HHHDDG$
.HDD.G$ 
$>
</pre>
</p>
</p>
