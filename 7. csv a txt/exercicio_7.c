/*  Boletín 3
 * Exercicio 7: De .csv a .txt
 * Autor: Daniel Souto Pazó
*/

#include <stdio.h>

void csv_to_txt(FILE *file_r, FILE *file_w, char* name_r, char* name_w);
void skipLine(FILE *file_r);

int main()
{
    //Abre os arquivos .csv e .txt, en modo de lectura e escritura, respectivamente
    char *datos = "weatherdata-420-72.csv";
    char *datos_txt = "weatherdata-420-72.txt";
    FILE *fpr = fopen(datos, "rt");
    FILE *fpw = fopen(datos_txt, "wt");
    if (fpr == NULL){
        printf("Erro: o arquivo %s non foi aberto", datos);
        return 1;
    } if(fpw == NULL){
        printf("Erro: o arquivo %s non foi aberto", datos_txt);
        return 1;
    }
    
    //Imprime o contido do ficheiro .csv nun ficheiro .txt, sen caracteres '"', ',' ou '/' e sen a primeira liña
    csv_to_txt(fpr, fpw, datos, datos_txt);
    
    fclose(fpw);
    fclose(fpr);

    return 0;
}

//Imprime o contido do ficheiro .csv nun ficheiro .txt, sen caracteres '"', ',' ou '/' e sen a primeira liña
void csv_to_txt(FILE *file_r, FILE *file_w, char* name_r, char* name_w) {
    printf("\nCopiando datos de \"%s\" a \"%s\"... ", name_r, name_w);
    skipLine(file_r);
    
    char temp;
    do{
        temp = fgetc(file_r);
        if(temp != '"' && temp != ',' && temp != '/') fprintf(file_w, "%c", temp);
    }while(temp != EOF);
    
    printf("[completado]\n");
}

//Move o punto de lectura á seguinte liña do ficheiro .csv
void skipLine(FILE *file_r){
    char c;
    do { c = fgetc(file_r); } while (c != '\n');
}
