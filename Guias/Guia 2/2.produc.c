#include <stdio.h>
struct producto
{
char codigo[10];
char desc[50];
int precio;
}



Gansito={"10","Confite",11000},
Redbull={"11","Bebida energetica",1500};



int main()
{
    printf("Gansito\n Codigo: %s\n Descripcion %s\n Precio:$ %i\n ",Gansito.codigo,Gansito.desc,Gansito.precio);
    printf("Redbull\n Codigo: %s\n Descripcion %s\n Precio:$ %i\n ",Redbull.codigo,Redbull.desc,Redbull.precio);
    if (Gansito.precio>Redbull.precio)
    {
        printf("El producto mas caro es el gansito");
    }
    else if ((Gansito.precio<Redbull.precio))
    {
        printf("El producto mas caro es la Redbull ");
    }

}



