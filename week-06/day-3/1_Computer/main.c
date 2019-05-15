#include <stdio.h>
#include <stdint.h>

// Use the Computer struct, give values to the fields and print them out in the main!
// Use the Notebook struct, give values to the fields and print them out in the main!

struct Computer {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
} ;

typedef struct {
    float cpu_speed_GHz;
    int ram_size_GB;
    int bits;
} Notebook;

int main()
{
    struct Computer computer;
    computer.cpu_speed_GHz = 3.6;
    computer.ram_size_GB = 16;
    computer.bits = 64;

    Notebook notebook;
    notebook.cpu_speed_GHz = 2.8;
    notebook.ram_size_GB = 8;
    notebook.bits = 64;

    printf("Computer's CPU speed: %.2f GHz\n", computer.cpu_speed_GHz);
    printf("Computer's RAM size: %d GB\n", computer.ram_size_GB);
    printf("Computer's CPU type: %d bits\n", computer.bits);

    printf("Notebook's CPU speed: %.2f GHz\n", notebook.cpu_speed_GHz);
    printf("Notebook's RAM size: %d GB\n", notebook.ram_size_GB);
    printf("Notebook's CPU type: %d bits\n", notebook.bits);

    return 0;
}