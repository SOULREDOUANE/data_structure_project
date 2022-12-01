#include<stdio.h>
#include<string.h>
int count_length(char * );
void update_student_data(int , int ,char * ,char * ,char *,float,int ,int ,int );
void ajout_white_space(int* ,char* , char* ,char* ,char* ,char* ,char* ,char* );
int compte_nomb_chiffre(int );
void main(){

    int jour=12;
    int mois=12;
    int ans=2022;
    float moyen=12.2;
    char nom[80];
    char prenom[80];
    char filliere[80];
    int new_mle;
    // char rest_nom[80];
    // char rest_prenom[80];
    // char rest_filliere[80];
    char rest_mle[80];
    int mle;

printf("Donnez le mle d'etudiant:");
scanf(" %d",&mle);
printf("Donnez le nouveau mle d'etudiant:");
scanf(" %d",&new_mle);
printf("Donnez son nom");
scanf(" %s",nom);
printf("Entrez son prenom");
scanf(" %s",prenom);
printf("Donnez son filliere");
scanf(" %s",filliere);
// ajout_white_space( mle, nom, prenom,filliere,rest_mle,rest_nom,rest_prenom,rest_filliere);
// printf("%d\n",strlen(rest_mle));
// printf("%d\n",strlen(rest_nom));
// printf("%d\n",strlen(rest_prenom));
// printf("%d\n",strlen(rest_filliere));
// printf("%s",nom);
// printf("%s",nom);
update_student_data(mle,new_mle,nom, prenom,filliere,moyen,jour,mois,ans);

}
void update_student_data(int current_mle_given, int new_mle,char * given_nom,char * given_prenom,char * given_filliere,float given_moyen,int given_jour,int given_mois,int given_ans){

    char rest_mle[80];
    char rest_nom[80];
    char rest_prenom[80];
    char rest_filliere[80];
    float moyen;
    int* mle;
    int jour;
    int mois;
    int ans;
    char nom[80];
    char prenom[80];
    char filliere[80];

    FILE * main_pointer;
    FILE * second_pointer;
    main_pointer=fopen("enriges.txt","r");
    second_pointer=fopen("temperary.txt","a");

    int length=count_length("enriges.txt");
    for (int i = 0; i < length; i++)
    {
        fscanf(main_pointer,"%d %s %s %s %f   %d %d %d",mle,nom,prenom,filliere,&moyen,&jour,&mois,&ans);
        // ajout_white_space( mle, nom, prenom,filliere,rest_mle,rest_nom,rest_prenom,rest_filliere);
        if (current_mle_given==*mle)
        {   int * new_mleP;
            new_mleP=&new_mle;
             ajout_white_space( new_mleP, given_nom, given_prenom,given_filliere,rest_mle,rest_nom,rest_prenom,rest_filliere);
            fprintf(second_pointer,"%d%s %s%s %s%s %s%s %f %d %d %d\n",new_mle,rest_mle,given_nom,
           rest_nom,given_prenom,rest_prenom,given_filliere,rest_filliere,given_moyen,given_jour,given_mois,given_ans);
        }
        else
        {
          ajout_white_space( mle, nom, prenom,filliere,rest_mle,rest_nom,rest_prenom,rest_filliere);  
          fprintf(second_pointer,"%d%s %s%s %s%s %s%s %f %d %d %d\n",*mle,rest_mle,nom,
           rest_nom,prenom,rest_prenom,filliere,rest_filliere,moyen,jour,mois,ans);
        }
    }

    fclose(main_pointer);
    fclose(second_pointer);
    remove("enriges.txt");
    rename("temperary.txt","enriges.txt");
}

int count_length(char * Path_of_file){
    FILE * pointer;
    pointer=fopen(Path_of_file,"r");
    int counter=0;
    int i;
    char empty[1000];

    i=fgetc(pointer);
    fgets(empty,900,pointer);
    while(i!=EOF){
        counter++;
        i=fgetc(pointer);
        fgets(empty,900,pointer);
    }
    fclose(pointer);
    return counter;
}
void ajout_white_space(int* mle,char* nom, char* prenom,char* filliere,char* rest_mle,char* rest_nom,char* rest_prenom,char* rest_filliere){
    int i;
    int contain_value=30;
    int helper=0;
    helper=contain_value-compte_nomb_chiffre(*mle);
    printf("%d\n",compte_nomb_chiffre(*mle));
    for ( i=0 ;i<helper;i++)
    {
        rest_mle[i]=' ';
    }
    rest_mle[helper]='\0';

    //rest_nom
    helper=contain_value-strlen(nom);
    for (i=0 ;i<helper;i++)
    {
        rest_nom[i]=' ';
    }
    rest_nom[helper]='\0';
    //rest_prenom
    helper=contain_value-strlen(prenom);
    for ( i=0 ;i<helper;i++)
    {
        rest_prenom[i]=' ';
    }
    rest_prenom[helper]='\0';

    //rest_filliere
    helper=contain_value-strlen(filliere);
    for ( i=0 ;i<helper;i++)
    {
        rest_filliere[i]=' ';
    }
    rest_filliere[helper]='\0';
}

int compte_nomb_chiffre(int nombre){

    int somme=1;
    nombre;
    while(nombre>10){
        somme+=1;
        nombre=nombre/10;
    }
    return somme;
}