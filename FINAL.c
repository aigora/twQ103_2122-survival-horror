#include<stdio.h>
#include<string.h>
#include<locale.h>
#define MAX_JUG 100

//Cada jugador puede jugar con hasta x personajes en función del nivel que se juegue
struct TPersonaje{
	char  nombrepers[20];
	char contrasenna[10];         
	int  vida;
	int survivalcoins;
};

struct TJugador{
	char  nombrejug[20];         
	char contrasenna[20];
};

void trivial (int*);
char menu();
void Instrucciones(char*info);
void cartelTitulo();
void cartelIniciarSesion();
void cartelRegistrarse();
void cartelInstrucciones();
void cartelSalida();
int main(){
	setlocale (LC_CTYPE,"spanish");
	cartelTitulo();
	struct TJugador jugadores[MAX_JUG];
	int i, contador, repetido;
	char opcion, informacion;
	char inicioNombrejug[20], inicioContrasenna[20];
	FILE*pfichero;

	do{
		opcion=menu(); //Se llama ala función menú
		
		switch (opcion){
			
			case 'I': cartelIniciarSesion();
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
						while(fscanf(pfichero,"%s %s", jugadores[i].nombrejug, jugadores[i].contrasenna)!=EOF){
							i++;
							contador++;
						} 
						
						printf("Ya existen %d jugadores\n", contador);
						
						//Por ultimo procedemos a cerrar el fichero
						fclose(pfichero);
						
					
						
						//SE piden los datos de inicio de sesión al jugador
						
						do{
							printf("Introduzca su nickname de jugador de SURVIVAL HORROR:\n");
							fflush(stdin);
							scanf("%s",inicioNombrejug);
							printf("Introduzca su contraseña:\n");
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
							
						}while(repetido==0); //Pregunta hasta que encuentra un usuario y contraseña ya existentes
						break;
			case 'R': cartelRegistrarse();
				  printf("\nDebes crear un nuevo usuario de jugador, siguiendo las instrucciones:\n");
			                
			         //Abrimos el fichero nuevamente
			         pfichero=fopen("usuarios.txt","r");//En modo lectura para ver los usuarios ya existentes
			         //Comprobamos que existe el fichero
			         if(pfichero==NULL){
			         	printf("ERROR EN LA LECTURA DEL FICHERO");
			         	return 0;
					}
					 
					 	//Se comprueban los personajes existentes en el fichero
						i=0, contador=0;
						while(fscanf(pfichero,"%s %s", jugadores[i].nombrejug, jugadores[i].contrasenna)!=EOF){
							i++;
							contador++;
						} 
						
						
						
						printf("Ya existen %d jugadores\n", contador);
						
						//Por ultimo procedemos a cerrar el fichero
						fclose(pfichero);
						
						//Se procede a pedir los datos al nuevo jugador y se compruba que no coincida con ninguno ya existente
						
						do{
							printf("Introduxcs el nickname del nuevo jugador:\n");
							fflush(stdin);
							scanf("%s",inicioNombrejug);
							for(i=0;i<contador;i++){
								if(strcmp(inicioNombrejug,jugadores[i].nombrejug)==0){
									repetido=1;
									break;
								} else {
									repetido=0;
								} 
							}
							
							if(repetido==1){
								printf("Lo sentimos ese nombre de jugador ya ha sido utilizado, prueba de nuevo\n");
							} else {
								printf("Nombre de jugador aceptado\n");
								strcpy(jugadores[contador].nombrejug,inicioNombrejug);
							}
						} while(repetido==1);
						
						printf("Introduzca su contrasenna para su inicio de sesion.\n");
						fflush(stdin);
						scanf("%s",jugadores[contador].contrasenna);
						
						
						for(i=0;i<=contador;i++){
							printf("%s %s\n",jugadores[i].nombrejug,jugadores[i].contrasenna);
						}
						
						//Ahora se abre el fichero en modo escritura para guardar los datos del nuevo jugador
						
						pfichero=fopen("usuarios.txt","w");
						
						if(pfichero==NULL){
							printf("ERROR EN LA ESCRITURA DEL FICHERO");
							return 0;
						}
						
						for(i=0; i<=contador; i++){
							fprintf(pfichero,"%s %s\n",jugadores[i].nombrejug,jugadores[i].contrasenna);
						}
					
						
						//Cerramos el fichero utilizado
					    fclose(pfichero);
					    system("PAUSE");
					    break;
							
			case 'X': cartelInstrucciones();
				
					Instrucciones(&informacion);
					break;
	}
			if(opcion=='I' || opcion=='R')
			{
				printf("\n");
	
				int oport=0,numeropers=0,codigo=0,muneca=0,mechero=0,mata=0,resp1=1,resp2=0;
				char respuesta1[8],respuesta2[7],ret,cocina;
	
	
		//Puntero a estructura personajes
		struct TPersonaje pers1,pers2;
		
		
		//Bucle para que no de 0 personajes, números negativos o más de 4
		do
		{
			//Pregunta con cuántos personajes quiere jugar
			printf("Introduce el número de personajes (máximo 2):\n");
			scanf("%i",&numeropers);
			fflush(stdin);
		}while(numeropers<=0 || numeropers>2);

		//Pedir los nombre de personajes 1 por 1 y asignar vida
		printf ("\nEscribe el nombre del primer personaje:\n");
		fflush(stdin);
		gets(pers1.nombrepers);
		pers1.vida=40; 
		pers1.survivalcoins=0;
		if(numeropers>1)
		{
			printf ("\nEscribe el nombre del segundo personaje:\n");
			fflush(stdin);
			gets(pers2.nombrepers);
			pers2.vida=40;
			pers2.survivalcoins=0;
		}
		
		printf("\n\007¡Buenos días, %s ! Como recordarás, eres un alumno del Grado de Historia en la Universidad Complutense de Madrid, y estás preparando tu TFG: <<La España vaciada. Mitos y leyendas y su relación con la\n despoblación>>. Para finalizar el TFG has decidido viajar a uno de los llamados pueblos fantasma de España, Belchite, en Zaragoza.\n\n",pers1.nombrepers);
		system("PAUSE");
		if(numeropers==1)
		{
		
		printf("\n\007¡Por fin alguien me ve! Soy Carlos, la última persona que habitó esta casa, si quieres salir de aquí, tendrás que demostrar tu ingenio tomando buenas decisiones según se te planteen. En caso de que tomes muchas malas decisiones, esta casa se encargará de matarte.\n");
		system("PAUSE");
		
			//PREGUNTA 1
			if(pers1.vida!=0)
			{
				do
				{
					printf("\n- %s -\n",pers1.nombrepers);
					printf("\nDecides dar una vuelta por la cocina y ves una hoja.\na. La coges y la lees.\nb. La ignoras.\n");
					fflush(stdin);
					scanf("%c",&respuesta1[resp1]);
				}while(respuesta1[resp1]!='a' && respuesta1[resp1]!='b');
				
				if(respuesta1[resp1]=='a')
				{
					printf("- PREGUNTAS TRIVIAL -\n");
					trivial (&pers1.survivalcoins);
					printf("Has conseguido %d survivalcoins.\n",pers1.survivalcoins);
				} else
				{
					printf("No sé yo si igual te habría venido bien leerla.\n");
				}
				
				resp1++;
			}
			system("PAUSE");
			
		
			//PREGUNTA 2
			if(pers1.vida!=0)
			{
				do
				{
					printf("\n- %s -\n",pers1.nombrepers);
					printf("A continuación, ¿qué quieres hacer?\na. Coger el reloj que hay en la pared para tener una referencia horaria.\nb. Buscar un mechero.\nc. Buscar comida.\n");
					fflush(stdin);
					scanf("%c",&respuesta1[resp1]);
				}while(respuesta1[resp1]!='a' && respuesta1[resp1]!='b' && respuesta1[resp1]!='c');
				
				if(respuesta1[resp1]=='a')
				{
					printf("¡Vaya! El reloj no funciona, pero al cogerlo, ha caído una nota <<C+A <3>>, ¡no me digas que los amores adolescentes no te dan vida!\n");
					printf("Te quedan %d puntos de vida\n",pers1.vida+5);
				} else
				{
					printf("¡Has encontrado un mechero! Igual te es de utilidad, de momento te has quemado.\n");
					printf("Te quedan %d puntos de vida\n",pers1.vida-10);
				}
				system("PAUSE");
				if(pers1.survivalcoins>=100)
				{
					do
					{
					printf("\nTienes survivalcoins suficientes para rehacer la decisión, ¿quieres hacerlo ahora?\na.Sí\nb.No\n");
					fflush(stdin);
					scanf("%c",&ret);
					}while(ret!='a' && ret!='b');
					switch(ret)
					{
						case 'a':	printf("Diga su nueva elección\n");
									fflush(stdin);
									scanf("%c",&respuesta1[resp1]);
									if(respuesta1[resp1]=='a')
									{
										printf("¡Vaya! El reloj no funciona, pero al cogerlo, ha caído una nota <<C+A <3>>, ¡no me digas que los amores adolescentes no te dan vida!\n");
										printf("Te quedan %d puntos de vida\n",pers1.vida+5);
									}else if(respuesta1[resp1]=='b'||respuesta1[resp1]=='c')
									{
										printf("¡Has encontrado un mechero! Igual te es de utilidad, de momento te has quemado.\n");
										printf("Te quedan %d puntos de vida\n",pers1.vida-10);
									}
									pers1.survivalcoins-=100;
									break;

						case 'b': 
									printf("Ahorrar es bueno a veces, supongo...\n");
									break;
					}
					system("PAUSE");
				}
				if(respuesta1[resp1]=='a')
				{
					pers1.vida+=5;
					printf("\nVida %s: %d\n\n",pers1.nombrepers,pers1.vida);
				} else
				{
					pers1.vida-=10;
					mechero++;
					printf("\nVida %s: %d\n\n",pers1.nombrepers,pers1.vida);
				}
				resp1++;
			}
			system("PAUSE");
			
			//PREGUNTA 3
			if(pers1.vida!=0 && respuesta1[2]=='a')
			{
				do
				{
					printf("\n- %s -\n",pers1.nombrepers);
					printf("\nAhora toca moverse para:\na. Inspeccionar los muebles de la cocina.\nb. Inspeccionar el resto de la casa.\n");
					fflush(stdin);
					scanf("%c",&respuesta1[resp1]);
				}while(respuesta1[resp1]!='a' && respuesta1[resp1]!='b');
				
				if(respuesta1[resp1]=='a')
				{
					printf("¡Has encontrado un mechero! Igual te es de utilidad, de momento te has quemado.\n");
					printf("Te quedan %d puntos de vida\n",pers1.vida-10);
				} else
				{
					printf("La puerta está cerrada con clave, ya sabes.\n");
					printf("Te quedan %d puntos de vida\n",pers1.vida+5);
				}
				system("PAUSE");
				if(pers1.survivalcoins>=100)
				{
					do
					{
					printf("\nTienes survivalcoins suficientes para rehacer la decisión, ¿quieres hacerlo ahora?\na.Sí\nb.No\n");
					fflush(stdin);
					scanf("%c",&ret);
					}while(ret!='a' && ret!='b');
					switch(ret)
					{
						case 'a':	printf("Diga su nueva elección\n");
									fflush(stdin);
									scanf("%c",&respuesta1[resp1]);
									if(respuesta1[resp1]=='b')
									{
										printf("La puerta está cerrada con clave, ya sabes.\n");
										printf("Te quedan %d puntos de vida\n",pers1.vida+5);
									}else if(respuesta1[resp1]=='a')
									{
										printf("¡Has encontrado un mechero! Igual te es de utilidad, de momento te has quemado.\n");
										printf("Te quedan %d puntos de vida\n",pers1.vida-10);
									}
									pers1.survivalcoins-=100;
									break;

						case 'b': 
									printf("Ahorrar es bueno a veces, supongo...\n");
									break;
					}
					system("PAUSE");
				}
				if(respuesta1[resp1]=='a')
				{
					pers1.vida-=10;
					mechero++;
					printf("\nVida %s: %d\n\n",pers1.nombrepers,pers1.vida);
				} else
				{
					pers1.vida+=5;
					printf("\nVida %s: %d\n\n",pers1.nombrepers,pers1.vida);
				}
				resp1++;
			}
			system("PAUSE");
			
			//PREGUNTA 4
			if(pers1.vida!=0 && mechero)
			{
				do
				{
					printf("\n- %s -\n",pers1.nombrepers);
					printf("\nYa tienes el mechero, quieres:\na. Cocinar algo.\nb. Salir de la cocina para ver el resto de la casa.\n");
					fflush(stdin);
					scanf("%c",&respuesta1[resp1]);
				}while(respuesta1[resp1]!='a' && respuesta1[resp1]!='b');
				
				if(respuesta1[resp1]=='a')
				{
					printf("El gas estaba abierto cuando has llegado, corres hacia la puerta, pero está cerrada. Mueres trágicamente.\n");
					printf("Te quedan %d puntos de vida\n",pers1.vida-pers1.vida);
				} else
				{
					printf("La puerta está cerrada con clave, ya sabes.\n");
					printf("Te quedan %d puntos de vida\n",pers1.vida+5);
				}
				system("PAUSE");
				if(pers1.survivalcoins>=100)
				{
					do
					{
					printf("\nTienes survivalcoins suficientes para rehacer la decisión, ¿quieres hacerlo ahora?\na.Sí\nb.No\n");
					fflush(stdin);
					scanf("%c",&ret);
					}while(ret!='a' && ret!='b');
					switch(ret)
					{
						case 'a':	printf("Diga su nueva elección\n");
									fflush(stdin);
									scanf("%c",&respuesta1[resp1]);
									if(respuesta1[resp1]=='a')
									{
										printf("El gas estaba abierto cuando has llegado, corres hacia la puerta, pero está cerrada. Mueres trágicamente.\n");
										printf("Te quedan %d puntos de vida\n",pers1.vida-pers1.vida);
									}else if(respuesta1[resp1]=='b')
									{
										printf("La puerta está cerrada con clave, ya sabes.\n");
										printf("Te quedan %d puntos de vida\n",pers1.vida+5);
									}
									pers1.survivalcoins-=100;
									break;

						case 'b': 
									printf("Ahorrar es bueno a veces, supongo...\n");
									break;
					}
					system("PAUSE");
				}
				if(respuesta1[resp1]=='a')
				{
					pers1.vida==0;
					printf("\n%s ha muerto\n\n",pers1.nombrepers);
					return 0;
				} else
				{
					pers1.vida+=5;
					printf("\nVida %s: %d\n\n",pers1.nombrepers,pers1.vida);
				}
				resp1++;
			}
			system("PAUSE");
			
			//PREGUNTA 5
			if(pers1.vida!=0 && respuesta1[3]=='b'||pers1.vida!=0 && respuesta1[4]=='b')
			{
				do
				{
					printf("\n- %s -\n",pers1.nombrepers);
					printf("\n¿Cómo quieres abrir la puerta? \na. Esta casa está destartalada, con dos patadas la puerta está abajo.\nb. Buscar alguna pista para conseguir el código.\n");
					fflush(stdin);
					scanf("%c",&respuesta1[resp1]);
				}while(respuesta1[resp1]!='a' && respuesta1[resp1]!='b');
				
				if(respuesta1[resp1]=='a')
				{
					printf("La puerta no se cae, sin embargo, se escuchan pasos al otro lado de la puerta. Decides:\na. Gritar para que te oigan y te ayuden.\nb. Callarte.\n");
					fflush(stdin);
					scanf("%c",&cocina);
					if(cocina=='a')
					{
						printf("Has muerto.\n");
					}else
					{
						printf("La puerta está cerrada con clave, ya sabes.\n");
					}
				} else
				{
					printf("Te quedan %d puntos de vida\n",pers1.vida+5);
				}
				system("PAUSE");
				if(pers1.survivalcoins>=100)
				{
					do
					{
					printf("\nTienes survivalcoins suficientes para rehacer la decisión, ¿quieres hacerlo ahora?\na.Sí\nb.No\n");
					fflush(stdin);
					scanf("%c",&ret);
					}while(ret!='a' && ret!='b');
					switch(ret)
					{
						case 'a':	printf("Diga su nueva elección\n");
									fflush(stdin);
									scanf("%c",&respuesta1[resp1]);
									if(respuesta1[resp1]=='a')
									{
										if(cocina=='a')
										{
											printf("Has muerto.\n");
										}else
										{
											printf("La puerta está cerrada con clave, ya sabes.\n");
										}
									}else if(respuesta1[resp1]=='b')
									{
										printf("Te quedan %d puntos de vida\n",pers1.vida+5);
									}
									pers1.survivalcoins-=100;
									break;

						case 'b': 
									printf("Ahorrar es bueno a veces, supongo...\n");
									break;
					}
					system("PAUSE");
				}
				if(respuesta1[resp1]=='a'&& cocina=='a')
				{
					return 0;
				}else if (respuesta1[resp1]=='b')
				{
					pers1.vida+=5;
					printf("\nVida %s: %d\n\n",pers1.nombrepers,pers1.vida);
				}
				resp1++;
			}
			system("PAUSE");
			
			//PREGUNTA 5b
			if(pers1.vida!=0 && respuesta1[resp1-1]=='b'||pers1.vida!=0 && cocina=='b')
			{
				do
				{
					printf("\n- %s -\n",pers1.nombrepers);
					printf("\nDespués de estar buscando, has encontrado 6 ideas, tienes 3 oportunidades:\n1. La hora del reloj\n2. La fecha de la nota de detrás del reloj.\n3. El número que hay pintado en el cuadro que hay colgado.\n4. Los números que están arrancados del microondas.\n5. Los números que no están arrancados del microondas.\n6. La fecha que está señalada en el calendario.\n");
					fflush(stdin);
					scanf("%d",&codigo);
					oport++;
				}while(codigo!=2 && oport<3);
				
				if(codigo==2)
				{
					printf("Efectivamente la fecha en la que Alicia y yo nos conocimos era el código, lo puse porque desde el momento en el que nos vimos supe que jamás se me olvidaría ese día, fuimos tan felices...\nEn fin, que me pongo melancólico, ¡por fin has salido de la cocina! Ahora dirígete a la puerta principal, ya es hora de terminar el TFG.\n\n- FIN -\n");
					return 0;
				} else
				{
					printf("Ya quedaba poco, supongo que la presión te ha podido, has muerto.\n\n");
					pers1.vida=0;
					return 0;
				}
				system("PAUSE");
			}
		}else if(numeropers>1)
		{
			printf("\n\007¡Por fin alguien me ve! Soy Carlos, la última persona que habitó esta casa, si quieres salir de aquí, tendrás que demostrar tu ingenio tomando buenas decisiones según se te planteen. En caso de que tomes muchas malas decisiones, esta casa se encargará de matarte.\n");
			system("PAUSE");
			
			//PREGUNTA 1
			if(pers1.vida!=0)
			{
				do
				{
					printf("\n- %s -\n",pers1.nombrepers);
					printf("\nDecides dar una vuelta por la cocina y ves una hoja.\na. La coges y la lees.\nb. La ignoras.\n");
					fflush(stdin);
					scanf("%c",&respuesta1[resp1]);
				}while(respuesta1[resp1]!='a' && respuesta1[resp1]!='b');
				
				if(respuesta1[resp1]=='a')
				{
					printf("- PREGUNTAS TRIVIAL -\n");
					trivial (&pers1.survivalcoins);
					printf("Has conseguido %d survivalcoins.\n",pers1.survivalcoins);
					
				} else
				{
					printf("No sé yo si igual te habría venido bien leerla.\n");
				}
				
				resp1++;
			}
			system("PAUSE");
			
			//PREGUNTA 9
			if(pers2.vida!=0)
			{
				do
				{
					printf("\n- %s -\n",pers2.nombrepers);
					printf("\nTe encuentras en lo que parece ser una buhardilla, ¿qué quieres hacer?\na. Hacerte con el matainsectos y echarlo por la buhardilla.\nb. Limpiar la buhardilla en busca de una llave.\n");
					fflush(stdin);
					scanf("%c",&respuesta2[resp2]);
				}while(respuesta2[resp2]!='a' && respuesta2[resp2]!='b');
				
				if(respuesta2[resp2]=='a')
				{
					printf("El matainsectos es tóxico y te está provocando un mareo, sin embargo, te lo guardas por lo que pudiera pasar en adelante.\n");
					printf("Te quedan %d puntos de vida\n",pers2.vida-10);
					
				} else
				{
					printf("No has encontrado una llave, pero sí has perdido tiempo y energía.  Ahora te encuentras algo mareado\n");
					printf("Te quedan %d puntos de vida\n",pers2.vida-15);
				}
				system("PAUSE");
				if(pers1.survivalcoins>=100)
				{
				do
				{
					printf("\nTienes survivalcoins suficientes para rehacer la decisión, ¿quieres hacerlo ahora?\na.Sí\nb.No");
					fflush(stdin);
					scanf("%c",&ret);
				}while (ret!='a' && ret!='b');
					switch(ret)
					{
						case 'a':	printf("Diga su nueva elección\n");
									fflush(stdin);
									scanf("%c",&respuesta2[resp2]);
									if(respuesta2[resp2]=='a')
									{
										printf("El matainsectos es tóxico y te está provocando un mareo, sin embargo, te lo guardas por lo que pudiera pasar en adelante.\n");
										printf("Te quedan %d puntos de vida\n",pers2.vida-10);
									}else if(respuesta2[resp2]=='b')
									{
										printf("No has encontrado una llave, pero sí has perdido tiempo y energía.  Ahora te encuentras algo mareado\n");
										printf("Te quedan %d puntos de vida\n",pers2.vida-15);
									}
									pers1.survivalcoins-=100;
									break;
						case 'b': 
									printf("Ahorrar es bueno a veces, supongo...\n");
									break;
					}
				} 
				system("PAUSE");
				if(respuesta2[resp2]=='a')
				{
					pers2.vida-=10;
					mata++;
					printf("\nVida %s: %d\n\n",pers2.nombrepers,pers2.vida);
				} else
				{
					pers2.vida-=15;
					printf("\nVida %s: %d\n\n",pers2.nombrepers,pers2.vida);
				}
				resp2++;
			}
			system("PAUSE");
			
			//PREGUNTA 2
			if(pers1.vida!=0)
			{
				do
				{
					printf("\n- %s -\n",pers1.nombrepers);
					printf("A continuación, ¿qué quieres hacer?\na. Coger el reloj que hay en la pared para tener una referencia horaria.\nb. Buscar un mechero.\nc. Buscar comida.\n");
					fflush(stdin);
					scanf("%c",&respuesta1[resp1]);
				}while(respuesta1[resp1]!='a' && respuesta1[resp1]!='b' && respuesta1[resp1]!='c');
				
				if(respuesta1[resp1]=='a')
				{
					printf("¡Vaya! El reloj no funciona, pero al cogerlo, ha caído una nota <<C+A <3>>, ¡no me digas que los amores adolescentes no te dan vida!\n");
					printf("Te quedan %d puntos de vida\n",pers1.vida+5);
				} else
				{
					printf("¡Has encontrado un mechero! Igual te es de utilidad, de momento te has quemado.\n");
					printf("Te quedan %d puntos de vida\n",pers1.vida-10);
				}
				system("PAUSE");
				if(pers1.survivalcoins>=100)
				{
					do
					{
					printf("\nTienes survivalcoins suficientes para rehacer la decisión, ¿quieres hacerlo ahora?\na.Sí\nb.No\n");
					fflush(stdin);
					scanf("%c",&ret);
					}while(ret!='a' && ret!='b');
					switch(ret)
					{
						case 'a':	printf("Diga su nueva elección\n");
									fflush(stdin);
									scanf("%c",&respuesta1[resp1]);
									if(respuesta1[resp1]=='a')
									{
										printf("¡Vaya! El reloj no funciona, pero al cogerlo, ha caído una nota <<C+A <3>>, ¡no me digas que los amores adolescentes no te dan vida!\n");
										printf("Te quedan %d puntos de vida\n",pers1.vida+5);
									}else if(respuesta1[resp1]=='b'||respuesta1[resp1]=='c')
									{
										printf("¡Has encontrado un mechero! Igual te es de utilidad, de momento te has quemado.\n");
										printf("Te quedan %d puntos de vida\n",pers1.vida-10);
									}
									pers1.survivalcoins-=100;
									break;

						case 'b': 
									printf("Ahorrar es bueno a veces, supongo...\n");
									break;
					}
					system("PAUSE");
				}
				if(respuesta1[resp1]=='a')
				{
					pers1.vida+=5;
					printf("\nVida %s: %d\n\n",pers1.nombrepers,pers1.vida);
				} else
				{
					pers1.vida-=10;
					mechero++;
					printf("\nVida %s: %d\n\n",pers1.nombrepers,pers1.vida);
				}
				resp1++;
			}
			system("PAUSE");
			
			//PREGUNTA 10
			if(pers2.vida!=0)
			{
				do
				{
					printf("\n- %s -\n",pers2.nombrepers);
					printf("\nPara aliviar el mareo, ¿qué prefieres hacer?\na. Abrir la puerta de la buhardilla y salir.\nb. Abrir la ventana y salir al balconcillo.\n");
					fflush(stdin);
					scanf("%c",&respuesta2[resp2]);
				}while(respuesta2[resp2]!='a' && respuesta2[resp2]!='b');
				
				if(respuesta2[resp2]=='a')
				{
					printf("Con el mareo te caes.\n");
					printf("Te quedan %d puntos de vida\n",pers2.vida-5);
					
				} else
				{
					printf("Este aire te está sentando genial.\n");
					printf("Te quedan %d puntos de vida\n",pers2.vida+10);
				}
				system("PAUSE");
				if(pers1.survivalcoins>=100)
				{
				do
				{
					printf("\nTienes survivalcoins suficientes para rehacer la decisión, ¿quieres hacerlo ahora?\na.Sí\nb.No");
					fflush(stdin);
					scanf("%c",&ret);
				}while (ret!='a' && ret!='b');
					switch(ret)
					{
						case 'a':	printf("Diga su nueva elección\n");
									fflush(stdin);
									scanf("%c",&respuesta2[resp2]);
									if(respuesta2[resp2]=='a')
									{
										printf("Con el mareo te caes.\n");
										printf("Te quedan %d puntos de vida\n",pers2.vida-5);
									}else if(respuesta2[resp2]=='b')
									{
										printf("Este aire te está sentando genial.\n");
										printf("Te quedan %d puntos de vida\n",pers2.vida+10);
									}
									pers1.survivalcoins-=100;
									break;
						case 'b': 
									printf("Ahorrar es bueno a veces, supongo...\n");
									break;
					}
				} 
				system("PAUSE");
				if(respuesta2[resp2]=='a')
				{
					pers2.vida-=5;
					printf("\nVida %s: %d\n\n",pers2.nombrepers,pers2.vida);
				} else
				{
					pers2.vida+=10;
					printf("\nVida %s: %d\n\n",pers2.nombrepers,pers2.vida);
				}
				resp2++;
			}
			system("PAUSE");
			
			//PREGUNTA 3
			if(pers1.vida!=0 && respuesta1[2]=='a')
			{
				do
				{
					printf("\n- %s -\n",pers1.nombrepers);
					printf("\nAhora toca moverse para:\na. Inspeccionar los muebles de la cocina.\nb. Inspeccionar el resto de la casa.\n");
					fflush(stdin);
					scanf("%c",&respuesta1[resp1]);
				}while(respuesta1[resp1]!='a' && respuesta1[resp1]!='b');
				
				if(respuesta1[resp1]=='a')
				{
					printf("¡Has encontrado un mechero! Igual te es de utilidad, de momento te has quemado.\n");
					printf("Te quedan %d puntos de vida\n",pers1.vida-10);
				} else
				{
					printf("La puerta está cerrada con clave, ya sabes.\n");
					printf("Te quedan %d puntos de vida\n",pers1.vida+5);
				}
				system("PAUSE");
				if(pers1.survivalcoins>=100)
				{
					do
					{
					printf("\nTienes survivalcoins suficientes para rehacer la decisión, ¿quieres hacerlo ahora?\na.Sí\nb.No\n");
					fflush(stdin);
					scanf("%c",&ret);
					}while(ret!='a' && ret!='b');
					switch(ret)
					{
						case 'a':	printf("Diga su nueva elección\n");
									fflush(stdin);
									scanf("%c",&respuesta1[resp1]);
									if(respuesta1[resp1]=='b')
									{
										printf("La puerta está cerrada con clave, ya sabes.\n");
										printf("Te quedan %d puntos de vida\n",pers1.vida+5);
									}else if(respuesta1[resp1]=='a')
									{
										printf("¡Has encontrado un mechero! Igual te es de utilidad, de momento te has quemado.\n");
										printf("Te quedan %d puntos de vida\n",pers1.vida-10);
									}
									pers1.survivalcoins-=100;
									break;

						case 'b': 
									printf("Ahorrar es bueno a veces, supongo...\n");
									break;
					}
					system("PAUSE");
				}
				if(respuesta1[resp1]=='a')
				{
					pers1.vida-=10;
					mechero++;
					printf("\nVida %s: %d\n\n",pers1.nombrepers,pers1.vida);
				} else
				{
					pers1.vida+=5;
					printf("\nVida %s: %d\n\n",pers1.nombrepers,pers1.vida);
				}
				resp1++;
			}
			system("PAUSE");
			
			//PREGUNTA 11
			if(pers2.vida!=0)
			{
				do
				{
					printf("\n- %s -\n",pers2.nombrepers);
					printf("\nYa estás mejor, te recompones y:\na. Vas al baño a mojarte la cara.\nb. Bajas las escaleras hacia la planta baja.\n");
					fflush(stdin);
					scanf("%c",&respuesta2[resp2]);
				}while(respuesta2[resp2]!='a' && respuesta2[resp2]!='b');
				
				if(respuesta2[resp2]=='a')
				{
					printf("¡Pff qué gustazo pasar por el baño!\n");
					printf("Te quedan %d puntos de vida\n",pers2.vida+5);
					
				} else
				{
					printf("Buena elección puesto que la puerta está abajo.\n");
					printf("Te quedan %d puntos de vida\n",pers2.vida+5);
				}
				system("PAUSE");
				if(pers1.survivalcoins>=100)
				{
				do
				{
					printf("\nTienes survivalcoins suficientes para rehacer la decisión, ¿quieres hacerlo ahora?\na.Sí\nb.No");
					fflush(stdin);
					scanf("%c",&ret);
				}while (ret!='a' && ret!='b');
					switch(ret)
					{
						case 'a':	printf("Diga su nueva elección\n");
									fflush(stdin);
									scanf("%c",&respuesta2[resp2]);
									if(respuesta2[resp2]=='a')
									{
										printf("¡Pff qué gustazo pasar por el baño!\n");
										printf("Te quedan %d puntos de vida\n",pers2.vida+5);
									}else if(respuesta2[resp2]=='b')
									{
										printf("Buena elección puesto que la puerta está abajo.\n");
										printf("Te quedan %d puntos de vida\n",pers2.vida+5);
									}
									pers1.survivalcoins-=100;
									break;
						case 'b': 
									printf("Ahorrar es bueno a veces, supongo...\n");
									break;
					}
				} 
				system("PAUSE");
				if(respuesta2[resp2]=='a')
				{
					pers2.vida+=5;
					printf("\nVida %s: %d\n\n",pers2.nombrepers,pers2.vida);
				} else
				{
					pers2.vida+=5;
					printf("\nVida %s: %d\n\n",pers2.nombrepers,pers2.vida);
				}
				resp2++;
			}
			system("PAUSE");
			
			//PREGUNTA 4
			if(pers1.vida!=0 && mechero)
			{
				do
				{
					printf("\n- %s -\n",pers1.nombrepers);
					printf("\nYa tienes el mechero, quieres:\na. Cocinar algo.\nb. Salir de la cocina para ver el resto de la casa.\n");
					fflush(stdin);
					scanf("%c",&respuesta1[resp1]);
				}while(respuesta1[resp1]!='a' && respuesta1[resp1]!='b');
				
				if(respuesta1[resp1]=='a')
				{
					printf("El gas estaba abierto cuando has llegado, corres hacia la puerta, pero está cerrada. Mueres trágicamente.\n");
					printf("Te quedan %d puntos de vida\n",pers1.vida-pers1.vida);
				} else
				{
					printf("La puerta está cerrada con clave, ya sabes.\n");
					printf("Te quedan %d puntos de vida\n",pers1.vida+5);
				}
				system("PAUSE");
				if(pers1.survivalcoins>=100)
				{
					do
					{
					printf("\nTienes survivalcoins suficientes para rehacer la decisión, ¿quieres hacerlo ahora?\na.Sí\nb.No\n");
					fflush(stdin);
					scanf("%c",&ret);
					}while(ret!='a' && ret!='b');
					switch(ret)
					{
						case 'a':	printf("Diga su nueva elección\n");
									fflush(stdin);
									scanf("%c",&respuesta1[resp1]);
									if(respuesta1[resp1]=='a')
									{
										printf("El gas estaba abierto cuando has llegado, corres hacia la puerta, pero está cerrada. Mueres trágicamente.\n");
										printf("Te quedan %d puntos de vida\n",pers1.vida-pers1.vida);
									}else if(respuesta1[resp1]=='b')
									{
										printf("La puerta está cerrada con clave, ya sabes.\n");
										printf("Te quedan %d puntos de vida\n",pers1.vida+5);
									}
									pers1.survivalcoins-=100;
									break;

						case 'b': 
									printf("Ahorrar es bueno a veces, supongo...\n");
									break;
					}
					system("PAUSE");
				}
				if(respuesta1[resp1]=='a')
				{
					pers1.vida==0;
					printf("\n%s ha muerto\n\n",pers1.nombrepers);
				} else
				{
					pers1.vida+=5;
					printf("\nVida %s: %d\n\n",pers1.nombrepers,pers1.vida);
				}
				resp1++;
			}
			system("PAUSE");
			
			//PREGUNTA 12
			if(pers2.vida!=0 && respuesta2[2]=='a')
			{
				do
				{
					printf("\n- %s -\n",pers2.nombrepers);
					printf("\nEstando en el baño observas que algo se mueve en la habitación de enfrente.\na. Vas a investigar.\nb. Bajas las escaleras.\n");
					fflush(stdin);
					scanf("%c",&respuesta2[resp2]);
				}while(respuesta2[resp2]!='a' && respuesta2[resp2]!='b');
				
				if(respuesta2[resp2]=='a')
				{
					printf("Mi hijo siempre dijo que su muñeca le hablaba, yo pensé que era una cosa de niños, hasta que apareció muerto. Encuéntrala si pretendes seguir vivo. Tienes una oportunidad:\n1. Debajo de la cama.\n2. En el armario.\n3. En el alféizar de la ventana.\n4. Encima del armario.\n5. Detrás de la puerta.\n");
					fflush(stdin);
					scanf("%d",&muneca);
					if(muneca==3)
					{
						printf("La coges y la tiras por la ventana. Ahora sí, bajas las escaleras. El susto no te sienta bien\n");
						printf("Te quedan %d puntos de vida\n",pers2.vida-5);
					}else
					{
						printf("Igual tendría que haber comentado esto antes, pero vaya que te advertí de que tomar malas decisiones harían que la casa te matase. Lo siento.\n");
						printf("Te quedan %d puntos de vida\n",pers2.vida-pers2.vida);
					}
				} else
				{
					printf("Buena elección puesto que la puerta está abajo.\n");
					printf("Te quedan %d puntos de vida\n",pers2.vida+5);
				}
				system("PAUSE");
				if(pers1.survivalcoins>=100)
				{
				do
				{
					printf("\nTienes survivalcoins suficientes para rehacer la decisión, ¿quieres hacerlo ahora?\na.Sí\nb.No");
					fflush(stdin);
					scanf("%c",&ret);
				}while (ret!='a' && ret!='b');
					switch(ret)
					{
						case 'a':	printf("Diga su nueva elección\n");
									fflush(stdin);
									scanf("%c",&respuesta2[resp2]);
									if(respuesta2[resp2]=='a')
									{
										printf("Mi hijo siempre dijo que su muñeca le hablaba, yo pensé que era una cosa de niños, hasta que apareció muerto. Encuéntrala si pretendes seguir vivo. Tienes una oportunidad:\n1. Debajo de la cama.\n2. En el armario.\n3. En el alféizar de la ventana.\n4. Encima del armario.\n5. Detrás de la puerta.\n");
										fflush(stdin);
										scanf("%d",&muneca);
										if(muneca==3)
										{
											printf("La coges y la tiras por la ventana. Ahora sí, bajas las escaleras. El susto no te sienta bien\n");
											printf("Te quedan %d puntos de vida\n",pers2.vida-5);
										}else
										{
											printf("Igual tendría que haber comentado esto antes, pero vaya que te advertí de que tomar malas decisiones harían que la casa te matase. Lo siento.\n");
											printf("Te quedan %d puntos de vida\n",pers2.vida-pers2.vida);
										}
									}else if(respuesta2[resp2]=='b')
									{
										printf("Buena elección puesto que la puerta está abajo.\n");
										printf("Te quedan %d puntos de vida\n",pers2.vida+5);
									}
									pers1.survivalcoins-=100;
									break;
						case 'b': 
									printf("Ahorrar es bueno a veces, supongo...\n");
									break;
					}
				} 
				system("PAUSE");
				if(respuesta2[resp2]=='a' && muneca==3)
				{
					pers2.vida-=5;
					printf("\nVida %s: %d\n\n",pers2.nombrepers,pers2.vida);
				} else if (respuesta2[resp2]=='a' && muneca!=3)
				{
					pers1.vida==0;
					printf("\n%s ha muerto\n\n",pers2.nombrepers);
				} else
				{
					pers2.vida+=5;
					printf("\nVida %s: %d\n\n",pers2.nombrepers,pers2.vida);
				}
				resp2++;
			}
			system("PAUSE");
			
			//PREGUNTA 5
			if(pers1.vida!=0 && respuesta1[3]=='b'||pers1.vida!=0 && respuesta1[4]=='b')
			{
				do
				{
					printf("\n- %s -\n",pers1.nombrepers);
					printf("\n¿Cómo quieres abrir la puerta? \na. Esta casa está destartalada, con dos patadas la puerta está abajo.\nb. Buscar alguna pista para conseguir el código.\n");
					fflush(stdin);
					scanf("%c",&respuesta1[resp1]);
				}while(respuesta1[resp1]!='a' && respuesta1[resp1]!='b');
				
				if(respuesta1[resp1]=='a')
				{
					printf("La puerta no se cae, sin embargo, se escuchan pasos al otro lado de la puerta. Decides:\na. Gritar para que te oigan y te ayuden.\nb. Callarte.\n");
					fflush(stdin);
					scanf("%c",&cocina);
					
				} else
				{
					printf("Te quedan %d puntos de vida\n",pers1.vida+5);
				}
				system("PAUSE");
				if(pers1.survivalcoins>=100)
				{
					do
					{
					printf("\nTienes survivalcoins suficientes para rehacer la decisión, ¿quieres hacerlo ahora?\na.Sí\nb.No\n");
					fflush(stdin);
					scanf("%c",&ret);
					}while(ret!='a' && ret!='b');
					switch(ret)
					{
						case 'a':	printf("Diga su nueva elección\n");
									fflush(stdin);
									scanf("%c",&respuesta1[resp1]);
									if(respuesta1[resp1]=='a')
									{
										printf("La puerta no se cae, sin embargo, se escuchan pasos al otro lado de la puerta. Decides:\na. Gritar para que te oigan y te ayuden.\nb. Callarte.\n");
										fflush(stdin);
										scanf("%c",&cocina);
									}else if(respuesta1[resp1]=='b')
									{
										printf("Te quedan %d puntos de vida\n",pers1.vida+5);
									}
									pers1.survivalcoins-=100;
									break;

						case 'b': 
									printf("Ahorrar es bueno a veces, supongo...\n");
									break;
					}
					system("PAUSE");
				}
				if(respuesta1[resp1]=='b')
				{
					pers1.vida+=5;
					printf("\nVida %s: %d\n\n",pers1.nombrepers,pers1.vida);
				}
				resp1++;
			}
			system("PAUSE");
			
			//PREGUNTA 13
			if(pers2.vida!=0)
			{
				do
				{
					printf("\n- %s -\n",pers2.nombrepers);
					printf("\nEscuchas un ruido.\na. Vas hacia él.\nb. No vas hacia él.\n");
					fflush(stdin);
					scanf("%c",&respuesta2[resp2]);
				}while(respuesta2[resp2]!='a' && respuesta2[resp2]!='b');
				
				if(respuesta2[resp2]=='a'&& respuesta1[5]=='a'&&cocina=='a')
				{
					printf("Genial, a partir de ahora iréis juntos.\n");
					printf("A %s le quedan %d puntos de vida\nA %s le quedan %d puntos de vida",pers1.nombrepers,pers1.vida+5,pers2.nombrepers,pers2.vida+5);
					
				} else if(respuesta2[resp2]=='a'&& respuesta1[5]!='a'||respuesta2[resp2]=='a'&&cocina!='a')
				{
					printf("No será porque no te avisé de que esta casa te mataría.\n");
					printf("%s, has muerto.\n", pers2.nombrepers);
				} else if(respuesta2[resp2]=='b'&& respuesta1[5]=='a'&&cocina=='a')
				{
					printf("No será porque no te avisé de que esta casa te mataría.\n");
					printf("%s, has muerto.\n", pers1.nombrepers);
				} else
				{
					printf("Ve a por %s.\n",pers1.nombrepers);
					printf("Te quedan %d puntos de vida\n",pers2.vida+5);
				}
				system("PAUSE");
				if(pers1.survivalcoins>=100)
				{
				do
				{
					printf("\nTienes survivalcoins suficientes para rehacer la decisión, ¿quieres hacerlo ahora?\na.Sí\nb.No");
					fflush(stdin);
					scanf("%c",&ret);
				}while (ret!='a' && ret!='b');
					switch(ret)
					{
						case 'a':	printf("Diga su nueva elección\n");
									fflush(stdin);
									scanf("%c",&respuesta2[resp2]);
									if(respuesta2[resp2]=='a'&& respuesta1[5]=='a'&&cocina=='a')
									{
										printf("Genial, a partir de ahora iréis juntos.\n");
										printf("A %s le quedan %d puntos de vida\nA %s le quedan %d puntos de vida",pers1.nombrepers,pers1.vida+5,pers2.nombrepers,pers2.vida+5);
					
									} else if(respuesta2[resp2]=='a'&& respuesta1[5]!='a'||respuesta2[resp2]=='a'&&cocina!='a')
									{
										printf("No será porque no te avisé de que esta casa te mataría.\n");
										printf("%s, has muerto.\n", pers2.nombrepers);
									} else if(respuesta2[resp2]=='b'&& respuesta1[5]=='a'&&cocina=='a')
									{
										printf("No será porque no te avisé de que esta casa te mataría.\n");
										printf("%s, has muerto.\n",pers1.nombrepers);
									} else if(pers1.vida!=0)
									{
										printf("Ve a por %s.\n",pers1.nombrepers);
										printf("Te quedan %d puntos de vida\n",pers2.vida+5);
									} else
									{
										printf("\n¡Enhorabuena, has conseguido salir!\n");
										return 0;
									}
									pers1.survivalcoins-=100;
									break;
						case 'b': 
									printf("Ahorrar es bueno a veces, supongo...\n");
									break;
					}
				} 
				system("PAUSE");
				if(respuesta2[resp2]=='a'&& respuesta1[5]=='a'&&cocina=='a')
				{
					pers2.vida+=5;
					pers1.vida+=5;
					printf("\nVida %s: %d\n\nVida %s: %d\n\n",pers1.nombrepers,pers1.vida,pers2.nombrepers,pers2.vida);
				} else if(respuesta2[resp2]=='a'&& respuesta1[5]!='a'||respuesta2[resp2]=='a'&&cocina!='a')
				{
					pers2.vida=0;
					printf("%s, has muerto.\n", pers2.nombrepers);
				} else if(respuesta2[resp2]=='b'&& respuesta1[5]=='a'&&cocina=='a')
				{
					pers1.vida=0;
					printf("%s, has muerto.\n", pers1.nombrepers);
				} else
				{
					pers2.vida+=5;
					printf("\nVida %s: %d\n\n",pers2.nombrepers,pers2.vida);
				}
				resp2++;
			}
			system("PAUSE");
			
			//PREGUNTA 6
			if(pers1.vida!=0 && pers2.vida!=0 && respuesta1[5]=='a'&&cocina=='a')
			{
				printf("\n- %s %s -\n",pers1.nombrepers,pers2.nombrepers);
				printf("\nAhora que estáis reunidos, queréis ir a la puerta principal");
				printf("¡Enhorabuena, habéis salido! Echaré de menos estar acompañado.\n");
			}
			system("PAUSE");
			
			//PREGUNTA 5b
			if(pers1.vida!=0 && respuesta1[resp1-1]=='b'||pers1.vida!=0 && cocina=='b')
			{
				do
				{
					printf("\n- %s -\n",pers1.nombrepers);
					printf("\nDespués de estar buscando, has encontrado 6 ideas, tienes 3 oportunidades:\n1. La hora del reloj\n2. La fecha de la nota de detrás del reloj.\n3. El número que hay pintado en el cuadro que hay colgado.\n4. Los números que están arrancados del microondas.\n5. Los números que no están arrancados del microondas.\n6. La fecha que está señalada en el calendario.\n");
					fflush(stdin);
					scanf("%d",&codigo);
					oport++;
				}while(codigo!=2 && oport<3);
				
				if(codigo==2 && pers2.vida!=0)
				{
					printf("Efectivamente la fecha en la que Alicia y yo nos conocimos era el código, lo puse porque desde el momento en el que nos vimos supe que jamás se me olvidaría ese día, fuimos tan felices...\nEn fin, que me pongo melancólico, ¡por fin has salido de la cocina! ¡Mira quién está ahí, %s! Ahora dirgíos a la puerta principal, ya es hora de terminar el TFG.\n",pers2.nombrepers);
				} else if(codigo==2 && pers2.vida==0)
				{
					printf("Efectivamente la fecha en la que Alicia y yo nos conocimos era el código, lo puse porque desde el momento en el que nos vimos supe que jamás se me olvidaría ese día, fuimos tan felices...\nEn fin, que me pongo melancólico, ¡por fin has salido de la cocina! Ahora dirígete a la puerta principal, ya es hora de terminar el TFG.\n\n- FIN -\n");
					return 0;
				} else
				{
					printf("Ya quedaba poco, supongo que la presión te ha podido, has muerto.\n\n");
					pers1.vida=0;
				}
				system("PAUSE");
			}
		
		}
			}

} while (opcion!='S');
}

