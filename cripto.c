#include <stdio.h>
#include <stdlib.h>
#include <string.h>

////////////////////////////////////////
/* cripto <operacao> <path> <chave>   //
/**************************************/
//Programa para criptografar textos   //
//usando o algoritmo da cifra de cesar//
/**************************************/
/*       ARGUMENTOS DO PROGRAMA       */
////////////////////////////////////////
// <operacao>			      //
//	 -c -> criptografar	      //
//	 -d -> descriptografar	      //
//	 -h -> help		      //
//************************************//
// <pathin>			      //
//  caminho do arquivo que será lido //
//************************************//
// <pathout>			      //
//  caminho do arquivo de saída mais //
//   o nome do arquivo                //
//************************************//
// <chave>		    	      //
//   chave para criptografar ou	      //
//	 descriptografar o arquivo    //
////////////////////////////////////////

void criptografa(char *pathin, char *pathout, char *chave)
{
	int i = atoi(chave);
	i = i % 26;
	FILE *arqin;
	FILE *arqout;
	char c;
	int caracter;

	arqin = fopen(pathin,"r");
	arqout = fopen(pathout,"w");
	
	if(i != 0)
	{
		while(!feof(arqin))
		{
			c = fgetc(arqin);
			c = tolower(c);
			caracter = (int)c;
			
			if(caracter >= 97 && caracter <= 122)
			{
				caracter = (int)c + i;
				if(caracter > 122)
					caracter = caracter - 123 + 97;
				else if(caracter < 97)
					caracter = 122 - ( 97 - caracter - 1);
			}
			
			if(caracter != -1)
				fputc(caracter,arqout);
		}
		
		fclose(arqin);
		fclose(arqout);
	}
}

void descriptografa(char *pathin, char *pathout, char *chave)
{
	int i = atoi(chave);
	i = i % 26;
  	FILE *arqin;
	FILE *arqout;
	char c;
	int caracter;
	
	if(i != 0)
	{
		arqin = fopen(pathin,"r");
		arqout = fopen(pathout,"w");
		
		while(!feof(arqin))
		{
			c = fgetc(arqin);
			c = tolower(c);
			caracter = (int)c;
			
			if(caracter >= 97 && caracter <= 122)
			{
				caracter = (int)c - i;
				if(caracter > 122)
					caracter = caracter - 123 + 97;
				else if(caracter < 97)
					caracter = 122 - ( 97 - caracter - 1);
			}
			
			if(caracter != -1)
				fputc(caracter,arqout);
		}
		
		fclose(arqin);
		fclose(arqout);
	}
}

void help()
{
	printf("Programa cripto.exe\n");
    printf("\t-> cripto <operacao> <pathin> <pathout> <chave>\n");
    printf("\t -- cripto -c <pathin> <pathout> <chave> -> criptografar\n");
    printf("\t -- cripto -d <pathin> <pathout> <chave> -> descriptografar\n");
    printf("\t -- cripto -h -> help\n");
}

int main(int argc, char * argv[])
{
    if(argv[1] != NULL)	
    {
        if(strcmp(argv[1],"-c") == 0)
	    {
		    if(argv[2] == NULL || argv[3] == NULL || argv[4] == NULL)
		    {
			    printf("Help:\t -- cripto -c <pathin> <pathout> <chave>\n");
			    exit(0);
		    }			
		    criptografa(argv[2],argv[3],argv[4]);
		
	    }
	    else if(strcmp(argv[1],"-d") == 0)
	    {
		    if(argv[2] == NULL || argv[3] == NULL || argv[4] == NULL)
		    {
			    printf("Help:\t -- cripto -d <pathin> <pathout> <chave>\n");
			    exit(0);
		    }			
		    descriptografa(argv[2],argv[3],argv[4]);	
	    }
	    else
	    {
		    help();
	    }
    }
    else
    {
        help();
    }
	return 0;
}
