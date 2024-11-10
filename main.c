#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "citoyen.h"

void main()
{
int cx;
citoyen c;
char login[20];
char password[20];
int trouve=0;
int choix;

printf("1-connexion \n");
printf("2-Sign up \n");
scanf("%d",&choix);






switch(choix)
{
case 1:

printf("LOGIN : \n");
scanf("%s",login);
printf("Password : \n");
scanf("%s",password);

FILE *f=fopen("citoyens.txt","a+");
if(f==NULL)
{
printf("error\n");
return;
}
while(fscanf(f,"%s %s %s %s %s %s %s %d %d %d \n",c.id_c,c.nom_c,c.prenom_c,c.sexe_c,c.contact_c,c.mot_c,c.ville_c,&c.date_nai.j,&c.date_nai.m,&c.date_nai.a)!=EOF)
{
if(strcmp(login,c.id_c)==0 && strcmp(password,c.mot_c)==0)
{
trouve=1;
}
}
fclose(f);
if(trouve==1)
{
do
{
printf("menu \n");
printf("1-affichage \n");
printf("2-mod \n");
printf("3-supp \n");
scanf("%d",&cx);
switch(cx)
{
case 1:
affichage_citoyen("citoyens.txt",login,&c);
break;
case 2:
mod_citoyen("citoyens.txt","t_citoyens.txt",login,&c);
break;
case 3:
supp_citoyen("citoyens.txt","t_citoyens.txt",login,&c);
break;
default:
printf("choix invalide \n");
break;

}

}while(cx>1||cx<3);


}

else 
{
printf("verifier votre donnee \n");
}
break;
case 2:
ajout_citoyen(&c,"citoyens.txt");
break;
default :
printf("choix invalide \n");
break;
}





















}
