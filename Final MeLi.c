#include <stdio.h>
#include <string.h>
#include <conio.h>
#define IT 50    //cantidad maxima de items por vendeddor 
#define SL 20000 //cantidad maxima de vendedores


typedef struct {
    int item_id;
    char title[50];
    int cat_id;
    char cat_name[20];
}it;

typedef struct {
    it seller[IT];
    char name[20];
    int edad[3]
}sel;

typedef struct {
    sel MLA[SL];
    sel MLB[SL];
} sit ;

sit site;

void vacio();
void cargar();
void mostrar();

char site_id[4];
long int seller_id;

int main (){


    int R;
    int key;

    vacio();

    do{
        do{
            printf("\n ¿Que desea hacer?\n\n");
            printf("1) Cargar datos.\n\n");
            printf("2) Mostrar datos y generar archivo de log.\n\n");
            printf(" Respuesta: ");
            scanf("%i", &R);
        }while(R<1 || R>3);

        switch(R){
            case 1:
                R=0;
                cargar();
                break;
            case 2:
                mostrar();
                break;

        }

        printf("\n\n¿Desea realizar otra operacion? \n");
        printf("1) si\n");
        printf("2) no\n");
        printf("Respuesta:");
        scanf("%i", &R);
        if(R==1){
            key=1;
        }
        if(R==2){
            key=0;
        }

    }while(key==1 );

    system("pause");
    return 0;

}

void vacio(){
    long int i,j;

    for(j=0 ; j<SL ; j++){
        for(i=0; i<IT ; i++){
            site.MLA[j].seller[i].item_id=0;
            site.MLB[j].seller[i].item_id=0;
        }
    }
}

void cargar(){

    int aux=0;
    long int i;

        printf("\n\n Inserte id del sitio: (MLA , MLB)\n\n");
        printf("Respuesta: ");
        fflush(stdin);
        fgets(site_id, 4, stdin);

        if (strcmp(site_id, "MLA") == 0){
            printf("\n\n Inserte id del vendedor: \n\n");
            printf("Respuesta: ");
            scanf("%i", &seller_id);

            for(i=0 ; i<IT && aux==0; i++){
                if (site.MLA[seller_id].seller[i].item_id==0){
                    site.MLA[seller_id].seller[i].item_id=i+1;
                    aux=1;

            printf("\n\n Inserte el titulo del item\n\n");
            printf("Respuesta: ");
            fflush(stdin);
            fgets(site.MLA[seller_id].seller[i].title, 50, stdin);


            printf("\n\n Inserte id de la categoria\n\n");
            printf("Respuesta: ");
            scanf("%i" , &site.MLA[seller_id].seller[i].cat_id);


            printf("\n\n Inserte nombre de la categoria\n\n");
            printf("Respuesta: ");
            fflush(stdin);
            fgets(site.MLA[seller_id].seller[i].cat_name, 20, stdin);

                }
            }
        }
        if (strcmp(site_id, "MLB") == 0){
            printf("\n\n Inserte id del vendedor: \n\n");
            printf("Respuesta: ");
            scanf("%i", &seller_id);


            for(i=0 ; i<IT && aux==0; i++){
                if (site.MLB[seller_id].seller[i].item_id==0){
                    site.MLB[seller_id].seller[i].item_id=i+1;
                    aux=1;


            printf("\n\n Inserte el titulo del item\n\n");
            printf("Respuesta: ");
            fflush(stdin);
            fgets(site.MLB[seller_id].seller[i].title, 50, stdin);


            printf("\n\n Inserte id de la categoria\n\n");
            printf("Respuesta: ");
            scanf("%i" , &site.MLB[seller_id].seller[i].cat_id);


            printf("\n\n Inserte nombre de la categoria\n\n");
            printf("Respuesta: ");
            fflush(stdin);
            fgets(site.MLB[seller_id].seller[i].cat_name, 20, stdin);

                }
            }
        }
        else{
            printf("no corresponde anigun sitio");
        }
}


void mostrar(){

    FILE *arch;

    long int i, j, R;

    printf("\n\n Sitio ID: \n\n");
    printf("1) MLA\n");
    printf("2) MLB\n");
    printf("Respuesta:");
    scanf("%i", &R);

    arch=fopen("archivo_log.txt", "a");
    if(arch==NULL){
        printf("\n error en apertura del archivo");
    }

    do{
        printf("\n\n Ingrese ID del vendedor (Finaliza con numero negativo):");
        scanf("%i", &seller_id);


            if(R==1 && seller_id>=0){
                fprintf(arch,"\n\n Items del vendedor MLA %i:\n", seller_id);
                printf("\n\n Items del vendedor MLA %i:\n\n", seller_id);
                for(i=0; i<(IT) ; i++){
                    if(site.MLA[seller_id].seller[i].item_id!=0){

                        printf("ItemID= %i\n", site.MLA[seller_id].seller[i].item_id);
                        printf("Titulo= %s", site.MLA[seller_id].seller[i].title);
                        printf("CatID= %i \n", site.MLA[seller_id].seller[i].cat_id);
                        printf("CatName= %s\n\n", site.MLA[seller_id].seller[i].cat_name);

                        fprintf(arch,"ItemID= %i\n", site.MLA[seller_id].seller[i].item_id);
                        fprintf(arch,"Titulo= %s", site.MLA[seller_id].seller[i].title);
                        fprintf(arch,"CatID= %i \n", site.MLA[seller_id].seller[i].cat_id);
                        fprintf(arch,"CatName= %s\n\n", site.MLA[seller_id].seller[i].cat_name);
                    }

                }
            }

            if(R==2 && seller_id>=0){
                fprintf(arch,"\n\n Items del vendedor MLB %i:\n", seller_id);
                printf("\n\n Items del vendedor MLB %i:\n\n", seller_id);
                for(j=0; j<(IT) ; j++){

                    if(site.MLB[seller_id].seller[j].item_id!=0){

                        printf("ItemID= %i\n", site.MLB[seller_id].seller[j].item_id);
                        printf("Titulo= %s", site.MLB[seller_id].seller[j].title);
                        printf("CatID= %i \n", site.MLB[seller_id].seller[j].cat_id);
                        printf("CatName= %s\n\n", site.MLB[seller_id].seller[j].cat_name);

                        fprintf(arch,"ItemID= %i\n", site.MLB[seller_id].seller[j].item_id);
                        fprintf(arch,"Titulo= %s", site.MLB[seller_id].seller[j].title);
                        fprintf(arch,"CatID= %i \n", site.MLB[seller_id].seller[j].cat_id);
                        fprintf(arch,"CatName= %s\n\n", site.MLB[seller_id].seller[j].cat_name);
                    }

                }
            }


    }while(seller_id>=0);

    fclose(arch);
    getch();


}