void trivial (int* monedas)
{
	int respuesta;
	int coins;
	int j = 1;
	
	
	if(j == 1){
	
		printf("\n\n¿Cuál es el océano más grande del mundo?\n1.Pacífico\n2.Índico\n3.Atlántico\n4.Mediterráneo\n");
		scanf("%d", &respuesta);
		if(respuesta == 1){
			coins+=20;
	
		}
		
		if(respuesta < 5){
		j++;
		respuesta = 6;
		}
	}
	
	if(j == 2){
	
		printf("\n\n¿Cuál es la fórmula química del agua?\n1.CO2\n2.H3O\n3.H2O\n4.HH\n");
		scanf("%d",&respuesta);
		if(respuesta==3){
			coins+=20;
		};
		
		if(respuesta<5){
		j++;
		respuesta = 6;
		}
	}
	
	if(j == 3){
	
		printf("\n\n¿Cuándo se descubrió América?\n1.1942\n2.100\n3.1492\n4.1400\n");
		scanf("%d",&respuesta);
		if(respuesta==3){
			coins+=20;	
		};
		
		if(respuesta<5){
		j++;
		respuesta = 6;
		}
	}
	
	if(j == 4){
	
		printf("\n\n¿Cómo se llama el proceso por el que se alimentan las plantas?\n1.Rumiar\n2.Fotosíntesis\n3.Comer\n4.Respirar\n");
		scanf("%d",&respuesta);
		if(respuesta==2){
			coins+=20;
		};
		
		if(respuesta<5){
		j++;
		respuesta= 6;
		}
	}
	
	if(j == 5){
	
		printf("\n\n¿En qué isla está situado el volcán del Teide?\n1.Tenerife\n2.Menorca\n3.La isla del perejil\n4.Las Palmas\n");
		scanf("%d",&respuesta);
		if(respuesta==1){
			coins+=20;
		};
		
		if(respuesta<5){
		j++;
		respuesta= 6;
		}
	}
	
	if(j == 6){
	
		printf("\n\n¿Cuál es el libro sagrado del Islam?\n1.El mundo de la Fantasía\n2.Biblia\n3.Corán\n4.Felks\n");
		scanf("%d", &respuesta);
		if(respuesta == 3){
			coins+=20;
	
		}
		
		if(respuesta < 5){
		j++;
		respuesta = 6;
		}
	}
	
	if(j == 7){
	
		printf("\n\n¿Qué rama de la Biología se encarga del estudio de los animales?\n1.Botánica\n2.Zoología\n3.Arquitectura\n4.Faunia\n");
		scanf("%d",&respuesta);
		if(respuesta==1){
			coins+=20;
		};
		
		if(respuesta<5){
		j++;
		respuesta = 6;
		}
	}
	
	if(j == 8){
	
		printf("\n\n¿Quién es el autor de el Don Quijote de la Mancha?\n1.Gongora\n2.Dali\n3.Pinocho\n4.Miguel de Cervantes\n");
		scanf("%d",&respuesta);
		if(respuesta==4){
			coins+=20;	
		};
		
		if(respuesta<5){
		j++;
		respuesta = 6;
		}
	}
	
	if(j == 9){
	
		printf("\n\n¿Cómo se llama el estadio del F.C. Barcelona?\n1.Calderon\n2.Camp Nou\n3.New Camp\n4.Barcelona Stadium\n");
		scanf("%d",&respuesta);
		if(respuesta==2){
			coins+=20;
		};
		
		if(respuesta<5){
		j++;
		respuesta= 6;
		}
	}
	
	if(j == 10){
	
		printf("\n\n¿Según la Biblia, quién traicionó a Jesús?\n1.Judas\n2.Moises\n3.Teresa de Calcuta\n4.Maoma\n");
		scanf("%d",&respuesta);
		if(respuesta==1){
			coins+=20;
		};
		
		if(respuesta<5){
		j++;
		respuesta= 6;
		}
	}
	
	*monedas=coins;

	
	
}
	
