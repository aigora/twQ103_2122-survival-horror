#include	<stdio.h>
#include	<stdlib.h>

int main()
{
	
	
	int i;
	int survivalcoins;
	
	void trivial (int survivalcoins);
	
	
	printf("�Quieres completar el test?\n 1 - si\n 2 - no\n");
	scanf("%d",&i);
	if(i=1){
		
		 trivial (survivalcoins);
		
		
	}
	fflush(stdin);
}

//printf("\n%s\n�Cu�l es el r�o m�s largo del mundo?\nA.Tajo\nB.NIlo\nC.Taju�a\nD.Chan Se",pers[6].nombrepers);
//printf("\n%s\n�Qu� es un narval?\nA.Animal\nB.Planta\nC.Instrumento\nD.Material escolar",pers[6].nombrepers);
//printf("\n%s\n�Qu� son las mitocondrias?\nA.Org�nulos celulares\nB.Organos\nC.Animales\nD.Conjunto de Pa�ses",pers[6].nombrepers);



void trivial (int survivalcoins)
{
	char respuesta;
	int coins;
	int j='1';
	
	
	if(j='1'){
	
	printf("\n%s\n�Cu�l es el oc�ano m�s grande del mundo?\nA.Pac�fico\nB.�ndico\nC.Atl�ntico\nD.Mediterr�neo\n");
	scanf("%c",&respuesta);
	if(respuesta='A'){
		coins+=5;
		
	}
	j++;
}
	if(j='2'){
	
	printf("\n%s\n�Cu�l es la f�rmula qu�mica del agua?\nA.CO2\nB.H3O\nC.H2O\nD.HH\n");
	scanf("%c",&respuesta);
	if(respuesta='C'){
		coins+=5;
	}
}
}

