#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct cadastro_cliente
{
    int CPF;
    char nome[50];
    char email[50];
    char telefone[15];
    int status;

} Cliente;
// Struct utilizado para o cliente
typedef struct manager
{
    int cliente;
} Manager;
// Struct criado para somar 1 toda vez que um cliente for cadastrado, vulgo contador
enum Status_cadastro_cliente
{
    EXISTE,
    CADASTRADO,
};
// Enum utilizado para dizer se o cliente existe ou tem contrato

typedef struct cadastro_filme
{
    int codigo;
    char nome[50];
    int genero;
    int classificacao;
} Filme;
// Struct utilizado para o filme
enum Genero_filme
{
    AVENTURA,
    COMEDIA,
    DRAMA,
    TERROR,
    ACAO,
    ROMANCE,
};
// Enum para facilitar o encontro do genero do filme
enum Classificacao_Filme
{
    LIVRE,
    MAIS10,
    MAIS12,
    MAIS14,
    MAIS16,
    MAIS18,
};
// Enum para facilitar o encontro da classificacao do filme
typedef struct manager_Filme
{
    int contador;
} M_Filme;
// Struct criado para somar 1 toda vez que um filme for cadastrado, vulgo contador
enum Status_cadastro_filme
{
    CADASTRADO_FILME,
};
// enum utilizado para deixar o codigo mais abstraido, a fim de entender quando realmente o filme foi cadastrado na subrotina
typedef struct Plano_Basico
{
    int qtd_filmes;
    float valor_base;
    float valor_ex;

} plano_b;
// struct utilizado para armazenar o que o plano basico deveria ter
typedef struct Plano_Premium
{
    float valor_base;
} plano_p;
// struct utilizado para armazenar o que o plano premium deveria ter

typedef union
{
    plano_b planobasico;
    plano_p planopremium;
} planos;

// union utilizado para com os planos
typedef struct manager_Contrato
{
    int contador;
} M_contrato;
// Struct criado para somar 1 toda vez que um contrato for cadastrado, vulgo contador
enum Status_Contrato
{
    SEM_CLIENTES,
    CLIENTE_N_CADASTRADO,
    CLIENTE_COM_CONTRATO,
    CONTRATO_BEMSUCEDIDO,
};

// enum utilizado so no return da parte de contratos

typedef struct S_CONTRATO
{
    int CPF;
    int tipo_plano;
    int pagamento;
    int credito; //Quando o cliente seleciona para pagar no credito
    int agencia; //Quando o cliente seleciona para pagar no debito
    int conta;   //Quando o cliente seleciona para pagar no debito
    int dia_inicial;
    int mes_inicial;
    int dia_final;
    int mes_final;
} Contrato;

typedef struct historico
{
    int codigo;
    int dia;
} Historico;

// A matriz que deve existir vai ser do tipo historico
enum status_cliente
{
    NAO_CADASTRADO,
    NAO_ATIVO,
    FILME_NEXISTE,
    BEM_SUCEDIDO,
    N_DESEJOU,
    JA_PREENCHIDO,
    NAO_QUER,
    QUER_ASSISTIR,
    SUCESSO,
    DATA_ANTERIOR,

};
// outro enum usado sobre o status_cliente

enum frequencia_filmes
{
    CODIGO_INVALIDO,
    NENHUM_FILME_ASSISTIDO,
};
// enum usado para frequencia do filme

enum
{
    NENHUM_CLIENTE_EXCEDENTE,
};
// enum auxiliar para clientes excedidos
enum recomendar_filme
{
    ASSISTIU_NENHUM = 2,
    TODOS_FILMES_ASSIST,

};
// Enum utlizado para recomendar filme