char menu(){
	
	char opcion;
	printf("Survival Horror-Un juego para los mas valientes\n Bienvenido al menu de opciones:\n");
	printf("Introduce la opcion que desees:\n");
	printf("************************\n");
	printf("I-iniciar sesión para una nueva partida\n");
	printf("R-Registrarse\n");
	printf("X-Intrucciones del juego\n");
	printf("S-Salir del juego\n");
	printf("************************\n");
	fflush(stdin);
	scanf("%c",&opcion);
	
	return opcion;
	
}
void Instrucciones(char*informacion){
	
	printf("En SURVIVAL HORROR hay dos tipos de preguntas:\n El primer banco de preguntas es de cultura general las cuales serviran para ganar survival coins con las que mas adelante podras comprar pistas.\n El segundo banco de preguntas son de supervivencia, cada jugador iniciara con un 50 de vida y ganara o perdera en funcion de estas preguntas.\n");
	printf("Para que el juego funcione debes crear un fichero usuario.txt en el que podrás comprobar los usuarios ya creados y crear tu perfil de jugador\n");
	
	do{
		printf("Bienvenido al menu de instrucciones:\n");
		printf("***********************\n");
		printf("A-Tipos de preguntas\n");
		printf("B-Tipos de monedas\n");
		printf("S-Salir de este menu\n");
		printf("***********************\n");
		fflush(stdin);
		scanf("%c",&*informacion);
		
		if(*informacion=='A'){
			printf("Se trata de preguntas de cultura general tipo trivial en las que tendrás 4 opciones para responde\n Si aciertas estas preguntas ganaras survivals coins que son las monedas existentes en nuestro juego y si no las aciertas las perderas");
		}else if(*informacion=='B'){
			printf("Las monedas de nuestro juego se llaman survivalcoins y estas son las que marcaran el nivel de tu inteligencia respondiendo preguntas de cultura general\n");
			
		}else if(*informacion=='C'){
			break;
		}else{
			printf("Vaya creo que se ha equivocado, marque una opcion disponible\n");
		}
		system("PAUSE");
		
	}while(*informacion!='S');
}
	
