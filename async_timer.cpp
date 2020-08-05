#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

void work_for_io_service(const boost::system::error_code& /*e*/){
        std::cout << "Non-blocking wait() \n";
}

void push_vector(int length){
    
    std::srand(std::time(nullptr));
    std::vector<int> arr;

    for(int i=0; i<length; i++){
        arr.push_back(std::rand());
    }
    
    for(int i=0; i<arr.size(); i++){
            std::cout<<arr.at(i)<<' ';
    }
    std::cout<<"\n";
    
    std::sort(arr.begin(), arr.end());

    for(int i=0; i<arr.size(); i++){
        std::cout<<arr.at(i)<<' ';
    }
    std::cout<<"\n";
}

int main(){

        boost::asio::io_service io;
        boost::asio::deadline_timer timer(io, boost::posix_time::seconds(5));

        timer.async_wait(&work_for_io_service);

        std::cout << "If we see this before the callback function, we know async_wait() returns immediately.\nThis confirsms async_wait is non-blocking call!\n";
        
        

        push_vector(10);

        io.run();
        
        return 0;
}
