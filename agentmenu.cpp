#include "agentmenu.hpp"

using namespace std;

void AgentMenu::mainMenu(AgentList& a) {
    int op;

    do {
        system("cls");

        cout << endl << endl;
        cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
        cout << "\t\t\t|------------------------Call Center Chipi Chou------------------------|" << endl;
        cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
        cout << "\t\t\t|        [1] Agregar agente                                            |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|        [2] Buscar agente                                             |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|        [3] Eliminar agente                                           |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|        [4] Eliminar todos los agentes                                |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|        [5] Mostrar agentes                                           |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|        [6] Guardar en disco                                          |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|        [7] Leer del disco                                            |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|        [8] Salir                                                     |" << endl;
        cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
        cout << "\t\t\tingresa una opcion (1,2,3,4,5,6,7,8): ";
        cin >> op;
        cin.ignore();

        switch(op) {
            case 1:
                addAgent(a);
                break;
            case 2:
                searchAgent(a);
                break;
            case 3:
                delAgent(a);
                break;
            case 4:
                delAllAgent(a);
                break;
            case 5:
                showAgents(a);
                break;
            case 6:
                writeToDisk(a);
                break;
            case 7:
                readFromDisk(a);
                break;
            case 8:
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
                cout << "\t\t\t|                          Gracias por usarme                          |" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                cout << "\t\t\t|                        Terminando el programa                        |" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                enterToContinue();
                break;
            default:
                cout << "\t\t\tincorrecto vuelva a intentarlo" << endl;
                enterToContinue();
            }
        }
    while(op != 8);
    }

void AgentMenu::addAgent(AgentList& a) {
    int op2(0), myInt(0);
    AgentNode* pos;
    string myStr;
    Agent myAgent;
    Name myName;
    Date myDate;
    Hour myHour;

    system("cls");

    cout << endl << endl;
    cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
    cout << "\t\t\t|---------------------------Agregar nuevo agente-----------------------|" << endl;
    cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|   Nombre: ";
    getline(cin, myStr, ' ');
    myName.setLast(myStr);
    getline(cin, myStr);
    myName.setFirst(myStr);
    myAgent.setAgentName(myName);

    cout << "\t\t\t|   Numero: ";
    getline(cin, myStr);
    myAgent.setAgentNumber(myStr);

    pos = a.findData(myAgent);

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
    myAgent.setAgentExtencion(myStr);

    cout << "\t\t\t|   Especialidad: ";
    getline(cin, myStr);
    myAgent.setSpecialty(myStr);

    cout << "\t\t\t|   Inicio de turno: ";
    getline(cin, myStr, ':');
    myHour.setHour(atoi(myStr.c_str()));
    getline(cin, myStr);
    myHour.setMinute(atoi(myStr.c_str()));
    myAgent.setStartHour(myHour);

    cout << "\t\t\t|   Cierre de turno: ";
    getline(cin, myStr, ':');
    myHour.setHour(atoi(myStr.c_str()));
    getline(cin, myStr);
    myHour.setMinute(atoi(myStr.c_str()));
    myAgent.setEndHour(myHour);

    cout << "\t\t\t|   Horas extras: ";
    cin >> myInt;
    myAgent.setExtraHours(myInt);

    cout << "\t\t\t|   fecha de registro(dd/mm/aaaa): ";
    getline(cin, myStr, '/');
    myDate.setDay(stoi(myStr.c_str()));
    getline(cin, myStr, '/');
    myDate.setMonth(stoi(myStr.c_str()));
    getline(cin, myStr);
    myDate.setYear(stoi(myStr.c_str()));

    myAgent.setAgentDate(myDate);

    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    enterToContinue();

    do {
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
        cout << "\t\t\t|                Quiere ingresar las llamadas del agente?              |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                  1) si                      2)no                     |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t| ";
        cin >> op2;
        cin.ignore();
        }
    while(op2 != 1 and op2 != 2);

    if(op2 == 1) {
        new CallMenu(myAgent.getCallList());
        }
    try {
        a.insertData(a.getLastPos(), myAgent);
        }
    catch(AgentException ex) {
        cout << "Hubo un problema, el sistema reporta: " << endl;
        cout << ex.what() << endl;
        return;
        }

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
    cout << "\t\t\t|                 El agente a sido guardado exitosamente               |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
    enterToContinue();
    }

