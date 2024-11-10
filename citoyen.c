#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "citoyen.h"

void saisir_citoyen(citoyen *c)
{
printf("donner votre id\n");
scanf("%s",c->id_c);
printf("donner votre nom\n");
scanf("%s",c->nom_c);
printf("donner votre prenom\n");
scanf("%s",c->prenom_c);
printf("donner votre sexe\n");
scanf("%s",c->sexe_c);
printf("donner votre contact\n");
scanf("%s",c->contact_c);
printf("donner votre mot de passe\n");
scanf("%s",c->mot_c);
printf("donner votre ville\n");
scanf("%s",c->ville_c);
printf("donner votre date de naissance (jour,mois,annee)\n");
scanf("%d %d %d",&c->date_nai.j,&c->date_nai.m,&c->date_nai.a);
}

void ajout_citoyen(citoyen *c,char *citoyens)
{
citoyen c1;
int trouve=0;
FILE *f=fopen(citoyens,"a+");
if(f==NULL)
{
printf("error\n");
return;
}
saisir_citoyen(&c1);

while(fscanf(f,"%s %s %s %s %s %s %s %d %d %d",c->id_c,c->nom_c,c->prenom_c,c->sexe_c,c->contact_c,c->mot_c,c->ville_c,&c->date_nai.j,&c->date_nai.m,&c->date_nai.a)!=EOF)
{
if(strcmp(c->id_c,c1.id_c)==0)
{
trouve=1;
}
}
if(trouve==1)
{
printf("l'id deja existe \n");
}
else
{
fprintf(f,"%s %s %s %s %s %s %s %d %d %d \n",c1.id_c,c1.nom_c,c1.prenom_c,c1.sexe_c,c1.contact_c,c1.mot_c,c1.ville_c,c1.date_nai.j,c1.date_nai.m,c1.date_nai.a);
printf("inscription avec succee\n");
}
}

void affichage_citoyen(char *citoyens,char *login,citoyen *c)
{
FILE *f=fopen(citoyens,"r");
if(f==NULL)
{
printf("error\n");
return;
}
while(fscanf(f,"%s %s %s %s %s %s %s %d %d %d",c->id_c,c->nom_c,c->prenom_c,c->sexe_c,c->contact_c,c->mot_c,c->ville_c,&c->date_nai.j,&c->date_nai.m,&c->date_nai.a)!=EOF)
{
if(strcmp(c->id_c,login)==0)
{
printf(" id: %s nom: %s prenom: %s sexe: %s contact :%s mot de passe :%s ville: %s jour: %d mois: %d annee: %d \n",c->id_c,c->nom_c,c->prenom_c,c->sexe_c,c->contact_c,c->mot_c,c->ville_c,c->date_nai.j,c->date_nai.m,c->date_nai.a);
}
}
}
void mod_citoyen(char *citoyens,char *t_citoyens,char *login,citoyen *c)
{
int p;
FILE *f=fopen(citoyens,"r");
if(f==NULL)
{
printf("error\n");
return;
}
FILE *f1=fopen(t_citoyens,"w");
if(f1==NULL)
{
printf("error\n");
return;
}
while(fscanf(f,"%s %s %s %s %s %s %s %d %d %d",c->id_c,c->nom_c,c->prenom_c,c->sexe_c,c->contact_c,c->mot_c,c->ville_c,&c->date_nai.j,&c->date_nai.m,&c->date_nai.a)!=EOF)
{
if(strcmp(login,c->id_c)==0)
{
printf("donner le champs a modifier \n");
printf("1-Nom \n");
printf("2-Prenom \n");
printf("3-sexe \n");
printf("4-contact \n");
printf("5-mot de passe \n");
printf("6-ville \n");
printf("7-date de naissance \n");
scanf("%d",&p);
switch(p)
{
case 1:
printf("saisir la modification du nom \n");
scanf("%s",c->nom_c);
break;
case 2:
printf("saisir la modification du prénom \n");
scanf("%s",c->prenom_c);
break;
case 3:
printf("saisir la modification du sexe \n");
scanf("%s",c->sexe_c);
break;
case 4:
printf("saisir la modification du contact \n");
scanf("%s",c->contact_c);
break;
case 5:
printf("saisir la modification du mot de passe \n");
scanf("%s",c->mot_c);
break;
case 6:
printf("saisir la modification du mot de ville \n");
scanf("%s",c->ville_c);
break;
case 7:
printf("saisir la modification de votre date de naissance  (jj/mm/aa) \n");
scanf("%d %d %d",&c->date_nai.j,&c->date_nai.m,&c->date_nai.a);
break;
default:
printf("choix invalide \n");
break;
}
}
fprintf(f1,"%s %s %s %s %s %s %s %d %d %d \n",c->id_c,c->nom_c,c->prenom_c,c->sexe_c,c->contact_c,c->mot_c,c->ville_c,c->date_nai.j,c->date_nai.m,c->date_nai.a);
}
fclose(f);
fclose(f1);
remove(citoyens);
rename(t_citoyens,citoyens);
}

void supp_citoyen(char *citoyens,char *t_citoyens,char *login,citoyen *c)
{
const char vide[30]= "Champs_supprime";
int p;
FILE *f=fopen(citoyens,"r");
if(f==NULL)
{
printf("error\n");
return;
}
FILE *f1=fopen(t_citoyens,"w");
if(f1==NULL)
{
printf("error\n");
return;
}
while(fscanf(f,"%s %s %s %s %s %s %s %d %d %d",c->id_c,c->nom_c,c->prenom_c,c->sexe_c,c->contact_c,c->mot_c,c->ville_c,&c->date_nai.j,&c->date_nai.m,&c->date_nai.a)!=EOF)
{
if(strcmp(login,c->id_c)==0)
{
printf("donner le champs a modifier \n");
printf("1-sexe \n");
printf("2-contact \n");
printf("3-ville \n");
scanf("%d",&p);
switch(p)
{
case 1:
strcpy(c->sexe_c,vide);
printf("DONE \n");
break;
case 2:
strcpy(c->contact_c,vide);
printf("DONE \n");
break;
case 3:
strcpy(c->ville_c,vide);
printf("DONE \n");
break;
default:
printf("choix invalide \n");
break;
}
}
fprintf(f1,"%s %s %s %s %s %s %s %d %d %d \n",c->id_c,c->nom_c,c->prenom_c,c->sexe_c,c->contact_c,c->mot_c,c->ville_c,c->date_nai.j,c->date_nai.m,c->date_nai.a);
}
fclose(f);
fclose(f1);
remove(citoyens);
rename(t_citoyens,citoyens);


}


