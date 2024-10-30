#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void show(int array[]);
void reverse(int array[]);
int get_index(int array[] ,int value);
void play(int array[]);
int win(int array[]);
int main (){
   
    int array[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    reverse(array);
    do {
        system("clear"); 
        show(array);
        play(array);
    }while(win(array) != 1);
    printf ("\n Your are wiiiin "); 
    return (0);
}

void show(int array[]){
    for (int i = 0 ;i <16; i++)
    {
        if (i % 4 == 0){
            printf("\n");
        }
        if (array[i] == 0)
        {
            printf ("%c\t",223);
        }else {
            printf ("%d\t ",array[i]);
        }
    }
}

void reverse(int array[])
{
    int index_1;
    int index_2;
    int temp;
    srand(time(0));
    for (int i = 0; i < 18 ;i++){
        index_1 = rand() % 16 ;
        index_2 = rand() % 16 ;
        temp =array[index_1];
        array[index_1] = array[index_2];
        array[index_2] = temp;
    }
}
int get_index(int array[] ,int value)
{
    for (int i = 0 ; i < 16; i++){
        if (array[i] == value)
        {
            return (i);
        }
    }
    return (-1);
}
void play(int array[]){
    int nbr_move;
    int index_nbr;
    int index_0;
    int temp;
    printf ("\nentrer number your want move : ");
    scanf ("%d",&nbr_move);
    index_nbr =get_index(array,nbr_move);
    index_0 =get_index(array,0);
    if ((index_nbr == index_0 - 1 )|| (index_nbr == index_0 + 1) || 
        (index_nbr ==index_0 - 4) || (index_nbr == index_0 + 4))
        {
            temp =array[index_0];
            array[index_0] = array[index_nbr];
            array[index_nbr] = temp;
        }
}
int win(int array[]){
    for (int i = 0;i < 16 ;i++){
        if (i !=array[i]){
            return (0);
        }
    }
    return (1);
}
