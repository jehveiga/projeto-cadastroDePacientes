#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <locale.h>


int main(void)
{
    setlocale(LC_ALL, ""); //para ser aceito acento no programa
   //definicao do ponteiro para o arquivo
   FILE *pont_arq; //cria a variavel ponteiro para o arquivo
   FILE *infor_arq; //criando ponteiro do arquivo do grupo de risco
   FILE *usuario_arq; //criando ponteiro do arquivo de usuario e senha

   //declaracao das constantes e variaveis usadas no programa
    char nome[50], rua[60], bairro[50], cidade[50], uf[30], email[40], op, op2, op_com, op_user[16],  op_senha[11], op_user2[16],  op_senha2[11], op_user3, op_senha3;
    int cpf[12], tel[15], num_end[10], diag, diag2, diag3, cep[9];
    diag = diag2 = diag3 = 0;
    int dat1, dat2, dat3, idade;
    dat1 = dat2 = dat3 = idade = 0;
    char user [16] = "admin"; //usuario admistrador
    char senha [11] = "123456"; //senha do usuario admistrador
    char *p_user, *p_senha;


    //abrindo o arquivo com tipo de abertura a -> texto
    pont_arq = fopen("arquivo_cadastro.txt", "a");

    //testando se o arquivo foi realmente aberto/criado
    if(pont_arq == NULL)
    {
        printf("Erro na abertura do arquivo: Digite qualquer tecla\n");
        getch();
    }else{
    fclose(pont_arq);
    }

       //abrindo o arquivo com tipo de abertura ab+ -> abertura/criação do arquivo binário
    usuario_arq = fopen("cadastro_usuario.dat", "ab+");

    //testando se o arquivo foi realmente aberto/criado
    if(usuario_arq == NULL)
    {
        printf("Erro na abertura do arquivo: Digite qualquer tecla\n");
        getch();
    }else{
    fclose(usuario_arq);
    }

    do{
        printf("\t\t\t\t ==== Programa Cadastramento COVID-19 ====\n"); //Tela de abertura do programa
        printf("\n");
        //imprimindo as opcoes do menu
        printf("\n (1) Cadastro usuário\n");
        printf(" (2) Cadastro paciente\n");
        printf(" (0) Sair do programa\n");


        printf("\n\tInforme a opção desejada: \n");
        printf("\t\t\t\t>>>");
        op = getche(); // getche -> recebe o caracter e imprime em tela
        system("cls");
        printf("\n");


        switch (op)
        {
        case ('1'):
            //abrindo o arquivo com tipo de abertura wb -> somente um usuário pode ser cadastrado
            usuario_arq = fopen("cadastro_usuario.dat", "wb");

            //testando se o arquivo foi realmente aberto/criado
            if(usuario_arq == NULL)
            {
                printf("Erro na abertura do arquivo: Digite qualquer tecla\n");
                getch();
            }else
            {
            //CADASTRAMENTO DO USUARIO E SENHA (SOMENTE UM USUARIO e SENHA)
            printf("\tDigite o usuário até 15 caracteres e aperte ENTER para continuar: (Somente letras e números!) \n\n");
            printf("\t\t\t\t>>>\t");
            fflush(stdin);
            scanf("%s", op_user);
            fwrite(op_user, sizeof(op_user), 1, usuario_arq);
            p_user = op_user;
            printf(" \tUSUÁRIO REGISTRADO: >>> %s <<<<\n", p_user);

            printf("\tDigite a senha ate 10 caracteres e aperte ENTER para continuar: (Somente letras e números!)\n\n");
            printf("\t\t\t\t>>>\t");
            fflush(stdin);
            scanf("%s", op_senha);
            fwrite(op_senha, 1, sizeof(op_senha), usuario_arq);
            p_senha = op_senha;
            printf(" \tSENHA REGISTRADA: >>> %s <<<\n", p_senha);

            printf("\tDigite ENTER para continuar\n");
            getch();
            system("cls");
            fclose(usuario_arq);
            }
            break;

        case('2'):


            //abrindo o arquivo com tipo de abertura rb -> abertura para leitura do arquivo binário, para realizar a validação do usuario e senha
            usuario_arq = fopen("cadastro_usuario.dat", "rb");

            //testando se o arquivo foi realmente aberto/criado
            if(usuario_arq == NULL)
            {
                printf("Erro na abertura do arquivo: Digite qualquer tecla\n");
                getch();
            }else
            {

            fread(op_user, sizeof(op_user), 1, usuario_arq); //Leitura do usuario cadastrado
            p_user = op_user;


            fread(op_senha, sizeof(op_senha), 1, usuario_arq); //Leitura da senha cadastrado
            p_senha = op_senha;


            fclose(usuario_arq);
            }

            printf("\n\tEntre com o login do usuário e aperte ENTER para continuar: \n"); //Entrada  do login do usuario para validação
            printf("\n");
            printf("\t\t\t\t>>>\t");
            fflush(stdin);
            scanf("%s", op_user2);



                if ((strcmp(user, op_user2) ==0) || (strcmp(p_user, op_user2) == 0)) //CONDIÇÃO PARA VALIDAÇÃO DO USUARIO
                {

                    printf("\tEntre com a senha do usuário e aperte ENTER para continuar: \n"); //Entrada  da senha do usuario para validação
                    printf("\t\t\t\t>>>\t");
                    fflush(stdin);
                    scanf("%s", op_senha2);
                    printf("\n");

                        if ((strcmp(senha, op_senha2) == 0) || (strcmp(p_senha, op_senha2) == 0)) //CONDIÇÃO PARA VALIDAÇÃO DE SENHA
                        {
                            do{
                                //abrindo o arquivo com tipo de abertura a
                                pont_arq = fopen("arquivo_cadastro.txt", "a");

                                //testando se o arquivo foi realmente aberto/criado
                                if(pont_arq == NULL)
                                {
                                printf("Erro na abertura do arquivo: Digite qualquer tecla\n");
                                getch();
                                }else
                                {

                                //CADASTRO DO PACIENTE NO SISTEMA
                                printf("\t\t\t\t======== USUÁRIO LOGADO ==========\n\n"); //cadastro do paciente
                                printf("\n");
                                printf("\tDigite o NOME do paciente e aperte ENTER: \n");
                                printf("\t\t\t\t>>>\t");
                                fflush(stdin);
                                scanf(" %[^\n]s", nome); // [^\n] -> usado para ler uma string com espaço e limpar o buffer do teclad
                                fwrite(nome, strlen(nome), 1, pont_arq);

                                printf("\tDigite o CPF do paciente e aperte ENTER: >> SOMENTE NÚMEROS << \n"); //Digitar somente numeros para CPF
                                printf("\t\t\t\t>>>\t");
                                scanf("%d",&cpf);
                                fwrite(&cpf, strlen(cpf), 1, pont_arq);

                                printf("\tDigite o TELEFONE com (DDD) do paciente e aperte ENTER: >> SOMENTE NÚMEROS << \n"); //Entrada do telefone do paciente -> somente numeros
                                printf("\t\t\t\t>>>\t");
                                scanf("%d", &tel);
                                fwrite(&tel, strlen(tel), 1,  pont_arq);
                                system("cls"); //Limpar a tela


                                printf("\t>>> Endereco do paciente <<<\n\n");
                                printf("\tDigite a: >> RUA, AVENIDA, TRAVESSA, ETC. << e aperte ENTER:\n"); //Entrada do endereço do paciente -> tipo char
                                printf("\t\t\t\t>>>\t");
                                fflush(stdin);
                                scanf(" %[^\n]s", rua);
                                fwrite(rua, strlen(rua), 1,  pont_arq);

                                printf("\t>>> Digite o: >> NÚMERO << da Casa, Apartamento, Viela, etc. e aperte ENTER:\n"); //Digitar somente numeros no NUMERO residencial
                                printf("\t\t\t\t>>>\t");
                                scanf("%d", &num_end);
                                fwrite(&tel, strlen(tel), 1,  pont_arq);

                                printf("\t>>> Digite o: BAIRRO e aperte ENTER:\n"); //Entrada do bairro do paciente -> tipo char
                                printf("\t\t\t\t>>>\t");
                                fflush(stdin);
                                scanf(" %[^\n]s", bairro);
                                fwrite(bairro, strlen(bairro), 1,  pont_arq);

                                printf("\t>>> Digite a: CIDADE e aperte ENTER:\n"); //Entrada da cidade do paciente -> tipo char
                                printf("\t\t\t\t>>>\t");
                                fflush(stdin);
                                scanf(" %[^\n]s", cidade);
                                fwrite(cidade, strlen(cidade), 1,  pont_arq);

                                printf("\t>>> Digite o: ESTADO(UF) e aperte ENTER: \n"); //Entrada do estado do paciente, aconselhado formato de duas Letras (UF) -> tipo char
                                printf("\t\t\t\t>>>\t");
                                fflush(stdin);
                                scanf(" %[^\n]s", uf);
                                fwrite(uf, strlen(uf), 1,  pont_arq);

                                printf("\t>>> Digite o: CEP >> SOMENTE NÚMEROS SEM (- OU .) << e aperte ENTER:\n"); //Digitar somente numeros no CEP
                                printf("\t\t\t\t>>>\t");
                                scanf("%d", &cep);
                                fwrite(&cep, strlen(cep), 1,  pont_arq);
                                system("cls");


                                 printf("\tDigite A DATA DE NASCIMENTO: >> SOMENTE NÚMEROS - DD/MM/AAAA <<\n"); //Digitar da de nascimento pausadamente Ex: Dia ENTER, mës ENTER, Ano ENTER
                                printf("\t\t\t\tDigite o DIA e aperte ENTER:>>>\t");
                                scanf("%d", &dat1);
                                printf("\t\t\t\tDigite o MÊS e aperte ENTER:\t%d / ", dat1);
                                scanf("%d", &dat2);
                                printf("\t\t\t\tDigite o ANO e aperte ENTER:\t%d /%d / ", dat1, dat2);
                                scanf("%d", &dat3);
                                printf("\t\t\t\tDATA DE NASCIMENTO DIGITADA: %d /%d / %d\n", dat1, dat2, dat3);
                                idade = 2020 - dat3;
                                fwrite(&dat1, sizeof(int), 1,  pont_arq);
                                fwrite(&dat2, sizeof(int), 1,  pont_arq);
                                fwrite(&dat3, sizeof(int), 1,  pont_arq);

                                printf("\tDigite o EMAIL do paciente SE NÃO TIVER DIGITE: >> N << e aperte ENTER:\n"); //Entrada do email do paciente -> tipo char
                                printf("\t\t\t\t>>>\t");
                                fflush(stdin);
                                scanf(" %[^\n]s", email);
                                fwrite(email, strlen(email), 1,  pont_arq);

                                  printf("\t>>> Digite a DATA do diagnóstico do paciente:  >> SOMENTE NÚMEROS DD/MM/AAAA\n"); //Digitar data de diagnostico pausadamente Ex: Dia ENTER, mës ENTER, Ano ENTER
                                printf("\t\t\t\tDigite o DIA e aperte ENTER:>>>\t");
                                scanf("%d", &diag);
                                printf("\t\t\t\tDigite o MÊS e aperte ENTER:\t%d / ", diag);
                                scanf("%d", &diag2);
                                printf("\t\t\t\tDigite o ANO e aperte ENTER:\t%d / %d / ", diag, diag2);
                                scanf("%d", &diag3);
                                printf("\t\t\t\tDATA DO DIAGNÓSTICO DIGITADA: %d / %d / %d\n", diag, diag2, diag3);
                                fwrite(&diag, sizeof(int), 1,  pont_arq);
                                fwrite(&diag2, sizeof(int), 1,  pont_arq);
                                fwrite(&diag3, sizeof(int), 1,  pont_arq);

                                system("pause"); //Pause no sistema
                                system("cls");


                                printf("\n");
                                printf("\t>>> Paciente possui alguma COMORBIDADE:  \n\n"); //Opcao para fazer a condição do arquivo posteriormente
                                printf(" (1) Não tem\n");
                                printf(" (2) Diabetes\n");
                                printf(" (3) Obesidade\n");
                                printf(" (4) Hipertensão\n");
                                printf(" (5) Tuberculose\n");
                                printf(" (6) Outros\n");


                                printf("\n\tInforme a opção desejada: \n");
                                printf("\t\t\t\t>>>");
                                op_com = getche(); // getche -> recebe o caracter e imprime em tela



                                infor_arq = fopen("grupo_risco.txt", "a"); //abertura do arquivo do grupo de risco

                                    //testando se o arquivo foi realmente aberto/criado
                                    if(infor_arq == NULL)
                                {
                                    printf("Erro na abertura do arquivo: Digite qualquer tecla\n");
                                    getch();
                                }else{

                                    if (idade >= 65) //condição da gravação no arquivo de risco por idade
                                    {
                                        fwrite(&idade, sizeof(int), 1,  infor_arq);
                                        fwrite(&cep, sizeof(int), 1,  infor_arq);
                                    }else

                                    if ((op_com >= '2') && (op_com <= '6')) //condição da gravação no arquivo -> Paciente de risco por comorbidade
                                     {
                                        fwrite(&idade, sizeof(int), 1,  infor_arq);
                                        fwrite(&cep, sizeof(int), 1,  infor_arq);

                                     }


                                fclose(infor_arq);
                                fclose(infor_arq);
                                }

                                printf("\n");
                                system("pause"); //Pause no sistema
                                printf("\n");
                                printf("\tDigite >>> 0 <<< para sair");

                                op2 = getche();
                                system("cls");

                                }

                        }while(op2 != '0'); //CONDIÇÃO DA OPÇÃO DO CADASTRO DO PACIENTE
                        }else
                        {
                            printf("\t>>> Senha invalida <<<\n"); //mostrar senha invaliada no usuario
                        }
                }else
                {
                    printf("\t>>> Usuario invalido <<<\n"); //mostrar usuario invalido no usuario
                }


            default:
            {
                printf("\n"); //DEFAULT COM RETORNO EM BRANCO

            }
            }



        }while (op != '0'); //CONDIÇÃO DA OPÇÃO DO CADASTRO DO MENU




    return 0;
}
