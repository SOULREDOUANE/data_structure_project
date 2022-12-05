#include<stdio.h>
#include<string.h>
typedef struct 
{
    int mle;char nom[80];char prenom[80];char filliere[80];float moyen;int jour;int mois ;int ans;
} Student;
int count_length(char * );
void update_moyen(Student student1[],int );
void ajout_white_space(int* ,char* , char* ,char* ,char* ,char* ,char* ,char* );
int compte_nomb_chiffre(int );
void main(){
        Student student2[20];
        Student student1[20];
        printf("Donnez la nouvelle moyen:");
        scanf("%f",&student1[1].moyen);

        update_moyen( student1, 2210714);
}
void update_moyen(Student student1[],int current_mle_given){

    char rest_mle[80];
    char rest_nom[80];
    char rest_prenom[80];
    char rest_filliere[80];

    FILE * main_pointer;
    FILE * second_pointer;
    main_pointer=fopen("enriges.txt","r");
    second_pointer=fopen("temperary.txt","a");

    int length=count_length("enriges.txt");
    for (int i = 0; i < length; i++)
    {
        fscanf(main_pointer,"%d %s %s %s %f   %d %d %d",&student1[0].mle,student1[0].nom,
        student1[0].prenom,student1[0].filliere,&student1[0].moyen,&student1[0].jour,
        &student1[0].mois,&student1[0].ans);
        // ajout_white_space( mle, nom, prenom,filliere,rest_mle,rest_nom,rest_prenom,rest_filliere);
        if (current_mle_given==student1[0].mle)
        {  
            
            ajout_white_space( &student1[0].mle, student1[0].nom, student1[0].prenom,student1[0].filliere,rest_mle,rest_nom,rest_prenom,rest_filliere);
            fprintf(second_pointer,"%d%s %s%s %s%s %s%s %.2f    %d %d %d\n",student1[0].mle,rest_mle,student1[0].nom,
            rest_nom,student1[0].prenom,rest_prenom,student1[0].filliere,rest_filliere,student1[1].moyen,student1[0].jour,student1[0].mois,student1[0].ans);
        }
        else
        {
          ajout_white_space( &student1[0].mle, student1[0].nom, student1[0].prenom,
          student1[0].filliere,rest_mle,rest_nom,rest_prenom,rest_filliere);  
          fprintf(second_pointer,"%d%s %s%s %s%s %s%s %.2f    %d %d %d\n",student1[0].mle,
          rest_mle,student1[0].nom,rest_nom,student1[0].prenom,rest_prenom,student1[0].filliere,
          rest_filliere,student1[0].moyen,student1[0].jour,student1[0].mois,student1[0].ans);
          
        }
    }

    fclose(main_pointer);
    fclose(second_pointer);
    remove("enriges.txt");
    rename("temperary.txt","enriges.txt");
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
void ajout_white_space(int* mle,char* nom, char* prenom,char* filliere,char* rest_mle,char* rest_nom,char* rest_prenom,char* rest_filliere){
    int i;
    int contain_value=30;
    int helper=0;
    helper=contain_value-compte_nomb_chiffre(*mle);
    // printf("%d\n",compte_nomb_chiffre(*mle));
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