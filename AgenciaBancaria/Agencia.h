// Declarações do programa de agencia bancária
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

// Menu de opções
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
	int nCodigo;						// código do cliente 1, 2, 3, ....QTDE_CLIENTES
	char cAtivo,						// 'A' - ativo e 'I' - inativo
		cNome[EXTENSAO_NOME + 1];		// nome do cliente
	DATA stDataUltimoAcesso;			// data do último acesso
	double	dSaldo,						// saldo do cliente
		dTotalDebitos,					// total dos débitos
		dTotalCreditos;					// total dos créditos
} CLIENTE;								// struct do cliente
										
// protótipos das funções
int PedirCodigoCliente(char *ptrAcao);
bool LerClientePosicional(int nCodigo, CLIENTE *ptrCliente, FILE *fdArquivo);
bool GravarClientePosicional(int nCodigo, CLIENTE *ptrCliente, FILE *fdArquivo);







