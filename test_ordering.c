#include<stdio.h>
#include<string.h>
int is_first_one_smaller(char * ,char* );
int count_length(char *);

void main(){
  
}
int is_first_one_smaller(char * chaine1,char* chaine2){
    int min_length;
    if (strlen(chaine1)<strlen(chaine2))
    {
       min_length= strlen(chaine1);
    }
    else{
        min_length=strlen(chaine2);
    }
    for (int i = 0; i < min_length; i++)
    {
        if (chaine1[i]<chaine1[i])
        {
           return 1;
        }
        else if (chaine1[i]<chaine2[i])
        {
            return 0;
        }
        else{  
        }
    }
    return 1;
}
void put_all_student_name_in_struct(){
    FILE * open_file;
    open_file=fopen("enriges.txt","r");
    int nombre_student=count_length("enriges.txt");
    
    


    fclose(open_file);
}

void display_student_on_asc_order(){
    FILE * open_file;
    open_file=fopen("enriges.txt","r");

    int nombre_student=count_length("enriges.txt");
    int list_mle[nombre_student+11];
    char list_nom[nombre_student+11];
    




    fclose(open_file);
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