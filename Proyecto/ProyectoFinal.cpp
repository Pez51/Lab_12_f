#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;


template <typename T>

class Persona{
    private:
        string clave;
    protected:
        string correo;
    public:
        int codigo;
        string telefono;
        string nombre;

        Persona(){
            clave="";
            correo="";
            codigo=0;
            nombre="";
            telefono="";
        }


        Persona(string clave,string correo,int codigo,string nombre,string telefono) {
            this->clave=clave;
            this->correo=correo;
            this->codigo=codigo;
            this->nombre=nombre;
            this->telefono=telefono;
        }

        virtual void mostrarInformacion() const {
            cout<<"Nombre: "<<nombre<<endl;
            cout<<"Correo: "<<correo<<endl;
            cout<<"Codigo: "<<codigo<<endl;
            cout<<"Telefono: "<<telefono<<endl;
        }

        friend ostream& operator<<(ostream& mostrar, const Persona<T>& p) {
            mostrar<<"Nombre: "<<p.nombre<<endl;
            mostrar<<"Correo: "<<p.correo<<endl;
            mostrar<<"Codigo: "<<p.codigo<<endl;
            mostrar<<"Telefono: "<<p.telefono<<endl;
            return mostrar;
        }

        friend istream& operator>>(istream& ingresar, Persona<T>& p) {
            cout<<"Ingrese el nombre: ";
            ingresar>>p.nombre;
            system("cls");
           cout<<"Ingrese el correo: ";
            ingresar>>p.correo;
            system("cls");
            cout<<"Ingrese el codigo: ";
            ingresar>>p.codigo;
            system("cls");
            int j=0;
            while(j==0){
                cout<<"Ingrese el telefono: ";
                ingresar>>p.telefono;
                if(p.telefono.size()==9){
                    j=1;
                    system("cls");
                } else {
                    cout<<"Ingrese un numero valido..."<<endl;
                    system("pause");
                    system("cls");
                }
            }
            return ingresar;
        }
};

template <typename T>

class Vendedor:public Persona<T>{
    public:
        int salario;
    //constructor sin atributos y por defecto
        Vendedor():Persona<T>(){
            salario = 0;
        }

    //constructor con parametros que llama al constructor de Persona
        Vendedor(string clave,string correo,int codigo,string nombre,string telefono,int salario)
            :Persona<T>(clave, correo, codigo, nombre, telefono){
            this->salario = salario;
        }
    //Muestra los datos personales y de cliente
        void mostrarInformacion() const override{
            Persona<T>::mostrarInformacion();
            cout<<"Salario: "<<salario<<endl;
        }
    //Sobrecarga para facilitar imprimir los datos
        friend ostream& operator<<(ostream& mostrar,const Vendedor<T>& vende){
            mostrar<<static_cast<const Persona<T>&>(vende);
            mostrar<<"Salario: S/,"<<vende.salario<<endl;
            return mostrar;
        }
    //Sobracarga para facilitar ingresar los datos
        friend istream& operator>>(istream& ingresar,Vendedor<T>& vende){
            ingresar>>static_cast<Persona<T>&>(vende);
            cout<<"Ingrese su salario: ";
            ingresar>>vende.salario;
            system("cls");
            return ingresar;
        }
};
// Clase ClienteIndividual hereda de Persona
template <typename T>

class ClienteIndividual:public Persona<T>{
    public:
        char categoria;
        string dni;
    //constructor sin atributos y por defecto
        ClienteIndividual():Persona<T>(){
            categoria='D';
            dni="";
        }

