#include <stdio.h>
#include <stdlib.h>

#include "commands.h"

int main(int argc, char *argv[])
{
    if (argc < 4)
    {
        fprintf(stderr,
                "Usage:\n"
                "  %s 1 <input> <output>   Encode\n"
                "  %s 2 <input> dummy      Read header\n"
                "  %s 3 <input> <output>   Decode\n",
                argv[0],
                argv[0],
                argv[0]);

        return 1;
    }

    int mode = atoi(argv[1]);

    switch (mode)
    {
    case 1:
        return encode_command(argv[2], argv[3]);
        break;
    case 2:
        read_command(argv[2]);
        break;
    case 3:
        decode_command(argv[2], argv[3]);
        break;
    default:
        fprintf(stderr, "Invalid mode.\n");
        return 1;
    }

    return 0;
}