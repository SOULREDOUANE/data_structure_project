#include<stdio.h>
#include<string.h>
void delete_student(int );
int count_length(char *);
void ajout_white_space(int* ,char* , char* ,char* ,char* ,char* ,char* ,char* );
int compte_nomb_chiffre(int );
void main(){
printf("hello world!");
// int length=count_length("enriges.txt");
// printf("la  taile du fichiers est :%d",length);

    int mle= 2210714;
    // int jour;
    // int mois;
    // int ans;
    // float moyen=12.2;
//     char nom[80];
//     char prenom[80];
//     char filliere[80];
//     char rest_nom[80];
//     char rest_prenom[80];
//     char rest_filliere[80];
//     char rest_mle[80];

delete_student( mle);
// printf("answer the question:");
// scanf(" %d",&mle);
// printf("inter name");
// scanf(" %s",nom);
// printf("inter you're second name");
// scanf(" %s",prenom);
// printf("enter you subject");
// scanf(" %s",filliere);
// ajout_white_space( mle, nom, prenom,filliere,rest_mle,rest_nom,rest_prenom,rest_filliere);
// printf("%d\n",strlen(rest_mle));
// printf("%d\n",strlen(rest_nom));
// printf("%d\n",strlen(rest_prenom));
// printf("%d\n",strlen(rest_filliere));
// printf("%s",nom);
// printf("%s",nom);

}


void delete_student(int mle_given){
    int* mle;
    int mle_valeur=0;
    mle=&mle_valeur;
    int jour=0;
    int mois=0;
    int ans=0;
    float moyen=87;
    char nom[80];
    char prenom[80];
    char filliere[80];
    char rest_nom[80];
    char rest_prenom[80];
    char rest_filliere[80];
    char rest_mle[80];


    FILE * main_pointer;
    FILE * second_pointer;
    main_pointer=fopen("enriges.txt","r");
    second_pointer=fopen("temperary.txt","a");
    // int buffer=0;
    int file_length=count_length("enriges.txt");
    // ajout_white_space( mle, nom, prenom,filliere,rest_mle,rest_nom,rest_prenom,rest_filliere);
    for (int i= 0; i < file_length; i++)
    {

        fscanf(main_pointer,"%d %s %s %s %f   %d %d %d",mle,nom,prenom,filliere,&moyen,&jour,&mois,&ans);
        ajout_white_space( mle, nom, prenom,filliere,rest_mle,rest_nom,rest_prenom,rest_filliere);
        if (*mle==mle_given)
        {
            int do_noting;
        }
        else
        {                
            fprintf(second_pointer,"%d%s %s%s %s%s %s%s %f %d %d %d\n",mle_valeur,rest_mle,nom,
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