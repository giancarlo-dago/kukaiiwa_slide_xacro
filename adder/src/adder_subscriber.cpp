#include "ros/ros.h"
#include "adder/message1.h"
#include "adder/message2.h"
#include <iostream>

class SUB {
	private:
		ros::NodeHandle _nh;
		ros::Subscriber _sub;
		ros::Publisher _pub;
	public:
		SUB();
		void sub_callback(adder::message1ConstPtr);
};

SUB::SUB() {
	_sub = _nh.subscribe("/random", 10, &SUB::sub_callback, this);
	_pub = _nh.advertise<adder::message2>("/sum", 10);
}

void SUB::sub_callback(adder::message1ConstPtr msg) {
	adder::message2 result;
	result.number1 = msg->number1;
	result.number2 = msg->number2;
	result.sum = msg->number1 + msg->number2;
	_pub.publish(result);	
}

int main (int argc, char **argv) {
	ros::init(argc, argv, "adder_subscriber");
	ROS_INFO ("The node is reading information from '/random' and publishing results on '/sum'");
	SUB sub;
	ros::spin();
	return true;
} 



