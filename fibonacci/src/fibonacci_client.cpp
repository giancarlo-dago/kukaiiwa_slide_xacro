#include "ros/ros.h"
#include "fibonacci/service.h"
#include <iostream>

int main (int argc, char **argv) {
	ros::init(argc, argv, "fibonacci_client");
	ros::NodeHandle nh;
	ros::ServiceClient client = nh.serviceClient<fibonacci::service>("service");
	fibonacci::service srv;
	std::cout << "Insert the INDEX: ";
	std::cin >> srv.request.index;
	std::cout << "Insert the LENGTH: ";
	std::cin >> srv.request.length; 
	if (client.call(srv)) {
		std::cout << "Server says: [ ";
		for(int i=0; i<srv.request.length; i++) {
			std::cout << srv.response.sequence[i] << " ";
		}
		std::cout << "]" << std::endl;
	}
	else {
		ROS_ERROR("Failed to call service");
		return false;
	}
	return true;
}
