#include<stdio.h>
#include<string.h>
int is_first_one_smaller(char * ,char* );

typedef struct 
{
    int mle;char nom[80];char prenom[80];char filliere[80];
} Student;
void tri_student_by_name( Student student[]);
void main(){
    Student student[23];
    tri_student_by_name(student);
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


void tri_student_by_name(  Student student[]){
    student[0].mle=1212;
    student[1].mle=31421;
    printf("mle  est :%d\n",student[0].mle);
    printf("mle  est :%d\n",student[1].mle);

}