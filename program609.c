//////////////////////////////////////////////////////////////////
//
//  Header Files Inclusion
//
//////////////////////////////////////////////////////////////////

#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<stdbool.h>


//////////////////////////////////////////////////////////////////
//
// User Defined Macros
//
//////////////////////////////////////////////////////////////////

#define MAXFILESIZE 50
#define MAXOPENFILES 10

#define READ 1
#define WRITE 2
#define EXECUTE 4

#define START 0
#define CURRENT 1
#define END 2

#define EXECUTE_SUCCESS 0

#define REGULARFILE 1
#define SPECIALFILE 2



//////////////////////////////////////////////////////////////////
//
// User Defined Macros For Error Handling
//
//////////////////////////////////////////////////////////////////

#define ERR_INVALID_PARAMETER -1

#define ERR_NO_INODES -2

#define ERR_FILE_ALREADY_EXIST -3
#define ERR_FILE_NOT_EXIST -4

#define ERR_PERMISSION_DENIED -5

#define ERR_INSUFFICIENT_SPACE -6

#define ERR_INSUFFICIENT_DATA -7

#define ERR_MAX_FILES_OPEN -8



//////////////////////////////////////////////////////////////////
//
//  Entry Point Function Of The CVFS Project
//
//////////////////////////////////////////////////////////////////

int main()
{


    return 0;
}