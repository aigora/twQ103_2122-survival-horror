#include<stdio.h>
#include<string.h>
#define MAX_JUG 100

//Cada jugador puede jugar con hasta x personajes en funci�n del nivel que se juegue
struct TPersonaje{
	char  nombrepers[20];
	char contrasenna[10];         
	int  vida;
};

struct TJugador{
	char  nombrejug[20];         
	char contrasenna[20];
	int survivalcoins;
	//struct personajes *pers[];
};
/*
void ComprobarDatosJugadores(char palabra1[20], char palabra2[20], contador){
	int i, repetido=0;
	
	for(i=0, i<contador; i++){
		if(strcmp(palabra1,palabra2)==0){
			printf("Nombre de ju")
		}
	}
}*/
char menu(){
	
	char opcion;
	printf("Survival Horror-Un juego para los mas valientes\n Bienvenido al menu de opciones:\n");
	printf("Introduce la opcion que desees:\n");
	printf("************************\n");
	printf("I-iniciar sesi�n para una nueva partida\n");
	printf("R-Registrarse\n");
	printf("X-Intrucciones del juego\n");
	printf("S-Salir del juego\n");
	printf("************************\n");
	fflush(stdin);
	scanf("%c",&opcion);
	
	return opcion;
	
}


int main(){
	
	struct TJugador jugadores[MAX_JUG];
	int i, contador, repetido;
	char opcion;
	char inicioNombrejug[20], inicioContrasenna[20];
	FILE*pfichero;
	
	do{
		opcion=menu(); //Se llama ala funci�n men�
		
		switch (opcion){
			
			case 'I': printf("BIENVENIDO DE NUEVO\n INICIAR SESION:\n");
			         system("PAUSE");
			
			            //En primer lugar se abre el fichero
			            pfichero=fopen("usuarios.txt","r"); //Lo abrimos en modo lectura
			            
			            //Se comprueba si existe el fichero
			            if(pfichero==NULL){
			            	printf("ERROR EN LA LECTURA DEL FICHERO");
			            	return 0;
						}
						
						//Se comprueban los personajes existentes en el fichero
						i=0, contador=0;
						while(fscanf(pfichero,"%s %s %d", jugadores[i].nombrejug, jugadores[i].contrasenna, &jugadores[i].survivalcoins)!=EOF){
							i++;
							contador++;
						} 
						
						printf("Ya existen %d jugadores\n", contador);
						
						//Por ultimo procedemos a cerrar el fichero
						fclose(pfichero);
						
					
						
						//SE piden los datos de inicio de sesi�n al jugador
						
						do{
							printf("Introduzca su nickname de jugador de SURVIVAL HORROR:\n");
							fflush(stdin);
							scanf("%s",inicioNombrejug);
							printf("Introduzca su contrase�a:\n");
							fflush(stdin);
							scanf("%s",inicioContrasenna);
							
							//Verificamos que los datos introducidos son los correctos
							for(i=0; i<contador; i++){
								if(strcmp(inicioNombrejug,jugadores[i].nombrejug)==0 && strcmp(inicioContrasenna, jugadores[i].contrasenna)==0){
									repetido=1;
									break;
								} else{
									repetido=0;
								}
							}
							
							if(repetido==1){
								printf("Bienvenido de nuevo %s\n",inicioNombrejug);
							} else{
								printf("Usuario y/o contrasenna no validos\n");
							}
							
						}while(repetido==0); //Pregunta hasta que encuentra un usuario y contrase�a ya existentes
						
						
						
			
			
			
			
			
			
				
		}
	} while (opcion!='S');
}
