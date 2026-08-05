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

#define MAXINODE 10
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
//  Structure Name :    BootBlock
//  Description :       It holds the information to
//                      boot the operating system
//
//////////////////////////////////////////////////////////////////

struct BootBlock
{
    char Information[100];
};


//////////////////////////////////////////////////////////////////
//
//  Structure Name :    SuperBlock
//  Description :       It holds the information of
//                      complete file system
//
//////////////////////////////////////////////////////////////////

struct SuperBlock
{
    int TotalInodes;
    int FreeInodes;
};


//////////////////////////////////////////////////////////////////
//
//  Structure Name :    Inode
//  Description :       It holds the information of files
//
//////////////////////////////////////////////////////////////////

#pragma pack(1)
struct Inode
{
    char FileName[20];
    int InodeNumber;
    int FileSize;
    int ActualFileSize;
    int FileType;
    int ReferenceCount;
    int Permission;
    char *Buffer;
    struct Inode *next;
};

typedef struct Inode INODE;
typedef struct Inode* PINODE;
typedef struct Inode** PPINODE;


//////////////////////////////////////////////////////////////////
//
//  Structure Name :    FileTable
//  Description :       It holds the information of opned files
//
//////////////////////////////////////////////////////////////////

#pragma pack(1)
struct FileTable
{
    int ReadOffset;
    int WriteOffset;
    int Mode;
    PINODE ptrinode;
    
};

typedef struct FileTable FILETABLE;
typedef struct FileTable* PFILETABLE;


//////////////////////////////////////////////////////////////////
//
//  Structure Name :    UAREA
//  Description :       It holds the information of process
//
//////////////////////////////////////////////////////////////////

struct UAREA
{
    char ProcessName[20];
    PFILETABLE UFDT[MAXOPENFILES];
};


//////////////////////////////////////////////////////////////////
//
//  Global Varibles Used In Project
//
//////////////////////////////////////////////////////////////////

struct BootBlock bootobj;
struct SuperBlock superobj;
struct UAREA uareaobj;

PINODE head = NULL;


//////////////////////////////////////////////////////////////////
//
//  Function Name :     InitialiseUAERA
//  Description :       It is used to initilise UAREA
//  Author :            Anuraj Ramkrushna Ghawate
//  Date :              31/07/2026
//
//////////////////////////////////////////////////////////////////

void InitialiseUAREA()
{
    int i = 0;
    strcpy(uareaobj.ProcessName,"Myexe");

    for(i = 0; i < MAXOPENFILES; i++)
    {
        uareaobj.UFDT[i] = NULL;
    }

    printf("Marvellous CVFS : UAREA Gets Initilised Succesfully\n");
}


//////////////////////////////////////////////////////////////////
//
//  Function Name :     InitialiseSuperBlock
//  Description :       It is used to initilise Super Block
//  Author :            Anuraj Ramkrushna Ghawate
//  Date :              31/07/2026
//
//////////////////////////////////////////////////////////////////

void InitialiseSuperBlock()
{
    superobj.TotalInodes = MAXINODE;
    superobj.FreeInodes = MAXINODE;

    printf("Marvellous CVFS : Super Block Gets Initilised Succesfully\n");
}


//////////////////////////////////////////////////////////////////
//
//  Function Name :     CreateDILB()
//  Description :       It is used to create Linked List
//                      Of Inodes
//  Author :            Anuraj Ramkrushna Ghawate
//  Date :              31/07/2026
//
//////////////////////////////////////////////////////////////////

void CreateDILB()
{
   PINODE temp = NULL;
   PINODE newn = NULL;

   int i = 0;

   temp = head;

   for(i = 1; i <= MAXINODE; i++)
   {
        newn = (PINODE)malloc(sizeof(INODE));

        newn->InodeNumber = i;
        strcpy(newn->FileName,"\0");
        newn->FileSize = 0;
        newn->ActualFileSize = 0;
        newn->FileType = 0;
        newn->ReferenceCount = 0;
        newn->Permission = 0;
        newn->Buffer = NULL;
        
        if(temp == NULL)
        {
            head = newn;
            temp = head;
        }
        else
        {
            temp ->next = newn;
            temp = temp->next;
        }
   }

    printf("Marvellous CVFS : DILB Gets Created Succesfully\n");
}


//////////////////////////////////////////////////////////////////
//
//  Function Name :     StartAuxillaryDataInitialisation()
//  Description :       It is used to call all such funtions
//                      which are used to initialise Auxillary
//                      Data
//  Author :            Anuraj Ramkrushna Ghawate
//  Date :              31/07/2026
//
//////////////////////////////////////////////////////////////////

void StartAuxillaryDataInitialisation()
{
    strcpy(bootobj.Information,"Booting Of Marvellous CVFS Is Completed");
    printf("%s\n",bootobj.Information);

    InitialiseUAREA();
    InitialiseSuperBlock();
    CreateDILB();
}


//////////////////////////////////////////////////////////////////
//
//  Entry Point Function Of The CVFS Project
//
//////////////////////////////////////////////////////////////////

int main()
{
    StartAuxillaryDataInitialisation();

    return 0;
}