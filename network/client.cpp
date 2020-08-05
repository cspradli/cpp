#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(int argc, char* argv[]){

    try{

        if(argc != 2){
                std::cerr<<"Usage: client <host>"<<std::endl;
                return 1;
        }

        boost::asio::io_service io_service;

        //convert the server name that was spec as a param of the app
        tcp::resolver resolver(io_service);

        //resolver takes query obj and turns into list of endpts
        //construct query using name of server, specified in argv[1]
        tcp::resolver::query query(argv[1], "daytime");

        //list of endpts is returned using an iter of type ip::tcp::rsolver
        tcp::resolver::iterator endpoint_iterator = resolver.resolve(query);

        //now create and connect the socket
        //list of endpts obtained may contain both ipv4 and ipv6 endpts
        tcp::socket socket(io_service);
        boost::asio::connect(socket, endpoint_iterator);

        for(;;){
            //use boost array to hold reciever data
            boost::array<char, 128> buf;
            boost::system::error_code error;
            
            //boost::asio:buffer() func auto determines the size of array
            //to help prevent buff overflows
            size_t len = socket.read_some(boost::asio::buffer(buf), error);

            //when server closes connection
            //the tcp ip socket read_some funct will exit with the boost error
            // how we exit out of loop
            if(error == boost::asio::error::eof){
                    break;
            } else if (error) {
                    throw boost::system::system_error(error); //some other error
            }

            std::cout.write(buf.data(), len);
        }
    }

    catch (std::exception& e) {
            std::cerr<<e.what()<<std::endl;
    }

    return 0;

}

