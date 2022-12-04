#include<stdio.h>
#include<string.h>
int compte_nomb_chiffre(int);
void remplissage(int,char*,char*,char*,float,int,int,int);
void delete_student(int );
int count_length(char *);
void ajout_white_space(int* ,char* , char* ,char* ,char* ,char* ,char* ,char* );
void find_student(int );
void update_student_data(int , int ,char * ,char * ,char *,float,int ,int ,int );

typedef char User[80];
void main(){
    printf("hello word!");
//    system(color 0);

    int mle;
    int jour;
    int mois;
    int ans;
    float moyen;
    User nom ;
    // char nom[80];
    User prenom;
    // char prenom[80];
    User filliere;
    // char filliere[80];

 printf("Entrez svp votre matrecule:");
    scanf(" %d",&mle);
    printf("Donnez votre nom en majuscule:");
    scanf(" %s",nom);
    printf("Donnez votre prenom: ");
    scanf(" %s",prenom);
    printf("Entrez votre filliere:");
    scanf(" %s",filliere);
    printf("Donnez votre note moyen:");
    scanf(" %f",&moyen);
    // printf("Donnez votre date de naissance sous la forme  'jour mois ans '    ");
    // scanf(" %d %d %d",&jour,&mois,&ans);
    printf("donnez le jour");
    scanf(" %d",&jour);
    printf("Donnez le mois");
    scanf(" %d",&mois);
    printf("Donnez l'anee");
    scanf(" %d",&ans);
    
    remplissage( mle,nom,prenom,filliere,moyen,jour,mois,ans );

}
// this function adds new student 
void remplissage(int mle,char* nom, char* prenom ,char* filliere,float moyen,int jour,int mois,int ans )
{
    char rest_nom[80];
    char rest_prenom[80];
    char rest_filliere[80];
    char rest_mle[80];
    int contain_value=30;
    int helper;
    int i;

    //rest_mle
    helper=contain_value-compte_nomb_chiffre(mle);
    for ( i=0 ;i<helper;i++)
    {
        rest_mle[i]=' ';
    }

    //rest_nom
    helper=contain_value-strlen(nom);
    for (i=0 ;i<helper;i++)
    {
        rest_nom[i]=' ';
    }

    //rest_prenom
    helper=contain_value-strlen(prenom);
    for ( i=0 ;i<helper;i++)
    {
        rest_prenom[i]=' ';
    }

    //rest_filliere
    helper=contain_value-strlen(filliere);
    for ( i=0 ;i<helper;i++)
    {
        rest_filliere[i]=' ';
    }
    FILE * pointer_enrigestrement;
    pointer_enrigestrement=fopen("enriges.txt","a");
    if (pointer_enrigestrement)
    {
           fprintf(pointer_enrigestrement,"%d%s %s%s %s%s %s%s %.2f    %d %d %d\n",mle,rest_mle,nom,
           rest_nom,prenom,rest_prenom,filliere,rest_filliere,moyen,jour,mois,ans);
    // fprintf(pointer_enrigestrement,"%s","\n");
    fclose(pointer_enrigestrement);
    }
    else
    {
        printf("something is wrong");
    }
}
// this function can count the number of digits in a integer
int compte_nomb_chiffre(int nombre){

    int somme=1;
    nombre;
    while(nombre>10){
        somme+=1;
        nombre=nombre/10;
    }
    return somme;
}
//  this function can count the length of txt file 
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
// this function can  delete a student from the file 
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
            fprintf(second_pointer,"%d%s %s%s %s%s %s%s %.2f    %d %d %d\n",mle_valeur,rest_mle,nom,
           rest_nom,prenom,rest_prenom,filliere,rest_filliere,moyen,jour,mois,ans);
        }
        
    }
    

    fclose(main_pointer);
    fclose(second_pointer);
    remove("enriges.txt");
    rename("temperary.txt","enriges.txt");

}
// this function is not so important but it helps having the data well organazed in the file
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
//this function displays  a student's information  
void find_student(int mle_given){
    int mle;
    int jour;
    int mois;
    int ans;
    float moyen;
    char nom[80];
    char prenom[80];
    char filliere[80];

    FILE * main_pointer;
    main_pointer=fopen("enriges.txt","r");

    int length=count_length("enriges.txt");
    for (int i = 0; i < length; i++)
    {
        fscanf(main_pointer,"%d %s %s %s %f   %d %d %d",&mle,nom,prenom,filliere,&moyen,&jour,&mois,&ans);
        if (mle==mle_given)
        {
            printf("matricule:%d\n Nom:%s\n Prenom:%s\n Filliere:%s\n Moyen:%f\n Date:%d/%d/%d",mle,nom,prenom,filliere,moyen,jour,mois,ans);
            fclose(main_pointer);
            break;
        }  
    }
    fclose(main_pointer);
    printf("cette etudiant n'existe pas dans.");
}
// this function update the a student's information
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
            fprintf(second_pointer,"%d%s %s%s %s%s %s%s %.2f    %d %d %d\n",new_mle,rest_mle,given_nom,
           rest_nom,given_prenom,rest_prenom,given_filliere,rest_filliere,given_moyen,given_jour,given_mois,given_ans);
        }
        else
        {
          ajout_white_space( mle, nom, prenom,filliere,rest_mle,rest_nom,rest_prenom,rest_filliere);  
          fprintf(second_pointer,"%d%s %s%s %s%s %s%s %.2f    %d %d %d\n",*mle,rest_mle,nom,
           rest_nom,prenom,rest_prenom,filliere,rest_filliere,moyen,jour,mois,ans);
        }
    }

    fclose(main_pointer);
    fclose(second_pointer);
    remove("enriges.txt");
    rename("temperary.txt","enriges.txt");
}