#include<stdio.h>
#include<string.h>
typedef struct 
{
    int mle;char nom[80];char prenom[80];char filliere[80];float moyen;int jour;int mois ;int ans;
} Student;

void put_struct_into_struct(Student student1[],Student student2[], int ,int );
void put_all_mle_in_struct_student(Student student[]);
void tri_student_by_name(  Student student[], Student student2[]);
void diplay_of_student_ordered(Student student[],Student student2[]);

int compte_nomb_chiffre(int);
void remplissage(Student student1[]);
void do_everything(Student student1[],Student student[],Student student2[]);
void delete_student(int );
int count_length(char *);
void ajout_white_space(int* ,char* , char* ,char* ,char* ,char* ,char* ,char* );
void find_student(int );
void update_student_data(Student student1[], int );
void tri_student_by_moyen(  Student student[], Student student2[]);
void diplay_of_student_ordered_moyen(Student student[],Student student2[]);
void update_moyen(Student student1[],int current_mle_given);

void main(){
        Student student1[1000];
        Student student[1000];
        Student student2[1000];
        do_everything(student1,student,student2);


}
// this function adds new student 
void remplissage( Student student1[]  )
{
    char rest_nom[80];
    char rest_prenom[80];
    char rest_filliere[80];
    char rest_mle[80];

    FILE * pointer_enrigestrement;
    ajout_white_space(&student1[0].mle,student1[0].nom,student1[0].prenom,student1[0].filliere,
    rest_mle,rest_nom,rest_prenom,rest_filliere);
    pointer_enrigestrement=fopen("enriges.txt","a");
    if (pointer_enrigestrement)
    {
           fprintf(pointer_enrigestrement,"%d%s %s%s %s%s %s%s %.2f    %d %d %d\n",student1[0].mle,rest_mle,student1[0].nom,
           rest_nom,student1[0].prenom,rest_prenom,student1[0].filliere,
           rest_filliere,student1[0].moyen,student1[0].jour,student1[0].mois,student1[0].ans);
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
            printf("\n\n  matricule:%d\n\n  Nom:%s\n\n  Prenom:%s\n\n  Filliere:%s\n\n  Moyen:%.2f\n\n  Date:%d/%d/%d\n\n\n",mle,nom,prenom,filliere,moyen,jour,mois,ans);
            fclose(main_pointer);
            break;
        }  
    }
    fclose(main_pointer);
    
}
// this function update the a student's information
void update_student_data(Student student1[],int current_mle_given){

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
            ajout_white_space( &student1[1].mle, student1[1].nom, student1[1].prenom,student1[1].filliere,rest_mle,rest_nom,rest_prenom,rest_filliere);
            fprintf(second_pointer,"%d%s %s%s %s%s %s%s %.2f    %d %d %d\n",student1[1].mle,rest_mle,student1[1].nom,
            rest_nom,student1[1].prenom,rest_prenom,student1[1].filliere,rest_filliere,student1[1].moyen,student1[1].jour,student1[1].mois,student1[1].ans);
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
// cette fonction peut trier les etudiant selon leur nom
void tri_student_by_name(  Student student[], Student student2[]){
    int number_student=count_length("enriges.txt");
    char buffer[80];
    int flag;
    int index_for_premutation;    
    for (int i = 0; i < number_student-1; i++)
    {
        strcpy(buffer,student[i].nom);
        put_struct_into_struct( student2,student,0, i);
        index_for_premutation=i;
        for (int j = i+1; j < number_student; j++)
        {
            flag=strcmp(buffer,student[j].nom);
            if (flag==1)
            {
                index_for_premutation=j;
            } 
            strcpy(buffer,student[index_for_premutation].nom);
        } 
        put_struct_into_struct( student,student,i, index_for_premutation);
        put_struct_into_struct( student,student2,index_for_premutation, 0);
    }
}
// cette fonction se consedere comme un outil pour faciliter le triage
void put_struct_into_struct(Student student1[],Student student2[], int i,int j){
        student1[i].mle=student2[j].mle;
        strcpy(student1[i].nom,student2[j].nom);
        strcpy(student1[i].prenom,student2[j].prenom);
        strcpy(student1[i].filliere,student2[j].filliere);
        student1[i].moyen=student2[j].moyen;
        student1[i].jour=student2[j].jour;
        student1[i].mois=student2[j].mois;
        student1[i].ans=student2[j].ans;
}
//  cette fonction affiche les etudiant on ordre selon leur nom
void diplay_of_student_ordered(Student student[],Student student2[]){

    put_all_mle_in_struct_student( student);
    tri_student_by_name(student, student2);

    char rest_mle[80];
    char rest_nom[80];
    char rest_prenom[80];
    char rest_filliere[80];
    int number_student=count_length("enriges.txt");
    for (int i = 0; i < number_student; i++)
    {
        ajout_white_space(&student[i].mle,student[i].nom,student[i].prenom,student[i].filliere,
        rest_mle,rest_nom,rest_prenom,rest_filliere);
        printf("%d%s    %s%s      %s%s        %s%s      %.2f        %d  %d  %d\n\n\n",student[i].mle,rest_mle,student[i].nom,rest_nom,student[i].prenom,rest_prenom,student[i].filliere,rest_filliere,student[i].moyen,student[i].jour,
        student[i].mois,student[i].ans);
        printf("---------------------------------------------------------------------------------------------------------------------\n");
    }
}
void put_all_mle_in_struct_student(Student student[]){
    FILE * open_file;

    open_file=fopen("enriges.txt","r");
    int number_student=count_length("enriges.txt");

    for (int i = 0; i < number_student; i++)
    {
        fscanf(open_file,"%d %s %s %s %f %d %d %d",&student[i].mle,student[i].nom,student[i].prenom,
        student[i].filliere,&student[i].moyen,&student[i].jour,&student[i].mois,&student[i].ans); 
    }
    fclose(open_file);
    
}
// this function merge all of the functin we build her
void do_everything(Student student1[],Student student[],Student student2[]){
    int valeur_de_operation;
    int stop_adding_student;
    int current_mle_given;
    printf("Svp choisi l'operation que vous voulez affecter:\n");
    printf("Entrer:\n");
    printf(" 1 si vous voulez ajouter des etudiant\n");
    printf(" 2 si vous voulez faire la mis a jour des donnees d'un etudiant\n");
    printf(" 3 si vous voulez afficher les etudiant par ordre croissant de leur nom\n");
    printf(" 4 si vous voulez supprimer un etudiant\n");
    printf(" 5 si vous  voulez chercher un etudiant \n");
    printf(" 6 si vous voulez afficher les etudiant par ordre croissant de leur moyen\n");
    printf(" 7 si vous voulez faire  la mis a jour de la moyen d'un etudiant\n");

    printf("------------:");
    scanf("%d",&valeur_de_operation);
    switch (valeur_de_operation)
    {
    case 1:
        printf("Entrer:\n");
        printf(" 1: si vous voullez ajouter  etudiant\n");
        printf(" 0: si vous voullez arretez\n");
        printf("----------:");

        scanf("%d",&stop_adding_student);
        while (stop_adding_student==1)
        {
            printf("Donnez la matricule de l'etudiant: ");
            scanf("%d",&student1[0].mle);
            printf("Donnez le nom de l'etudiant : ");
            scanf("%s",student1[0].nom);
            printf("Donnez le prenom de l'etudiant: ");
            scanf("%s",student1[0].prenom);
            printf("Donnez la filliere de l'etudiant: ");
            scanf("%s",student1[0].filliere);
            printf("Donnez la moyen de l'etudiant: ");
            scanf("%f",&student1[0].moyen);
            printf("Donnez le jour dont  vous voullez l'associer a cette operation: ");
            scanf("%d",&student1[0].jour);
            printf("Donnez le mois dont vous voullez l'associer a cette operation: ");
            scanf("%d",&student1[0].mois);
            printf("Donnez l'annee dont vous voullez l'associer a cette operation: ");
            scanf("%d",&student1[0].ans);

            remplissage( student1 );

            printf("----------------------------------\n");
            printf("Entrer:\n");
            printf(" 1: si vous voullez ajouter un autre etudiant\n");
            printf(" 0: si vous voullez arretez\n");
            printf("----------:");
            scanf("%d",&stop_adding_student);
        }
        break;
    case 2:
        printf("Entrer:\n");
        printf(" 1: si vous voullez faire la mis a jour  des donnees d'un etudiant\n");
        printf(" 0: si vous voullez arretez\n");
        printf("----------:");

        scanf("%d",&stop_adding_student);
        while (stop_adding_student==1)
        {
            printf("Donnez le matricule actuelle de l'etudiant dont vous voullez modifier:");
            scanf("%d",&current_mle_given);
            printf("Donnez la nouvelle  matricule  de l'etudiant: ");
            scanf("%d",&student1[1].mle);
            printf("Donnez le nouveau nom de l'etudiant : ");
            scanf("%s",student1[1].nom);
            printf("Donnez le nouveau prenom de l'etudiant: ");
            scanf("%s",student1[1].prenom);
            printf("Donnez la nouvelle filliere de l'etudiant: ");
            scanf("%s",student1[1].filliere);
            printf("Donnez la nouvelle moyen de l'etudiant: ");
            scanf("%f",&student1[1].moyen);
            printf("Donnez le nouveau jour dont  vous voullez l'associer a cette operation: ");
            scanf("%d",&student1[1].jour);
            printf("Donnez le nouveau mois dont vous voullez l'associer a cette operation: ");
            scanf("%d",&student1[1].mois);
            printf("Donnez la nouvelle annee dont vous voullez l'associer a cette operation: ");
            scanf("%d",&student1[1].ans);

            update_student_data(student1, current_mle_given);

            printf("----------------------------------\n");
            printf("Entrer:\n");
            printf(" 1: si vous voullez faire la mis a jour  des donnees d'un autre etudiant\n");
            printf(" 0: si vous voullez arretez\n");
            printf("----------:");
            scanf("%d",&stop_adding_student);
        }
        break;
    case 3:
        diplay_of_student_ordered(student, student2);
        break;
    case 4:
        printf("Entrer:\n");
        printf(" 1: si vous voullez supprimer un etudiant\n");
        printf(" 0: si vous voullez arretez\n");
        printf("----------:");

        scanf("%d",&stop_adding_student);
        while (stop_adding_student==1)
        {
            printf("Donnez la matricule de l'etudiant: ");
            scanf("%d",&student1[0].mle);

            delete_student( student1[0].mle);

            printf("----------------------------------\n");
            printf("Entrer:\n");
            printf(" 1: si vous voullez supprimer un autre etudiant\n");
            printf(" 0: si vous voullez arretez\n");
            printf("----------:");
            scanf("%d",&stop_adding_student);
        }
    
    case 5:

        printf("Entrer:\n");
        printf(" 1: si vous voullez chercher un etudiant\n");
        printf(" 0: si vous voullez arretez\n");
        printf("----------:");

        scanf("%d",&stop_adding_student);
        while (stop_adding_student==1)
        {
            printf("Donnez la matricule de l'etudiant que vous cherchez: ");
            scanf("%d",&student1[0].mle);

            find_student(student1[0].mle);

            printf("----------------------------------\n");
            printf("Entrer:\n");
            printf(" 1: si vous voullez chercher un autre etudiant\n");
            printf(" 0: si vous voullez arretez\n");
            printf("----------:");
            scanf("%d",&stop_adding_student);
        }
        break;
    case 6:
        diplay_of_student_ordered_moyen(student,student2);
        break;
    case 7:
        printf("Entrer:\n");
        printf(" 1: si vous voullez faire la mis a jour de la moyen d'un etudiant\n");
        printf(" 0: si vous voullez arretez\n");
        printf("----------:");

        scanf("%d",&stop_adding_student);
        while (stop_adding_student==1)
        {
            printf("Donnez le matricule actuelle de l'etudiant dont vous voullez modifier:");
            scanf("%d",&current_mle_given);
            printf("Donnez la nouvelle moyen de l'etudiant: ");
            scanf("%f",&student1[1].moyen);

            update_moyen(student1, current_mle_given);

            printf("----------------------------------\n");
            printf("Entrer:\n");
            printf(" 1: si vous voullez faire la mis a jour  de la moyen d'un autre etudiant\n");
            printf(" 0: si vous voullez arretez\n");
            printf("----------:");
            scanf("%d",&stop_adding_student);
        }
        break;
    default:
        break;
    }
 
}
// this function sort all student by their gpa
void tri_student_by_moyen(  Student student[], Student student2[]){
    int number_student=count_length("enriges.txt");
    float buffer;
    int index_for_premutation; 

    for (int i = 0; i < number_student-1; i++)
    {
        buffer=student[i].moyen;
        // strcpy(buffer,student[i].nom);
        put_struct_into_struct( student2,student,0, i);
        index_for_premutation=i;
        for (int j = i+1; j < number_student; j++)
        {
            if (buffer>student[j].moyen)
            {
                index_for_premutation=j;
                buffer=student[index_for_premutation].moyen;
            } 
        } 
        put_struct_into_struct( student,student,i, index_for_premutation);
        put_struct_into_struct( student,student2,index_for_premutation, 0);
    }
}
// this function display all student ordered by their gpa
void diplay_of_student_ordered_moyen(Student student[],Student student2[]){

    put_all_mle_in_struct_student( student);
    tri_student_by_moyen(student, student2);

    char rest_mle[80];
    char rest_nom[80];
    char rest_prenom[80];
    char rest_filliere[80];
    int number_student=count_length("enriges.txt");
    for (int i = 0; i < number_student; i++)
    {
        ajout_white_space(&student[i].mle,student[i].nom,student[i].prenom,student[i].filliere,
        rest_mle,rest_nom,rest_prenom,rest_filliere);
        printf("%d%s    %s%s      %s%s        %s%s      %.2f        %d  %d  %d\n\n\n",student[i].mle,rest_mle,student[i].nom,rest_nom,student[i].prenom,rest_prenom,student[i].filliere,rest_filliere,student[i].moyen,student[i].jour,
        student[i].mois,student[i].ans);
        printf("---------------------------------------------------------------------------------------------------------------------\n");
    }
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

