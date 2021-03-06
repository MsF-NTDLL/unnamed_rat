#include "headers.hpp"
#include "Server.hpp"
#include "Misc.hpp"
bool bSignalFlag;

void CleanEx(int){
	std::cout<<"\nProgram interrupted press enter to exit\n";
	bSignalFlag = true;
}

int main(int argc, char **argv){
	if(argc < 2){
			std::cout<<argv[0]<<" port\n";
			return 0;
	}
	#ifdef _TERMUX
	#ifdef ES
	std::cout<<"\n\tunnamedRAT\n\tHerramienta de Administracion remota\n\tpor d3adlym1nd\n";
	#endif
	#ifdef EN
	std::cout<<"\n\tunnamedRAT\n\tRemote Access Tool\n\tby d3adlym1nd\n";
	#endif
	#else
    const char *cBanner = BrightBlack "\n" \
"                                              __              __\n"\
"  __  ______  ____  ____ _____ ___  ___  ____/ /  _________ _/ /_\n"\
" / / / / __ \\/ __ \\/ __ `/ __ `__ \\/ _ \\/ __  /  / ___/ __ `/ __/\n"\
"/ /_/ / / / / / / / /_/ / / / / / /  __/ /_/ /  / /  / /_/ / /_\n"\
"\\__,_/_/ /_/_/ /_/\\__,_/_/ /_/ /_/\\___/\\__,_/  /_/   \\__,_/\\__/\n\n" CReset\
"               ";

    std::cout<<cBanner;
	#ifdef EN
	std::cout<<"Command-Line Remote Access Tool\n"\
	"                      by " BrightCyan "d3adlym1nd" CReset "\n";
	#endif
	#ifdef ES
	std::cout<<"Herramienta de Acceso Remoto desde linea de comandos\n"\
	"                      por " BrightCyan "d3adlym1nd" CReset "\n";
	#endif
	#endif
	bSignalFlag = false;
	OpenSSL_add_ssl_algorithms();
	SSL_load_error_strings();

	#ifdef _NOTIFY
	if(!notify_init("unnamed")){
		#ifdef EN
        std::cout<<"Error initializing libnotify\n";
        #endif
        #ifdef ES
        std::cout<<"Error inicializando libnotify\n";
        #endif
        return -1;
	}
	#endif

	u_int uiLport = Misc::StrToUint(argv[1]);
	Server *srvServer = new Server(uiLport);
	srvServer->NullClients();
	signal(SIGPIPE, SIG_IGN);
	signal(SIGINT, CleanEx);
	if(srvServer->Listen(10)){
			srvServer->thStartHandler();
	}
	delete srvServer;
	srvServer = nullptr;
	#ifdef _NOTIFY
	notify_uninit();
	#endif
	ERR_free_strings();
        EVP_cleanup();
	return 0;
}
