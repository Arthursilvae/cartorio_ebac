#include <stdio.h>  // biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço de memória
#include <locale.h> // biblioteca de alocação de texto por região(acentuação)
#include <string.h> // biblioteca das strings
int registro() //função de adicionar funcionário
{
 // Inicio da criação de variáveis do tipo string
 char arquivo [200]; //
 char cpf [40]; // string de 40 caracteres designidao ao cpf(obs:. string são representados com [quantos caracteres cabem na string])
 char nome [40]; // string de 40 caracteres designinado ao nome
 char sobrenome [40]; // string designinada ao sobrenome
 char cargo[40]; // string de 40 caracteres desiginado aos cargos
 int escolha = 0;


   system ("cls"); //limpar a tela para continuar adicionando usuários  
 // final da criação de variáveis do tipo string
 printf ("\t\t\t\t\tMenu De Adicionar Usuários");
 printf ("\nPreencha As Informações Abaixo");
 
 //cpf
  printf ("\n\n\n\nDigite Aqui o CPF Para Cadastro:");
  scanf ("%s", cpf); // armazena a string cpf (não possui & porque é uma string e não uma variável) %s refere-se a strings
  
  strcpy (arquivo, cpf); // copiar o valor da string cpf na estring arquivo
  
  FILE *file; // FILE(função do sistema) *file criar um arquivo
  file = fopen(arquivo, "w"); // abrir o arquivo (escrever dentro do arquivo(arquivo escrever) obs:. escrever representado por w
  fprintf (file, "o CPF É "); // escrever no arquivo a string cpf
  fclose(file); // fechar arquivo
  
  file = fopen(arquivo, "a"); // abrir o arquivo e atualizar o a significa atualizar
  fprintf (file, cpf); // adicionar uma virgula(escrever uma virgula)
  fclose(file); // fecha o arquivo
 
  //nome
   printf ("Digite Aqui o Nome Para Cadastro:"); 
   scanf ("%s", nome); 
   
   file = fopen (arquivo, "a"); // abrir o arquivo e "a" atualizar (adicionar)
   fprintf (file, ", O nome é "); // adicionar a string nome (add nome) no arquivo
   fclose(file); // fecha o arquivo
   
   file = fopen (arquivo, "a"); // abrir o arquivo e "a" significa atualizar 
   fprintf (file, nome); //add uma virgula(adicionar uma virgula ao arquivo)
   fclose(file); //fecha o arquivo
 
   //sobrenome
   printf ("Digite Aqui O Sobrenome Para Cadastro:"); 
   scanf ("%s", sobrenome); // coletar valor para ser guarado na string nesse caso os valores são caracteres
   
   file = fopen (arquivo, "a"); // abrir o arquivo e atualizar
   fprintf (file, ", O sobrenome é "); // escrever dentro do arquivo 
   fclose(file); // fecha arquivo
   
   file = fopen (arquivo, "a"); // abrir o arquivo e atualizar
   fprintf (file, sobrenome); // escrever dentro do arquivo
   fclose(file); // fecha o arquivo
 
   // cargo
   printf ("Digite Aqui O Cargo Para Cadastro:");
   scanf ("%s", cargo); // coleta o valor para armazena na string
   
   file = fopen (arquivo, "a"); // abrir o arquivo e atualizar representado pelo "a"
   fprintf (file, " e o cargo é "); // escrever dentro do arquivo
   fclose (file); // fecha o arquivo
   
   file  = fopen (arquivo,"a"); // abrir o arquivo e atualizar
   fprintf (file, cargo); // escrever dentro do arquivo a string
   fclose (file); // fecha o arquivo
   
   printf ("\n\nAs informações foram Cadastradas Com Sucesso!!\n\n\n\n");
   system ("pause"); //pausa a tela para o usuário ver que foi um sucesso
   system("cls"); // limpar a tela 

   printf ("Deseja Continuar Adicionando Usuários?"); // continuar adicionando usuário
   printf ("\n\n\n\t1-Sim \n \t2-Não Voltar Ao Menu");
   printf ("\n\nSelecionar:");
   scanf ("%d",&escolha);
   switch (escolha)
   {
    case 1:	
     registro ();
     break;
     case 2:
     menu (); // abrir a função menu
	 break;	
   }


}


int consulta() // função de consultar funcionário 
{
 system ("cls");
 int casa = 0;
 setlocale (LC_ALL, "portuguese");
 char cpf [40]; //declarar a string cpf de novo porque está em outra função
 char conteudo [200]; // string do conteudo a ser consultado

  printf ("\t\t\t\t\tMenu De Consultar Usuários\n\n\n\n");
  printf ("Digite Aqui o CPF a ser consultado:");
  scanf ("%s", cpf); // coletar o calor cpf para ser armazenado na string consulta 	
	
  FILE *file; // consultar o arquivo file
  file = fopen (cpf, "r"); // abrir o arquivo o arquivo file e ler o cpf "r".

  if (file == NULL)	// se o valor da string cpf não for encontrado no arquivo 
  {
  	printf ("Desculpe, CPF NÃO ENCONTRADO!!\n"); // aparecerá esta mensagem
  }
  
  while(fgets(conteudo, 200, file) != NULL); // RODAR 200 CARACTERES e quando não achar será nulo
  {
  	printf ("\n Essas São as informações do Usuário: "); //
  	printf ("%s", conteudo); // expor a string conteudo %s porque é uma string
    printf ("\n\n\n");	// espaçamento
  }   
  system ("pause");
  fclose(file);
 system ("cls"); // limpa a tela
 printf ("Deseja Continuar Consultando Usuários?");
 printf ("\n\n\n\t1-Sim \n \t2-Não Voltar Ao Menu");
 printf ("\n\nSelecionar:");
 scanf ("%d",&casa);
 
 switch (casa)
{
 case 1: // caso 1 
 {
 consulta (); // abrir função consulta
 break;
 }	
 case 2: // caso 2
  {
  menu (); // abrir função menu
  break;
  }
 default:
 	{
	 printf ("Desculpe, Essa Opção Não Existe (;\n\n\n");
 	system ("pause");
	 break;
    }
} 

}