    //constructor con parametros que llama al constructor de Persona
        ClienteIndividual(string clave,string correo,int codigo,string nombre,string telefono,char categoria,string dni)
            :Persona<T>(clave, correo, codigo, nombre, telefono){
            this->categoria=categoria;
            this->dni=dni;
        }
    //Muestra los datos personales y de cliente
        void mostrarInformacion() const override{
            Persona<T>::mostrarInformacion();
            cout<<"Categoria: "<<categoria<<endl;
            cout<<"DNI: "<<dni<<endl;
        }
    //Sobrecarga para facilitar imprimir los datos
        friend ostream& operator<<(ostream& mostrar,const ClienteIndividual<T>& cliente){
            mostrar<<static_cast<const Persona<T>&>(cliente);
            mostrar<<"Categoria: "<<cliente.categoria<<endl;
            mostrar<<"DNI: "<<cliente.dni<<endl;
            return mostrar;
        }
    //Sobracarga para facilitar ingresar los datos
        friend istream& operator>>(istream& ingresar,ClienteIndividual<T>& cliente){
            ingresar>>static_cast<Persona<T>&>(cliente);
            cout<<"Ingrese la categoria: ";
            ingresar>>cliente.categoria;
            int j = 0;
            while(j==0){
                system("cls");
                cout<<"Ingrese el DNI: ";
                ingresar>>cliente.dni;
                if(cliente.dni.size()==8){
                    j=1;
                } else {
                    cout<<"Ingrese un DNI valido..."<<endl;
                    system("pause");
                }
            }
            return ingresar;
        }
};

// Clase ClienteCorporativo hereda de Persona
template <typename T>

class ClienteCorporativo:public Persona<T>{
    public:
        char categoria;
        string ruc;
    //constructor sin atributos y por defecto
        ClienteCorporativo():Persona<T>(){
            categoria='D';
            ruc=" ";
        }

    //constructor con parametros que usa el constructor de la clase Persona
        ClienteCorporativo(string clave,string correo,int codigo,string nombre,string telefono,char categoria,string ruc)
        : Persona<T>(clave,correo,codigo,nombre,telefono){
            this->categoria=categoria;
            this->ruc=ruc;
        }
    //Muestra los datos personales y de cliente
        void mostrarInformacion() const override{
            Persona<T>::mostrarInformacion();
            cout<<"Categoria: "<<categoria<< endl;
            cout<<"RUC: "<<ruc<<endl;
        }

        friend ostream& operator<<(ostream& mostrar,const ClienteCorporativo<T>& cliente) {
            mostrar<<static_cast<const Persona<T>&>(cliente);
            mostrar<<"Categoria: "<<cliente.categoria<<endl;
            mostrar<<"RUC: "<<cliente.ruc<<endl;
            return mostrar;
        }

        friend istream& operator>>(istream& ingresar,ClienteCorporativo<T>& cliente) {
            ingresar>>static_cast<Persona<T>&>(cliente);
            cout<<"Ingrese la categoria: ";
            ingresar>>cliente.categoria;
            system("cls");
            int j=0;
            while(j==0){
                cout<<"Ingrese el RUC: ";
                ingresar>>cliente.ruc;
                if(cliente.ruc.size()==11){
                    j=1;
                } else {
                    cout<<"Ingrese un RUC valido..."<<endl;
                    system("pause");
                    system("cls");
                }
            }
            return ingresar;
        }
};

// Clase Producto
class Producto{
    public:
        int codigo;
        string descripcion;
        double precio;
        string tipo;
        int stock;

    // Constructor por defecto
        Producto(){
            codigo=0;
            descripcion="";
            precio=0.0;
            stock = 0;
            tipo = "";
            
        }

    // Constructor con parametros de la clase Producto
        Producto(int codigo,string descripcion,double precio,int stock,string tipo) {
            this->codigo=codigo;
            this->descripcion=descripcion;
            this->precio=precio;
            this->stock = stock;
            this->tipo=tipo;
            
        }

        friend ostream& operator<<(ostream& mostrar,const Producto& producto) {
            mostrar<<"Codigo: "<<producto.codigo<<endl;
            mostrar<<"Tipo: "<<producto.tipo<<endl;
            mostrar<<"Descripcion: "<< producto.descripcion<<endl;
            mostrar<<"Precio: "<< producto.precio<<endl;
            mostrar<<"Stock: "<<producto.stock<<endl;
            
            return mostrar;
        }

