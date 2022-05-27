#include<stdio.h>
#include<string.h>
#include<locale.h>
#define MAX_JUG 100

//Cada jugador puede jugar con hasta x personajes en función del nivel que se juegue
struct TPersonaje{
	char  nombrepers[20];
	char contrasenna[10];         
	int  vida;
	int ins;
};

struct TJugador{
	char  nombrejug[20];         
	char contrasenna[20];
	int survivalcoins;
	int njug;
	//struct personajes *pers[];
};


char menu();
void Instrucciones(char*informacion);
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
						while(fscanf(pfichero,"%s %s %d", jugadores[i].nombrejug, jugadores[i].contrasenna, &jugadores[i].survivalcoins)!=EOF){
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
									jugadores[i].njug=i+1;
									break;
								} else{
									repetido=0;
								}
							}
							
							if(repetido==1){
								printf("Bienvenido de nuevo %s eres el jugador numero %d\n",inicioNombrejug,jugadores[i].njug);
							} else{
								printf("Usuario y/o contrasenna no validos\n");
							}
							
						}while(repetido==0); //Pregunta hasta que encuentra un usuario y contraseña ya existentes
						
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
						while(fscanf(pfichero,"%s %s %d", jugadores[i].nombrejug, jugadores[i].contrasenna, &jugadores[i].survivalcoins)!=EOF){
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
						
						printf("Introduzca su contrasenna para su inicio de sesion");
						fflush(stdin);
						scanf("%s",jugadores[contador].contrasenna);
						jugadores[contador].survivalcoins=0;
						
						
						for(i=0;i<=contador;i++){
							printf("%s %s %d\n",jugadores[i].nombrejug,jugadores[i].contrasenna,jugadores[i].survivalcoins);
						}
						
						//Ahora se abre el fichero en modo escritura para guardar los datos del nuevo jugador
						
						pfichero=fopen("usuarios.txt","w");
						
						if(pfichero==NULL){
							printf("ERROR EN LA ESCRITURA DEL FICHERO");
							return 0;
						}
						
						for(i=0; i<=contador; i++){
							fprintf(pfichero,"%s %s %d\n",jugadores[i].nombrejug,jugadores[i].contrasenna,jugadores[i].survivalcoins);
						}
						
						jugadores[contador].njug=contador+1;
						printf("Numero de jugador: %d\n",jugadores[contador].njug);
						
						
						//Cerramos el fichero utilizado
					    fclose(pfichero);
					    system("PAUSE");
					    break;
				
			case 'X': cartelInstrucciones();
				
					Instrucciones(&informacion);
					break;
					 
					 

	}
} while (opcion!='S');
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
	
