

int CargarFichero(struct TJugador jugadores[], int *nusuario){
	FILE * pfichero;
	int i;
	

	pfichero= fopen("usuarios.txt","r");//Se abre el fichero
	
					
	
	if(pfichero==NULL){
		printf("No se ha encontrado el fichero\n");
		return 0;//Comprueba el fichero de no encontrarse finaliza
		
	}
					
	i=0;
	while(fscanf(pfichero,"%s %s %d",&jugadores[i].nombrejug,&jugadores[i].contrasenna,&jugadores[i].survivalcoins)!=EOF){
	i++;//Se comprueban los usuarios del fichero y los guarda en memoria
	
	}
	*nusuario=i;
	
	fclose(pfichero);
	return 1;
}
void CrearUsuario(char inicioNombrejug[], int *jugadore,struct TJugador jugadores[]){
	
	FILE * pfichero;
	int i,nada=0;
	char contrasena1[100];
	
	do{//Comprueba que el nombre de usuario no coincide con ninguno anterior
		printf("Introduzca su nombre de jugador:\n");
		fflush(stdin);
		scanf("%s",inicioNombrejug);
		
		for(i=0;i<*jugadore;i++){
			if(strcmp(inicioNombrejug,jugadores[i].nombrejug)==0){
				nada=1;
				break;
			}else{
				nada=0;
			}
		}
		
		if(nada==1){
			printf("El nombre de jugador ya ha sido elegido.\n");
			printf("Por favor, escoja otro distinto.\n");
			//system("PAUSE");
		}else{
			printf("Jugador aceptado\n");
			strcpy(jugadores[*jugadore].nombrejug,inicioNombrejug);
		}
						
	}while(nada==1);
					
	printf("Introduzca una contrasena\n",164);//164?
	fflush(stdin);
	scanf("%s",jugadores[*jugadore].contrasenna);
	
				
	pfichero= fopen("usuarios.txt","w");//Modo escritura el en fichero
	
	for(i=0;i<=*jugadore;i++){
		fprintf(pfichero,"%s\n%s\n%d\n",jugadores[i].nombrejug,jugadores[i].contrasenna,jugadores[i].survivalcoins);//Se suscriben los datos introducidos en el fichero
	}
	
	fclose(pfichero);
	//system("PAUSE");
}


void InicioSesion(char inicioNombrejug[], int *jugadore,struct TJugador jugadores[]){
	
	int i,nada=0;
	char inicioContrasenna[100];
	
	
	do{//Se piden los datos de inicio de sesión
		printf("Introduzca su nombre de jugador:\n");
		fflush(stdin);
		scanf("%s",inicioNombrejug);
		printf("Introduzca su contrasena\n",164);
		fflush(stdin);
		scanf("%s",inicioContrasenna);
					
		
		for(i=0;i<*jugadore;i++){//Comprobación de datos introducidos
			if(strcmp(inicioNombrejug,jugadores[i].nombrejug)==0 && strcmp(inicioContrasenna,jugadores[i].contrasenna)==0){
				nada=1;
				break;
			}else{
				nada=0;
			}
		}
						
		if(nada==0){
			printf("Usuario o contrasena incorrecto.\n",164);
		}else{
			printf("Usuario valido\n");
		}
			//system("PAUSE");
			
	}while(nada==0);
				
}