        friend istream& operator>>(istream& ingresar,Producto& producto) {
            system("cls");
            cout<<"Ingrese el codigo: ";
            ingresar>>producto.codigo;
            system("cls");
            cout<<"Ingrese el tipo: ";
            ingresar>>producto.tipo;
            system("cls");
            cout<<"Ingrese la descripcion: ";
            ingresar>>producto.descripcion;
            system("cls");
            int j=0;
            while(j==0){
                cout<<"Ingrese el precio: ";
                ingresar>>producto.precio;
                if(producto.precio<=0){
                    cout<<"\nIngrese un Precio correcto..."<<endl;
                    system("pause");
                    system("cls");
                } else {
                    j=1;
                }
            }
            system("cls");
            j=0;
            while(j==0){
                cout<<"Ingrese el stock: ";
                ingresar>>producto.stock;
                if(producto.stock<=0){
                    cout<<"\nIngrese una cantidad correcta..."<<endl;
                    system("pause");
                    system("cls");
                } else {
                    j=1;
                }
            }
            system("cls");
            return ingresar;
        }
};

class Datos{
    
};
// Función para ordenar la lista de clientes individuales por código de forma ascendente
template <typename T>

void ordenarClientesIndividuales(vector<ClienteIndividual<T>>& clientes) 
{
    int n=clientes.size();

    for(int i= 0;i<n;i++){
        int minIndex= i;

        for(int j= i+1;j<n;j++){
            if(clientes[j].codigo<clientes[minIndex].codigo){
                minIndex=j;
            }
        }

        if(minIndex != i){
            swap(clientes[i], clientes[minIndex]);
        }
    }
}

// Función para ordenar la lista de clientes corporativos por código de forma ascendente
template<typename T>

void ordenarClientesCorporativos(vector<ClienteCorporativo<T>>& clientes) {
    int n=clientes.size();
    
    for(int i= 0;i< n;i++){
        int minIndex= i;

        for(int j= i+1;j< n;j++){
            if(clientes[j].codigo< clientes[minIndex].codigo){
                minIndex=j;
            }
        }
        if(minIndex !=i){
            swap(clientes[i],clientes[minIndex]);
        }
    }
}

// Función para ordenar la lista de productos por código de forma descendente
void ordenarProductos(vector<Producto>& productos) 
{
    int n=productos.size();

    for(int i=0;i<n;i++){
        int maxIndex= i;

        for(int j=i+1;j<n;j++){
            if(productos[j].codigo> productos[maxIndex].codigo){
                maxIndex= j;
            }
        }

        if(maxIndex!=i){
            swap(productos[i],productos[maxIndex]);
        }
    }
}

template<typename T>

void ordenarVendedores(vector<Vendedor<T>>& Vendedores) 
{
    int n=Vendedores.size();

    for(int i=0;i<n;i++){
        int maxIndex= i;

        for(int j=i+1;j<n;j++){
            if(Vendedores[j].codigo> Vendedores[maxIndex].codigo){
                maxIndex= j;
            }
        }

        if(maxIndex!=i){
            swap(Vendedores[i],Vendedores[maxIndex]);
        }
    }
}

void buscarClientes(vector<ClienteCorporativo<string>>& clientes,vector<ClienteIndividual<string>>& clientesIn) {
    int codigo;
    cout<<"Ingrese el codigo a buscar: ";
    cin>>codigo;
    int j=0;
    int n;
    n = clientes.size();
    
    for(int i= 0;i< n;i++){
        if(clientes[i].codigo == codigo){
            system("cls");
            cout<<"Persona encontrada, ";
            j=1;
            system("pause");
            system("cls");
            clientes[i].mostrarInformacion();
            system("pause");
            system("cls");
        }
    }
    n = clientesIn.size();
    for(int i= 0;i< n;i++){
        if(clientesIn[i].codigo == codigo){
            system("cls");
            cout<<"Persona encontrada, ";
            j = 1;
            system("pause");
            system("cls");
            clientesIn[i].mostrarInformacion();
            system("pause");
            system("cls");
        }
    }

    if(j=0){
        system("cls");
        cout<<"El codigo "<<codigo<<" no existe en nuestro registro..."<<endl;
        system("pause");
        system("cls");
    }

}

string BuscarTipo(int codigo,vector<ClienteCorporativo<string>>& clientes,vector<ClienteIndividual<string>>& clientesIn) {
    system("cls");
    string f="";
    int var = 0;
    for(int i=0;i<clientes.size();i++){
        if(clientes[i].codigo==codigo){
            f = clientes[i].nombre;
            var=1;
        }
    }
    for(int i=0;i<clientesIn.size();i++){
        if(clientesIn[i].codigo==codigo){
            f = clientes[i].nombre;
            var=1;
        }
    }
    if(var == 0){
        cout<<"El codigo ingresado no fue registrado..."<<endl;
        system("pause");
        system("cls");
    }
    return f;
}

