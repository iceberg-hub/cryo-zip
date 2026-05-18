#ifndef COMMANDS_H
#define COMMANDS_H

int encode_command(const char *input_path, const char *output_path);
int read_command(const char *input_path);
int decode_command(const char *input_path, const char *output_path);

#endif