void cartelInstrucciones(){
	printf("\n");
	printf("\t\t\t\t\t\t.------..------..------..------..------..------..------..------..------..------..------..------..------.\n");
	printf("\t\t\t\t\t\t|I.--. ||N.--. ||S.--. ||T.--. ||R.--. ||U.--. ||C.--. ||C.--. ||I.--. ||O.--. ||N.--. ||E.--. ||S.--. |\n");
	printf("\t\t\t\t\t\t| :(): || :(): || :(): || :(): || :(): || :(): || :(): || :(): || :(): || :(): || :(): || :(): || :(): |\n");
	printf("\t\t\t\t\t\t| ()() || ()() || ()() || ()() || ()() || ()() || ()() || ()() || ()() || ()() || ()() || ()() || ()() |\n");
	printf("\t\t\t\t\t\t| '--'I|| '--'N|| '--'S|| '--'T|| '--'R|| '--'U|| '--'C|| '--'C|| '--'I|| '--'O|| '--'N|| '--'E|| '--'S|\n");
	printf("\t\t\t\t\t\t`------'`------'`------'`------'`------'`------'`------'`------'`------'`------'`------'`------'`------'\n");
}

void cartelTitulo(){
	printf("\n");
	printf("\t\t\t .S    S.     sSSSSSSSs     .SSSSSs     .SSSSSs      sSSSSSSSs     .SSSSSs            sSSs   .S       S.    .SSSSSs     .S    S.    .S   .S    S.    .SSSSSs    S.      \n");
	printf("\t\t\t.SS    SS.   dSSSP~YSSSb   .SS~YSSSb   .SS~YSSSb    dSSSP~YSSSb   .SSSSSSSb          dSSSP  .SS       SS.  .SSSSSSSb   .SS    SS.  .SS  .SS    SS.  .SSSSSSSS   SS.     \n");
	printf("\t\t\tSSS    SSS  dSS'     `SSb  SSS   `SSb  SSS   `SSb  dSS'     `SSb  SSS   `SSb        dSS'    SSS       SSS  SSS   `SSb  SSS    SSS  SSS  SSS    SSS  SSS   SSSS  SSS     \n");
	printf("\t\t\tSSS    SSS  SSS       SSS  SSS    SSS  SSS    SSS  SSS       SSS  SSS    SSS        SS|     SSS       SSS  SSS    SSS  SSS    SSS  SSS  SSS    SSS  SSS    SSS  SSS     \n");
	printf("\t\t\tSSS SSSSSS  SSS       SSS  SSS    dSS  SSS    dSS  SSS       SSS  SSS    dSS        SSS     SSS       SSS  SSS    dSS  SSS    SSS  SSS  SSS    SSS  SSS SSSSSS  SSS     \n");
	printf("\t\t\tSSS  SSSSS  SSS       SSS  SSS   .SSS  SSS   .SSS  SSS       SSS  SSS   .SSS        YSSs    SSS       SSS  SSS   .SSS  SSS    SSS  SSS  SSS    SSS  SSS  SSSSS  SSS     \n");
	printf("\t\t\tSSS    SSS  SSS       SSS  SSS_sdSSS   SSS_sdSSS   SSS       SSS  SSS_sdSSS         `SSSS   SSS       SSS  SSS_sdSSS   SSS    SSS  SSS  SSS    SSS  SSS    SSS  SSS     \n");
	printf("\t\t\tSSS    SSS  SSS       SSS  SSS~YSSSb   SSSSYSSSb   SSS       SSS  SSSSYSSSb           `SSS  SSS       SSS  SSSSYSSSb   SSS    SSS  SSS  SSS    SSS  SSS    SSS  SSS     \n");
	printf("\t\t\tSSS    SSS  SSb       dSS  SSS   `SSb  SSS   `SSb  SSb       dSS  SSS   `SSb           lSS  SSb       dSS  SSS   `SSb  SSS    SSS  SSS  SSb    SSS  SSS    SSS  SSS     \n");
	printf("\t\t\tSSS    SSS  SSS.     .SSS  SSS    SSS  SSS    SSS  SSS.     .SSS  SSS    SSS          .SSP  SSS.     .SSS  SSS    SSS  SSS.   SSS  SSS  SSS.   SSS  SSS    SSS  SSS.    \n");
	printf("\t\t\tSSS    SSS   SSSbs_sdSSS   SSS    SSS  SSS    SSS   SSSbs_sdSSS   SSS    SSS        sSSSS    SSSbs_sdSSS   SSS    SSS   SSSbs_SSS  SSS   SSSbs_SSS  SSS    SSS   SSSbs  \n");
	printf("\t\t\tSSS    SSS    YSSPSSSSY    SSS    SSS  SSS    SSS    YSSPSSSSY    SSS    SSS        YSS'      YSSPSSSSY    SSS    SSS    YSSSSSSS  SSS    YSSSSSSS  SSS    SSS    YSSP  \n");
	printf("\t\t\t       SP                  SP          SP                         SP                                       SP                      SP                      SP           \n");
	printf("\t\t\t       Y                   Y           Y                          Y                                        Y                       Y                       Y            \n");
}