int cadastra_cliente(Cliente *clientes, int tam);
// Passei o vetor dos clientes por referencia e o contador manager.cliente e toda vez que o cliente e cadastrado e é bem sucedido, esse contador soma +1 e caso selecione essa funcao novamente
// o tam torna-se = 1 e nao 0.
int cadastra_filme(Filme *filmes, int tam);
// Passei o vetor dos filmes por referencia e o contador managerFilme.contador e toda vez que o filme e cadastrado e é bem sucedido, esse contador soma +1 e caso selecione essa funcao novamente
// o tam torna-se = 1 e nao 0.
int cadastra_plano_B(plano_b *planobasico);
// Passo a variavel do tipo plano_b por referencia e preenche os dados la dentro da funcao
int cadastra_plano_P(plano_p *planopremium);
// Passo a variavel do tipo plano_p por referencia e preenche os dados la dentro da funcao
int mostra_dados_cliente(Cliente *clientes, int tam);
// Passa o vetor clientes e contador manager.cliente como referencia
int cadastro_contrato(Contrato *contratos, Cliente *clientes, int tam, int tam1, int mes);
// Passa o vetor contratos, clientes o contador dos clientes(manager.cliente) e o contador dos contratos(managerContrato.contador) e o mes que eu iniciei pra funcao como 1
// Verifica se o cliente existe e esta com contrato, depois preenche os dados deles baseado na ordem dada pelo comando.
int carregar_filme(Historico historico[][30], Cliente *clientes, plano_b *dados_pbasico, int qtd_clientes, int qtd_filmes, Contrato *contratos, Filme *filmes, int qtd_contratos, int qtd_filmestotal);
// Passa o a matriz_historico do tipo historico, o vetor de clientes, pois sera usado para salvar a posicao que o cpf do cliente informado esta no vetor e usar essa posicao
// pra salvar no historico o codigo e o dia e usar os dados do plano basico pra verificar se o cliente do plano basico ja excedeu a cota dos filmes permitidos. Apos isso
// mostra na tela os filmes cadastrados (usando o vetor filmes) e depois de informar o codigo do filme que deseja ser carregado,
// agora ha o salvamento do codigo do filme assistido e do dia
int cancelar_contrato(Cliente *clientes, Historico historico[][30], int qtd_clientes, Contrato *contratos, int qtd_contratos, plano_p *dados_ppremium, plano_b *dados_pbasico, int qtdtotal_filmes, int mes);
// Basicamente e usado a logica a fim de gerar a fatura do cliente baseado na logica da funcao (gerar_fatura) e apos as verificacoes(cliente existe e cliente_cadastrado)
// muda o status do cliente para 0.
int gerar_fatura(int qtd_totalclientes, Cliente *clientes, Historico historico[][30], int qtd_clientes, Contrato *contratos, int qtd_contratos, plano_p *dados_ppremium, plano_b *dados_pbasico, int qtdtotal_filmes, int qtd_filmescadastrados, Filme *filmes, int *mes);
// Para gerar a fatura especifica informa o cpf faz as verificacoes(cliente existe e cliente cadastrado) e apos isso usa a matriz_historico a fim de verificar quantos filmes ele
// assistiu e ai gerar a sua fatura, baseado no plano encontrado no tipo do plano do vetor contratos, assim imprime quanto ele deve e qual mes vigente.
// Para gerar a fatura para todo mundo, imprime o nome dos usuarios ativos, o valor que eles estao devendo, somar um no mes que foi inicializado na main(passado por parametro)
// e zerar a matriz_historico.
int lista_historico(Historico historico[][30], Cliente *clientes, Filme *filmes, int qtd_clientescadastrados, int qtdtotalfilmes, int qtdfilmescadastrados, int mes);
// Informa o cpf, salva a posicao no vetor cliente(pos_cliente) e printa os filmes assistidos da matriz_historico, a partir da posicao salva (pos_cliente).
int checar_clientes_excedentes(Historico historico[][30], Cliente *clientes, int qtd_clientescadastrados, int qtdtotalfilmes, int qtdcontratos, Contrato *contratos, plano_b dados_base);
// Verifica os filmes assistidos na matriz_historico e com o auxilio de contador de quando uma posicao na matriz ta preenchida, compara com o plano do usuario que foi informado no contrato
// Logo, verifica-se quais passaram do limite normal.
int listar_frequencia(Filme *filmes, Historico historico[][30], int qtdtotalclientes, int qtdtotalfilmes, int qtd_filmescadastrados);
// Utiliza-se um contador auxiliar para ver quantos filmes foram assistidos e um para quando o codigo encontrado na matriz for igual ao informado
int recomendar_filme(Historico historico[][30], Cliente *clientes, int qtdfilmestotal, int qtdfilmescadastrados, int qtd_clientescadastrados, Filme *filmes);
// Criado a fim de recomendar os filmes que nao foram assistidos do genero que o usuario mais assistiu.
int main()
{
    // Declaracao de algumas variaveis e vetores que serao passados como parametro
    int i, j;
    Manager manager = {0};
    const int tam = 10;
    const int qtd_filmes = 30;
    Cliente contas[tam];
    Filme filmes[tam];
    M_Filme managerFilme = {0};
    plano_b dados_base;
    plano_p valor_unico;
    M_contrato managerContrato = {0};
    Contrato contratos[tam];
    int mes = 1;
    Historico matriz_historico[tam][qtd_filmes];
    ////////////////////////////////////////////////////////////////////////////
    for (i = 0; i < tam; i++)
    {
        for (j = 0; j < qtd_filmes; j++)
        {
            matriz_historico[i][j].codigo = 0;
            matriz_historico[i][j].dia = 0;
        }
    }

    int menu;
    do
    {
        scanf("%d", &menu);
        switch (menu)
        {
        case 0:
            printf("Finalizando programa...");
            break;

        case 1:
            if (manager.cliente < tam)
            {
                switch (cadastra_cliente(contas, manager.cliente))
                {
                case EXISTE:
                    printf("ERRO: CPF do cliente ja cadastrado\n");
                    break;
                case CADASTRADO:
                    printf("Cliente cadastrado com sucesso\n");
                    manager.cliente++;
                    break;
                default:
                    break;
                }
            }
            else
                printf("ERRO: Numero maximo de clientes no sistema atingido\n");

            break;
        case 2:
            if (managerFilme.contador < tam)
            {
                switch (cadastra_filme(filmes, managerFilme.contador))
                {
                case CADASTRADO_FILME:
                    printf("Filme cadastrado com sucesso\n");
                    managerFilme.contador++;
                    break;
                }
            }
            else
                printf("ERRO: Numero maximo de filmes no sistema atingido\n");
            break;
        case 3:
            switch (cadastra_plano_B(&dados_base))
            {
            case 0:
                printf("Plano Basico cadastrado com sucesso\n");
                break;
            }
            break;
        case 4:
            switch (cadastra_plano_P(&valor_unico))
            {
            case 0:
                printf("Plano Premium cadastrado com sucesso\n");
                break;
            }
            break;
        case 5:
            if (managerContrato.contador < tam)
            {
                if (manager.cliente != 0)
                {
                    switch (cadastro_contrato(contratos, contas, manager.cliente, managerContrato.contador, mes))
                    {
                    case CLIENTE_N_CADASTRADO:
                        printf("ERRO: Cliente nao cadastrado\n");
                        break;
                    case CLIENTE_COM_CONTRATO:
                        printf("ERRO: Cliente com contrato existente\n");
                        break;
                    case CONTRATO_BEMSUCEDIDO:
                        printf("Contrato cadastrado com sucesso\n");
                        managerContrato.contador++;
                        break;
                    }
                }
                else
                {
                    printf("ERRO: Nenhum cliente cadastrado no sistema\n");
                    break;
                }
            }
            else
                printf("ERRO: Numero maximo de contratos no sistema atingido\n");
            break;
        case 6:
            if (manager.cliente != 0)
            {
                switch (carregar_filme(matriz_historico, contas, &dados_base, manager.cliente, managerFilme.contador, contratos, filmes, managerContrato.contador, qtd_filmes))
                {
                case NAO_CADASTRADO:
                    printf("ERRO: Cliente nao cadastrado\n");
                    break;
                case NAO_ATIVO:

                    printf("ERRO: Cliente nao ativo\n");
                    break;
                case FILME_NEXISTE:
                    printf("ERRO: Filme nao encontrado\n");
                    break;
                case BEM_SUCEDIDO:
                    printf("Filme carregado com sucesso\n");
                    break;
                case JA_PREENCHIDO:
                    printf("ERRO: Numero maximo de filmes no sistema atingido\n");
                    break;
                case NAO_QUER:
                    printf("ERRO: Taxa adicional negada\n");
                    break;
                }
            }
            else
                printf("ERRO: Nenhum cliente cadastrado no sistema\n");
            break;
        case 7:
            if (managerContrato.contador != 0)
            {
                switch (cancelar_contrato(contas, matriz_historico, manager.cliente, contratos, managerContrato.contador, &valor_unico, &dados_base, qtd_filmes, mes))
                {
                case NAO_CADASTRADO:
                    printf("ERRO: Cliente nao cadastrado\n");
                    break;
                case NAO_ATIVO:
                    printf("ERRO: Cliente inativo\n");
                    break;
                case DATA_ANTERIOR:
                    printf("ERRO: Data de cancelamente anteiror a data de contratacao\n");
                    break;
                case SUCESSO:
                    printf("Cancelamento feito com sucesso\n");
                    break;
                }
            }
            else
                printf("ERRO: Nenhum contrato cadastrado no sistema\n");
            break;

        case 8:

            switch (gerar_fatura(tam, contas, matriz_historico, manager.cliente, contratos, managerContrato.contador, &valor_unico, &dados_base, qtd_filmes, managerFilme.contador, filmes, &mes))
            {
            case NAO_CADASTRADO:
                printf("ERRO: Cliente nao cadastrado\n");
                break;
            case NAO_ATIVO:
                printf("ERRO: Cliente nao possui contrato\n");
                break;
            }

            break;

        case 9:
            if (manager.cliente == 0)
            {
                printf("ERRO: Nenhum cliente cadastrado no sistema\n");
                break;
            }

            else
            {
                switch (mostra_dados_cliente(contas, manager.cliente))
                {
                case 0:
                    printf("ERRO: Cliente nao cadastrado\n");
                    break;
                case 1:
                    break;
                }
            }
            break;
        case 10:
            if (manager.cliente == 0)
            {
                printf("ERRO: Nenhum cliente cadastrado no sistema\n");
                break;
            }
            else
            {
                switch (lista_historico(matriz_historico, contas, filmes, manager.cliente, qtd_filmes, managerFilme.contador, mes))
                {
                case NAO_CADASTRADO:
                    printf("ERRO: Cliente nao cadastrado\n");
                    break;
                case NENHUM_FILME_ASSISTIDO:
                    printf("ERRO: Nenhum filme assistido\n");
                    break;
                }
            }
            break;
        case 11:
            switch (checar_clientes_excedentes(matriz_historico, contas, manager.cliente, qtd_filmes, managerContrato.contador, contratos, dados_base))
            {
            case NENHUM_CLIENTE_EXCEDENTE:
                printf("ERRO: Nenhum cliente excedente\n");
                break;
            }
            break;
        case 12:
            if (managerFilme.contador == 0)
            {
                printf("ERRO: Nenhum filme cadastrado no sistema\n");
                break;
            }
            else
            {
                switch (listar_frequencia(filmes, matriz_historico, tam, qtd_filmes, managerFilme.contador))
                {
                case CODIGO_INVALIDO:
                    printf("ERRO: Codigo invalido\n");
                    break;
                case NENHUM_FILME_ASSISTIDO:
                    printf("ERRO: Nenhum filme assistido\n");
                    break;
                }
            }
            break;
        case 13:
            if (manager.cliente == 0)
            {
                printf("ERRO: Nenhum cliente cadastrado no sistema\n");
            }
            else
            {
                switch (recomendar_filme(matriz_historico, contas, qtd_filmes, managerFilme.contador, manager.cliente, filmes))
                {
                case NAO_ATIVO:
                    printf("ERRO: Cliente nao ativo\n");
                    break;
                case NAO_CADASTRADO:
                    printf("ERRO: Cliente nao cadastrado\n");
                    break;
                case ASSISTIU_NENHUM:
                    printf("ERRO: Nenhum filme assistido\n");
                    break;
                case TODOS_FILMES_ASSIST:
                    printf("ERRO: Todos os filmes do(s) genero(s) foram assistidos\n");
                    break;
                }
            }
            break;
        default:
            printf("ERRO: Opcao invalida\n");
            break;
        }
    } while (menu != 0);

    return 0;
}
//Funcao que cadastra cliente
int cadastra_cliente(Cliente *clientes, int tam)
{

    int i, nao_existe = 1;
    int CPF;

    scanf("%d", &CPF);

    for (i = 0; i < tam; i++)
    {
        if (CPF == clientes[i].CPF)
        {
            nao_existe = 0;
            return EXISTE;
            break;
        }
    }
    if (nao_existe)
    {

        clientes[tam].CPF = CPF;
        scanf(" %[^\n]%*c", clientes[tam].nome);
        scanf(" %[^\n]%*c", clientes[tam].email);
        scanf(" %[^\n]%*c", clientes[tam].telefone);
        clientes[tam].status = 0;
    }
    return CADASTRADO;
}

