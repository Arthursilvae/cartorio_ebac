#include <stdio.h>  // biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria
#include <locale.h> // biblioteca de aloca��o de texto por regi�o(acentua��o)
#include <string.h> // biblioteca das strings
int registro() //fun��o de adicionar funcion�rio
{
 // Inicio da cria��o de vari�veis do tipo string
 char arquivo [200]; //
 char cpf [40]; // string de 40 caracteres designidao ao cpf(obs:. string s�o representados com [quantos caracteres cabem na string])
 char nome [40]; // string de 40 caracteres designinado ao nome
 char sobrenome [40]; // string designinada ao sobrenome
 char cargo[40]; // string de 40 caracteres desiginado aos cargos
 int escolha = 0;


   system ("cls"); //limpar a tela para continuar adicionando usu�rios  
 // final da cria��o de vari�veis do tipo string
 printf ("\t\t\t\t\tMenu De Adicionar Usu�rios");
 printf ("\nPreencha As Informa��es Abaixo");
 
 //cpf
  printf ("\n\n\n\nDigite Aqui o CPF Para Cadastro:");
  scanf ("%s", cpf); // armazena a string cpf (n�o possui & porque � uma string e n�o uma vari�vel) %s refere-se a strings
  
  strcpy (arquivo, cpf); // copiar o valor da string cpf na estring arquivo
  
  FILE *file; // FILE(fun��o do sistema) *file criar um arquivo
  file = fopen(arquivo, "w"); // abrir o arquivo (escrever dentro do arquivo(arquivo escrever) obs:. escrever representado por w
  fprintf (file, "o CPF � "); // escrever no arquivo a string cpf
  fclose(file); // fechar arquivo
  
  file = fopen(arquivo, "a"); // abrir o arquivo e atualizar o a significa atualizar
  fprintf (file, cpf); // adicionar uma virgula(escrever uma virgula)
  fclose(file); // fecha o arquivo
 
  //nome
   printf ("Digite Aqui o Nome Para Cadastro:"); 
   scanf ("%s", nome); 
   
   file = fopen (arquivo, "a"); // abrir o arquivo e "a" atualizar (adicionar)
   fprintf (file, ", O nome � "); // adicionar a string nome (add nome) no arquivo
   fclose(file); // fecha o arquivo
   
   file = fopen (arquivo, "a"); // abrir o arquivo e "a" significa atualizar 
   fprintf (file, nome); //add uma virgula(adicionar uma virgula ao arquivo)
   fclose(file); //fecha o arquivo
 
   //sobrenome
   printf ("Digite Aqui O Sobrenome Para Cadastro:"); 
   scanf ("%s", sobrenome); // coletar valor para ser guarado na string nesse caso os valores s�o caracteres
   
   file = fopen (arquivo, "a"); // abrir o arquivo e atualizar
   fprintf (file, ", O sobrenome � "); // escrever dentro do arquivo 
   fclose(file); // fecha arquivo
   
   file = fopen (arquivo, "a"); // abrir o arquivo e atualizar
   fprintf (file, sobrenome); // escrever dentro do arquivo
   fclose(file); // fecha o arquivo
 
   // cargo
   printf ("Digite Aqui O Cargo Para Cadastro:");
   scanf ("%s", cargo); // coleta o valor para armazena na string
   
   file = fopen (arquivo, "a"); // abrir o arquivo e atualizar representado pelo "a"
   fprintf (file, " e o cargo � "); // escrever dentro do arquivo
   fclose (file); // fecha o arquivo
   
   file  = fopen (arquivo,"a"); // abrir o arquivo e atualizar
   fprintf (file, cargo); // escrever dentro do arquivo a string
   fclose (file); // fecha o arquivo
   
   printf ("\n\nAs informa��es foram Cadastradas Com Sucesso!!\n\n\n\n");
   system ("pause"); //pausa a tela para o usu�rio ver que foi um sucesso
   system("cls"); // limpar a tela 

   printf ("Deseja Continuar Adicionando Usu�rios?"); // continuar adicionando usu�rio
   printf ("\n\n\n\t1-Sim \n \t2-N�o Voltar Ao Menu");
   printf ("\n\nSelecionar:");
   scanf ("%d",&escolha);
   switch (escolha)
   {
    case 1:	
     registro ();
     break;
     case 2:
     menu (); // abrir a fun��o menu
	 break;	
   }


}


int consulta() // fun��o de consultar funcion�rio 
{
 system ("cls");
 int casa = 0;
 setlocale (LC_ALL, "portuguese");
 char cpf [40]; //declarar a string cpf de novo porque est� em outra fun��o
 char conteudo [200]; // string do conteudo a ser consultado

  printf ("\t\t\t\t\tMenu De Consultar Usu�rios\n\n\n\n");
  printf ("Digite Aqui o CPF a ser consultado:");
  scanf ("%s", cpf); // coletar o calor cpf para ser armazenado na string consulta 	
	
  FILE *file; // consultar o arquivo file
  file = fopen (cpf, "r"); // abrir o arquivo o arquivo file e ler o cpf "r".

  if (file == NULL)	// se o valor da string cpf n�o for encontrado no arquivo 
  {
  	printf ("Desculpe, CPF N�O ENCONTRADO!!\n"); // aparecer� esta mensagem
  }
  
  while(fgets(conteudo, 200, file) != NULL); // RODAR 200 CARACTERES e quando n�o achar ser� nulo
  {
  	printf ("\n Essas S�o as informa��es do Usu�rio: "); //
  	printf ("%s", conteudo); // expor a string conteudo %s porque � uma string
    printf ("\n\n\n");	// espa�amento
  }   
  system ("pause");
  fclose(file);
 system ("cls"); // limpa a tela
 printf ("Deseja Continuar Consultando Usu�rios?");
 printf ("\n\n\n\t1-Sim \n \t2-N�o Voltar Ao Menu");
 printf ("\n\nSelecionar:");
 scanf ("%d",&casa);
 
 switch (casa)
{
 case 1: // caso 1 
 {
 consulta (); // abrir fun��o consulta
 break;
 }	
 case 2: // caso 2
  {
  menu (); // abrir fun��o menu
  break;
  }
 default:
 	{
	 printf ("Desculpe, Essa Op��o N�o Existe (;\n\n\n");
 	system ("pause");
	 break;
    }
} 

}



