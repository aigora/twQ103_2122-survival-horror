#include<stdio.h>
#define TAM_NAME 15
#define TAM_MAX 500

void banner(){
	
	printf("********************************************************************************\n");
	printf("********************************************************************************\n");
	printf("*****************BIENVENIDOS A VUESTRA PEOR PESADILLA***************************\n");
	printf("*****************SERAS CAPAZ DE HACERTE CON EL RECORD***************************\n");
	printf("***************************SURVIVAL HORROR**************************************\n");
	printf("*********************UN JUEGO PARA LOS MAS VALIENTES****************************\n");
	printf("********************************************************************************\n");
	printf("********************************************************************************\n");
	
}

char menu(){
	char opcion;
	printf("Elige la opcion desada:\n");
	printf("R-Registrar un nuevo usuario\n");
	printf("E-Eliminar uno de los usuarios\n");
	printf("I- Imprimir lista de puntuacion de los usuarios\n");
	printf("N-Niveles disponibles\n");
	printf("D-Devolver a la pagina anterior\n");
	printf("S-Salir del juego\n");
	scanf("%c",&opcion);
	return opcion;
}

struct TJugador{
	
	char nickname[TAM_NAME];
	int nivel;
	int puntuacion;
	float HorasJugadas;
	
	
};

int main(){
	
	struct TJugador jugadores[TAM_MAX];
	char opcion;
	int i, contador=0;
	
	banner();
	
    
    FILE * pfichero;
     
    

	
	do{
		opcion=menu();
		
		switch (opcion){
			case 'I': 
			 pfichero = fopen("jugadores.txt", "r");
	         if(pfichero == NULL){
	         printf("Error en la apertura del fichero");
		     return 0;
		    } 
		     i=0;
		     while (fscanf(pfichero, "%s %d %d %f", jugadores[i].nickname, &jugadores[i].nivel, &jugadores[i].puntuacion, &jugadores[i].HorasJugadas) != EOF){
		    	printf("%s-NickName %d-Nivel %d-PuntuacionMaxima %.2f-HorasJugadas\n\n", jugadores[i].nickname, jugadores[i].nivel, jugadores[i].puntuacion, jugadores[i].HorasJugadas);
		    	contador++;
		    	i++;
			}
			
			fclose(pfichero);
			break;
			 
			
			 
			case 'R': 
			 printf("Introduce el nikname del nuevo jugador:\n");
			 fflush(stdin);
             scanf("%s", jugadores[contador].nickname);
             jugadores[contador].nivel=0;
             jugadores[contador].puntuacion=0;
             jugadores[contador].HorasJugadas=0;
             contador ++;
			 break;
            
	}
		
	
	} while (opcion != 'S');
	


}
