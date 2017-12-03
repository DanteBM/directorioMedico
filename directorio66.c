#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
// #not_include<conio.h> 
#define p printf
#define s scanf
//Funciones
int leer();
void oftalmologia();
void neurologia();
void oncologia();
void archivos();
void registrar();
void limpiar(char purgatorio[80]);
void cleaner();
//Variables
int med;
int hh,mm,n,i; //Variables de f archivos
char espacio[1]={' '};
struct paciente
{
	char nombre[50];
	char apP[100];
	char apM[25];
	char tel[15];
	char hora[6];
} pac[15];
FILE *fichero,*copia;
const char *nombreMedicos[]={"Dr. Juan Antonio Ham Yee","Dr. Enrique Graue Wiechers","Dra. Patricia Garcia Regil","Dr Stephen Strange","Dr. Gregory House","Dr. Arthur Conan Doyle","Sr. Dr. Prof. Patricio Estrella","Dr. Emmet Brown","Dr. Chapatin"};
const char *nombreArchivos[]={"ofta1.txt","ofta2.txt","ofta3.txt","neuro1.txt","neuro2.txt","neuro3.txt","onco1.txt","onco2.txt","onco3.txt"};
//Main
int main()
{
	int z,ramas;
	do
	{
		system("cls");
		p("Directorio m%cdico\n",130);
		p("1) Oftalmolog%ca\n",161);
		p("2) Neurolog%ca\n",161);
		p("3) Oncolog%ca\n",161);
		p("Ingrese una opci%cn: ",162);
		ramas=leer();
		switch(ramas)
		{
			case 1: {
				oftalmologia();
				break;
			}
			case 2: {
				neurologia();
				break;
			}
			case 3: {
				oncologia();
				break;
			}
			default: {
				p("Opci%cn inv%clida\n",162,160);
			}
		}
		p("%cDesea regresar a las %creas? (Presione 1 para proceder): ",168,160);
		z=leer();
	}
	while(z==1);
	p("\n\t\tPROYECTO FINAL\n\n");
	p("\tIntegrantes:\n\n");
	p("Berm%cdez Marb%cn Dante\n",163,160);
	p("Ham Garc%ca Diana Patricia\n",161);
	p("Olgu%cn Castillo Luis %cngel\n\n\a",161,181);
	return 0;
}
void oftalmologia()
{
	int ofta,rep;
	do
	{
		system("cls");
		p("\tOftamolog%ca\n",161);
		p("1) Dr. Juan Antonio Ham Yee\n");
		p("2) Dr. Enrique Graue Wiechers\n");
		p("3) Dra. Patricia Gar%ca Regil\n",161);
		p("Eliga un m%cdico: ",130);
		ofta=leer();
		switch(ofta)
		{
			case 1: {
				med=0;
				archivos();
				break;
			}
			case 2: {
				med=1;
				archivos();
				break;
			}
			case 3: {
				med=2;
				archivos();
				break;
			}
			default: {
				p("Opci%cn inv%clida",162,160);
			}
		}
		p("%cDesea regresar a los oftalm%clogos? (Presione 1 para proceder): ",168,162);
		rep=leer();
	}
	while(rep==1);
}
void neurologia()
{
	int neuro,rep;
	do
	{
		system("cls");
		p("\tNeurolog%ca\n",161);
		p("1) Dr. Stephen Strange\n");
		p("2) Dr. Gregory House\n");
		p("3) Dr. Arthur Conan Doyle\n",161);
		p("Eliga un m%cdico: ",130);
		neuro=leer();
		switch(neuro)
		{
			case 1: {
					med=3;
					archivos();
					break;
				}
				case 2: {
					med=4;
					archivos();
					break;
				}
				case 3: {
					med=5;
					archivos();
					break;
				}
				default: {
					p("Opci%cn inv%clida",162,160);
				}
		}
		p("%cDesea regresar a los neur%clogos? (Presiona 1 para proceder): ",168,162);
		rep=leer();
	}
	while(rep==1);
}
void oncologia()
{
	int onco,rep;
	do
	{
		system("cls");
		p("\tOncolog%ca\n",161);
		p("1) Sr. Dr. Prof. Patricio Estrella\n");
		p("2) Dr. Emmett Brown\n");
		p("3) Dr. Chapat%cn\n",161);
		p("Eliga un m%cdico: ",130);
		s("%d",&onco);
		fflush(stdin);
		switch(onco)
		{
			case 1: {
				med=6;
				archivos();
				break;
			}
			case 2: {
				med=7;
				archivos();
				break;
			}
			case 3: {
				med=8;
				archivos();
				break;
			}
			default: {
				p("Opci%cn inv%clida",162,160);
			}
		}
		p("%cDesea regresar a los onc%clogos? (Presione 1 para proceder): ",168,162);
		rep=leer();	
	}
	while(rep==1);
	
}
void archivos()
{
	int menuArc,del,z,con,booleano=0,comparar,salve=4;
	int explorer=1,linea,numLineas,visiter=0,aureo;
	char cha;
	char temporal,nombreB[25],apPB[100],apMB[25];
	do
	{
		system("cls");
		p("%cQu%c desea hacer?\n",168,130);
		p("1) Crear directorio\n");
		p("2) Agregar al directorio\n");
		p("3) Consultar directorio\n");
		p("4) Borrar paciente\n");
		p("5) Borrar directorio\n");
		p("Elige una opci%cn: ",162);
		menuArc=leer();
		switch(menuArc)
		{
			case 1: {
				p("Crear directorio\n");
				fichero=fopen(*(nombreArchivos+med),"r");
				if(fichero!=NULL)
				{
					p("Ya hay un archivo existente, %cdesea crear uno nuevo? (Presione 1 para proceder): ",168);
					con=leer();
					if(con!=1)
					{
						break;
					}
				}
				p("Cu%cntos pacientes agendar%cs\n",160,160);
				cleaner();
				n=leer();
				fichero=fopen(*(nombreArchivos+med),"w");
				registrar();
				break;	
			}
			case 2: {
				p("Agregar al directorio\n");
				p("Cu%cntos pacientes agregar%cs\n",160,160);
				cleaner();
				n=leer();
				fichero=fopen(*(nombreArchivos+med),"a");
				registrar();
				break;
			}
			case 3: {
				p("Consultar directorio\n");
				fichero=fopen(*(nombreArchivos+med),"r");
				if(fichero==NULL)
				{
					p("Error al abrir archivo\n");
				}
				else
				{
					p("El archivo se abri%c correctamente\n",162);
					p("El contenido del archivo es:\n");
					while(feof(fichero)==0)
					{
						cha=fgetc(fichero);
						p("%c",cha);
					}
					p("Fin del archivo\n");
				}
				fclose(fichero);
				break;
			}
			case 4: {
				p("Borrar paciente\n");
				fichero=fopen(*(nombreArchivos+med),"r");
				if(fichero==NULL)
				{
					p("El archivo no existe\n");
				}
				else
				{
					p("Ingresa nombre del paciente: ");
					cleaner();
					fgets(nombreB,25,stdin);
					limpiar(nombreB);
					p("Ingresa apellido paterno del paciente: ");
					cleaner();
					fgets(apPB,100,stdin);
					limpiar(apPB);
					p("Ingresa apellido materno del paciente: ");
					cleaner();
					fgets(apMB,25,stdin);
					limpiar(apMB);
					strcat(apPB,espacio);
					strcat(apPB,apMB);
					strcat(apPB,espacio);
					strcat(apPB,nombreB);
					strupr(apPB);
					while(feof(fichero)==0)
					{
						fgets(temporal,51,fichero);
						limpiar(temporal);
						comparar=strcmp(temporal,apPB);
						if(comparar==0)
						{
							linea=explorer;
							booleano=1;
						}
						explorer++;
					}
					if(visiter==0)
					{
						numLineas=explorer;
						aureo=numLineas;
						visiter++;
					}
					p("%d",numLineas);
					if(booleano==0)
					{
						p("No se encontr%c el paciente\n",162);
					}
					else
					{
						p("Se encontr%c al paciente\n",162);
						rewind(fichero);
						explorer=1;
						salve=4;
						temporal=fgetc(fichero);
						copia=fopen("copia.txt","w");
						while(temporal!=EOF)
						{
							temporal=fgetc(fichero);
							//p("%s",temporal);
							if(temporal=='\n')
							{
								explorer++;
							}
							if((explorer==linea)&&(salve>0))
							{
								if(temporal=='\n')
								{
									linea++;
									salve--;
								}
							}
							else
							{
								fputc(temporal,copia);
							}
							//explorer++;
						}
						if(visiter!=0)
						{
							numLineas=aureo-4;
						}
						fclose(fichero);
						fclose(copia);
						remove(*(nombreArchivos+med));
						rename("copia.txt",*(nombreArchivos+med));
					}
				}				
				break;
			}
			case 5: {
				p("Borrar directorio\n");
				fichero=fopen(*(nombreArchivos+med),"r");
				if(fichero==NULL)
				{
					p("No se encontr%c el archivo\n",162);
				}
				else
				{
					p("%cDesea borrar el archivo? (Presione 1 para proceder): ",168);
					con=leer();
					if(con==1);
					{
						fclose(fichero);
						del=remove(*(nombreArchivos+med));
						if(del==0)
						{
							p("Se ha borrado\n");
						}
					}
				}
				break;
			}
			default :{
				p("Opci%cn inv%clida\n",161,160);
			}
		}
		p("%cDesea regresar al men%c del directorio? (Presione 1 para proceder): ",168,163);
		z=leer();
	}
	while(z==1);
}
void registrar()
{
		int ver;
		/*if((med<3)&&(med>-1))
		{
			fprintf(fichero,"\tOftalmologia\n");
		}
		if((med<6)&&(med>=3))
		{
			fprintf(fichero,"\tNeurologia\n");
		}
		if((med<9)&&(med>=6))
		{
			fprintf(fichero,"\tOncologia\n");
		}
		fprintf(fichero,"\t%s\n",*(nombreMedicos+med));
		fprintf(fichero,"\tLista de pacientes\n\n"); */
		for(i=0;i<n;i++)
		{
			cleaner();
			p("Nombre %d: ",i+1);
			fgets(pac[med].nombre,50,stdin);
			limpiar(pac[med].nombre);
			strupr(pac[med].nombre);
			p("Apellido paterno %d: ",i+1);
			fgets(pac[med].apP,25,stdin);
			limpiar(pac[med].apP);
			strupr(pac[med].apP);
			p("Apellido materno %d: ",i+1);
			fgets(pac[med].apM,25,stdin);
			limpiar(pac[med].apM);
			strupr(pac[med].apM);
			strcat(pac[med].apP,espacio);
			strcat(pac[med].apP,pac[med].apM);
			strcat(pac[med].apP,espacio);
			strcat(pac[med].apP,pac[med].nombre);
			fprintf(fichero,"%s\n",pac[med].apP);
			p("Telefono %d: ",i+1);
			fgets(pac[med].tel,11,stdin);
			fprintf(fichero,"Tel: %s",pac[med].tel);
			do
			{
				p("Ingrese hora (formato hh:mm): ");
				cleaner();						
				ver=s("%d:%d",&hh,&mm);
			}
			while((hh>24)||(hh<0)||(mm<0)||(mm>60)||(ver!=2));
			if(hh>10)
			{
				pac[med].hora[0]=(hh/10)+'0';
				pac[med].hora[1]=(hh%10)+'0';
			}
			else
			{
				pac[med].hora[0]='0';
				pac[med].hora[1]=hh+'0';
			}
			pac[med].hora[2]=':';
			if(mm>10)
			{
				pac[med].hora[3]=(mm/10)+'0';
				pac[med].hora[4]=(mm%10)+'0';
			}
			else
			{
				pac[med].hora[3]='0';
				pac[med].hora[4]=mm+'0';
			}
			fprintf(fichero,"Hora: %s\n",pac[med].hora);
			fprintf(fichero,"\n");
			p("\n");
		}
		/*fprintf(fichero,"\tFin de lista de pacientes\n");
		fprintf(fichero,"\tPacientes de %s\n",*(nombreMedicos+med));
		fprintf(fichero,"\tFolio: 283754759214\n"); */
		fclose(fichero);
		p("Se ha agregado la informaci%cn\n",162); 
}
int leer()
{
	int x,ver;
	do
	{
		cleaner();
		ver=s("%d",&x);
	}
	while(ver!=1);
	return x;
}
void limpiar(char purgatorio[80])
{
	int len;
	len=strlen(purgatorio);
	if(purgatorio[len-1]!='\0')
	{
		purgatorio[len-1]='\0';
	}
}
void cleaner()
{
	fflush(stdin);
	setbuf(stdin,NULL);
}
