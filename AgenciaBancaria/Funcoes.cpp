// Funções do programa de Agencia Bancária
#include "Agencia.h"

// Função que pede o código de um cliente válido
//	ou zero para cancelar a transação
//	Parâmetros:
//		Entrada: char *ptrAcao - ponteiro para um string que contem a ação
//								que está sendo executada
//		Retorno: int - código de cliente válido ou zero para cancelar a ação
int PedirCodigoCliente(char *ptrAcao)
{
	int nCodigo;					// para receber o código
	cout << "\n\t" << ptrAcao << endl;
	do
	{
		cout << "Código do cliente entre 1 e " << QTDE_CLIENTES << endl
			<< "Ou zero para cancelar a transação: ";
		cin >> nCodigo;				// recebe o código
		if (nCodigo == 0)			// cancelar a transação?
			return 0;				// indica que cancelou a transação
	} while (nCodigo < 1 || nCodigo > QTDE_CLIENTES);
	return nCodigo;					// devolve o código válido
}
// Função que lê um cliente de forma posicional (acesso direto)
// Parâmetros:
//	Entrada: int nCodigo - código do cliente desejado
//			 CLIENTE *ptrCliente - ponteiro de uma struct para receber os
//									dados do cliente
//			 FILE *fdArquivo - ponteiro do file descriptor do cadastro
//	Retorno: bool - true - leitura foi Ok
//					false - erro de seek ou de leitura
bool LerClientePosicional(int nCodigo, CLIENTE *ptrCliente, FILE *fdArquivo)
{
	if (fseek(fdArquivo, (nCodigo - 1) * sizeof(CLIENTE), SEEK_SET) != 0) // erro?
	{
		return false;					// indica que houve erro
	}
	if (fread_s(ptrCliente, sizeof(CLIENTE), sizeof(CLIENTE),
		1, fdArquivo) == 0)				// erro de leitura?
		return false;					// indica erro
	return true;						// indica tudo OK
}
// Função que grava um cliente posicional (acesso direto)
//	Entrada: int nCodigo - código do cliente a ser gravado
//			 CLIENTE *ptrCliente - ponteiro de uma struct que contem os 
//									dados do cliente
//			 FILE *fdArquivo - ponteiro do file descriptor do cadastro
//	Retorno: bool - true - gravação foi Ok
//					false - erro de seek ou de gravação
bool GravarClientePosicional(int nCodigo, CLIENTE *ptrCliente, FILE *fdArquivo)
{
	if (fseek(fdArquivo, (nCodigo - 1) * sizeof(CLIENTE), SEEK_SET) != 0) // erro?
		return false;					// indica que houve erro
	if (fwrite(ptrCliente, sizeof(CLIENTE), 1, fdArquivo) == 0) // erro gravação?
		return false;					// indica o erro
	return true;						// indica que gravação foi OK
}