void cartelSalida(){
	printf("\n");
	printf("\t\t\t\t\t\t\t\t\t\t\t         (     (        )   (     \n");
	printf("\t\t\t\t\t\t\t\t\t\t\t   (     )%c )  )%c )  ( /(   )%c )  \n",92,92,92);
	printf("\t\t\t\t\t\t\t\t\t\t\t   )%c   (()/( (()/(  )%c()) (()/(  \n",92,92);
	printf("\t\t\t\t\t\t\t\t\t\t\t((((_)(  /(_)) /(_))((_)%c   /(_)) \n",92);
	printf("\t\t\t\t\t\t\t\t\t\t\t )%c _ )%c(_))_ (_))    ((_) (_))   \n",92,92);
	printf("\t\t\t\t\t\t\t\t\t\t\t (_)_%c(_)|   %c|_ _|  / _ %c / __|  \n",92,92,92);
	printf("\t\t\t\t\t\t\t\t\t\t\t  / _ %c  | |) || |  | (_) |%c__ %c  \n",92,92,92);
	printf("\t\t\t\t\t\t\t\t\t\t\t /_/ %c_%c |___/|___|  %c___/ |___/  \n",92,92,92);
}

void cartelRegistrarse(){
	printf("\n");
	printf("\t\t\t\t\t\t\t   (`-')  (`-')  _            _      (`-').->(`-')        (`-')  (`-')  _    (`-')  (`-').->(`-')  _ \n");
	printf("\t\t\t\t\t\t\t<-.(OO )  ( OO).-/    .->    (_)     ( OO)_  ( OO).->  <-.(OO )  (OO ).-/ <-.(OO )  ( OO)_  ( OO).-/ \n");
	printf("\t\t\t\t\t\t\t,------,)(,------. ,---(`-') ,-(`-')(_)--%c_) /    '._  ,------,) / ,---.  ,------,)(_)--%c_)(,------. \n",92,92);
	printf("\t\t\t\t\t\t\t|   /`. ' |  .---''  .-(OO ) | ( OO)/    _ / |'--...__)|   /`. ' | %c /`.%c |   /`. '/    _ / |  .---' \n",92,92);
	printf("\t\t\t\t\t\t\t|  |_.' |(|  '--. |  | .-, %c |  |  )%c_..`--. `--.  .--'|  |_.' | '-'|_.' ||  |_.' |%c_..`--.(|  '--.  \n",92,92,92);
	printf("\t\t\t\t\t\t\t|  .   .' |  .--' |  | '.(_/(|  |_/ .-._)   %c   |  |   |  .   .'(|  .-.  ||  .   .'.-._)   %c|  .--'  \n",92,92);
	printf("\t\t\t\t\t\t\t|  |%c  %c  |  `---.|  '-'  |  |  |'->%c       /   |  |   |  |%c  %c  |  | |  ||  |%c  %c %c       /|  `---. \n",92,92,92,92,92,92,92,92);
	printf("\t\t\t\t\t\t\t`--' '--' `------' `-----'   `--'    `-----'    `--'   `--' '--' `--' `--'`--' '--' `-----' `------' \n");
}

