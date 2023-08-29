#ifndef PERROQ_H_INCLUDED
#define PERROQ_H_INCLUDED

void enreg_perroquet(const char *perroquet);
void loadPerroquet(char *perroquet, int long_max);
void chiffr_text(char *text, const char *perroquet);
int chiffr_file(const char *perroquet, const char *source_name, const char *dest_name);
void supp_file();



#endif // PERROQ_H_INCLUDED
