//Zombie state when child dies before parrent

#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>



int main(){
    int cpid=fork();
    if(cpid==0){
        exit(0);
    }
    else{
        // printf("Main process id %d",getpid());
        sleep(50);
    }


    return 0;
}
/**
 * In proc directory
 Name:	a.out
State:	Z (zombie)
Tgid:	17967
Ngid:	0
Pid:	17967
PPid:	17966
TracerPid:	0
Uid:	1000	1000	1000	1000
Gid:	1000	1000	1000	1000
FDSize:	0
Groups:	4 24 27 30 46 113 128 1000 
NStgid:	17967
NSpid:	17967
NSpgid:	17966
NSsid:	11974
Threads:	1
SigQ:	2/14406
SigPnd:	0000000000000000
ShdPnd:	0000000000000000
SigBlk:	0000000000000000
SigIgn:	0000000000000000
SigCgt:	0000000000000000
CapInh:	0000000000000000
CapPrm:	0000000000000000
CapEff:	0000000000000000
CapBnd:	0000003fffffffff
CapAmb:	0000000000000000
Seccomp:	0
Cpus_allowed:	ff
Cpus_allowed_list:	0-7
Mems_allowed:	00000000,00000001
Mems_allowed_list:	0
voluntary_ctxt_switches:	1
nonvoluntary_ctxt_switches:	0

 **/





