#include<stdio.h>
#include<string.h>
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

char menu();
void Instrucciones(int ins);
void cartelTitulo();
void cartelIniciarSesion();
void cartelRegistrarse();
void cartelInstrucciones();
void cartelSalida();
int main(){
	cartelTitulo();
	struct TJugador jugadores[MAX_JUG];
	int i, contador, repetido;
	char opcion;
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
						
						//Cerramos el fichero utilizado
					    fclose(pfichero);
					    system("PAUSE");
					    break;
				
			case 'x': cartelInstrucciones();
				
					Instrucciones(&ins);
					break;
					 
					 

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
void Instrucciones(int ins){
	
	printf("SURVIVAL HORROR es un juego de preguntas donde el jugador se encarna en un grupo de amigos que quedan separados y deben ir avanzando a traves de diferentes caminos para poder lograr reencontrarse.\n La historia se divide en dos partes diferenciadas.\n\n");
	printf("La primera parte es Cultura general, en ella el jugador tratara de ganar puntos acertando preguntas que le serviran mas adelante.\n En la segunda parte del juego llamada Supervivencia el jugador debera enfrentarse a otro tipo de preguntas donde acertar o fallar consume los puntos de vida de dicho personaje. \n Los puntos ganados en Cultura General sirven para generar pistas en caso de necesitarlos y solo pueden ser usados en Supervivencia.\n El objetivo del juego es conseguir responder todas las preguntas y no perder todos los puntos de vida en el camino.\n")
	
	printf("Para acceder al juego es necesario crear un archivo .txt llamado "" en la carpeta del programa\n");
					
	do{
		do
		{
			printf("Puede saber mas acerca del juego indicando una de las siguientes opciones:\n");
		
			printf("--------------------------------------------------------------------------\n");
		
			printf("1-Cultura General\n");
			
			printf("2-Supervivencia\n");
		
			printf("3-Volver al Menu\n");
		
			fflush(stdin);
		
			scanf("%d",&ins);
		}while(ins!=1 && ins!=2 && ins!=3);
					
		if(ins=='1'){
			printf("Cultura General\n");
			
			printf("Las preguntas referidas a cultura general, como indica su nombre son preguntas de todo ambito.\n Cada pregunta acertada otorgara al jugador Survival Coins que podran ser gastadas posteriormente en pistas para la segunda parte del juego.\n");
			
		}else if(ins=='2'){
			printf("Supervivencia\n");
			
			printf("En Supervivencia el jugador empieza el juego con 50 puntos de vida que iran disminuyendo a medida que se fallen las preguntas.\n");
			
		}else if(ins=='3'){
			break; 
			
		}else{
			printf("Por favor, eliga una de las opciones validas\n");
		}			
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
	