void cartelIniciarSesion(){
	printf("\n");
	printf("\t\t\t\t\t  _     <-. (`-')_  _                 _     (`-')  _    (`-')      (`-').->(`-')  _ (`-').->  _                <-. (`-')_ \n");
	printf("\t\t\t\t\t (_)       %c( OO) )(_)     _         (_)    (OO ).-/ <-.(OO )      ( OO)_  ( OO).-/ ( OO)_   (_)         .->      %c( OO) )\n",92);
	printf("\t\t\t\t\t ,-(`-'),--./ ,--/ ,-(`-') %c-,-----. ,-(`-')/ ,---.  ,------,)    (_)--%c_)(,------.(_)--%c_)  ,-(`-')(`-')----. ,--./ ,--/ \n",92,92,92);
	printf("\t\t\t\t\t | ( OO)|   %c |  | | ( OO)  |  .--./ | ( OO)| %c /`.%c |   /`. '    /    _ / |  .---'/    _ /  | ( OO)( OO).-.  '|   %c |  | \n",92,92,92,92);
	printf("\t\t\t\t\t |  |  )|  . '|  |)|  |  ) /_) (`-') |  |  )'-'|_.' ||  |_.' |    %c_..`--.(|  '--. %c_..`--.  |  |  )( _) | |  ||  . '|  |)\n",92,92);
	printf("\t\t\t\t\t(|  |_/ |  |%c    |(|  |_/  ||  |OO )(|  |_/(|  .-.  ||  .   .'    .-._)   %c|  .--' .-._)   %c(|  |_/  %c|  |)|  ||  |%c    | \n",92,92,92,92,92);
	printf("\t\t\t\t\t |  |'->|  | %c   | |  |'->(_'  '--'%c |  |'->|  | |  ||  |%c  %c     %c       /|  `---.%c       / |  |'->  '  '-'  '|  | %c   | \n",92,92,92,92,92,92,92);
	printf("\t\t\t\t\t `--'   `--'  `--' `--'      `-----' `--'   `--' `--'`--' '--'     `-----' `------' `-----'  `--'      `-----' `--'  `--' \n");
}

