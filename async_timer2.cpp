#include <iostream>
#include <vector>
#include <ctime>
#include <algorithm>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

void work_for_io_service(const boost::system::error_code& /*e*/){
        std::cout << "Non-blocking wait() 5 sec \n";
}

void work_for_io_service_10(const boost::system::error_code& /*e*/){
    std::cout << "Non-blocking wait() 10 sec \n";
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
        boost::asio::deadline_timer timer_10(io, boost::posix_time::seconds(10));
       
        timer.async_wait(&work_for_io_service);
        timer_10.async_wait(&work_for_io_service_10);        
        
        //push_vector(10);

        io.run();
        
        return 0;
}
