#include<stdio.h>
#include<string.h>
int compte_nomb_chiffre(int);
void remplissage(int,char*,char*,char*,float,int,int,int);
void main(){
    printf("hello word!");
//    system(color 0);

    int mle;
    int jour;
    int mois;
    int ans;
    float moyen;
    char nom[80];
    char prenom[80];
    char filliere[80];

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
           fprintf(pointer_enrigestrement,"%d%s %s%s %s%s %s%s %f   %d %d %d\n",mle,rest_mle,nom,
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