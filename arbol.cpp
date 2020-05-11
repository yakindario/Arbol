#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;

struct Nodo
{
    /* data */
    int dato;
    Nodo *der;
    Nodo *izq;
};

    void menu();
Nodo *crearNodo(int);
void insertarNodo(Nodo *&arbol, int);
void mostrarArbol(Nodo *, int);
bool busqueda(Nodo *, int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);

//Punbtero 
Nodo *arbol = NULL;

int main(){

    menu();

    getch();
    return 0;
}

// funcion del menu 
void menu(){

    int dato, opcion,contador=0,n;
    do{
        cout<<"**************************************"<<endl;
        cout<<"\t \t :MENU: "<<endl;
        cout<<"**************************************"<<endl;
        cout << "\n*\t1. Insertar un nodo del arbol"<<endl;
        cout << "*\t2. Mostrar el arbol completo"<<endl;
        cout << "*\t3. Busqueda de elemento en el arbol" << endl;
        cout << "*\t4. Recorrer el arbol en PreOrden " << endl;
        cout << "*\t5. Recorrer el arbol en InOrden " << endl;
        cout << "*\t6. Recorrer el arbol en PostOrden" << endl;
        cout << "*\t7. Salir" << endl;
        cout << "\n**************************************" << endl;
        cout << "\n";
        cout<<"Seleccione una Opcion: "<<endl;
        cin>>opcion;
        switch (opcion)
        {
        case 1:
            cout << "\n**************************************" << endl;
            cout << "\t Ingresar nodo"<<endl;
            cout << "**************************************" << endl;
            cout << "¿Cuantos Nodos quieres ingresar?"<<endl;
            cin>> n;
            for (int i = 0; i < n; i++)
            {

                cout << "\n Digite un numero: ";
                cin >> dato;
                insertarNodo(arbol, dato); //Insertarmos un nuevo nodo
                cout << "\n";              /* code */
            }
            
            system("pause");
            break;
        case 2:
        	cout << "\n**************************************" << endl;
            cout << "\t Mostrar el arbol completo"<<endl;
            cout << "**************************************" << endl;
            cout<<"\n\n";
            mostrarArbol(arbol,contador);
            cout<<"\n";
            system("Pause");
            break;
        case 3:
        	cout << "\n**************************************" << endl;
            cout << "\t Buscar Arbol "<<endl;
            cout << "**************************************" << endl;
            cout<<"digite el elemeto a buscar: "<<endl;
            cin>>dato;
            if(busqueda(arbol,dato) == true){
                cout<<"\n Elemento "<<dato<< " a sido encontrado en el arbol \n";
            }else
            {
                cout<<"\n ELEMENTO NO ENCONTRADO \n";
            }
            cout<<"\n";
            system("pause");
            break;
        case 4:
        	cout << "\n**************************************" << endl;
            cout << "\t Recorrido en preOrden "<<endl;
            cout << "**************************************" << endl;
            cout<<"\n Recorrido en preOrden: ";
            preOrden(arbol);
            cout<<"\n \n";
            system("pause");
            break;
        case 5:
        	cout << "\n**************************************" << endl;
            cout << "\t Recorrido en InOrden "<<endl;
            cout << "**************************************" << endl;
            cout << "\n Recorrido en InOrden: ";
            inOrden(arbol);
            cout << "\n \n";
            system("pause");
            break;
        case 6:
        	cout << "\n**************************************" << endl;
            cout << "\t Recorrido en PostOrden "<<endl;
            cout << "**************************************" << endl;
            cout << "\n Recorrido en PostOrden: ";
            postOrden(arbol);
            cout << "\n \n";
            system("pause");
            break;
        }
        system("cls");
    }while (opcion != 7);
    

}

//Funcion Para creavo nodo 
Nodo *crearNodo(int n){
    Nodo *nuevo_nodo = new Nodo();
    
    nuevo_nodo->dato = n;
    nuevo_nodo->der = NULL;
    nuevo_nodo->izq = NULL;

    return nuevo_nodo;
}


//Funcion para inzertar el elementos del arbol 
void insertarNodo(Nodo *&arbol, int n){
    //Si el arbol esta vacion, 
    // crear un nuevo NOdo
    if(arbol  == NULL){
        Nodo *nuevo_nodo = crearNodo(n);
        arbol = nuevo_nodo;
    }
    //Si el arbol tiene mas nodo 
    else {
        int valorRaIZ = arbol->dato;
        if (n<valorRaIZ) //sie el elemento es menos a la raiz , se inserta a la izquierda
            {
            insertarNodo(arbol->izq,n);
            } //Sis el elemento es mayor a la raiz , insertemos a la derecha 
        else{
            insertarNodo(arbol->der,n);
            }
    }
}


//MOSTRAR UN ARBOL 
void mostrarArbol(Nodo *arbol, int cont){
    if(arbol == NULL){
        return;
    }
    else
    {
        mostrarArbol(arbol->der,cont+1);
        for (int i = 0; i < cont; i++)
        {
           cout<<"   ";
        }
        cout<<arbol->dato<<endl;
        mostrarArbol(arbol->izq,cont+1);

    }
    
}

//Busqueda de arbol 
bool busqueda(Nodo *arbol, int n){
    if(arbol == NULL){
        return false;
    }
    //si el elementoe es igual al elemento
    else if (arbol->dato == n)
    {   
        return true;
    }
    else if (n < arbol->dato)
    {
        return busqueda(arbol->izq,n);
    }
    else
    {
        return busqueda(arbol->der,n);
    }

}


//Funcion de recorrido prufundidad - PreOrden 
void preOrden(Nodo *arbol){
    //Si el arbol esta vacio
    if(arbol == NULL){ 
        return;
    }else
    {
        cout<<arbol->dato<<" - ";
        preOrden(arbol->izq);
        preOrden(arbol->der);
    }
    
}

//Funcion de recorrido prufundidad - InOrden
void inOrden(Nodo *arbol){
    if(arbol == NULL){
        return;
    }
    else
    {
        inOrden(arbol->izq);
        cout<<arbol->dato<<" - ";
        inOrden(arbol->der);
    }
    

}

////Funcion de recorrido prufundidad - PostOrden
void postOrden(Nodo *arbol)
{
    if(arbol == NULL){
        return;
    }else
    {
        postOrden(arbol->izq);
        postOrden(arbol->der);
        cout<<arbol->dato<<" - ";
    }
    
}
