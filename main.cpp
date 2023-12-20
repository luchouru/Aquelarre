#include "FachadaLogica.h"
#include "Fecha.h"
#include "Menu.h"


void initDatos(FachadaLogica &fachada, TipoError &err)
{
    fachada.ingresarBrujaSuprema("1", "Ana Bolena", Fecha(10,10,1900),1, err);
    fachada.ingresarBrujaSuprema("2", "Epona", Fecha(10,10,1800),2, err);
    fachada.ingresarBrujaSuprema("3", "Alice", Fecha(10,10,1850),3, err);
    fachada.ingresarBrujaSuprema("7", "Bruja Ana Bolena", Fecha(15,5,1875),10, err);
    fachada.ingresarBrujaSuprema("8", "Bruja Epona", Fecha(15,5,1880),11, err);
    fachada.ingresarBrujaSuprema("9", "Bruja Alice Kyteler", Fecha(15,5,1700),12, err);

    fachada.ingresarBrujaComun("7","13","Bruja Madre Shipton","Salem", true, err);
    fachada.ingresarBrujaComun("8","14","Bruja Madame Blavatsky","Astuza", true, err);
    fachada.ingresarBrujaComun("9","15","Bruja Allison Gross","Arletuza", false, err);
    fachada.ingresarBrujaComun("1","4","Madre Shipton","Salem", true, err);
    fachada.ingresarBrujaComun("2","5","Blavatsky","Astuza", true, err);
    fachada.ingresarBrujaComun("3","6","Allison","Arletuza", false, err);

    fachada.registrarNuevoHechizo("1","Abracadabra", err);
    fachada.registrarNuevoHechizo("2","Conjureishon", err);
    fachada.registrarNuevoHechizo("2","Hechizo", err);
    fachada.registrarNuevoHechizo("1","Wicca", err);
    fachada.registrarNuevoHechizo("7","Expecto Patronum", err);
    fachada.registrarNuevoHechizo("8","Avada Kedavra", err);
    fachada.registrarNuevoHechizo("9","Wingardium Leviosa", err);

    fachada.registrarNuevoHechizoEspecial("1","Abracadabra mejorado", 1950, "Hechizo que ", err);
    fachada.registrarNuevoHechizoEspecial("1","Abracadabra mejorado", 1950, "Hechizo test  ", err);
    fachada.registrarNuevoHechizoEspecial("2","Abracadabra mejorado", 1950, "Hechizo descripcion", err);
    fachada.registrarNuevoHechizoEspecial("3","Abracadabra mejorado", 1950, "Hechizo descripcion", err);
    fachada.registrarNuevoHechizoEspecial("7","Expecto Patronum mejorado", 1975, "Hechizo que", err);
    fachada.registrarNuevoHechizoEspecial("8","Avada Kedavra mejorado", 1985, "Hechizo descripcion", err);
    fachada.registrarNuevoHechizoEspecial("9","Wingardium Leviosa mejorado", 1995, "Hechizo descripcion", err);
}