string& operator <<(ostream& o,vector<string>& datos){

}

int main() 
{
    int cont=3;
    int cont1=3;
    int cont2 = 0;
    int k=0;
    string opc;
    vector<Vendedor<string>>Vendedores;
    vector<ClienteIndividual<string>>clientesIndividuales;
    vector<ClienteCorporativo<string>>clientesCorporativos;
    vector<Producto> productos;
    vector<string> Ventas;
    vector<int> datos;
    //Clientes
    ClienteIndividual<string> Jorge("1234","jorge@gmail.com",7755,"Jorge","977111204",68,"71928735");
    ClienteIndividual<string> Ron("4632","ron@gmail.com",7756,"Ron","986535224",66,"64532312");
    ClienteCorporativo<string> Pablo("7842","pablo@gmail.com",7757,"Pablo","987432123",65,"76542123981");
    clientesIndividuales.push_back(Jorge);
    clientesIndividuales.push_back(Ron);
    clientesCorporativos.push_back(Pablo);
    ordenarClientesCorporativos(clientesCorporativos);
    ordenarClientesIndividuales(clientesIndividuales);
    //Vendedores
    Vendedor<string> Renato("4321","renato@gmail.com",8877,"Renato","988000432",300);
    Vendedor<string> Joseph("3424","joseph@gmail.com",8878,"Joseph","990097438",400);
    Vendedor<string> Andrew("6554","andrew@gmail.com",8879,"Andrew","978483923",350);
    Vendedores.push_back(Renato);
    Vendedores.push_back(Joseph);
    Vendedores.push_back(Andrew);
    ordenarVendedores(Vendedores);
    //Productos
    Producto Manzana(345,"manzana",0.5,50,"comida");
    Producto CocaCola(346,"CocaCola",2.5,30,"bebida");
    Producto Lejia(342,"Lejia",3,60,"limpieza");
    Producto Detergente(348,"DetergenteOpal",6,15,"limpieza");
    Producto Impresora(340,"ImpresoraCanon",400,10,"tecnologia");
    Producto Plancha(339,"PlanchaOster",149.9,20,"Domestico");
    Producto Camara(336,"CamaraWeb",49.9,30,"tecnologia");
    productos.push_back(Manzana);
    productos.push_back(CocaCola);
    productos.push_back(Lejia);
    productos.push_back(Detergente);
    productos.push_back(Impresora);
    productos.push_back(Plancha);
    productos.push_back(Camara);
    ordenarProductos(productos);
    //Ventas
    




    while(k == 0){
        ifstream menu("Menu.txt");
        if (menu.is_open()){
            string linea;
            while (getline(menu,linea)){
                cout<<linea<<endl;
            }
        }
        cout<<"\nIngrese su opcion: ";
        cin>>opc;
        if(opc=="1"||opc=="2"||opc=="3"||opc=="4"||opc=="5"||opc=="6"||opc=="7"||opc=="8"){
            if(opc=="1"){
                if(cont < 6){
                    string tipoCliente;
                    system("cls");
                    cout<<"Ingrese el tipo de cliente (individual/corporativo): ";
                    cin>>tipoCliente;
                    system("cls");

                    if(tipoCliente=="individual"){
                        ClienteIndividual<string> cliente;
                        cin>>cliente;
                        clientesIndividuales.push_back(cliente);
                    } else if (tipoCliente=="corporativo"){
                        ClienteCorporativo<string> cliente;
                        cin>>cliente;
                        clientesCorporativos.push_back(cliente);
                    } else {
                        system("cls");
                        cout<<tipoCliente<<" no es un tipo de cliente."<<endl;
                        system("pause");
                        system("cls");
                    }
                    ordenarClientesCorporativos(clientesCorporativos);
                    ordenarClientesIndividuales(clientesIndividuales);
                    cont = clientesCorporativos.size() + clientesIndividuales.size();
                }else if(cont >= 6){
                    cout<<"Agenda llena, no puede ingresar mas clientes";
                    system("pause");
                    system("cls");
                }
            }
            else if(opc=="2")
            {
                system("cls");
                buscarClientes(clientesCorporativos,clientesIndividuales);
            } 
            else if (opc=="3")
            {
                if(cont1 < 10){
                    system("cls");
                    Vendedor<string> v;
                    cin>>v;
                    system("cls");
                    int j=0;
                    for(int i=0;i<Vendedores.size();i++){
                        if(v.nombre==Vendedores[i].nombre){
                            system("cls");
                            cout<<"Ya existe "<<v.nombre<<" registrado, vuelva a intentarlo..."<<endl;
                            system("pause");
                            system("cls");
                            j=1;
                        }
                    }
                    if(j==0){
                        Vendedores.push_back(v);
                        ordenarVendedores(Vendedores);
                        system("cls");
                    }
                } else if (cont1 >= 10){
                    system("cls");
                    cout<<"Lleno..."<<endl;
                    system("pause");
                    system("cls");
                }
            } 
            else if (opc=="4")
            {
                system("cls");
                Producto producto;
                cin>>producto;
                productos.push_back(producto);
                system("cls");
            } 
            else if (opc=="5")
            {
                cont2 += 1;
                int codigo,cant;
                system("cls");
                cout<<"Ingrese el codigo del cliente: ";
                cin>>codigo;
                system("cls");
                string var = BuscarTipo(codigo,clientesCorporativos,clientesIndividuales);
                datos.push_back(cont);
                
            } 
            else if (opc=="6")
            {
                system("cls");
                cout<<"Lista de Clientes: "<<endl<<"Individuales:"<<endl;
                cout<<"=========================================================="<<endl;
                for(int i=0;i<clientesIndividuales.size();i++){
                    clientesIndividuales[i].mostrarInformacion();
                    cout<<"=========================================================="<<endl;
                } system("pause");system("cls");
    
                cout<<"Corporativos:"<<endl;
                cout<<"=========================================================="<<endl;
                for(int i=0;i<clientesCorporativos.size();i++){
                    clientesCorporativos[i].mostrarInformacion();
                    cout<<"=========================================================="<<endl;
                } system("pause");system("cls");
            } 
            else if (opc=="7")
            {
                system("cls");
                cout<<"Lista de Vendedores: "<<endl;
                cout<<"=========================================================="<<endl;
                for(int i=0;i<Vendedores.size();i++){
                    Vendedores[i].mostrarInformacion();
                    cout<<"=========================================================="<<endl;
                } system("pause");system("cls");
            } 
            else if (opc=="8")
            {
                k=1;
            }
        } else {
            system("cls");
            cout<<"\nIngrese una opcion correcta...\n"<<endl;
            system("pause");
            system("cls");
        }
    }

    // Guardar clientes individuales en un archivo
    ofstream clientesIndividualesFile("clientes_individuales.txt");
    if(clientesIndividualesFile.is_open()){
        for(const auto& cliente : clientesIndividuales){
            clientesIndividualesFile<<cliente<<endl;
        }
        clientesIndividualesFile.close();
    } else {
        cout<<"No se pudo abrir el archivo clientes_individuales.txt"<<endl;
    }
    // Guardar clientes corporativos en un archivo
    ofstream clientesCorporativosFile("clientes_corporativos.txt");
    if(clientesCorporativosFile.is_open()){
        for (const auto& cliente : clientesCorporativos) {
            clientesCorporativosFile<<cliente<<endl;
        }
        clientesCorporativosFile.close();
    } else {
        cout<<"No se pudo abrir el archivo clientes_corporativos.txt"<<endl;
    }

    ofstream vendedoresFile("vendedores.txt");
    if(vendedoresFile.is_open()){
        for (const auto& vendedor : Vendedores) {
            vendedoresFile<<vendedor<<endl;
        }
        vendedoresFile.close();
    } else {
        cout<<"No se pudo abrir el archivo clientes_corporativos.txt"<<endl;
    }

    ofstream productosFile("productos.txt");
    if (productosFile.is_open()) 
    {
        for (const auto& producto : productos) 
        {
            productosFile<<producto<<endl;
        }
        productosFile.close();
    } else {
        cout<<"No se pudo abrir el archivo productos.txt"<<endl;
    }

    return 0;
}