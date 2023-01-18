#include "callmenu.hpp"

using namespace std;

void CallMenu::addCall(CallList& c) {
    Call myCall;
    Hour myHour;
    string myStr;
    CallNode* pos;
    Name myName;
    Date myDate;
    int op(0);

    system("cls");

    cout << endl << endl;
    cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                            Agregar llamada                           |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|   Nombre: ";
    getline(cin, myStr, ' ');
    myName.setLast(myStr);
    getline(cin, myStr);
    myName.setFirst(myStr);
    myCall.setName(myName);

    cout << "\t\t\t|   Numero: ";
    getline(cin, myStr);
    myCall.setNumber(myStr);

    pos = c.findData(myCall);

    if(pos != nullptr) {
        system("cls");
        cout << endl << endl;
        cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |"<< endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                     ESE NUMERO YA ESTA REGISTRADO                    |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                          REGRESANDO AL MENU                          |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        enterToContinue();
        return;
        }

    cout << "\t\t\t|   Extencion: ";
    getline(cin, myStr);
    myCall.setExtencion(myStr);

    cout << "\t\t\t|   Hora inicio: ";
    getline(cin, myStr, ':');
    myHour.setHour(atoi(myStr.c_str()));
    getline(cin, myStr);
    myHour.setMinute(atoi(myStr.c_str()));
    myCall.setStartHour(myHour);

    cout << "\t\t\t|   Hora final: ";
    getline(cin, myStr, ':');
    myHour.setHour(atoi(myStr.c_str()));
    getline(cin, myStr);
    myHour.setMinute(atoi(myStr.c_str()));
    myCall.setEndHour(myHour);

    cout << "\t\t\t|   fecha(dd/mm/aaaa): ";
    getline(cin, myStr, '/');
    myDate.setDay(stoi(myStr.c_str()));
    getline(cin, myStr, '/');
    myDate.setMonth(stoi(myStr.c_str()));
    getline(cin, myStr);
    myDate.setYear(stoi(myStr.c_str()));

    myCall.setDate(myDate);

    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;

    system("cls");

    cout << endl << endl;
    cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                    Usted esta por guarda la llamada                  |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t| " << myCall.toString() << "   |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                          desea continuar?                            |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                  1) si                      2)no                     |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|";
    cin >> op;
    cin.ignore();

    if(op == 1) {
        c.insertSorteData(myCall);
        system("cls");
        cout << endl << endl;
        cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |"<< endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                      LA LLAMADA A SIDO GUARDADA                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        enterToContinue();
        }
    else {
        return;
        }
    }

void CallMenu::delCall(CallList& c) {
    Call myCall;
    CallNode* pos;
    string myStr;
    int op(0);

    system("cls");

    cout << endl << endl;
    cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                           Eliminar llamada                           |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|       numero: ";
    getline(cin, myStr);

    myCall.setNumber(myStr);

    pos = c.findData(myCall);

    if(pos == nullptr) {
        system("cls");
        cout << endl << endl;
        cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                    ESE NUMERO NO ESTA EN LA LISTA                    |"<< endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                         REGRESANDO AL MENU                           |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        enterToContinue();

        return;
        }

    system("cls");
    cout << endl << endl;
    cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                   USTED ESTA POR ELIMINAR LA LLAMADA                 |"<< endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t| " << pos->getData().toString() << "   |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                          DESEA CONTINUAR?                            |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                 1) si                        2)no                    |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|";
    cin >> op;
    cin.ignore();
    if(op == 1) {
        c.deleteData(pos);
        system("cls");
        cout << endl << endl;
        cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |"<< endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                      LA LLAMADA A SIDO ELIMINADA                     |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        enterToContinue();
        }
    else {
        return;
        }
    }

