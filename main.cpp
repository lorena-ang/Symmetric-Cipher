//
//  main.cpp
//  CifradosSimetricos
//
//  Created by Lore Ang on 14/11/22.
//

#include <iostream>
#include <cctype>
#include<vector>
using namespace std;

char alphabet[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', ';', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

// Encuentra el valor numérico según su posición en el alfabeo
int findAlphabetValue(char cElem)
{
	// Si es la letra Ñ
	if (cElem == ';')
	{
		return 14;
	}
	// Si es una letra antes de la Ñ
	else if (cElem - 'A' < 14)
	{
		return (cElem - 'A');
	}
	// Si es una letra depués de la Ñ
	else
	{
		return (cElem - 'A' + 1);
	}
}

// Operación equivalente a (iC % 27) pero funciona con negativos
int modulo(int iElem)
{
	return (27 + (iElem % 27)) % 27;
}

string caesarCipherEncryption(string sMessage, int iKey)
{
	int iC;
	char cElem;
	
	for (int i = 0; i < sMessage.length(); i++)
	{
		cElem = toupper(sMessage[i]);
		
		iC = findAlphabetValue(cElem) + (iKey % 27);

		if (iC >= 27 || iC < 0)
		{
			iC = modulo(iC);
		}
		cElem = alphabet[iC];
		
		sMessage[i] = cElem;
	}
	
	return sMessage;
}

string caesarCipherDecryption(string sMessage, int iKey)
{
	int iC;
	char cElem;
	
	for (int i = 0; i < sMessage.length(); i++)
	{
		cElem = toupper(sMessage[i]);
		
		iC = findAlphabetValue(cElem) - (iKey % 27);

		if (iC >= 27 || iC < 0)
		{
			iC = modulo(iC);
		}
		
		cElem = alphabet[iC];
		sMessage[i] = cElem;
	}
	
	return sMessage;
}

string vigenereCipherEncryption(string sMessage, string sKey)
{
	char cElemMes, cElemKey;
	int iC, iTempMessage[sMessage.length()], iTempKey[sMessage.length()];
	
	// Guardar números de cada letra de message y key según alfabeto
	for (int i = 0, k = 0; i < sMessage.length(); i++, k++)
	{
		// Repetir llave para que sea de misma longitud que mensaje
		if (k == sKey.length())
		{
			k = 0;
		}
		
		cElemMes = toupper(sMessage[i]);
		iTempMessage[i] = findAlphabetValue(cElemMes);
		
		cElemKey = toupper(sKey[k]);
		iTempKey[i] = findAlphabetValue(cElemKey);
	}
	
	for (int i = 0; i < sMessage.length(); i++)
	{
		iC = (iTempMessage[i] + iTempKey[i]) % 27;
		sMessage[i] = alphabet[iC];
	}
	
	return sMessage;
}

string vigenereCipherDecryption(string sMessage, string sKey)
{
	char cElemMes, cElemKey;
	int iC, iTempMessage[sMessage.length()], iTempKey[sMessage.length()];
	
	// Guardar números de cada letra de message y key según alfabeto
	for (int i = 0, k = 0; i < sMessage.length(); i++, k++)
	{
		// Repetir llave para que sea de misma longitud que mensaje
		if (k == sKey.length())
		{
			k = 0;
		}
		
		cElemMes = toupper(sMessage[i]);
		iTempMessage[i] = findAlphabetValue(cElemMes);
		
		cElemKey = toupper(sKey[k]);
		iTempKey[i] = findAlphabetValue(cElemKey);
	}
	
	for (int i = 0; i < sMessage.length(); i++)
	{
		iC = modulo(iTempMessage[i] - iTempKey[i]);
		sMessage[i] = alphabet[iC];
	}
	
	return sMessage;
}

string hillCipherEncryption(string sMessage, string sKey)
{
	int iTempMessage1[2], iTempMessage2[2];
	int iTempKey[2][2];
	
	// Guardar números de cada letra de message y key según alfabeto
	for (int i = 0, iRow = 0, iCol = 0; i < 4; i++)
	{
		char cElemMes = toupper(sMessage[i]);
		char cElemKey = toupper(sKey[i]);
		
		iTempKey[iRow][iCol] = findAlphabetValue(cElemKey);
		
		if (i < 2)
		{
			iTempMessage1[iCol] = findAlphabetValue(cElemMes);
		}
		else
		{
			iTempMessage2[iCol] = findAlphabetValue(cElemMes);
		}
		
		if (i == 1)
		{
			iRow++;
			iCol = 0;
		}
		else
		{
			iCol++;
		}
	}
	
	// Realizar cálculo a través de multiplicación matricial
	for (int i = 0, k = 0; i < 4; i++, k++)
	{
		int iC;
		
		if (k == 2)
		{
			k = 0;
		}
		
		if (i < 2)
		{
			iC = modulo(iTempKey[k][0] * iTempMessage1[0] + iTempKey[k][1] * iTempMessage1[1]);
		}
		else
		{
			iC = modulo(iTempKey[k][0] * iTempMessage2[0] + iTempKey[k][1] * iTempMessage2[1]);
		}
		
		sMessage[i] = alphabet[iC];
	}
	
	return sMessage;
}

string hillCipherDecryption(string sMessage, string sKey)
{
	int iTempMessage1[2], iTempMessage2[2];
	int iTempKey[2][2];
	
	// Guardar números de cada letra de message y key según alfabeto
	for (int i = 0, iRow = 0, iCol = 0; i < 4; i++)
	{
		char cElemMes = toupper(sMessage[i]);
		char cElemKey = toupper(sKey[i]);
		
		iTempKey[iRow][iCol] = findAlphabetValue(cElemKey);
		
		if (i < 2)
		{
			iTempMessage1[iCol] = findAlphabetValue(cElemMes);
		}
		else
		{
			iTempMessage2[iCol] = findAlphabetValue(cElemMes);
		}
		
		if (i == 1)
		{
			iRow++;
			iCol = 0;
		}
		else
		{
			iCol++;
		}
	}
	
	// falta el cálculo
	
	return sMessage;
}

int main(int argc, const char * argv[])
{
	char cOpcion1, cOpcion2;
	string sMessage, sKey, sEncryptedMessage, sDecryptedMessage;
	int iKey;
	
	do
	{
		cout << "\nMenú - Cifrado Simétrico\n";
		cout << "1. Cifrado César\n";
		cout << "2. Cifrado Vigenère\n";
		cout << "3. Cifrado de Hill\n";
		cout << "4. Salir\n";
		cout << "Ingrese la opción deseada: ";
		cin >> cOpcion1;
		
		switch (cOpcion1)
		{
			case '1':
				do
				{
					cout << "\nCifrado César\n";
					cout << "1. Encriptado\n";
					cout << "2. Desencriptado\n";
					cout << "3. Regresar a menú principal\n";
					cout << "Ingrese la opción deseada: ";
					cin >> cOpcion2;
					
					if (cOpcion2 == '1')
					{
						cout << "Ingresa el mensaje a encriptar: ";
						cin >> sMessage;
						cout << "Ingresa la llave: ";
						cin >> iKey;
						
						sEncryptedMessage = caesarCipherEncryption(sMessage, iKey);
						cout << "El mensaje encriptado es: " << sEncryptedMessage << endl;
					}
					else if (cOpcion2 == '2')
					{
						cout << "Ingresa el mensaje a desencriptar: ";
						cin >> sMessage;
						cout << "Ingresa la llave: ";
						cin >> iKey;
						
						sDecryptedMessage = caesarCipherDecryption(sMessage, iKey);
						cout << "El mensaje desencriptado es: " << sDecryptedMessage << endl;
					}
					else
					{
						if (cOpcion2 != '3')
						{
							cout << "Error, ingrese una opción válida.\n";
						}
					}
				} while (cOpcion2 != '3');
				break;
			case '2':
				do
				{
					cout << "\nCifrado Vigenère\n";
					cout << "1. Encriptado\n";
					cout << "2. Desencriptado\n";
					cout << "3. Regresar a menú principal\n";
					cout << "Ingrese la opción deseada: ";
					cin >> cOpcion2;
					
					if (cOpcion2 == '1')
					{
						cout << "Ingresa el mensaje a encriptar: ";
						cin >> sMessage;
						cout << "Ingresa la llave: ";
						cin >> sKey;
						
						sEncryptedMessage = vigenereCipherEncryption(sMessage, sKey);
						cout << "El mensaje encriptado es: " << sEncryptedMessage << endl;
					}
					else if (cOpcion2 == '2')
					{
						cout << "Ingresa el mensaje a desencriptar: ";
						cin >> sMessage;
						cout << "Ingresa la llave: ";
						cin >> sKey;
						
						sDecryptedMessage = vigenereCipherDecryption(sMessage, sKey);
						cout << "El mensaje desencriptado es: " << sDecryptedMessage << endl;
					}
					else
					{
						if (cOpcion2 != '3')
						{
							cout << "Error, ingrese una opción válida.\n";
						}
					}
				} while (cOpcion2 != '3');
				break;
			case '3':
				do
				{
					cout << "\nCifrado de Hill\n";
					cout << "1. Encriptado\n";
					cout << "2. Desencriptado\n";
					cout << "3. Regresar a menú principal\n";
					cout << "Ingrese la opción deseada: ";
					cin >> cOpcion2;
					
					if (cOpcion2 == '1')
					{
						cout << "Ingresa el mensaje a encriptar: ";
						cin >> sMessage;
						cout << "Ingresa la llave: ";
						cin >> sKey;
						
						sEncryptedMessage = hillCipherEncryption(sMessage, sKey);
						cout << "El mensaje encriptado es: " << sEncryptedMessage << endl;
					}
					else if (cOpcion2 == '2')
					{
						cout << "Ingresa el mensaje a desencriptar: ";
						cin >> sMessage;
						cout << "Ingresa la llave: ";
						cin >> sKey;
						
						sDecryptedMessage = hillCipherDecryption(sMessage, sKey);
						cout << "El mensaje desencriptado es: " << sDecryptedMessage << endl;
					}
					else
					{
						if (cOpcion2 != '3')
						{
							cout << "Error, ingrese una opción válida.\n";
						}
					}
				} while (cOpcion2 != '3');
				break;
			case '4':
				cout << "Programa terminado.\n";
				break;
			default:
				cout << "Error, ingrese una opción válida.\n";
				break;
		}
	} while (cOpcion1 != '4');
	
	return 0;
}

/*
 cout << iTempMessage1[0] << endl;
 cout << iTempMessage1[1] << endl;
 cout << iTempMessage2[0] << endl;
 cout << iTempMessage2[1] << endl;
 
 cout << iTempKey[0][0] << endl;
 cout << iTempKey[0][1] << endl;
 cout << iTempKey[1][0] << endl;
 cout << iTempKey[1][1] << endl;
 */
