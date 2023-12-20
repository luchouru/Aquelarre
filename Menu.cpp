#include "Menu.h"

void mostrarMenuPrincipal(int &op){
    cout << "\n\n(-1)- Cargar datos de prueba." << endl;
    cout << "(1)- Registrar bruja suprema." << endl;
    cout << "(2)- Registrar bruja comun." << endl;
    cout << "(3)- Listar todas las brujas." << endl;
    cout << "(4)- Listar bruja." << endl;
    cout << "(5)- Listar bruja mas antigua." << endl;
    cout << "(6)- Registrar nuevo hechizo." << endl;
    cout << "(7)- Listar hechizo." << endl;
    cout << "(8)- Contar hechizos especiales." << endl;
    cout << "(9)- Salir." << endl;
    cout << "\n\nIngrese una opcion: ";
    cin >> op;
}

void mostrarError(TipoError error) {
    cout <<"ERROR: " << endl;
    switch(error) {
        case NO_HAY_BRUJAS:
            cout <<"No hay brujas en el aquelarre, cuanta Soledad." << endl;
            break;
        case BRUJA_YA_EXISTE:
            cout <<"La bruja ya pertenece al aquelarre, no sea pesado." << endl;
            break;
        case BRUJA_NO_EXISTE:
            cout <<"La bruja no se encuentra en el aquelarre, por favor invitela." << endl;
            break;
        case NO_ES_BRUJA_SUPREMA:
            cout <<"La bruja no es una suprema, todavia le falta." << endl;
            break;
        case HECHIZO_NO_EXISTE:
            cout <<"El hechizo no existe, debe practicar un poco mas." << endl;
            break;
        case MAXIMO_HECHIZOS:
            cout <<"La bruja es una capa en la magia, no puede aprender mas hechizos." << endl;
            break;
        default:
            cout <<"Error desconocido." << endl;
            break;
    }
}
