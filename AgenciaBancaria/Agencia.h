// Declara��es do programa de agencia banc�ria
#include <iostream>
#include <Windows.h>
using namespace std;

// defines
#define PAUSA							system("pause")
#define LIMPAR_TELA						system("cls")
#define QTDE_CLIENTES					2000
#define EXTENSAO_NOME					40
#define ATIVO							'A'
#define INATIVO							'I'
// caminho e nome do arquivo
#define CAMINHO_ARQUIVO					"..\\Cadastro.cad"

// Menu de op��es
#define CADASTRAR_CLIENTE				'C'
#define EXCLUIR_CLIENTE					'E'
#define MOSTRAR_CLIENTE					'M'
#define DEBITAR_CHEQUE					'D'
#define CREDITAR_DEPOSITO				'P'
#define LISTAR_CADASTRO					'L' // listar a partir de um dado cliente
#define EXIBIR_SALDO_TOTAL				'T' 
#define SAIR_DO_PROGRAMA				'S'

// struct da data
typedef struct tagDATA
{
	int nDia, nMes, nAno;				// dia mes e ano
} DATA;

// struct do cliente
typedef struct tagCLIENTE
{
	int nCodigo;						// c�digo do cliente 1, 2, 3, ....QTDE_CLIENTES
	char cAtivo,						// 'A' - ativo e 'I' - inativo
		cNome[EXTENSAO_NOME + 1];		// nome do cliente
	DATA stDataUltimoAcesso;			// data do �ltimo acesso
	double	dSaldo,						// saldo do cliente
		dTotalDebitos,					// total dos d�bitos
		dTotalCreditos;					// total dos cr�ditos
} CLIENTE;								// struct do cliente
										
// prot�tipos das fun��es
int PedirCodigoCliente(char *ptrAcao);
bool LerClientePosicional(int nCodigo, CLIENTE *ptrCliente, FILE *fdArquivo);
bool GravarClientePosicional(int nCodigo, CLIENTE *ptrCliente, FILE *fdArquivo);