int deletar() // fun��o de deletar funcion�rio
{
 char cpf [40]; // cria��o da vari�vel cpf do tipo string de conjuto de 40 caracteres
 int a = 0; // vari�vel  
  system ("cls"); // Limpar a Tela
  printf ("\t\t\t\tMenu De Deletar Usu�rios");
  
  printf ("\nDigite O CPF a Ser Deletado"); 
  printf ("\n\n\n\nDigite Aqui:");
  scanf ("%s", cpf); // armazena o dado na string cpf
  
  remove (cpf); // apaga a string cpf que possui esse dado
  
  FILE *file; // abrir o arquivo
  file = fopen (cpf,"r"); // consultar a vari�vel cpf e ler
  
  if (cpf == NULL); // se o cpf for diferente do escrito
  {
  	printf ("CPF Deletado com Sucesso\n");  // aparecer� isso
    system ("pause");
    fclose(file);
  }
 
  system ("cls");
  printf ("\nContinuar Deletando Usu�rios?");
  printf ("\n\n \t1-Sim \n \t2-N�o\n\n\n");
  printf ("Selecionar:");
  scanf ("%d", &a);
  system ("pause");
  switch (a)
  {
    case 1: // caso 1
   {
   deletar(); // abrir fun��o deletar
   break;
   }
   case 2: // caso 2 
   {
   menu (); // abrir fun��o menu
   break;
   }
   default:
    {
   	printf ("Desculpe, Essa Op��o N�o Existe (;\n\n"); // fala isso
   	system ("pause");
   	break;
    }
  }
}

int main() // fun��o prim�ra

 {
   setlocale(LC_ALL, "portuguese"); //setar idioma para o portugues
    
    char senha [10] = "a"; // vari�vel senha string[] de 10 caracteres com um valor atribuido
    int comparacao;
    
     printf ("c�rtorio De Alunos e Funcion�rios da EBAC \n\n\n");
     printf ("\t**LOGIN**");
     printf ("\n\n\nDigite A Senha Para Acesso\n");
     printf ("Senha:");
     scanf ("%s", senha);
     
    system ("cls");



    comparacao = strcmp(senha,"admin"); // salva admin na vari�vel comparacao
    if (comparacao ==0) // a variavel comparacao deve ser igual a zero ou seja n�o mudar
    { // se a afima�ao acima for verdade acontece a fun��o main
	menu ();
    }
	else // n�o vai ter {} porque � s� uma condi��o
       printf ("Senha Incorreta!"); 
	 
	 
   } // fim da fun��o main


int menu ()
 {
int opcao = 0; //vari�vel 
int repeticao = 1; //variavel de repeti��o (for)
	 
	 system ("cls");
	for (repeticao =1;repeticao =1;)
	{ // ponto de partida do "for"
	
	  system ("cls"); // limpar tela sempre que repetir
	  setlocale(LC_ALL,"Portuguese");
	
	printf ("c�rtorio De Alunos e Funcion�rios da EBAC \n\n\n");// Inicio do Menu
	printf ("\t\t\t\t    Escolha entre as Respectivas Op��es Abaixo:\n \n \n \n");
	printf ("\t1-Adicionar Usu�rio \n \t2-Consultar Usu�rio \n \t3-Deletar Usu�rio \n \t4-Sair Do Menu\n"); 
    printf ("\n\n\nSelecionar:");// Fim do Menu

	  scanf ("%d", &opcao); // registrar resposta do usu�rio

	  system ("cls");// limpa a tela
 	
switch (opcao)
{
	 case 1: // inicio do primeiro caso (inicio da sele��o)
	 registro(); // chamar fun��o registro caso seja 1
	 break; //fim do primeiro caso
	 
	 case 2: // inicio do segundo caso
	 consulta(); // chama fun��o consulta caso seja 2
	 break; //fim do segundo caso
	 
	 case 3: // inicio do terceiro caso
     deletar(); // chama fun��o deletar caso seja 3
	 break; // fim do terceiro caso
	 
	 case 4: // inicio do quarto caso
	printf ("Voc� Selecionou Sair Do Menu!!\n\n\n\n\n\n\n\n\n");
	return 0;
	 break;
	 
	 default: // caso o usu�rio escolha outra op��o alem das acima
	 printf ("Desculpe, Essa op��o N�o Existe (;\n\n");
	 system ("pause");
	 break;// fim desse caso (fim da sele��o)
}	
	 
    }  // ponto na qual o sistema ira volta ao ponto de partida
   
 
 } // fim da fun��o menu
