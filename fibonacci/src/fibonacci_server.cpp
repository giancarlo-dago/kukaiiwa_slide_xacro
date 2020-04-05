#include "ros/ros.h"
#include "fibonacci/service.h"
#include <iostream>


bool service_callback (fibonacci::service::Request &req, fibonacci::service::Response &res) {
	std::cout << "Client request: [Index: " << req.index << ", Length: " << req.length << "]" << std::endl;
	if (req.length <= 0 || req.index < 0) return false;
	res.sequence.resize(req.index+req.length);
	res.sequence[0] = 0;
	res.sequence[1] = 1;
	for (int i=2; i<=req.index+req.length; i++) {
		res.sequence[i] = res.sequence[i-2] + res.sequence[i-1];	
	}
	for(int i=0; i<req.length; i++) {
		res.sequence[i] = res.sequence[req.index+i];
	}
	res.sequence.resize(req.length);
	return true;
}

int main (int argc, char **argv) {
	ros::init(argc, argv, "fibonacci_server");
	ros::NodeHandle nh;
	ros::ServiceServer server = nh.advertiseService("service", service_callback);
	ROS_INFO("FIBONACCI SERVER: Ready to receive requests");
	ros::spin(); 
	return true;	
}
