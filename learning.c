#include<stdio.h>
typedef struct 
{
    int mle; char nom[80];prenom[80];char filliere[80];char res_mle[80];char res_nom[80];
    char res_prenom[80];char rest_filliere[80];
    float moyen; int jour;int mois;int ans
} Student;

void permutation_of_lines_in_file(int ,int );

void main(){
     
}

void permutation_of_lines_in_file(int mle1,int mle2){
    Student main_student;
    Student helper_student;

    FILE * main_file;
    FILE * second_file;
    open_file=fopen("enriges.txt","r");
    open_file=fopen("buffer.txt","a");

    int length_file=count_length("enriges.txt");
    
    for (int i = 0; i < length_file; i++)
    {
        fscanf(main_file,"%d %s %s %s %f   %d %d %d",main_student.mle,main_student.nom,main_student.prenom,main_student.filliere,
        &main_student.moyen,&main_student.jour,&main_student.mois,&main_student.ans);
        if (main_student.mle==mle1)
        {

        }
        
    }
    



    fclose(main_file);
    fclose(second_file);


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

void find_first_student(int mle1,){
    FILE * main_file;
    main_file=fopen("enriges.txt","r");



    fclose(main_file);
}


