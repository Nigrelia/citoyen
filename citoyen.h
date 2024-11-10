#ifndef CITOYEN_H_INCLUDED
#define CITOYEN_H_INCLUDED

typedef struct
{
int j;
int m;
int a;
}date;


typedef struct
{
char id_c[20];
char nom_c[20];
char prenom_c[20];
char sexe_c[20];
char contact_c[20];
char mot_c[20];
char ville_c[20];
date date_nai;
}citoyen;

void saisir_citoyen(citoyen *c);
void ajout_citoyen(citoyen *c,char *citoyens);
void affichage_citoyen(char *citoyens,char *login,citoyen *c);
void mod_citoyen(char *citoyens,char *t_citoyens,char *login,citoyen *c);
void supp_citoyen(char *citoyens,char *t_citoyens,char *login,citoyen *c);










































#endif
