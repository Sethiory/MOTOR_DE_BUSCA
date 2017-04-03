#include "hash.h"

HASH::HASH()
{
}

void HASH::index()
{
    ifstream openfile("C:\\Users\\Thiago\\Desktop\\MOTOR_DE_BUSCA\\arquivos\\entrada.txt");
    if(openfile.is_open())
    {
        int quant_arquivos;
        openfile>>quant_arquivos;
        cout<<"\t ***QUANTIDADE DE ARQUIVOS "<<quant_arquivos;

        while(!openfile.eof())
        {
            //O objeto openfile lê uma palavra do arquivo e escreve numa variável tipo string(tempString);
            string tempString;
            openfile >> tempString;
            //cria um ponteiro para um char de tamanho tempString
            char * cstr = new char[tempString.length()+1];
            //copia tempString para o array char(cstr)
            strcpy(cstr,tempString.c_str());
            //transforma em minusculas todas as letras de cstr
            strlwr(cstr);
            //devolve para tempString a palavra minuscula
            tempString=cstr;

            /*Para ser indexada a palavra deve ter mais que dois caracteres,
                            O terceiro caractere não pode ser especial e nem o penúltimo*/
            if(tempString.size()>2  && !isdigit(tempString[0]) && !ispunct(tempString[2]) && !ispunct(tempString[tempString.size()-3]))
            {
                //Caso o último caractere for especial, ele é subistituido por vazio
                if(ispunct(tempString[tempString.size()-1]))
                {
                    tempString[tempString.size()-1]='\0';
                }

                //Soma os códigos ASCII de cada caractere da palavra
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
}
