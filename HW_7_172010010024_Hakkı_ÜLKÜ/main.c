#include <stdio.h>
#include <stdlib.h>
void creditPrinter(){   //function to display credits
    printf("3D center calculator\n"); // name of the application
    printf("By HAKKI ULKU 172010010024\n"); // Name of the developer
    printf("With 3D center calcualtor, you can calculate the center point of a 3D object."); // short description of the program
    printf("\nAs instruction, \nyou need to make a file which is in the same folder with your program and name of the file should be teapot.obj,\nthen you will have the centre coordinates after running the program.\n"); //instructions for the program
    printf("------------------------------------------------------------------------------------------------------------------------");
}
struct Point3D{
        float x;
        float y;
        float z;
    };

struct Point3D centerPoint;

void calculateCenter(struct Point3D* point, int count){
    float sumX=0, sumY=0, sumZ=0;
    for(int n=0; n<count; n++){
        sumX+=point[n].x;
        sumY+=point[n].y;
        sumZ+=point[n].z;
    }
    centerPoint.x=sumX/count;
    centerPoint.y=sumY/count;
    centerPoint.z=sumZ/count;
    printf("x:%f , y:%f, z:%f", centerPoint.x, centerPoint.y, centerPoint.z); // prints the centre coordinates
}
int main()
{
    creditPrinter();
    char f_or_v;
    float x, y, z;

    int count=0;
    FILE* fr = fopen("teapot.obj", "r");
    if(fr==NULL){
        printf("file couldn't read!\n");
        exit(1);
    }
    while (!feof(fr)){ // counting the number of lines
        fscanf(fr, "%c %f %f %f\n", &f_or_v, &x, &y, &z);
        if(f_or_v == 'f'){
            continue;
        }
        count++;
     }
    fclose(fr);


    struct Point3D* point = malloc(count*3*sizeof(float)); //a struct array

    FILE* fp = fopen("teapot.obj", "r");
    int c=0;
    while(!feof(fp)){
        fscanf(fp, "%c %f %f %f\n", &f_or_v, &x, &y, &z);
        if(f_or_v=='f'){
            continue;
        }
        point[c].x=x;
        point[c].y=y;
        point[c].z=z;
        c++;
    }

    calculateCenter(point, count);

    fclose(fp);
    return 0;
}
