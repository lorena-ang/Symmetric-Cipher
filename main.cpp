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

char alphabet[27] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', '1', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

string caesarCipherEncryption(string sMessage, int iKey)
{
	int iC;
	char cElem;
	
	for (int i = 0; i < sMessage.length(); i++)
	{
		cElem = toupper(sMessage[i]);
		
		// Si es una Ñ
		if (cElem == '1')
		{
			iC = 14 + (iKey % 27);
		}
		// Si no es una Ñ
		else
		{
			// Si es una letra antes de la Ñ
			if (cElem - 'A' < 14)
			{
				iC = (cElem - 'A') + (iKey % 27);
			}
			// Si es una letra depués de la Ñ
			else
			{
				iC = (cElem - 'A' + 1) + (iKey % 27);
			}
		}
		
		if (iC >= 27 || iC < 0)
		{
			// Operación equivalente a (iC % 27) pero funciona con negativos
			iC = (27 + (iC % 27)) % 27;
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
		
		// Si es una Ñ
		if (cElem == '1')
		{
			iC = 14 - (iKey % 27);
		}
		// Si no es una Ñ
		else
		{
			// Si es una letra antes de la Ñ
			if (cElem - 'A' < 14)
			{
				iC = (cElem - 'A') - (iKey % 27);
			}
			// Si es una letra depués de la Ñ
			else
			{
				iC = (cElem - 'A' + 1) - (iKey % 27);
			}
		}
		
		if (iC >= 27 || iC < 0)
		{
			// Operación equivalente a (iC % 27) pero funciona con negativos
			iC = (27 + (iC % 27)) % 27;
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
		// Si es la Ñ
		if (cElemMes == '1')
		{
			iTempMessage[i] = 14;
		}
		// Si es una letra antes de la Ñ
		else if (cElemMes - 'A' < 14)
		{
			iTempMessage[i] = (cElemMes - 'A');
		}
		// Si es una letra depués de la Ñ
		else
		{
			iTempMessage[i] = (cElemMes - 'A' + 1);
		}
		
		cElemKey = toupper(sKey[k]);
		// Si es la Ñ
		if (cElemKey == '1')
		{
			iTempKey[i] = 14;
		}
		// Si es una letra antes de la Ñ
		else if (cElemKey - 'A' < 14)
		{
			iTempKey[i] = (cElemKey - 'A');
		}
		// Si es una letra depués de la Ñ
		else
		{
			iTempKey[i] = (cElemKey - 'A' + 1);
		}
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
		// Si es la Ñ
		if (cElemMes == '1')
		{
			iTempMessage[i] = 14;
		}
		// Si es una letra antes de la Ñ
		else if (cElemMes - 'A' < 14)
		{
			iTempMessage[i] = (cElemMes - 'A');
		}
		// Si es una letra depués de la Ñ
		else
		{
			iTempMessage[i] = (cElemMes - 'A' + 1);
		}
		
		cElemKey = toupper(sKey[k]);
		// Si es la Ñ
		if (cElemKey == '1')
		{
			iTempKey[i] = 14;
		}
		// Si es una letra antes de la Ñ
		else if (cElemKey - 'A' < 14)
		{
			iTempKey[i] = (cElemKey - 'A');
		}
		// Si es una letra depués de la Ñ
		else
		{
			iTempKey[i] = (cElemKey - 'A' + 1);
		}
	}
	
	for (int i = 0; i < sMessage.length(); i++)
	{
		// Operación equivalente a ((iTempMessage[i] - iTempKey[i]) % 27) pero funciona con negativos
		iC = (27 + ((iTempMessage[i] - iTempKey[i]) % 27)) % 27;
		sMessage[i] = alphabet[iC];
	}
	
	return sMessage;
}

string hillCipherEncryption(string sMessage, int iKey)
{
	
	return sMessage;
}

string hillCipherDecryption(string sMessage, int iKey)
{
	
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
						cin >> iKey;
						
						sEncryptedMessage = hillCipherEncryption(sMessage, iKey);
						cout << "El mensaje encriptado es: " << sEncryptedMessage << endl;
					}
					else if (cOpcion2 == '2')
					{
						cout << "Ingresa el mensaje a desencriptar: ";
						cin >> sMessage;
						cout << "Ingresa la llave: ";
						cin >> iKey;
						
						sDecryptedMessage = hillCipherDecryption(sMessage, iKey);
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
