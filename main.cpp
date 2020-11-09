#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
string nombre;
string fecha,hora,correo,nomb,apell;
string git;
int rep;
int nivel;
int expe;
int expo;
int act;
int mes;
int anio;
int pres;
ifstream fin;//Declaramos fin como variable de entrada
ofstream archivo;
void escribir(string guardar){
    archivo<<"----------------------------------------------------------------------------------------"<<endl;
    archivo<<guardar<<endl;

}
string viejo(){

    fin.open("Alumnos.txt",ios::in);//Abre el archivo en modo lectura
    string viejo;
    fin>>fecha>>hora>>correo>>nomb>>apell>>rep>>expe>>git>>nivel>>expo>>act>>mes>>anio>>pres;
    int min=anio;
    while(!fin.eof() ){

        if(anio<=min){
            min=anio;
            std::string s = std::to_string(min);
            viejo="El alumno mas viejo es: "+nomb+" "+apell+" nacido en el año "+s;
        }
        fin>>fecha>>hora>>correo>>nomb>>apell>>rep>>expe>>git>>nivel>>expo>>act>>mes>>anio>>pres;
    }
    cout<<viejo;
escribir(viejo);
    fin.close();
return viejo;
}
string birth(){
int contador=0;
    fin.open("Alumnos.txt",ios::in);//Abre el archivo en modo lectura
    fin>>fecha>>hora>>correo>>nomb>>apell>>rep>>expe>>git>>nivel>>expo>>act>>mes>>anio>>pres;
    //Aqui me uso el C time pero solo para saber el mes local
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    int tiempo= strftime (buffer,80,"El mes: %m",timeinfo)+1;
    puts(buffer);
    string alumno;
    archivo<<"----------------------------------------------------------------------------------------"<<endl;
    archivo<<"\n\t\t\t\t\t\tCUMPLE ESTE MES\n"<<endl;
    while(!fin.eof() ){

        if(mes==tiempo){
         contador++;
            //Esto nada mas era para pasar los int a strings
            std::string r = std::to_string(rep);
            std::string e = std::to_string(expe);
            std::string n = std::to_string(nivel);
            std::string ex = std::to_string(expo);
            std::string a = std::to_string(act);
            std::string m = std::to_string(mes);
            std::string yr = std::to_string(anio);
            std::string p = std::to_string(pres);
        alumno= fecha + "\t" + hora + "\t" + correo + "\t" + nombre + "\t" + apell + "\t" + r
                        + "\t" + e + "\t" + git + "\t" + n + "\t" + ex + "\t" + a + "\t"
                        + m + "\t" + yr + "\t" + p;
        }
        fin>>fecha>>hora>>correo>>nomb>>apell>>rep>>expe>>git>>nivel>>expo>>act>>mes>>anio>>pres;
    }
    cout<<"cumplen "<<contador<<" personas.";

   escribir(alumno);
    fin.close();
    return alumno;
}

  void listadoim( ){
   string listado;
    fin.open("Alumnos.txt",ios::in);//Abre el archivo en modo lectura
    fin>>fecha>>hora>>correo>>nomb>>apell>>rep>>expe>>git>>nivel>>expo>>act>>mes>>anio>>pres;
      archivo<<"----------------------------------------------------------------------------------------"<<endl;
    archivo<<"\n\t\t\t\t\t\tLISTADO IMPAR\n"<<endl;
    while(!fin.eof() ) {
        if ((expe % 2) == 1) {
            //Esto nada mas era para pasar los int a strings
            std::string r = std::to_string(rep);
            std::string e = std::to_string(expe);
            std::string n = std::to_string(nivel);
            std::string ex = std::to_string(expo);
            std::string a = std::to_string(act);
            std::string m = std::to_string(mes);
            std::string yr = std::to_string(anio);
            std::string p = std::to_string(pres);
           listado=fecha + "\t" + hora + "\t" + correo + "\t" + nombre + "\t" + apell + "\t" + r
                           + "\t" + e + "\t" + git + "\t" + n + "\t" + ex + "\t" + a + "\t"
                           + m + "\t" + yr + "\t" + p;
            cout << fecha << "\t" << hora << "\t" << correo << "\t" << nombre << "\t" << apell << "\t" << rep
                 << "\t" << expe << "\t" << git << "\t" << nivel << "\t" << expo << "\t" << act << "\t"
                 << mes << "\t" << anio << "\t" << pres<<endl;

            escribir(listado);
        }
        fin>>fecha>>hora>>correo>>nomb>>apell>>rep>>expe>>git>>nivel>>expo>>act>>mes>>anio>>pres;

    }

    fin.close();

}

