#include "lib.h"
#include "consumer_out.h"
#include "consumer_file.h"
#include "producer.h"

int main(int argc, char *argv[]){
 
    if(argc>1){
        homework::Producer producer(atoi(argv[1]));
        homework::ConsumerOut consumer_out(std::cout);
        homework::ConsumerFile consumer_file;

        producer.subscribe(&consumer_file);
        producer.subscribe(&consumer_out);


        std::string cmd;
        while(std::cin >> cmd)
            producer.produce(cmd);
        producer.flush();
    }

    UNUSED(argc);
    UNUSED(argv);
    return 0;
}