#ifndef PERROQUET_H
#define PERROQUET_H

void loadPerroquet(char *perroquet, int long_max);
void encryptText(const char *perroquet, const char *source_name, const char *dest_name);
void removeSourceFile();

#endif