void AgentMenu::delAgent(AgentList& a) {
    int myInt(0), x(0);
    Agent myAgent, myAgent2;
    Name myName;
    AgentNode* pos;
    string myStr;

    system("cls");

    cout << endl << endl;
    cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
    cout << "\t\t\t|------------------------------Eliminar agente-------------------------|" << endl;
    cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|       Nombre: ";
    getline(cin, myStr, ' ');
    myName.setLast(myStr);
    getline(cin, myStr);
    myName.setFirst(myStr);
    myAgent.setAgentName(myName);

    pos = a.findData(myAgent);

    if(pos == nullptr) {
        system("cls");
        cout << endl << endl;
        cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                    ESE AGENTE NO ESTA EN LA LISTA                    |"<< endl;
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
        cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
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
    cout << "\t\t\t|                   USTED ESTA POR ELIMINAR EL AGENTE                  |"<< endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t| " << a.retrieve(pos).toString(x) << "   |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                          DESEA CONTINUAR?                            |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                 1) si                        2)no                    |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|";
    cin >> myInt;
    cin.ignore();

    if(myInt == 1) {
        a.retrieve(pos).getCallList().deleteAll();
        a.deleteData(pos);
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
        cout << "\t\t\t|                       El agente a sido eliminado                     |" << endl;
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

void AgentMenu::searchAgent(AgentList& a) {
    int x(0), p(0), op(0), myInt(0), x1(1);
    Agent myAgent, myAgent2;
    Name myName;
    AgentNode* pos;
    Hour myHour;
    string myStr;

    system("cls");

    cout << endl << endl;
    cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
    cout << "\t\t\t|------------------------------Buscar agente---------------------------|" << endl;
    cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|       Nombre: ";
    getline(cin, myStr, ' ');
    myName.setLast(myStr);
    getline(cin, myStr);
    myName.setFirst(myStr);
    myAgent.setAgentName(myName);

    pos = a.findData(myAgent);

    if(pos == nullptr) {
        system("cls");
        cout << endl << endl;
        cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                    ESE AGENTE NO ESTA EN LA LISTA                    |"<< endl;
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
        cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
        enterToContinue();
        return;
        }
    system("cls");
    cout << endl << endl;
    cout << "\t\t|--------------------------------------------------------------------------------------|" << endl;
    cout << "\t\t|                                                                                      |" << endl;
    cout << "\t\t|                                    AGENTE                                            |" << endl;
    cout << "\t\t|                                                                                      |" << endl;
    cout << "\t\t|                                                                                      |" << endl;
    cout << "\t\t|" + a.retrieve(pos).toString(x1) << "|" << endl;
    enterToContinue();
    system("cls");
    cout << endl << endl;
    cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|           Te gustaria ........                                       |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |"<< endl;
    cout << "\t\t\t|       1) Ingresar al menu de llamadas                                |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|       2) Modificar este agente.                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|       3) Salir                                                       |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t| ";
    cin >> p;
    cin.ignore();

    if(p == 1) {
        myAgent2 = a.retrieve(pos);
        a.deleteData(pos);
        new CallMenu(myAgent2.getCallList());
        try {
            a.insertData(a.getLastPos(), myAgent2);
            }
        catch(AgentException ex) {
            cout << "Hubo un problema, el sistema reporta: " << endl;
            cout << ex.what() << endl;
            return;
            }
        }
    if(p == 2) {
        myAgent2 = a.retrieve(pos);
        a.deleteData(pos);
        system("cls");
        cout << endl << endl;
        cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                            Modificar agente                          |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |"<< endl;
        cout << "\t\t\t|       1) Duracion del turno                                          |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|       2) Numero y extencion                                          |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|       3) Especialidad                                                |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|       4) Horas extras                                                |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|       5) Salir                                                       |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t| ";
        cin >> op;
        cin.ignore();

        switch(op) {
            case 1:
                system("cls");
                cout << endl << endl;
                cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
                cout << "\t\t\t|----------------------Modificar Turno De Agente-----------------------|" << endl;
                cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                cout << "\t\t\t|   Inicio de turno: ";
                getline(cin, myStr, ':');
                myHour.setHour(atoi(myStr.c_str()));
                getline(cin, myStr);
                myHour.setMinute(atoi(myStr.c_str()));
                myAgent2.setStartHour(myHour);

                cout << "\t\t\t|   Cierre de turno: ";
                getline(cin, myStr, ':');
                myHour.setHour(atoi(myStr.c_str()));
                getline(cin, myStr);
                myHour.setMinute(atoi(myStr.c_str()));
                myAgent2.setEndHour(myHour);
                try {
                    a.insertData(a.getLastPos(), myAgent2);
                    }
                catch(AgentException ex) {
                    cout << "Hubo un problema, el sistema reporta: " << endl;
                    cout << ex.what() << endl;
                    return;
                    }
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
                cout << "\t\t\t|                      El agente a sido Modificado                     |" << endl;
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
            case 2:
                system("cls");
                cout << endl << endl;
                cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
                cout << "\t\t\t|-----------------Modificar numero y extencion del agente--------------|" << endl;
                cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                cout << "\t\t\t|   Numero: ";
                getline(cin, myStr);
                myAgent2.setAgentNumber(myStr);
                cout << "\t\t\t|   Extencion: ";
                getline(cin, myStr);
                myAgent2.setAgentExtencion(myStr);
                try {
                    a.insertData(a.getLastPos(), myAgent2);
                    }
                catch(AgentException ex) {
                    cout << "Hubo un problema, el sistema reporta: " << endl;
                    cout << ex.what() << endl;
                    return;
                    }
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
                cout << "\t\t\t|                      El agente a sido Modificado                     |" << endl;
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
            case 3:
                system("cls");
                cout << endl << endl;
                cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
                cout << "\t\t\t|-------------------Modificar especialidad del agente------------------|" << endl;
                cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                cout << "\t\t\t|   Especialidad: ";
                getline(cin, myStr);
                myAgent2.setSpecialty(myStr);
                try {
                    a.insertData(a.getLastPos(), myAgent2);
                    }
                catch(AgentException ex) {
                    cout << "Hubo un problema, el sistema reporta: " << endl;
                    cout << ex.what() << endl;
                    return;
                    }
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
                cout << "\t\t\t|                      El agente a sido Modificado                     |" << endl;
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
            case 4:
                system("cls");
                cout << endl << endl;
                cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
                cout << "\t\t\t|-------------------Modificar Horas extras del agente------------------|" << endl;
                cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
                cout << "\t\t\t|                                                                      |" << endl;
                cout << "\t\t\t|   Horas extras: ";
                cin >> myInt;
                myAgent2.setExtraHours(myInt);
                try {
                    a.insertData(a.getLastPos(), myAgent2);
                    }
                catch(AgentException ex) {
                    cout << "Hubo un problema, el sistema reporta: " << endl;
                    cout << ex.what() << endl;
                    return;
                    }
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
                cout << "\t\t\t|                      El agente a sido Modificado                     |" << endl;
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
            case 5:
                break;
            }
        }

    }

void AgentMenu::delAllAgent(AgentList& a) {
    int op(0);

    system("cls");

    cout << endl << endl;
    cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|          USTED ESTA POR ELIMINAR TODA LA LISTA DE AGENTES            |" << endl;
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

    if(op == 1) {
        a.deleteAll();
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
        cout << "\t\t\t|                 LA LISTA DE AGENTES A SIDO ELIMINADA                 |" << endl;
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

void AgentMenu::showAgents(AgentList& a) {
    int myInt(0), myInt2(0), myInt3(0), x(0);
    string myStr;

    system("cls");
    cout << endl << endl;
    cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                           Mostrar agentes                            |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |"<< endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|         [1] Filtrar agentes por especialidad                         |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|         [2] Ordenar lista de agentes                                 |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|         [3] Mostrar lista de agentes                                 |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t| ";
    cin >> myInt;
    cin.ignore();

    if(myInt == 1) {
        system("cls");
        cout << endl << endl;
        cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                  Filtrando lista de agentes por....                  |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |"<< endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|         [1] Linux                                                    |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|         [2] Serivdores                                               |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|         [3] Redes                                                    |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|         [4] Impresoras                                               |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t| ";
        cin >> myInt2;
        cin.ignore();

        switch(myInt2) {
            case 1:
                myStr = "linux";
                system("cls");
                cout << endl << endl;
                cout << "\t\t|--------------------------------------------------------------------------------------|" << endl;
                cout << "\t\t|                                                                                      |" << endl;
                cout << "\t\t|                          LISTA DE AGENTES                                            |" << endl;
                cout << "\t\t|                                                                                      |" << endl;
                cout << "\t\t|                                                                                      |" << endl;
                cout << "\t\t|                                                                                      |" << endl;
                cout << a.toStringFilt(myStr, x);
                enterToContinue();
                break;
            case 2:
                myStr = "servidores";
                system("cls");
                cout << endl << endl;
                cout << "\t\t|--------------------------------------------------------------------------------------|" << endl;
                cout << "\t\t|                                                                                      |" << endl;
                cout << "\t\t|                          LISTA DE AGENTES                                            |" << endl;
                cout << "\t\t|                                                                                      |" << endl;
                cout << "\t\t|                                                                                      |" << endl;
                cout << a.toStringFilt(myStr, x);
                enterToContinue();
                break;
            case 3:
                myStr = "redes";
                system("cls");
                cout << endl << endl;
                cout << "\t\t|--------------------------------------------------------------------------------------|" << endl;
                cout << "\t\t|                                                                                      |" << endl;
                cout << "\t\t|                          LISTA DE AGENTES                                            |" << endl;
                cout << "\t\t|                                                                                      |" << endl;
                cout << "\t\t|                                                                                      |" << endl;
                cout << a.toStringFilt(myStr, x);
                enterToContinue();
                break;
            case 4:
                myStr = "impresoras";
                system("cls");
                cout << endl << endl;
                cout << "\t\t|--------------------------------------------------------------------------------------|" << endl;
                cout << "\t\t|                                                                                      |" << endl;
                cout << "\t\t|                          LISTA DE AGENTES                                            |" << endl;
                cout << "\t\t|                                                                                      |" << endl;
                cout << "\t\t|                                                                                      |" << endl;
                cout << a.toStringFilt(myStr, x);
                enterToContinue();
                break;
            }
        }
    if(myInt == 2) {
        system("cls");
        cout << endl << endl;
        cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                  Ordenar lista de agentes por....                    |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |"<< endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|         [1] Nombre                                                   |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|         [2] Especialidad                                             |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t| ";
        cin >> myInt2;
        cin.ignore();

        switch(myInt2) {
            case 1:
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
                cout << "\t\t\t|               Ordenando lista de agentes por nombre.....             |" << endl;
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
                a.sortByName();
                system("cls");
                cout << endl << endl;
                cout << "\t\t|--------------------------------------------------------------------------------------|" << endl;
                cout << "\t\t|                                                                                      |" << endl;
                cout << "\t\t|                                    LISTA DE AGENTES                                  |" << endl;
                cout << "\t\t|                                                                                      |" << endl;
                cout << "\t\t|       Nombre     |        Numero      |   ES  |   HI  |   HF  | HE |  Fecha          |" << endl;
                cout << "\t\t|                                                                                      |" << endl;
                cout << a.toString(x) << endl;
                enterToContinue();
                break;
            case 2:
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
                cout << "\t\t\t|             Ordenando lista de agentes por especialidad.....         |" << endl;
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
                a.sortBySpecialty();
                system("cls");
                cout << endl << endl;
                cout << "\t\t|--------------------------------------------------------------------------------------|" << endl;
                cout << "\t\t|                                                                                      |" << endl;
                cout << "\t\t|                                    LISTA DE AGENTES                                  |" << endl;
                cout << "\t\t|                                                                                      |" << endl;
                cout << "\t\t|       Nombre     |        Numero      |   ES  |   HI  |   HF  | HE |  Fecha          |" << endl;
                cout << "\t\t|                                                                                      |" << endl;
                cout << a.toString(x) << endl;
                enterToContinue();
                break;
            }
        }
    if(myInt == 3) {
        system("cls");
        cout << endl << endl;
        cout << "\t\t\t|----------------------------------------------------------------------|" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                 Quiere mostrar las llamadas del agente?              |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |"<< endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|               [1]Si                            [2]No                 |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t|                                                                      |" << endl;
        cout << "\t\t\t| ";
        cin >> myInt3;
        cin.ignore();
        system("cls");
        cout << endl << endl;
        cout << "\t\t|--------------------------------------------------------------------------------------|" << endl;
        cout << "\t\t|                                                                                      |" << endl;
        cout << "\t\t|                                    LISTA DE AGENTES                                  |" << endl;
        cout << "\t\t|                                                                                      |" << endl;
        cout << "\t\t|       Nombre     |        Numero      |   ES  |   HI  |   HF  | HE |  Fecha          |" << endl;
        cout << "\t\t|                                                                                      |" << endl;
        cout << a.toString(myInt3) << endl;
        enterToContinue();
        }
    }

void AgentMenu::writeToDisk(AgentList& a) {
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
    cout << "\t\t\t|                      ESCRIBIENDO AL DISCO.........                   |" << endl;
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

    try {
        a.writeToDisk("listado.txt");
        }
    catch(AgentException ex) {
        cout << "Hubo un error" << endl;
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
    cout << "\t\t\t|                                                                      |"<< endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                     ARCHIVO GUARDADO EXITOSAMENTE                    |" << endl;
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

void AgentMenu::readFromDisk(AgentList& a) {
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
    cout << "\t\t\t|                       Leyendo datos del disco....                    |" << endl;
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

    try {
        a.readFromDisk("listado.txt");
        }
    catch(AgentException ex) {
        cout << "Hubo un error" << endl;
        cout << ex.what() << endl;
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
    cout << "\t\t\t|                                                                      |"<< endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                                                                      |" << endl;
    cout << "\t\t\t|                        Datos leidos exitosamente                     |" << endl;
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

void AgentMenu::enterToContinue() {
    cout << "\t\t\t\tpresione enter para continuar :)";

    cin.get();
    }

AgentMenu::AgentMenu(AgentList& a) {
    mainMenu(a);
    }
