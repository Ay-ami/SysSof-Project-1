#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// given default values
#define MAX_DATA_STACK_HEIGHT 1000;
#define MAX_CODE_LENGTH 500;

struct instruct{
    int OP; // opcode
    int  L; // L lexigraphical level
    int  M; // M
}instruct;

// opens the file
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

// returns the number of lines in the input file,
int countLines(FILE *fp)
{
    int count = 0;
    int temp;

    while(!feof(fp))
    {
    // stores entire row made up of 3 integers into a temp variable to keep track of position
      fscanf(fp, "%d %d %d", &temp, &temp, &temp);
      count++;
    }
    // send file pointer back at the start so we can read it again
    rewind(fp);
    return count;
}

// crates a string of interpreted assembly language with line number
char *interpertOP(int op)
{
    // where a, b, and c are the read integers
    // line, OP, L, M
    char *OP = (char *)malloc(3);
    switch (op)
    {
        case 1:
            strcpy(OP, "LIT");
            break;
        case 2:
            strcpy(OP, "OPR");
            break;
        case 3:
            strcpy(OP, "LOD");
            break;
        case 4:
            strcpy(OP, "STO");
            break;
        case 5:
            strcpy(OP, "CAL");
            break;
        case 6:
            strcpy(OP, "INC");
            break;
        case 7:
            strcpy(OP, "JMP");
            break;
        case 8:
            strcpy(OP, "JPC");
            break;
        case 9:
            strcpy(OP, "SIO");
            break;
        case 10:
            strcpy(OP, "SIO");
            break;
        case 11:
            strcpy(OP, "SIO");
            break;
        default:
            // some default/err case
            break;
    }
    return OP;
}

void output1(struct instruct ir[], int size)
{
    FILE *fpw = openFile("output1.txt", "w", fpw);

    fprintf(fpw, "Line, OP, L, M \n");

    for (int i = 0; i<size; i++)
    {
        fprintf(fpw, "%3d ", i);
        fprintf(fpw, "  %s ", interpertOP(ir[i].OP));
        fprintf(fpw, "%d ", ir[i].L);
        fprintf(fpw, "%d \n", ir[i].M);
    }

}
int main()
{
    // CPU Register
    int SP = MAX_DATA_STACK_HEIGHT;
    int BP = SP - 1;
    int PC = 0;
    //int IR = 0;
    int Hault = 1;

    FILE *fp;
    fp=openFile("input.txt", "r", fp);// remember to keep "input.txt" in the same file as the main c file so that the compiler can find it


    // determining the total number of instructions
    int num = countLines(fp); //num = number of instructions

    // Building and filling out the struct array
    struct instruct IR[num];
    int count = 0;
    while(!feof(fp)) // "while not at the end of the file"
    {
      fscanf(fp, "%d %d %d", &IR[count].OP, &IR[count].L, &IR[count].M); // "scan in 3 numbers per line"
      count++;
    }

    // print output1 based on the now built IR array
    output1(IR, num);


    /* switch skeleton
    switch(IR[0].OP)
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
*/

    fclose(fp);
    return 0;
}