void listadopar(){
    fin.open("Alumnos.txt",ios::in);//Abre el archivo en modo lectura
    fin>>fecha>>hora>>correo>>nomb>>apell>>rep>>expe>>git>>nivel>>expo>>act>>mes>>anio>>pres;
   string listado;
    archivo<<"----------------------------------------------------------------------------------------"<<endl;
    archivo<<"\n\t\t\t\t\t\tLISTADO PAR\n"<<endl;
    while(!fin.eof() ) {
        if ((expe % 2) == 0) {
            //Esto nada mas era para pasar los int a strings
            std::string r = std::to_string(rep);
            std::string e = std::to_string(expe);
            std::string n = std::to_string(nivel);
            std::string ex = std::to_string(expo);
            std::string a = std::to_string(act);
            std::string m = std::to_string(mes);
            std::string yr = std::to_string(anio);
            std::string p = std::to_string(pres);
            listado=fecha + "\t" + hora + "\t" + correo + "\t" + nombre + "\t" + apell + "\t" + r
                    + "\t" + e + "\t" + git + "\t" + n + "\t" + ex + "\t" + a + "\t"
                    + m + "\t" + yr + "\t" + p;
            escribir(listado);
            cout << fecha << "\t" << hora << "\t" << correo << "\t" << nombre << "\t" << apell << "\t" << rep
                 << "\t" << expe << "\t" << git << "\t" << nivel << "\t" << expo << "\t" << act << "\t"
                 << mes << "\t" << anio << "\t" << pres<<endl;
        }
        fin>>fecha>>hora>>correo>>nomb>>apell>>rep>>expe>>git>>nivel>>expo>>act>>mes>>anio>>pres;

    }
    fin.close();
}
void entregas(){
    double tamanio=0;
    fin.open("Alumnos.txt",ios::in);//Abre el archivo en modo lectura
    double suma=0;
    archivo<<"----------------------------------------------------------------------------------------"<<endl;
    archivo<<"\n\t\t\t\t\t\tPORCENTAJE DE ENTREGAS\n"<<endl;
    while(!fin.eof() ) {

        if(act==0){
            suma++;

        }
        tamanio++;

        fin>>fecha>>hora>>correo>>nomb>>apell>>rep>>expe>>git>>nivel>>expo>>act>>mes>>anio>>pres;
    }
    double porcentaje=((suma/tamanio)*100);// no estoy segura si se calcula el porcentaje asi pero aqui esta el intento jajaj
    cout<<"El porcentaje de los estudiantes que entregaron la actividad es de: "<<porcentaje<<"%"<<endl;
   archivo<<"El porcentaje de los estudiantes que entregaron la actividad es de: "<<porcentaje<<"%"<<endl;
    fin.close();
}
void asistentes(){
    fin.open("Alumnos.txt",ios::in);//Abre el archivo en modo lectura
    int hyflex=0;
    int ordinario=0;
    int total=0;
    archivo<<"----------------------------------------------------------------------------------------"<<endl;
    archivo<<"\n\t\t\t\t\t\tASISTENTES\n"<<endl;
    string listado1;
    string listado2;
    while(!fin.eof() ) {
        if(pres==0){
         ordinario++;
         archivo<<"\nORDINARIO:\n"<<endl;
            //Esto nada mas era para pasar los int a strings
            std::string r = std::to_string(rep);
            std::string e = std::to_string(expe);
            std::string n = std::to_string(nivel);
            std::string ex = std::to_string(expo);
            std::string a = std::to_string(act);
            std::string m = std::to_string(mes);
            std::string yr = std::to_string(anio);
            std::string p = std::to_string(pres);
            listado1=fecha + "\t" + hora + "\t" + correo + "\t" + nombre + "\t" + apell + "\t" + r
                    + "\t" + e + "\t" + git + "\t" + n + "\t" + ex + "\t" + a + "\t"
                    + m + "\t" + yr + "\t" + p;
            escribir(listado1);
        }
        else{
            archivo<<"\nHYFLEX:\n"<<endl;
            hyflex++;
            //Esto nada mas era para pasar los int a strings
            std::string r = std::to_string(rep);
            std::string e = std::to_string(expe);
            std::string n = std::to_string(nivel);
            std::string ex = std::to_string(expo);
            std::string a = std::to_string(act);
            std::string m = std::to_string(mes);
            std::string yr = std::to_string(anio);
            std::string p = std::to_string(pres);
            listado2=fecha + "\t" + hora + "\t" + correo + "\t" + nombre + "\t" + apell + "\t" + r
                     + "\t" + e + "\t" + git + "\t" + n + "\t" + ex + "\t" + a + "\t"
                     + m + "\t" + yr + "\t" + p;
            escribir(listado2);
        }
        total++;
        fin>>fecha>>hora>>correo>>nomb>>apell>>rep>>expe>>git>>nivel>>expo>>act>>mes>>anio>>pres;
    }
    //Esto nada mas era para pasar los int a strings
    std::string t = std::to_string(total);
    std::string o = std::to_string(ordinario);
    std::string h = std::to_string(hyflex);
    string resultado="-TOTAL ESTUDIANTES: "+t+"\n-ORDINARIO: "+o+"\n-HYFLEX: "+h;
    cout<<resultado;
    escribir(resultado);

    fin.close();
}
int main() {
int op;
    archivo.open("Respuestas.txt", ios::out);
do{
    cout<<"\n- - - - - - - MENÚ GRUPO M22 - - - - - - -\n"
          "1. Quién es el alumn@ más viej@ ?\n"
          "2. Cuánt@s alumn@s cumplen años este mes.?\n"
          "3. Listado de los alunm@s con exp.impar\n"
          "4. Listado de los alunm@s con exp.par\n"
          "5. Porcentaje de alunmos que entregaron la A1.\n"
          "6. Numero y listado de asistentes a clase tanto Hyflex como presenciales.\n"
          "7. Salir.\n"
          "- - - - - - - - - - - - - - - - - - - - - - \n"
          "Opcion: ";
    cin>>op;
    switch(op){
        case 1:
            viejo();

            break;
        case 2:
            birth();
            break;
        case 3:

            listadoim();

            break;
        case 4:
            listadopar();
            break;
        case 5:
            entregas();
            break;
        case 6:
            asistentes();
            break;
    }
}while(op!=7);
    cout<<"Adios!";
archivo.close();
}