int cadastra_filme(Filme *filmes, int tam)
{
    int genero, classificacao;
    scanf(" %[^\n]%*c", filmes[tam].nome);
    do
    {
        scanf("%d", &genero);
        if (genero < AVENTURA || genero > ROMANCE)
            printf("ERRO: Genero invalido\n");

    } while (genero < AVENTURA || genero > ROMANCE);
    filmes[tam].genero = genero;
    do
    {
        scanf("%d", &classificacao);
        if (classificacao < LIVRE || classificacao > MAIS18)
            printf("ERRO: Classificao invalida\n");

    } while (classificacao < LIVRE || classificacao > MAIS18);
    filmes[tam].classificacao = classificacao;
    filmes[tam].codigo = 1001 + tam;
    return CADASTRADO_FILME;
}

int cadastra_plano_B(plano_b *planobasico)
{

    scanf("%d", &planobasico->qtd_filmes);
    scanf("%f", &planobasico->valor_base);
    scanf("%f", &planobasico->valor_ex);
    return 0;
}

int cadastra_plano_P(plano_p *planopremium)
{
    scanf("%f", &planopremium->valor_base);
    return 0;
}
int cadastro_contrato(Contrato *contratos, Cliente *clientes, int tam, int tam1, int mes)
{
    int CPF, i, cliente_existe = 0, pos_cliente, tipo_plano, dia_inicial, pagamento;
    scanf("%d", &CPF);
    for (i = 0; i < tam; i++)
    {
        if (CPF == clientes[i].CPF)
        {
            cliente_existe = 1;
            pos_cliente = i;
            break;
        }
    }
    for (i = 0; i < tam1; i++)
    {
        if (CPF == contratos[i].CPF)
        {
            if (clientes[pos_cliente].status == 1)
            {
                return CLIENTE_COM_CONTRATO;
                break;
            }
        }
    }
    if (!cliente_existe)
        return CLIENTE_N_CADASTRADO;

    contratos[tam1].CPF = clientes[pos_cliente].CPF;
    do
    {
        scanf("%d", &tipo_plano);
        if (tipo_plano < 0 || tipo_plano > 1)
        {
            printf("ERRO: Tipo de plano invalido\n");
        }
    } while (tipo_plano < 0 || tipo_plano > 1);
    contratos[tam1].tipo_plano = tipo_plano;
    do
    {
        scanf("%d", &pagamento);
        if (pagamento < 0 || pagamento > 1)
        {
            printf("ERRO: Tipo de pagamento invalido\n");
        }
    } while (pagamento < 0 || pagamento > 1);
    contratos[tam1].pagamento = pagamento;

    if (contratos[tam1].pagamento == 1)
    {
        scanf("%d", &contratos[tam1].credito);
    }
    else if (contratos[tam1].pagamento == 0)
    {
        scanf("%d %d", &contratos[tam1].agencia, &contratos[tam1].conta);
    }
    do
    {
        scanf("%d", &dia_inicial);
        if (dia_inicial < 1 || dia_inicial > 31)
        {
            printf("ERRO: Dia invalido\n");
        }
    } while (dia_inicial < 1 || dia_inicial > 31);
    contratos[tam1].dia_inicial = dia_inicial;
    contratos[tam1].mes_inicial = mes;
    contratos[tam1].dia_final = 0;
    contratos[tam1].mes_final = 0;
    clientes[pos_cliente].status = 1;
    return CONTRATO_BEMSUCEDIDO;
}
int carregar_filme(Historico historico[][30], Cliente *clientes, plano_b *dados_pbasico, int qtd_clientes, int qtd_filmes, Contrato *contratos, Filme *filmes, int qtd_contratos, int qtd_filmestotal)
{
    int CPF, i, dia, cliente_existe = 0, tipo_escolha, codigo_filme, codigo_certo = 0, pos_contrato, pos_cliente, pos_historico, decisao, existe_posicao = 0, opcao_escolhida, contador_assitido = 0;
    scanf("%d", &CPF);
    for (i = 0; i < qtd_clientes; i++)
    {
        if (CPF == clientes[i].CPF)
        {
            pos_cliente = i;
            cliente_existe = 1;
            if (clientes[i].status == 0)
            {
                return NAO_ATIVO;
            }
        }
    }
    if (!cliente_existe)
        return NAO_CADASTRADO;
    for (i = 0; i < qtd_filmestotal; i++)
    {
        if (historico[pos_cliente][i].codigo == 0)
        {
            existe_posicao = 1;
            break;
        }
    }
    if (!existe_posicao)
    {
        return JA_PREENCHIDO;
    }
    do
    {
        scanf("%d", &dia);
        if (dia < 1 || dia > 31)
        {
            printf("ERRO: Dia invalido\n");
        }
    } while (dia < 1 || dia > 31);
    do
    {
        scanf("%d", &tipo_escolha);
        if (tipo_escolha < 0 || tipo_escolha > 1)
            printf("ERRO: Escolha invalida\n");
    } while (tipo_escolha < 0 || tipo_escolha > 1);
    do
    {
        scanf("%d", &opcao_escolhida);
        if (opcao_escolhida < 0 || opcao_escolhida > 5)
            printf("ERRO: Escolha invalida\n");

    } while (opcao_escolhida < 0 || opcao_escolhida > 5);
    for (i = 0; i < qtd_filmes; i++)
    {
        if (tipo_escolha == 0)
        {
            if (opcao_escolhida == filmes[i].genero)
            {
                printf("Codigo: %d\n", filmes[i].codigo);
                printf("Nome: %s\n", filmes[i].nome);
            }
        }
        else
        {
            if (opcao_escolhida == filmes[i].classificacao)
            {
                printf("Codigo: %d\n", filmes[i].codigo);
                printf("Nome: %s\n", filmes[i].nome);
            }
        }
    }

    scanf("%d", &codigo_filme);
    for (i = 0; i < qtd_filmes; i++)
    {
        if (codigo_filme == filmes[i].codigo)
        {
            codigo_certo = 1;
        }
    }
    if (!codigo_certo)
        return FILME_NEXISTE;

    for (i = 0; i < qtd_contratos; i++)
    {
        if (CPF == contratos[i].CPF)
        {
            pos_contrato = i;
            break;
        }
    }
    switch (contratos[pos_contrato].tipo_plano)
    {
    case 0:
        for (i = 0; i < dados_pbasico->qtd_filmes; i++)
        {
            if (historico[pos_cliente][i].codigo == 0)
            {
                pos_historico = i;
                break;
            }
            if (historico[pos_cliente][i].codigo != 0)
            {
                contador_assitido++;
            }
        }
        if (contador_assitido >= dados_pbasico->qtd_filmes)
        {
            do
            {
                scanf("%d", &decisao);
                if (decisao < 0 || decisao > 1)
                {
                    printf("ERRO: Escolha invalida\n");
                }
            } while (decisao < 0 || decisao > 1);
            if (decisao == 0)
            {
                return NAO_QUER;
            }
            if (decisao == 1)
            {
                for (i = 0; i < qtd_filmestotal; i++)
                {
                    if (historico[pos_cliente][i].codigo == 0)
                    {
                        pos_historico = i;
                        break;
                    }
                }
            }
        }
        break;
    case 1:
        for (i = 0; i < qtd_filmestotal; i++)
        {
            if (historico[pos_cliente][i].codigo == 0)
            {
                pos_historico = i;
                break;
            }
        }
        break;
    }
    historico[pos_cliente][pos_historico].codigo = codigo_filme;
    historico[pos_cliente][pos_historico].dia = dia;
    return BEM_SUCEDIDO;
}
int cancelar_contrato(Cliente *clientes, Historico historico[][30], int qtd_clientes, Contrato *contratos, int qtd_contratos, plano_p *dados_ppremium, plano_b *dados_pbasico, int qtdtotal_filmes, int mes)
{
    int i, pos_cliente, pos_contratos, cliente_existe = 0, dia, CPF, contador_f = 0, contador_fextra, qtdfilmes_pbasico;
    float fatura;
    scanf("%d", &CPF);
    for (i = 0; i < qtd_clientes; i++)
    {
        if (CPF == clientes[i].CPF)
        {
            pos_cliente = i;
            cliente_existe = 1;
            if (clientes[i].status == 0)
            {
                return NAO_ATIVO;
            }
        }
    }
    if (!cliente_existe)
        return NAO_CADASTRADO;
    for (i = 0; i < qtd_contratos; i++)
    {
        if (CPF == contratos[i].CPF)
        {
            pos_contratos = i;
        }
    }
    do
    {
        scanf("%d", &dia);
        if (dia < 1 || dia > 31)
        {
            printf("ERRO: Dia invalido\n");
        }
    } while (dia < 1 || dia > 31);

    if (contratos[pos_contratos].mes_inicial == mes)
    {
        if (dia < contratos[pos_contratos].dia_inicial)
        {
            return DATA_ANTERIOR;
        }
        else if (dia > contratos[pos_contratos].dia_inicial)
        {
            if (contratos[pos_contratos].tipo_plano == 1)
            {
                fatura = dados_ppremium->valor_base;
            }
            if (contratos[pos_contratos].tipo_plano == 0)
            {
                qtdfilmes_pbasico = dados_pbasico->qtd_filmes;
                for (i = 0; i < qtdfilmes_pbasico; i++)
                {
                    if (historico[pos_cliente][i].codigo == 0)
                    {
                        fatura = dados_pbasico->valor_base;
                    }
                }
                for (i = 0; i < qtdtotal_filmes; i++)
                {
                    if (historico[pos_cliente][i].codigo != 0)
                    {
                        contador_f++;
                    }
                    if (historico[pos_cliente][i].codigo == 0)
                    {
                        break;
                    }
                }
                if (contador_f >= qtdfilmes_pbasico)
                {
                    contador_fextra = contador_f - qtdfilmes_pbasico;
                    fatura = dados_pbasico->valor_base + (contador_fextra * dados_pbasico->valor_ex);
                }
            }
            contratos[pos_contratos].dia_final = dia;
            contratos[pos_contratos].mes_final = mes;
            clientes[pos_cliente].status = 0;
            printf("Valor devido: %.2f\n", fatura);
        }
    }
    else if (mes > contratos[pos_contratos].mes_inicial)
    {
        if (contratos[pos_contratos].tipo_plano == 1)
        {
            fatura = dados_ppremium->valor_base;
        }
        if (contratos[pos_contratos].tipo_plano == 0)
        {
            qtdfilmes_pbasico = dados_pbasico->qtd_filmes;
            for (i = 0; i < qtdfilmes_pbasico; i++)
            {
                if (historico[pos_cliente][i].codigo == 0)
                {
                    fatura = dados_pbasico->valor_base;
                }
            }
            for (i = 0; i < qtdtotal_filmes; i++)
            {
                if (historico[pos_cliente][i].codigo != 0)
                {
                    contador_f++;
                }
                if (historico[pos_cliente][i].codigo == 0)
                {
                    break;
                }
            }
            if (contador_f >= qtdfilmes_pbasico)
            {
                contador_fextra = contador_f - qtdfilmes_pbasico;
                fatura = dados_pbasico->valor_base + (contador_fextra * dados_pbasico->valor_ex);
            }
        }
        contratos[pos_contratos].dia_final = dia;
        contratos[pos_contratos].mes_final = mes;
        clientes[pos_cliente].status = 0;
        printf("Valor devido: %.2f\n", fatura);
    }
    return SUCESSO;
}

