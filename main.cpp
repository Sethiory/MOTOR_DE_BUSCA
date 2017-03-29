#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;
int main(){

    ifstream openfile("C:\\Users\\Thiago\\Desktop\\MOTOR_DE_BUSCA\\arquivos\\tempo_perdido-legiao_urbana.txt");
    if(openfile.is_open())
    {
        while(!openfile.eof())
        {
            //O objeto openfile l� uma palavra do arquivo e escreve numa vari�vel tipo string(tempString);
            string tempString;
            openfile >> tempString;

            /*Para ser indexada a palavra deve ter mais que dois caracteres,
                            O terceiro caractere n�o pode ser especial e nem o pen�ltimo*/
            if(tempString.size()>2 && !ispunct(tempString[2]) && !ispunct(tempString[tempString.size()-3]))
            {
                //Caso o �ltimo caractere for especial, ele � subistituido por vazio
                if(ispunct(tempString[tempString.size()-1]))
                {
                    tempString[tempString.size()-1]='\0';
                }

                //Soma os c�digos ASCII de cada caractere da palavra
                int n=0, somador=0;
                while(tempString[n] != '\0' )
                {
                    somador+=tempString[n];
                    n++;
                }
                cout<<"\nSTRING="<<tempString<<"\nSOMA DOS COD ASCII=\t"<<somador<<" \n\n\n";
            }
        }
    }
    else
    {
        cout<<"ARQUIVO NAO ENCONTRADO!\n"<<endl;
    }

    
    system("pause");
    return 0;
}

