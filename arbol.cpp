#include <iostream>

using namespace std;

struct nodo {
    int dato;
    nodo *izquierda;
    nodo *derecha;
};

class BinarySearchTree{
    private:
        nodo *pBinarySearchTree;
    public:
    BinarySearchTree();
    ~BinarySearchTree();
    void insertar(void);
    void insertarBST(nodo **, int);
    void showPreorder(nodo *);
    void showInorder(void);
    void showIn(nodo *);
    void showPost(nodo *);
    void showPostOrder(void);
    void showPreorder(void);
    void showPre(nodo *);
    void buscarnumero(int);
    void buscarN(nodo *, int);
    void borrarnumero(int);
     void borrarnumeroRec(nodo **, int);
};

BinarySearchTree::BinarySearchTree(void)
{
    pBinarySearchTree = NULL;
}

BinarySearchTree::~BinarySearchTree()
{
    cout << "Program Execution" << endl;
}

void BinarySearchTree::insertar(void)
{
    int dato;
    char resp;

    do{
        cout << "Escriba y para continuar" << endl;
        cout << "Desea digitar un dato (S/N)?";
        cin >> resp;
        if(resp == 'S'|| 's'){
            cout << "Elemento que desea ingresar: ";
            cin >> dato;
            insertarBST(&pBinarySearchTree, dato);
        }

    }while(resp == 'S' || 's');
}

void BinarySearchTree::insertarBST(nodo **p, int dato)
{
    if(!(*p)){
        *p = new nodo;
        (*p)->dato = dato;
        (*p)->izquierda = NULL;
        (*p)->derecha = NULL; 
    }
    else{
        if(dato < (*p)->dato)
            insertarBST(&((*p)->izquierda), dato);
        else
            if(dato > (*p)->dato)
                insertarBST(&((*p)->derecha), dato);
            else
                cout << "El dato ya esta ingresado" << endl << endl;
    }
}

void BinarySearchTree::buscarnumero(int dato)
{
    buscarN(pBinarySearchTree, dato);
}

void BinarySearchTree::buscarN(nodo *p, int dato)
{
    if(!p)
        cout << "El dato no está en el árbol" << endl << endl;
    else
        if(dato < p->dato)
            buscarN(p->izquierda, dato);
        else
            if(dato > p->dato)
                buscarN(p->derecha, dato);
            else
                cout << "Ya llegué al dato" << endl << endl;
}


void BinarySearchTree::borrarnumero(int dato)
{
    borrarnumeroRec(&pBinarySearchTree, dato);
}



void BinarySearchTree::borrarnumeroRec(nodo **r, int dato)
{
    nodo *p;

    if(!(*r)) 
        cout << "El dato NO está en el árbol" << endl << endl;
    else
        if(dato < (*r)->dato) 
            borrarnumeroRec(&((*r)->izquierda), dato);
        else
            if(dato > (*r)->dato) 
                borrarnumeroRec(&((*r)->derecha), dato);
            else{ 
                if(!((*r)->izquierda) && !((*r)->derecha)){ 
                    p = *r;
                    *r = NULL;
                }
                else
                    if(!((*r)->izquierda) && (*r)->derecha){ 
                        p = *r; 
                        *r = (*r)->derecha;
                    }
                    else
                        if((*r)->izquierda && !((*r)->derecha)){ 
                            p = *r; 
                            *r = (*r)->izquierda; 
                        }
                        else
                            if((*r)->izquierda && (*r)->derecha){ 
                                p = (*r)->izquierda; 
                                if(!p->derecha){
                                    (*r)->dato = p ->dato;
                                    (*r)->izquierda = p->izquierda;
                                }
                                else{
                                    nodo *q;
                                    while(p->derecha){
                                        q = p;
                                        p = p->derecha;
                                    }
                                    (*r)->dato = p->dato;
                                    q->derecha = p->izquierda;
                                }
                            }
                    delete p;
            }
}

void BinarySearchTree::showInorder(void)
{
    showIn(pBinarySearchTree);
}

void BinarySearchTree::showIn(nodo *p)
{
    if(p){
        showIn(p->izquierda);
        cout << p->dato << " ";
        showIn(p->derecha);
    }
    cout << endl;
}

void BinarySearchTree::showPreorder(void)
{
    showPre(pBinarySearchTree);
}

void BinarySearchTree::showPre(nodo *p)
{
    if(p){
        cout << p->dato << " ";
        showPre(p->izquierda);
        showPre(p->derecha);
    }
    cout << endl;
}

void BinarySearchTree::showPostOrder(void)
{
    showPost(pBinarySearchTree);
}

void BinarySearchTree::showPost(nodo *p)
{
    if(p)
    {
        showPost(p->izquierda);
        showPost(p->derecha);
        cout << p->dato << " ";
    }
    cout << endl;
}


int main(void)
{
    cout << endl;
    cout << "hola, buenos dias :D" << endl;

    BinarySearchTree objBinarySearchTree;
    int datoB;

    cout << "Insertar datos en el arbol:" ;
    objBinarySearchTree.insertar();

    cout << "Mostrar Pre-orden: ";
    objBinarySearchTree.showPostOrder();
    cout << endl;

    cout << "Mostrar In-Orden: " ;
    objBinarySearchTree.showInorder();
    cout << endl;

    cout << "Mostrar Post-Orden: ";
    objBinarySearchTree.showPostOrder();
    cout << endl;

    cout << "Busquemos un dato:" << endl;
    cout << "Digite el dato a buscar: ";
    cin >> datoB;
    objBinarySearchTree.buscarnumero(datoB);

    cout << "Borremos un dato:" << endl;
    cout << "Digite el dato a borrar: ";
    cin >> datoB;
    objBinarySearchTree.borrarnumero(datoB);

    return 0;
}