void CallMenu::modCall(CallList& c) {
    Call myCall;
    CallNode* pos;
    string myStr;
    Hour myHour;
    int op(0);

    system("cls");

    cout << endl << endl;
    cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                          Modificando llamada                         |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|      numero: ";
    getline(cin, myStr);

    myCall.setNumber(myStr);

    pos = c.findData(myCall);

    if(pos == nullptr) {
        system("cls");
        cout << endl << endl;
        cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                    ESE NUMERO NO ESTA EN LA LISTA                    |"<< endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                         REGRESANDO AL MENU                           |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        enterToContinue();
        return;
        }

    myCall = pos->getData();

    cout << "\t\t\t|      Hora inicio: ";
    getline(cin, myStr, ':');
    myHour.setHour(atoi(myStr.c_str()));
    getline(cin, myStr);
    myHour.setMinute(atoi(myStr.c_str()));
    myCall.setStartHour(myHour);

    cout << "\t\t\t|      Hora final: ";
    getline(cin, myStr, ':');
    myHour.setHour(atoi(myStr.c_str()));
    getline(cin, myStr);
    myHour.setMinute(atoi(myStr.c_str()));
    c.retrieve(pos).setEndHour(myHour);
    myCall.setEndHour(myHour);

    system("cls");
    cout << endl << endl;
    cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                   USTED ESTA POR MODIFICAR LA LLAMADA                |"<< endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t| " << pos->getData().toString() << "   |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                          DESEA CONTINUAR?                            |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                 1) si                        2)no                    |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|";
    cin >> op;
    cin.ignore();

    if(op == 1) {
        c.deleteData(pos);

        c.insertSorteData(myCall);

        system("cls");
        cout << endl << endl;
        cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |"<< endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|               LA LLAMADA A SIDO MODIFICADA EXITOSAMENTE              |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        enterToContinue();
        }
    else {
        return;
        }
    }

void CallMenu::delAllCall(CallList& c) {
    int op(0);

    system("cls");

    cout << endl << endl;
    cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|          USTED ESTA POR ELIMINAR TODA LA LISTA DE LLAMADAS           |" << endl;
    cout << "\t\t\t|                                                                      |"<< endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                         DESEA CONTINUAR?                             |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|              1) si                           2) no                   |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|";
    cin >> op;
    cin.ignore();

    if(op == 1){
        c.deleteAll();

        system("cls");
        cout << endl << endl;
        cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |"<< endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                 LA LISTA DE LLAMADAS A SIDO ELIMINADA                |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        enterToContinue();
    }
    else{
        return;
    }
    }

void CallMenu::showCall(CallList& c) {
    system("cls");

    cout << endl << endl;
    cout << "\t\t|----------------------------------------------------------------------------------|" << endl;
    cout << "\t\t|                                                                                  |" << endl;
    cout << "\t\t|                          LISTA DE LLAMADAS                                       |" << endl;
    cout << "\t\t|                                                                                  |" << endl;
    cout << "\t\t|      Nombre      |       Numero       |   HI  |   HF  |  Fecha                   |" << endl;
    cout << "\t\t|                                                                                  |" << endl;
    cout << c.toString();
    cout << "\t\t|                                                                                  |" << endl;
    cout << "\t\t|----------------------------------------------------------------------------------|" << endl;
    enterToContinue();
    }

void CallMenu::enterToContinue() {
    cout << "\t\t\t\tpresione enter para continuar :)";

    cin.get();
    }

CallMenu::CallMenu(CallList& c) {
    mainMenu(c);
    }

void CallMenu::mainMenu(CallList& c) {
    int op(0);

    do {
        system("cls");

        cout << endl << endl;
        cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
        cout << "\t\t\t|---------------------------llamadas del agente------------------------|" << endl;
        cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|        [1] Agregar llamada                                           |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|        [2] Eliminar llamada                                          |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|        [3] Modificar duracion                                        |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|        [4] Mostrar llamadas                                          |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|        [5] Eliminar todas las llamadas                               |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|        [6] Salir                                                     |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
        cout << "\t\t\tingresa una opcion (1,2,3,4,5,6): ";
        cin >> op;
        cin.ignore();

        switch(op) {
            case 1:
                addCall(c);
                break;
            case 2:
                delCall(c);
                break;
            case 3:
                modCall(c);
                break;
            case 4:
                showCall(c);
                break;
            case 5:
                delAllCall(c);
                break;
            case 6:
                system("cls");
                cout << endl << endl;
                cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                cout << "\t\t\t|                                                                      |"<< endl;
                cout << "\t\t\t|                                                                      |" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                cout << "\t\t\t|                       Terminando menu de llamadas                    |" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                enterToContinue();
                break;
            default:
                cout << "incorrecto vuelva a intentar" << endl;
                enterToContinue();
            }
        }
    while(op != 6);
    }
