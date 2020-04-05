#include "ros/ros.h"
#include <iostream>
#include "adder/message1.h"

class PUB {
	private:
		ros::NodeHandle _nh;
		ros::Publisher _pub;	
	public:
		PUB();
		void publishing(adder::message1);
};

PUB::PUB() {
	_pub = _nh.advertise<adder::message1>("/random", 10);
}

void PUB::publishing(adder::message1 msg) {
	_pub.publish(msg);
}
 
int main (int argc, char **argv) {
	ros::init(argc, argv, "adder_publisher");
	ROS_INFO ("The node is publishing on '/random'");
	PUB pub;
	ros::Rate loop_rate(10);
	int Max = 100;
	adder::message1 x;
	while(ros::ok()) {
		x.number1 = float(rand())/float(RAND_MAX/Max);
		x.number2 = float(rand())/float(RAND_MAX/Max);
		pub.publishing(x);
		loop_rate.sleep();
	}
	return true;
}
