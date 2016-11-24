/*
name: Alex Austin
Lab Section: 03
Student ID: 001424250
Lab: 3
Question: 2
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct//creating the structure
{
    int id;
    char first[15];
    char last[15];
    int proj1;
    int proj2;
    double grade;
} student;

student **create_class_list(char *filename, int *sizePtr );//all the func prototypes
int find(int idNo, student **list, int size);
void input_grades(char *filename, student **list, int size);
void compute_final_course_grades(student **list,int size);
void output_final_course_grades(student **list,int size);
void print_list(student **list, int size);
void withdraw(int idNo, student **list, int *sizePtr);

int main(void) 
{
    int size,w;
    
    char filename[]="classlist.txt";//the filename char lists
    char filename2[]="grades.txt";


    student **list = create_class_list(filename,&size);//creating the class list
    w = find(654186,list,size);//demonstrating find
    input_grades(filename2,list,size);//getting grades
    compute_final_course_grades(list,size);//computes final
    output_final_course_grades(list,size);//outputs final
    print_list(list,size);//prints list
    withdraw(978679,list,&size);//first withdraw
    print_list(list,size);
    withdraw(4935789,list,&size);//invalid withdraw
    print_list(list,size);
    withdraw(215166,list,&size);//second withdraw    
    print_list(list,size);
    destroy_list(list,&size);//list destroy
    
    return 0;
}
student **create_class_list(char *filename, int *sizePtr )
{
    FILE *input_file=fopen(filename, "r");//opens the file
    
    fscanf(input_file,"%d",sizePtr);//scans the number of kids
    
    student **list=NULL;
    int i=0;
    
    list = (student**)malloc((*sizePtr)*sizeof(student**));//allocates the proper size based on the amount of kids
    for(i;i<(*sizePtr);i++)
    {
        list[i]=(student*)malloc(sizeof(student));//allocates the individual student
        fscanf(input_file,"%d",&list[i]->id);//initializes the student into the student struc
        fscanf(input_file,"%s",list[i]->first);
        fscanf(input_file,"%s",list[i]->last);
        list[i]->proj1 = 0;//sets grades to 0
        list[i]->proj2 = 0;
        list[i]->grade = 0;
    }
    
    fclose(input_file);//closes file
    return list;
}
int find(int idNo, student **list, int size)
{
    for(int i = 0;i<size;i++)
        if(list[i]->id == idNo)//searches for the idNo
            return i;//returns the index

    return -1;//or returns -1
}
void input_grades(char *filename, student **list, int size)
{
    int index,idNo,proj1, proj2,i =0;
 
    FILE *input_file2=fopen(filename, "r");//opens the grades file
    
    for(i;i<size;i++)
    {
        fscanf(input_file2,"%d",&idNo);//grabs the idNo
    
        index = find(idNo,list,size);//finds the pos that the idNo were looking for is in
    
        fscanf(input_file2,"%d",&proj1);//gets proj1 and 2
        fscanf(input_file2,"%d",&proj2);
    
        list[index]->proj1 = proj1;//sets the student to the proper grade
        list[index]->proj2 = proj2;
    }
        
    fclose(input_file2);
    
}
void compute_final_course_grades(student **list,int size)
{
    int i = 0;
    
    for(i;i<size;i++)//computes each students grade
    {
        list[i]->grade=((double)(list[i]->proj1+list[i]->proj2)/2);
    }
    
}
void output_final_course_grades(student **list,int size)
{
    FILE *output_file=fopen("finalGrades.txt", "w");//creates the output file
    
    int i = 0;
    
    fprintf(output_file,"%d\n",size );//prints the appropriate size to the file
    for(i;i<size;i++)
    {
        fprintf(output_file,"%d %f\n",list[i]->id,list[i]->grade );//outputs the proper id and grade to the file
    }
    fclose(output_file);
}
void print_list(student **list, int size)
{
    int i = 0;
    for(i;i<size;i++)//list print
    {
        printf("ID: %d\t name: %s %s\t project 1 grade: %d\t project 2 grade:%d\t final grade: %f \n",list[i]->id,list[i]->first,list[i]->last,list[i]->proj1,list[i]->proj2,list[i]->grade);

    }
    printf("\n");
}
void withdraw(int idNo, student **list, int *sizePtr)
{
    int index,w = (*sizePtr)-1;
    
    index =find(idNo,list,*sizePtr);//gets the index of the student being withdrawn
    
    if(index==-1)//if find returns -1 then its not a student
    {
        printf("specified student not on the list\n");
    }
    else if(index >=0 )
    {
        free(list[index]);//frees the mem of the student being withdrawn

        for(int i=index;i<w;i++)
        {
            list[i]=list[i+1];//shifts the pointers to point to the next student on the list
        }
        
        list[w]=NULL;//since the last pointer and second last pointer point to the same thing setting the last pointer to null makes sure there aren't two pointers pointing to the same thing
        *sizePtr -= 1;//reduces the size of the list
    }
}
void destroy_list(student **list, int *sizePtr)
{
    int i =0;
    
     for(i=0; i<*sizePtr;i++)//frees mem of each student
    {
        free(list[i]);
    }
    free(list);//frees the list itself
    *sizePtr = 0;//sets size to 0
}
