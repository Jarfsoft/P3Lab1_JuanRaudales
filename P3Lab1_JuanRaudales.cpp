#include <iostream>
#define LIMIT 20
using namespace std;

void matriz(int **M)
{
    int f= sizeof M/sizeof (int);
    int c= sizeof M[0]/sizeof (int);
    cout<<"f="<<f<<"\nc="<<c<<endl;
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<M[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
    int puntos=0;
    
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            bool isFila=true;
            bool isColumna=true;
            for(int k=0;k<5;k++)
            {
                if(i==k)
                    continue;
                if(M[i][j]>M[i][k])
                {
                    isFila=false;
                    break;
                }
            }
            for(int k=0;k<5;k++)
            {
                if(j==k)
                    continue;
                if(M[i][j]<M[k][j])
                {
                    isColumna=false;
                    break;
                }
            }
            if(isFila && isColumna)
            {
                cout<<"El punto ("<<i<<","<<j<<") es punto silla.\n";
                puntos++;
            }
        }
    }
    cout<<"Puntos silla: "<<puntos;
}
void nTriangular(int n1, int n2, int n3)
{
    if(n1<0)
    {
        cout<<"No es un numero triangular. El numero menor mas cercano es: "<<n3-n2+1;
    }else if(n1==0)
    {
        cout<<"Es numero triangular.";
    }else
    {
        nTriangular(n1-n2,n2+1,n3+n2);
    }
    
}
int factorial (unsigned int n){
    unsigned long long factorial = 1;
    for(int i = 1; i <=n; ++i)
    {
        factorial *= i;
    }
    return factorial;
    }
void secuencias(string carac, int indice)
{
    string s(carac);
    if((unsigned)indice == s.size())
		cout << s << endl;
	else
	{
		for(unsigned int i = indice; i < s.size(); i++)
		{
			swap(s[i], s[indice]);
			secuencias(s, indice + 1);
		}
	}
}

int main()
{
    cout<<"Llenar matriz para buscar puntos silla:\n\n";
    int **ma;
    ma=new int*[5];
    for(int x=0;x<5;x++)
    {
        ma[x]=new int[5];
    }
    for(int i=0;i<5;i++)
    {
        for(int j=0;j<5;j++)
        {
            cout<<"Espacio ["<<i<<"]["<<j<<"]: ";
            cin>>ma[i][j];
        }
    }
    matriz(ma);


    cout<<"\n\nIngrese numero para verficar si es triangular: ";
    int n;
    cin>>n;
    nTriangular(n,1,0);


    char *caracteres = new char[LIMIT];
    bool si=false;
    while(!si)
    {
        si=true;
        cout<<"\n\nIngrese palabra (sin repetir letras): ";
        cin>>caracteres;
        string g(caracteres);
        for(int x=0;x<g.length();x++)
        {
            int temp =  g.length()-1 ;
            for(int y=0;y<g.length();y++)
            {
                if(x==y)
                    continue;
                if(caracteres[x]==caracteres[y])
                    si=false;
            }
            
        }
    }
    secuencias(caracteres,0);
    
    
    return 0;
}