int gerar_fatura(int qtd_totalclientes, Cliente *clientes, Historico historico[][30], int qtd_clientes, Contrato *contratos, int qtd_contratos, plano_p *dados_ppremium, plano_b *dados_pbasico, int qtdtotal_filmes, int qtd_filmescadastrados, Filme *filmes, int *mes)
{
    int pos_cliente, pos_contrato, i, decisao, CPF, cpf_existe = 0, pos_historico, j, qtdfilmes_pbasico, k, contador_f = 0, contador_fextra, l;
    float fatura;
    do
    {
        scanf("%d", &decisao);
        if (decisao < 0 || decisao > 1)
        {
            printf("ERRO: Escolha invalida\n");
        }
    } while (decisao < 0 || decisao > 1);
    if (decisao == 0)
    {
        if (qtd_clientes == 0)
        {
            printf("ERRO: Nenhum cliente cadastrado no sistema\n");
        }
        else
        {
            scanf("%d", &CPF);
            for (i = 0; i < qtd_clientes; i++)
            {
                if (CPF == clientes[i].CPF)
                {
                    cpf_existe = 1;
                    pos_cliente = i;
                    if (clientes[i].status == 0)
                    {
                        return NAO_ATIVO;
                        break;
                    }
                    break;
                }
            }
            if (!cpf_existe)
            {
                return NAO_CADASTRADO;
            }
            for (i = 0; i < qtd_contratos; i++)
            {
                if (CPF == contratos[i].CPF)
                {
                    pos_contrato = i;
                    break;
                }
            }
            if (contratos[pos_contrato].tipo_plano == 1)
            {
                fatura = dados_ppremium->valor_base;
                for (i = 0; i < qtdtotal_filmes; i++)
                {
                    if (historico[pos_cliente][i].codigo == 0)
                    {
                        pos_historico = i;
                        break;
                    }
                    else
                    {
                        pos_historico = qtdtotal_filmes;
                    }
                }
                for (i = 0; i <= pos_historico; i++)
                {
                    for (j = 0; j < qtd_filmescadastrados; j++)
                    {
                        if (historico[pos_cliente][i].codigo == filmes[j].codigo)
                        {
                            printf("Nome: %s\n", filmes[j].nome);
                            printf("Data: %d/%d\n", historico[pos_cliente][i].dia, *mes);
                        }
                    }
                }
                printf("Valor devido: %.2f\n", fatura);
            }
            if (contratos[pos_contrato].tipo_plano == 0)
            {
                qtdfilmes_pbasico = dados_pbasico->qtd_filmes;
                for (i = 0; i < qtdfilmes_pbasico; i++)
                {
                    if (historico[pos_cliente][i].codigo == 0)
                    {
                        fatura = dados_pbasico->valor_base;
                        for (k = 0; k < qtdfilmes_pbasico; k++)
                        {
                            for (j = 0; j < qtd_filmescadastrados; j++)
                            {
                                if (historico[pos_cliente][k].codigo == filmes[j].codigo)
                                {
                                    printf("Nome: %s\n", filmes[j].nome);
                                    printf("Data: %d/%d\n", historico[pos_cliente][k].dia, *mes);
                                }
                            }
                        }
                    }
                }
                for (i = 0; i < qtdtotal_filmes; i++)
                {
                    if (historico[pos_cliente][i].codigo != 0)
                    {
                        contador_f++;
                    }
                    if (historico[pos_cliente][i].codigo == 0)
                    {
                        break;
                    }
                }
                if (contador_f >= qtdfilmes_pbasico)
                {
                    contador_fextra = contador_f - qtdfilmes_pbasico;
                    fatura = dados_pbasico->valor_base + (contador_fextra * dados_pbasico->valor_ex);
                    for (i = 0; i < qtdtotal_filmes; i++)
                    {
                        for (j = 0; j < qtd_filmescadastrados; j++)
                        {
                            if (historico[pos_cliente][i].codigo == filmes[j].codigo)
                            {
                                printf("Nome: %s\n", filmes[j].nome);
                                printf("Data: %d/%d\n", historico[pos_cliente][i].dia, *mes);
                            }
                        }
                    }
                }
                printf("Valor devido: %.2f\n", fatura);
                return 10;
            }
        }
    }
    if (decisao == 1)
    {
        for (i = 0; i < qtd_contratos; i++)
        {
            for (j = 0; j < qtd_clientes; j++)
            {
                if (contratos[i].CPF == clientes[j].CPF)
                {
                    if (clientes[j].status == 1)
                    {
                        if (contratos[i].tipo_plano == 1)
                        {
                            fatura = dados_ppremium->valor_base;
                            printf("CPF: %d\n", contratos[j].CPF);
                            printf("Nome: %s\n", clientes[j].nome);
                            printf("Valor devido: %.2f\n", fatura);
                        }
                        if (contratos[i].tipo_plano == 0)
                        {
                            qtdfilmes_pbasico = dados_pbasico->qtd_filmes;
                            for (k = 0; k <= qtdfilmes_pbasico; k++)
                            {
                                if (historico[j][k].codigo == 0)
                                {
                                    fatura = dados_pbasico->valor_base;
                                    printf("CPF: %d\n", contratos[j].CPF);
                                    printf("Nome: %s\n", clientes[j].nome);
                                    printf("Valor devido: %.2f\n", fatura);
                                }
                            }
                            for (l = 0; l < qtdtotal_filmes; l++)
                            {
                                if (historico[j][l].codigo != 0)
                                {
                                    contador_f++;
                                }
                            }
                            if (contador_f >= qtdfilmes_pbasico)
                            {
                                contador_fextra = contador_f - qtdfilmes_pbasico;
                                fatura = dados_pbasico->valor_base + (contador_fextra * dados_pbasico->valor_ex);
                                printf("CPF: %d\n", contratos[j].CPF);
                                printf("Nome: %s\n", clientes[j].nome);
                                printf("Valor devido: %.2f\n", fatura);
                            }
                        }
                    }
                }
            }
        }
        printf("Mes vigente apos a fatura: %d\n", *mes + 1);
        for (i = 0; i < qtd_totalclientes; i++)
        {
            for (j = 0; j < qtdtotal_filmes; j++)
            {
                historico[i][j].codigo = 0;
                historico[i][j].dia = 0;
            }
        }
        *mes = *mes + 1;
    }
    return 10;
}