int main()
{
    FachadaLogica fachada = FachadaLogica();

    TipoError error;

    IteradorBrujas listado;

    int opcion;
    do
    {
        system("cls");
        cout <<"\tMENU PRINCIPAL";
        mostrarMenuPrincipal(opcion);
        fflush(stdin);
        switch(opcion)
        {
        case -1:
        {
            system("cls");
            fflush(stdin);

            initDatos(fachada,error);
            if(error == SIN_ERROR)
            {
                cout <<"Datos cargados correctamente."<< endl;
            }
            else
            {
                mostrarError(error);
            }

            cout <<"Presione ENTER para continuar";
            fflush(stdin);
            getchar();
            break;
        }
        case 1:
        {
            system("cls");
            fflush(stdin);
            String id, nombre;
            Fecha nacimiento;
            int poderes, dia, mes, anio;

            cout << "Ingrese el identificador de la bruja: ";
            id.scan();

            cout << "Ingrese el nombre: ";
            nombre.scan();

            cout << "Ingrese dia de nacimiento: ";
            cin >> dia;
            nacimiento.setDia(dia);

            cout << "Ingrese mes de nacimiento: ";
            cin >> mes;
            nacimiento.setMes(mes);

            cout << "Ingrese anio de nacimiento: ";
            cin >> anio;
            nacimiento.setAnio(anio);

            cout << "Ingrese cantidad de poderes: ";
            cin >> poderes;

            fachada.ingresarBrujaSuprema(id,nombre,nacimiento,poderes,error);

            if(error == SIN_ERROR)
                cout << "Bruja suprema registrada correctamente" << endl;
            else
                mostrarError(error);

            cout << "Presione ENTER para continuar";
            fflush(stdin);
            getchar();
            break;
        }
        case 2:
        {
            system("cls");
            fflush(stdin);
            String idSuprema, id, nombre, region;
            bool vuelaEnEscoba = false;
            char respuesta = 'n';

            cout << "Ingrese el identificador de la bruja: ";
            id.scan();

            cout << "Ingrese el nombre: ";
            nombre.scan();

            cout << "Ingrese el identificador de la bruja suprema a la que se reporta: ";
            idSuprema.scan();

            cout << "Ingrese region de origen: ";
            region.scan();

            cout << "Vuela en escoba? (s/n) ";
            cin >> respuesta;

            if(respuesta == 's')
                vuelaEnEscoba = true;

            fachada.ingresarBrujaComun(idSuprema,id,nombre,region,vuelaEnEscoba,error);

            if(error == SIN_ERROR)
                cout << "Bruja comun registrada correctamente" << endl;
            else
                mostrarError(error);

            cout << "Presione ENTER para continuar";
            fflush(stdin);
            getchar();
            break;
        }
        case 3:
        {
            system("cls");
            cout << "Listado de brujas" << endl;
            listado = fachada.listarBrujas(error);
            if(error == SIN_ERROR)
            {
                while(listado.hayMasBrujas())
                {
                    Bruja * actual = listado.proximaBruja();

                    cout << "Identificador: ";
                    actual->getIdentificador().print();
                    cout << " Nombre: ";
                    actual->getNombre().print();

                    if(actual->tipoBruja() == "Suprema")
                    {
                        Suprema * sup = (Suprema *) actual;
                        cout << " Fecha de nacimiento: " << sup->getFechaNacimiento().getDia() << "/" << sup->getFechaNacimiento().getMes() << "/" << sup->getFechaNacimiento().getAnio();
                        cout << " Cantidad de poderes: " << sup->getCantidadPoderes() << endl;
                    }
                    else
                    {
                        Comun * comon = (Comun *) actual;
                        cout << " Region origen: ";
                        comon->getRegionOrigen().print();
                        cout << " Vuela escoba: " << (comon->getVuelaEscoba() ? "Si" : "No");
                        cout << " Se reporta a: ";
                        comon->getSupremaReporta()->getNombre().print();
                        cout << endl;
                    }
                }
            }
            else
            {
                mostrarError(error);
            }

            cout <<"Presione ENTER para continuar";
            fflush(stdin);
            getchar();
            break;

        }
        case 4:
        {
            system("cls");
            fflush(stdin);
            String idBruja;
            cout << "Ingrese el identificador de la bruja: ";
            idBruja.scan();
            listado = fachada.listarDetalleBruja(idBruja,error);
            if(error == SIN_ERROR)
            {
                while(listado.hayMasBrujas())
                {
                    Bruja * actual = listado.proximaBruja();

                    cout << "Identificador: ";
                    actual->getIdentificador().print();
                    cout << " Nombre: ";
                    actual->getNombre().print();

                    if(actual->tipoBruja() == "Suprema")
                    {
                        Suprema * sup = (Suprema *) actual;
                        cout << " Fecha de nacimiento: " << sup->getFechaNacimiento().getDia() << "/" << sup->getFechaNacimiento().getMes() << "/" << sup->getFechaNacimiento().getAnio();
                        cout << " Cantidad de poderes: " << sup->getCantidadPoderes();
                    }
                    else
                    {
                        Comun * comon = (Comun *) actual;
                        cout << " Region origen: ";
                        comon->getRegionOrigen().print();
                        cout << " Vuela escoba: " << comon->getVuelaEscoba();
                        cout << " Se reporta a: ";
                        comon->getSupremaReporta()->getNombre().print();
                    }
                    if(actual->getHechizos() == NULL)
                        cout << " Puntos de poder: 0" << endl;
                    else
                        cout << " Puntos de poder: " << actual->getPoder() << endl;
                }
            }
            else
            {
                mostrarError(error);
            }
            cout <<"Presione ENTER para continuar";
            fflush(stdin);
            getchar();
            break;
        }
        case 5:
        {
            system("cls");
            fflush(stdin);
            Suprema * sup;
            sup = fachada.obtenerBrujaSupremaMayor(error);
            if(error == SIN_ERROR)
            {
                cout << "Identificador: ";
                sup->getIdentificador().print();
                cout << " Nombre: ";
                sup->getNombre().print();
                cout << " Fecha de nacimiento: " << sup->getFechaNacimiento().getDia() << "/" << sup->getFechaNacimiento().getMes() << "/" << sup->getFechaNacimiento().getAnio();
                cout << " Cantidad de poderes: " << sup->getCantidadPoderes();
                if(sup->getHechizos() == NULL)
                    cout << " Puntos de poder: 0" << endl;
                else
                    cout << " Puntos de poder: " << sup->getPoder() << endl;
            }
            else
            {
                mostrarError(error);
            }
            cout <<"Presione ENTER para continuar";
            fflush(stdin);
            getchar();
            break;
        }
        case 6:
        {
            system("cls");
            fflush(stdin);
            String idBruja, texto;
            char especial = 'n';
            int anio;

            cout <<"Ingrese el identificador de la bruja:";
            idBruja.scan();

            cout <<"Ingrese el texto para el hechizo:";
            texto.scan();

            cout <<"Es el hechizo de tipo especial? (s/n):";
            cin >> especial;

            if(especial == 's')
            {
                int anio;
                String descripcion;

                cout <<"Ingrese el anio en el que la bruja manifesto el hechizo:";
                cin >> anio;
                fflush(stdin);
                cout <<"Ingrese la descipcion para el hechizo:";
                descripcion.scan();

                fachada.registrarNuevoHechizoEspecial(idBruja,texto,anio,descripcion,error);

            }
            else
            {
                fachada.registrarNuevoHechizo(idBruja,texto,error);
            }

            if(error == SIN_ERROR)
            {
                cout <<"Hechizo registrado correctamente."<< endl;

            }
            else
            {
                mostrarError(error);
            }

            cout <<"Presione ENTER para continuar";
            fflush(stdin);
            getchar();
            break;
        }
        case 7:
        {
            system("cls");
            fflush(stdin);
            Hechizo * hechizo = NULL;
            String idBruja;
            int nroHechizo;

            cout << endl << "Ingrese el identificador de la bruja:";
            idBruja.scan();

            cout <<"Ingrese el nro de hechizo:";
            cin >> nroHechizo;

            hechizo = fachada.listarHechizoBruja(idBruja,nroHechizo,error);

            if(error == SIN_ERROR)
            {
                cout << "Nro de hechizo: " << hechizo ->getNumero();
                cout << endl << "Texto: ";
                hechizo ->getTexto().print();
                cout << endl << "Tipo de Hechizo: ";
                hechizo ->tipoHechizo().print();
                cout << endl;
                if(hechizo->tipoHechizo() == "Especial")
                {
                    Especial * especial = (Especial *) hechizo;
                    cout << "Anio de manifiesto: " << especial->getAnioManifiesto() << endl;
                    cout << "Descripcion: ";
                    especial->getDescripcion().print();
                    cout << endl;
                }
            }
            else
            {
                mostrarError(error);
            }

            cout <<"Presione ENTER para continuar";
            fflush(stdin);
            getchar();
            break;
        }
        case 8:
        {
            system("cls");
            fflush(stdin);
            String idBruja;
            int anioHechizo, cantidad;

            cout << endl << "Ingrese el identificador de la bruja:";
            idBruja.scan();

            cout <<"Ingrese el anio de hechizo:";
            cin >> anioHechizo;

            cantidad = fachada.contarHechizosEspecialesEnAnio(idBruja, anioHechizo, error);

            if(error == SIN_ERROR)
                cout << "Cantidad de hechizos aprendidos: " << cantidad << endl;
            else
                mostrarError(error);

            cout <<"Presione ENTER para continuar";
            fflush(stdin);
            getchar();
            break;
        }
        default:
            if(opcion != 9)
                cout <<"Opcion incorrecta" << endl;
            cout <<"Presione ENTER para continuar";
            fflush(stdin);
            getchar();
            break;
        }
        cin.clear();
    }
    while(opcion != 9);
}

