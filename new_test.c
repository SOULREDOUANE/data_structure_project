#include<stdio.h>
int count_length(char *);
void find_student(int );
void main(){

    find_student(2210714);
    printf("hi there");
}

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