int mostra_dados_cliente(Cliente *clientes, int tam)
{
    int CPF, i, cliente_existe = 0, pos_cliente;
    scanf("%d", &CPF);
    for (i = 0; i < tam; i++)
    {
        if (CPF == clientes[i].CPF)
        {
            cliente_existe = 1;
            pos_cliente = i;
            break;
        }
    }
    if (!cliente_existe)
        return 0;
    printf("Nome: %s\n", clientes[pos_cliente].nome);
    printf("Email: %s\n", clientes[pos_cliente].email);
    printf("Telefone: %s\n", clientes[pos_cliente].telefone);
    printf("Status: %d\n", clientes[pos_cliente].status);
    return 1;
}
int lista_historico(Historico historico[][30], Cliente *clientes, Filme *filmes, int qtd_clientescadastrados, int qtdtotalfilmes, int qtdfilmescadastrados, int mes)
{
    int i, pos_cliente, CPF, cliente_existe = 0, contador_naoassistiu = 0, j;
    const char *const genero[] = {"aventura", "comedia", "drama", "terror", "acao", "romance"};
    const char *const classificacao[] = {"livre", "+10", "+12", "+14", "+16", "+18"};
    scanf("%d", &CPF);
    for (i = 0; i < qtd_clientescadastrados; i++)
    {
        if (CPF == clientes[i].CPF)
        {
            pos_cliente = i;
            cliente_existe = 1;
            break;
        }
    }
    if (!cliente_existe)
    {
        return NAO_CADASTRADO;
    }
    for (i = 0; i < qtdtotalfilmes; i++)
    {
        if (historico[pos_cliente][i].codigo != 0)
        {
            contador_naoassistiu++;
        }
    }
    if (contador_naoassistiu > 0)
    {
        if (clientes[pos_cliente].status == 1)
        {
            printf("Estado: Ativo\n");
        }
        if (clientes[pos_cliente].status == 0)
        {
            printf("Estado: Inativo\n");
        }
        for (i = 0; i < qtdtotalfilmes; i++)
        {
            for (j = 0; j < qtdfilmescadastrados; j++)
            {
                if (historico[pos_cliente][i].codigo == filmes[j].codigo)
                {

                    printf("Codigo: %d\n", filmes[j].codigo);
                    printf("Nome: %s\n", filmes[j].nome);
                    printf("Genero: %s\n", genero[filmes[j].genero]);
                    printf("Classificacao: %s\n", classificacao[filmes[j].classificacao]);
                    printf("Data do carregamento: %d/%d\n", historico[pos_cliente][i].dia, mes);
                    printf("\n");
                }
            }
        }
        return 10;
    }

    else
    {
        if (clientes[pos_cliente].status == 1)
        {
            printf("Estado: Ativo\n");
        }
        if (clientes[pos_cliente].status == 0)
        {
            printf("Estado: Inativo\n");
        }
        return NENHUM_FILME_ASSISTIDO;
    }
}

