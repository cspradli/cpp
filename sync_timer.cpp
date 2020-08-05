#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace std;


int main(){
    
    boost::asio::io_service io;

    for(int i=0; i < 5; i++){
        boost::asio::deadline_timer timer(io, boost::posix_time::seconds(i));
        timer.wait();
        cout<<"Blocking wait(): " << i << " second-wait\n"<<endl;

    }


    return 0;
}
