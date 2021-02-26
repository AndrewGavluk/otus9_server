#include <stdlib.h>     //for using the function sleep

#include "../libs/asyncLib.h"
#include "../libs/Server.h"

int main(/*int argc, char const *argv[]*/){
    /*assyncLib interp{};
    size_t size {3};
    uint64_t handler1{interp.connect(size)};
    uint64_t handler2{interp.connect(size)};
    
    const char *input1 = "cmd01 \ncmd02 \ncmd03 \ncmd04 \n{\ncmd11 \ncmd12 \n{\ncmd22 \n}\ncmd31 \n}\ncmd41 \ncmd42 \ncmd43 \n"; 
    size_t size1 = 86;
    const char *input2 = "cmd51 \ncmd52 \ncmd53 \ncmd54 \ncmd55 \n{\ncmd61 \ncmd62 \ncmd63 \n{\ncmd71 \ncmd72 \n}\ncmd81 \n}\ncmd91 \ncmd92 \ncmd93 \n"; 
    size_t size2 = 107;
    
    interp.receive(handler1, input1, size1);
    interp.receive(handler2, input2, size2);
    
    interp.receive(handler1, input2, size2);
    interp.receive(handler2, input1, size1);

    interp.disconnect(handler1);
    interp.disconnect(handler2);*/

 /*if(argc != 3) {
    std::cerr << "Wrong number of arguments (expected 2). Usage: bulk_server <port> <bulk_size>. \n" << std::endl;
    //return EXIT_FAILURE;
  }*/

  //auto port = std::strtoll(argv[1], nullptr, 0);
  auto port = 9001;
  if((port <= 0) || (port > 65535)) {
    std::cerr << "Port must be an integer between 0 and 65535.\n";
    //return EXIT_FAILURE;
  }

  // auto bulk_size = std::strtoll(argv[2], nullptr, 0);
  auto bulk_size = 3;
  if(bulk_size <= 0) {
    std::cerr << "Bulk size must be integer greater than 0.\n";
    //return EXIT_FAILURE;
  }

    try {
        Server bulk_server{static_cast<uint16_t>(port), static_cast<size_t>(bulk_size)};
        bulk_server.start();
    } 
        catch(std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