int listar_frequencia(Filme *filmes, Historico historico[][30], int qtdtotalclientes, int qtdtotalfilmes, int qtd_filmescadastrados)
{
    int i, j, historico_com_filmes = 0, codigo, filme_valido = 0, contador_filmescadastrados = 0, contador_codigo = 0;
    float frequencia;
    scanf("%d", &codigo);
    for (i = 0; i < qtdtotalclientes; i++)
    {
        for (j = 0; j < qtdtotalfilmes; j++)
        {
            if (historico[i][j].codigo != 0)
            {
                historico_com_filmes = 1;
                break;
            }
        }
    }
    if (!historico_com_filmes)
    {
        return NENHUM_FILME_ASSISTIDO;
    }
    for (i = 0; i < qtd_filmescadastrados; i++)
    {
        if (codigo == filmes[i].codigo)
        {
            filme_valido = 1;
        }
    }
    if (!filme_valido)
    {
        return CODIGO_INVALIDO;
    }
    for (i = 0; i < qtdtotalclientes; i++)
    {
        for (j = 0; j < qtdtotalfilmes; j++)
        {
            if (historico[i][j].codigo != 0)
            {
                contador_filmescadastrados++;
            }
            if (codigo == historico[i][j].codigo)
            {
                contador_codigo++;
            }
        }
    }
    frequencia = (float)contador_codigo / contador_filmescadastrados;
    frequencia = 100 * frequencia;
    printf("Frequencia: %.2f%%\n", frequencia);
    return 10;
}

