#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {

    char id[5][10];
    char nombre[5][30];
    int stock[5];
    float precio[5];
    float total_ganancias=0, venta=0;
    int opc1, cont=0, cantidad, aux, len;
    do{
        printf("Seleccione una opcion:\n");
        printf("1. Registrar producto\n");
        printf("2. Vender producto\n");
        printf("3. Reabastecer producto\n");
        printf("4. Mostrar detalle del producto\n");
        printf("5. Mostrar total de ganancias\n");
        printf("6. Salir\n");
        printf(">> ");
        scanf("%d",&opc1);
        switch (opc1)
        {
        case 1:
            if (cont < 5)
            {
                printf("Ingrese el id del producto %d: ", cont);
                scanf("%s", &id[cont]);
                printf("Ingrese el nombre del producto %d: ", cont);
                fflush(stdin);
                fgets(nombre[cont], 30, stdin);

                len = strlen(nombre[cont]) - 1;
                nombre[cont][len] = '\0';

                printf("Ingrese el stock del producto %d: ", cont);
                scanf("%d", &stock[cont]);
                printf("Ingrese el precio del producto %d: ", cont);
                scanf("%f", &precio[cont]);
                cont++;
            }
            break;
        case 2:
            printf("Seleccione el producto a vender: \n");
            printf("#\t\tID\t\tNombre\t\tStock\t\tPrecio\n");
            for (int i = 0; i < cont; i++)
            {
                printf("%d\t\t%s\t\t%s\t\t%d\t\t%.2f\n",i,id[i],nombre[i],stock[i],precio[i]);
            }
            printf(">> ");
            scanf("%d",&aux);
            printf("Ingrese la cantidad de %s a vender: ",nombre[aux]);
            scanf("%d",&cantidad);
            if (cantidad <= stock[aux])
            {
                venta = cantidad * precio[aux];
                printf("El valor de la venta es: %.2f\n",venta);
                stock[aux]-=cantidad;
                if (cantidad >= 20)
                {
                    printf("10 porciento de descuento por compra de 20 unidades o mas\n");
                    venta*=0.9;
                    printf("El valor de la venta con descuento es: %.2f\n",venta);
                }
                total_ganancias+=venta;
            }
            break;
        case 3:
            printf("Seleccione el producto a reabastecer: \n");
            printf("#\t\tID\t\tNombre\t\tStock\t\tPrecio\n");
            for (int i = 0; i < cont; i++)
            {
                printf("%d\t\t%s\t\t%s\t\t%d\t\t%.2f\n", i, id[i], nombre[i], stock[i], precio[i]);
            }
            printf(">> ");
            scanf("%d", &aux);
            printf("Ingrese la cantidad de %s a reabastecer: ",nombre[aux]);
            scanf("%d",&cantidad);
            if (cantidad > 0)
            {
                stock[aux]+=cantidad;
                printf("El nuevo stock del producto %s es: %d\n",nombre[aux],stock[aux]);
            }
            break;
        case 4:
            char auxNombre[30];
            int f=0;
            printf("Ingrese el nombre del producto a buscar: ");
            fflush(stdin);
            fgets(auxNombre,30,stdin);
            len = strlen(auxNombre) - 1;
            auxNombre[len] = '\0';
            for (int i = 0; i < cont; i++)
            {
                if (strcmp(nombre[i],auxNombre)==0){
                    printf("#\t\tID\t\tNombre\t\tStock\t\tPrecio\n");
                    printf("%d\t\t%s\t\t%s\t\t%d\t\t%.2f\n", i, id[i], nombre[i], stock[i], precio[i]);
                    f=1;
                }
            }
            if(f==0){
                printf("No existe el producto buscado\n");
            }
            break;
        case 5:
            printf("Las ganancias totales son: %.2f\n",total_ganancias);
            break;
        default:
            break;
        }

    }while(opc1!=6);


    return 0;
}