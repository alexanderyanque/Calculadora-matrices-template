#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
//No me dió tiempo a separar las clases en archivos, así que todo está junto
int posible(int xi,int yi,int xj, int yj,bool aux)//si la variable aux es verdadera comprueba si es posible suma o resta de matrices, si es falsa lo hace pero viendo si es posible la multiplicacion
{
    if(aux)
    {
    if(xj==yj&&xi==yi)
        return 1;
    else
        return 0;}
    else{
        if (yi==xj)
            return 1;
        else
            return 0;
    }
}

template <typename H,int G, int F>
class Matriz
{
public:
    int i=G;
    int j=F;
    H aa[G][F];
    Matriz(H mat[G][F]){
        for(int w=0;w<i;w++){
            for(int q=0;q<j;q++)
                aa[w][q]=mat[w][q];
        }
    }
    Matriz(){
        for(int w=0;w<i;w++){
            for(int q=0;q<j;q++)
                aa[q][w]=1.5;
    }}
};

template<typename H,int G, int F,int D,int A>
class Calculadora
{
public:
//    template <Matriz A,int B,int C>//,int D,int E>
    Matriz<H,G,F> a;
    Matriz<H,D,A> b;
    Calculadora(Matriz<H,G,F> x,Matriz<H,D,A> y):a(x.aa),b(y.aa)
    {    }
    void sumar()
    {
        if(posible(a.i,b.i,a.j,b.j,true))
        {
            for(int w=0;w<G;w++){
                for(int q=0;q<F;q++)
                {
                    cout<<a.aa[w][q]+b.aa[w][q]<<" ";
                }
            cout<<endl;}
        }
        else
            cout<<"No posible realizar esta operacion";
    return;}
    void restar()
    {
        if(posible(a.i,b.i,a.j,b.j,true))
        {
            for(int w=0;w<G;w++){
                for(int q=0;q<F;q++)
                {
                    cout<<a.aa[w][q]-b.aa[w][q];
                }
            cout<<endl;}
        }
        else
            cout<<"No posible realizar esta operacion";
    return;}
    void multiplicar()
    {
        float aux[G][A];
        if(posible(a.i,b.i,a.j,b.j,false)){
             {
             float c[a.i][b.j];
             int i,j,k;
             for (i=0;i<a.i;i++)
             {

                 for(j=0;j<b.j;j++)
                  {   c[i][j] = 0;
                      for(k=0;k<a.j;k++)
                          c[i][j] = c[i][j] + a.aa[i][j] * b.aa[i][j];
                  cout<<c[i][j]<<" ";}
                  cout<<endl;
             }}
        }
        else
            cout<<"No se puede realizar esa operación";
        return;
    }
};
template<typename A,int B,int C>
void busqueda(A x,Matriz<A,B,C> y)
{
    bool encontrado=false;
    for(int w=0;w<B;w++){
        for(int q=0;q<C;q++)
            if(y.aa[q][w]==x){
                cout<<"Encontrado en la posición: ["<<q<<"]["<<w<<"]";
                return;}}
    cout<<"No encontrado \n";
    return;

/* No me funcionaba el código de stl no se en qué me equivoqué
    list<int> L;
    for(int w=0;w<B;w++)
        for(int q=0;q<C;q++)
            L.push_back(y.aa[w][q]);

    list<int>::iterator result = find(L.begin(), L.end(), x);
    assert(result == L.end() || *result == x);
*/
}

template<typename A,int B,int C>
void operator++(Matriz<A,B,C> y)
{
    for(int w=0;w<B;w++){
        for(int q=0;q<C;q++)
                cout<<y.aa[q][w]+1<<" ";
                cout<<endl;}
    return;
}

template<typename A,int B,int C>
void operator+=(Matriz<A,B,C> y,float x)
{
    for(int w=0;w<B;w++){
        for(int q=0;q<C;q++)
                cout<<y.aa[q][w]+x<<" ";
                cout<<endl;}
    return;
}

template<typename A,int B,int C>
void operator-=(Matriz<A,B,C> y,float x)
{
    for(int w=0;w<B;w++){
        for(int q=0;q<C;q++)
                cout<<y.aa[q][w]-x<<" ";
                cout<<endl;}
    return;
}


template<typename A,int B,int C>
void operator--(Matriz<A,B,C> y)
{
    for(int w=0;w<B;w++){
        for(int q=0;q<C;q++)
                cout<<y.aa[q][w]-1<<" ";
                cout<<endl;}
    return;
}

template<typename A,int B,int C,int D,int E>
void operator+(Matriz<A,B,C> x, Matriz<A,D,E> y )
{
    Calculadora<A,B,C,D,E> calc(x,y);
    calc.sumar();
}

template<typename A,int B,int C,int D,int E>
void operator-(Matriz<A,B,C> x, Matriz<A,D,E> y )
{
    Calculadora<A,B,C,D,E> calc(x,y);
    calc.restar();
}

template<typename A,int B,int C,int D,int E>
void operator*(Matriz<A,B,C> x, Matriz<A,D,E> y )
{
    Calculadora<A,B,C,D,E> calc(x,y);
    calc.multiplicar();
}


template<typename A,int B,int C>
void operator<<(Matriz<A,B,C> y,int x)
{
    for(int w=0;w<B;w++){
        for(int q=0;q<C;q++)
                cout<<(y.aa[q][w]<<x)<<" ";
                cout<<endl;}
    return;
}

int main()
{
    float a[4][4],c[4][4];
    int b[4][4];
    for(int w=0;w<4;w++)
        for(int q=0;q<4;q++)
            {
            a[q][w]=1.0;
            b[q][w]=2;
            c[q][w]=2.3;
            }
    Matriz<float,4,4> ejemplo1(a);
    Matriz<int,4,4> ejemplo2(b);
    Matriz<float,4,4> ejemplo3(c);
    Matriz<float,5,4> ejemplo4();

    busqueda<float>(1.0,ejemplo1); cout<<endl<<endl;
    ejemplo2<<2;cout<<endl<<endl;//solo funciona cuando es entero
    ejemplo1+ejemplo3;cout<<endl<<endl;
    ejemplo1-ejemplo3;cout<<endl<<endl;
    ejemplo1*ejemplo3;cout<<endl<<endl;
  //  ejemplo1*ejemplo4;//no funciona por que no tienen el mismo numero de filas y columnas
    --ejemplo1;cout<<endl<<endl;
    ++ejemplo1;cout<<endl<<endl;
    ejemplo1-=0.5;cout<<endl<<endl;
    ejemplo1+=1.6;cout<<endl<<endl;
    return 0;
}
