#ifndef COMMANDS_H
#define COMMANDS_H

int encode_command(const char *input_path, const char *output_path);
void read_command(const char *input_path);
void decode_command(const char *input_path, const char *output_path);

#endif