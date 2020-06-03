#include <stdio.h>
#include <stdlib.h>

// given default values
#define MAX_DATA_STACK_HEIGHT 1000;
#define MAX_CODE_LENGTH 500;

struct instruct{
    int op; // opcode
    int  l; // L lexigraphical level
    int  m; // M
}instruct;

FILE *openFile(char fileName[], char mode[], FILE *fp)
{
    fp=fopen(fileName, mode);
    if(fp==NULL)
    {
        printf("Could not open %s\n", fileName);
        exit(0);
    }
    printf("file opened\n");
    return fp;
}

int main()
{
    // CPU Register
    int SP = MAX_DATA_STACK_HEIGHT;
    int BP = SP - 1;
    int PC = 0;
    int IR = 0;


    FILE *fp;

    // remember to keep "input.txt" in the same file as the main c file
    fp=openFile("input.txt", "r", fp);

    struct instruct stack[20]; // 20 is a place holder size, I aught to make it dynamic later

    // scan in and print out what has just been scanned
    // again, this is only hard coded because I don't want to figure out the dynamic at this moment
    fscanf(fp, "%d %d %d", &stack[0].op, &stack[0].l, &stack[0].m);
    printf("%d %d %d\n", stack[0].op, stack[0].l, stack[0].m);

    fscanf(fp, "%d %d %d", &stack[1].op, &stack[1].l, &stack[1].m);
    printf("%d %d %d\n", stack[1].op, stack[1].l, stack[1].m);

    fscanf(fp, "%d %d %d", &stack[2].op, &stack[2].l, &stack[2].m);
    printf("%d %d %d\n", stack[2].op, stack[2].l, stack[2].m);

    switch(stack[0].op)
    {
        case 1:
            // LIT	0, M	Push constant value (literal) M onto the stack
            break;
        case 2:
            // OPR	0, M	Operation to be performed on the data at the top of the stack
            break;
        case 3:
            // LOD	L, M	Load value to top of stack from the stack location at offset M from
            // L lexicographical levels down
            break;
        case 4:
            // STO	L, M	Store value at top of stack in the stack location at offset M from
            // L lexicographical levels down
            break;
        case 5:
            // CAL	L, M	Call procedure at code index M (generates new Activation Record
            // and pc <- M)
            break;
        case 6:
            // INC	0, M	Allocate M locals (increment sp by M). First three are Static Link
            // (SL), Dynamic Link (DL), and Return Address (RA)
            break;
        case 7:
            // JMP	0, M	Jump to instruction M
            break;
        case 8:
            // JPC	0, M	Jump to instruction M if top stack element is 0
            break;
        case 9:
            // SIO	0, 1	Write the top stack element to the screen
            break;
        case 10:
            // SIO	0, 2	Read in input from the user and store it on top of the stack.
            break;
        case 11:
            // SIO	0, 3	End of Program.
            break;
        default:
            // some default/err case
            break;

    }



    close(fp);
    return 0;
}
