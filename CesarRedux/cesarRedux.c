#include <include.h>

// funcoes
bool contemThe(const char *frase);
void deslocaStringEncripta(char *str, int N);
void deslocaStringDesencripta(char *str, int N);
void limpaFrase(char *str);

// main
int main() 
{   
    int numero = 0;
    int numeroDeslocamento = 0;
    char frase[256];  

    scanf("%d", &numero); // armazena o numero n
    getchar();
    
    for(int i = 0; i < numero; i++)
    {
        scanf("%d", &numeroDeslocamento); // numero deslocamento
        getchar(); 
        fgets(frase, sizeof(frase), stdin);

        // remove o caractere de nova linha
        limpaFrase(frase);

        if (contemThe(frase)) 
        {   
            deslocaStringEncripta(frase, numeroDeslocamento);
        } 
        else 
        {
            deslocaStringDesencripta(frase, numeroDeslocamento);
        }

        printf("%s\n",frase);
    }
    return 0;
}


// corpo das funcoes

void limpaFrase(char *str)
{
    size_t len = strlen(str);
    if (len > 0 && str[len-1] == '\n') 
    {
        str[len-1] = '\0';
    }
}

bool contemThe(const char *frase) 
{
    return strstr(frase, "the ") != NULL;
}

void deslocaStringEncripta(char *str, int N) 
{   
    for (int i = 0; str[i]; i++) 
    {
        if (isalpha(str[i])) 
        {  
            char base = islower(str[i]) ? 'a';
            str[i] = (str[i] - base - N) % 26;  
            if (str[i] < 0) {
                str[i] += 26;
            }
            str[i] += base;
        }
    }
}

void deslocaStringDesencripta(char *str, int N)
{
    const char *letras = "abcdefghijklmnopqrstuvwxyz";
    int totalLetras = strlen(letras);
    
    for (int i = 0; str[i]; i++) {
        if (isalpha(str[i])) {
            char letraAtual = str[i];
            char *posicaoAtual = strchr(letras, tolower(letraAtual));
            
            if (posicaoAtual) {
                int indice = (posicaoAtual - letras + N) % totalLetras;  
                if (indice < 0) {
                    indice += totalLetras;  
                }
                char novaLetra = letras[indice];
                
                str[i] = (isupper(letraAtual) ? toupper(novaLetra) : novaLetra);
            }
        }
    }
}