int checar_clientes_excedentes(Historico historico[][30], Cliente *clientes, int qtd_clientescadastrados, int qtdtotalfilmes, int qtdcontratos, Contrato *contratos, plano_b dados_base)
{
    int i, j, pos_cliente, contador = 0, contador_filmes, contador_passou = 0;
    float valor_final;
    for (i = 0; i < qtdcontratos; i++)
    {
        contador = 0;
        if (contratos[i].tipo_plano == 0 && contratos[i].dia_final == 0)
        {
            for (j = 0; j < qtd_clientescadastrados; j++)
            {
                if (clientes[j].CPF == contratos[i].CPF)
                {
                    pos_cliente = j;
                    break;
                }
            }
            for (j = 0; j < qtdtotalfilmes; j++)
            {
                if (historico[pos_cliente][j].codigo != 0)
                {
                    contador++;
                }
                if (historico[pos_cliente][j].codigo == 0)
                {
                    break;
                }
            }
            if (contador > dados_base.qtd_filmes)
            {
                contador_passou++;
                contador_filmes = contador - dados_base.qtd_filmes;
                valor_final = contador_filmes * dados_base.valor_ex;
                printf("CPF: %d\n", clientes[pos_cliente].CPF);
                printf("Nome: %s\n", clientes[pos_cliente].nome);
                printf("Valor excedente: %.2f\n\n", valor_final);
            }
        }
    }
    if (contador_passou == 0)
    {
        return NENHUM_CLIENTE_EXCEDENTE;
    }
    return 10;
}
int recomendar_filme(Historico historico[][30], Cliente *clientes, int qtdfilmestotal, int qtdfilmescadastrados, int qtd_clientescadastrados, Filme *filmes)
{
    const int tam = 6;
    int CPF, i, j, k, cliente_existe = 0, pos_cliente, vetor_filmes[tam], *vetor_filmes1, maior = 0, contador = 1, salva_codigo, filme_existe = 0, contador_genero = 0;
    const char *const genero[] = {"aventura", "comedia", "drama", "terror", "acao", "romance"};
    const char *const classificacao[] = {"livre", "+10", "+12", "+14", "+16", "+18"};
    for (i = 0; i < tam; i++)
    {
        vetor_filmes[i] = 0;
    }
    vetor_filmes1 = malloc(sizeof(int));
    scanf("%d", &CPF);
    for (i = 0; i < qtd_clientescadastrados; i++)
    {
        if (CPF == clientes[i].CPF)
        {
            cliente_existe = 1;
            pos_cliente = i;
            if (clientes[i].status == 0)
            {
                return NAO_ATIVO;
            }
            break;
        }
    }
    if (!cliente_existe)
    {
        return NAO_CADASTRADO;
    }
    if (historico[pos_cliente][0].codigo == 0)
    {
        return ASSISTIU_NENHUM;
    }

    for (i = 0; i < qtdfilmestotal; i++)
    {
        if (historico[pos_cliente][i].codigo == 0)
        {
            break;
        }
        for (j = 0; j < qtdfilmescadastrados; j++)
        {
            if (historico[pos_cliente][i].codigo == filmes[j].codigo)
            {
                switch (filmes[j].genero)
                {
                case 0:
                    vetor_filmes[0] += 1;
                    break;
                case 1:
                    vetor_filmes[1] += 1;
                    break;
                case 2:
                    vetor_filmes[2] += 1;
                    break;
                case 3:
                    vetor_filmes[3] += 1;
                    break;
                case 4:
                    vetor_filmes[4] += 1;
                    break;
                case 5:
                    vetor_filmes[5] += 1;
                    break;
                }
                break;
            }
        }
    }
    for (i = 0; i < tam; i++)
    {
        if (vetor_filmes[i] == 0)
        {
            continue;
        }
        if (vetor_filmes[i] > maior)
        {
            maior = vetor_filmes[i];
            vetor_filmes1[contador - 1] = i;
        }
        else if (vetor_filmes[i] == maior)
        {
            contador++;
            vetor_filmes1 = realloc(vetor_filmes1, sizeof(int) * contador);
            vetor_filmes1[contador - 1] = i;
        }
    }
    for (i = 0; i < qtdfilmescadastrados; i++)
    {
        if (filmes[i].genero == vetor_filmes1[contador - 1])
        {
            contador_genero++;
        }
    }
    if (maior >= contador_genero)
    {
        return TODOS_FILMES_ASSIST;
    }
    for (i = 0; i < contador; i++)
    {
        for (j = 0; j < qtdfilmescadastrados; j++)
        {
            filme_existe = 0;
            if (vetor_filmes1[i] == filmes[j].genero)
            {
                for (k = 0; k < qtdfilmestotal; k++)
                {
                    salva_codigo = historico[pos_cliente][k].codigo;
                    if (salva_codigo == 0)
                    {
                        break;
                    }
                    if (salva_codigo == filmes[j].codigo)
                    {
                        filme_existe = 1;
                        break;
                    }
                }
                if (!filme_existe)
                {
                    printf("Codigo: %d\n", filmes[j].codigo);
                    printf("Nome: %s\n", filmes[j].nome);
                    printf("Genero: %s\n", genero[filmes[j].genero]);
                    printf("Classificacao: %s\n", classificacao[filmes[j].classificacao]);
                }
            }
        }
    }
    return 10;
}