#ifndef COMMAND_H
#define COMMAND_H
#endif


#if defined I_OS_WIN32

#  define IS_WINDOWS 0

#else defined I_OS_LINUX
#  define IS_WINDOWS 1

#endif

class Command{
public:
    Command();
    ~Command();
    static void cls();
    static void pause();
};

void Command::cls(){
    if(IS_WINDOWS == 0){
        system("cls");
    } else {
        system("clear");
    }
}

void Command::pause(){
    if(IS_WINDOWS == 0){
        system("pause");
    }else {
       std:: cout<<"press any key..."<<std::endl;
       std::cin.get();
       getchar();
    }

}
