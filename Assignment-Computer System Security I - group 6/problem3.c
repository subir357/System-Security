/* program to write to a root owned file using the possibility of capability leak. Here we use the unclosed file descriptor.

we first create a file"imp" in etc folder using " sudo gedit /etc/imp " and save it with som initial text */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

int main(){
	int file_descriptor;
	char* v[2];
	file_descriptor= open("/etc/imp",O_RDWR | O_APPEND);
	// we check the value of the file descriptor, if it is -1 then open was unsuccessful 
	if( file_descriptor==-1){
		printf("\nThe file could not be opened\n");
		exit(0);
	}
	printf("\nThe value of the file descriptor is : %d\n", file_descriptor);
	
	//The program drops it privilege
	setuid(getuid());
	v[0]="/bin/sh"; 
	v[1]=0;
	
	//Executes the shell program
	//while in this shell, we can use the open file descriptor value to write to this file
	execve(v[0],v,0);
}

/* Instructions :

create the "imp" file in etc folder using :
$ sudo gedit /etc/imp
Enter the some text and save it

Then do :
$ls -l /etc/imp // to see that its owned by root and only writable by root
$cat /etc/imp   // to view the contents
$echo Can-I-Write-To-It? > /etc/imp   //try to write to this file. this attempt will fail

//Now we change the owner of this program to root and enable the set-uid bit
$gcc problem3.c -o problem3
$sudo chown root problem3
$sudo chmod 4755 problem3

$ls -l problem3   // check its owner and permissions

$./problem3   //run it
The value of the file descriptor is : 3  //output and you enter the shell program that is run within this program

//now once you're in the shell, try to write to the file
$ echo Now-I-Can-Write-To-It-Using-The-Open-File-Descriptor >& 3
$ exit  

//Now in the terminal check the content of the file

$ cat /etc/imp
This is an important system file owned by root 
Now-I-Can-Write-To-It-Using-The-Open-File-Descriptor     //write was successful     .............*/





	
