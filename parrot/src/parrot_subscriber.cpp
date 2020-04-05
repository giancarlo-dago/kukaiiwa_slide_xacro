#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>

class PARROT_SUB {
	private:
		ros::NodeHandle _nh;
		ros::Subscriber _parrot_sub;
	public:
		PARROT_SUB();
		void parrot_callback(std_msgs::StringConstPtr word);
};

PARROT_SUB::PARROT_SUB() {
	_parrot_sub = _nh.subscribe("/string", 0, &PARROT_SUB::parrot_callback, this);
}

void PARROT_SUB::parrot_callback(std_msgs::StringConstPtr word) {
	std::cout << "I heard: " << word->data << std::endl;
//	ROS_INFO("I heard: %s", word->data.c_str());
}

int main (int argc, char **argv) {
	ros::init(argc, argv, "parrot_subscriber");
	PARROT_SUB sub;
	ros::spin();
	return 0;
}
