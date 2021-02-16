#include "../inc/Connexion.h"
#include "../inc/HandShake.h"


INT main()
{
    
   // ShowWindow(GetConsoleWindow(),SW_HIDE);
    _setmode(_fileno(stdout), 0x00020000); 
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    Connexion Client; 
    HandShake Handshake;

    Client.openConnexion();

    Handshake.setSock(Client.getSocket());
    Handshake.beforeHandShake();
    Handshake.startHandShake(); 

    Client.setToken(Handshake.getToken());
    Client.setIsAdmin(Handshake.getIsAdmin());
    Client.setPathProg(Handshake.getPathProg());
    Client.main();

    Client.closeConnexion();
    
    return 0;
}