int deletar() // função de deletar funcionário
{
 char cpf [40]; // criação da variável cpf do tipo string de conjuto de 40 caracteres
 int a = 0; // variável  
  system ("cls"); // Limpar a Tela
  printf ("\t\t\t\tMenu De Deletar Usuários");
  
  printf ("\nDigite O CPF a Ser Deletado"); 
  printf ("\n\n\n\nDigite Aqui:");
  scanf ("%s", cpf); // armazena o dado na string cpf
  
  remove (cpf); // apaga a string cpf que possui esse dado
  
  FILE *file; // abrir o arquivo
  file = fopen (cpf,"r"); // consultar a variável cpf e ler
  
  if (cpf == NULL); // se o cpf for diferente do escrito
  {
  	printf ("CPF Deletado com Sucesso\n");  // aparecerá isso
    system ("pause");
    fclose(file);
  }
 
  system ("cls");
  printf ("\nContinuar Deletando Usuários?");
  printf ("\n\n \t1-Sim \n \t2-Não\n\n\n");
  printf ("Selecionar:");
  scanf ("%d", &a);
  system ("pause");
  switch (a)
  {
    case 1: // caso 1
   {
   deletar(); // abrir função deletar
   break;
   }
   case 2: // caso 2 
   {
   menu (); // abrir função menu
   break;
   }
   default:
    {
   	printf ("Desculpe, Essa Opção Não Existe (;\n\n"); // fala isso
   	system ("pause");
   	break;
    }
  }
}

int main() // função primára

 {
   setlocale(LC_ALL, "portuguese"); //setar idioma para o portugues
    
    char senha [10] = "a"; // variável senha string[] de 10 caracteres com um valor atribuido
    int comparacao;
    
     printf ("cártorio De Alunos e Funcionários da EBAC \n\n\n");
     printf ("\t**LOGIN**");
     printf ("\n\n\nDigite A Senha Para Acesso\n");
     printf ("Senha:");
     scanf ("%s", senha);
     
    system ("cls");



    comparacao = strcmp(senha,"admin"); // salva admin na variável comparacao
    if (comparacao ==0) // a variavel comparacao deve ser igual a zero ou seja não mudar
    { // se a afimaçao acima for verdade acontece a função main
	menu ();
    }
	else // não vai ter {} porque é só uma condição
       printf ("Senha Incorreta!"); 
	 
	 
   } // fim da função main


int menu ()
 {
int opcao = 0; //variável 
int repeticao = 1; //variavel de repetição (for)
	 
	 system ("cls");
	for (repeticao =1;repeticao =1;)
	{ // ponto de partida do "for"
	
	  system ("cls"); // limpar tela sempre que repetir
	  setlocale(LC_ALL,"Portuguese");
	
	printf ("cártorio De Alunos e Funcionários da EBAC \n\n\n");// Inicio do Menu
	printf ("\t\t\t\t    Escolha entre as Respectivas Opções Abaixo:\n \n \n \n");
	printf ("\t1-Adicionar Usuário \n \t2-Consultar Usuário \n \t3-Deletar Usuário \n \t4-Sair Do Menu\n"); 
    printf ("\n\n\nSelecionar:");// Fim do Menu

	  scanf ("%d", &opcao); // registrar resposta do usuário

	  system ("cls");// limpa a tela
 	
switch (opcao)
{
	 case 1: // inicio do primeiro caso (inicio da seleção)
	 registro(); // chamar função registro caso seja 1
	 break; //fim do primeiro caso
	 
	 case 2: // inicio do segundo caso
	 consulta(); // chama função consulta caso seja 2
	 break; //fim do segundo caso
	 
	 case 3: // inicio do terceiro caso
     deletar(); // chama função deletar caso seja 3
	 break; // fim do terceiro caso
	 
	 case 4: // inicio do quarto caso
	printf ("Você Selecionou Sair Do Menu!!\n\n\n\n\n\n\n\n\n");
	return 0;
	 break;
	 
	 default: // caso o usuário escolha outra opção alem das acima
	 printf ("Desculpe, Essa opção Não Existe (;\n\n");
	 system ("pause");
	 break;// fim desse caso (fim da seleção)
}	
	 
    }  // ponto na qual o sistema ira volta ao ponto de partida
   
 
 } // fim da função menu
