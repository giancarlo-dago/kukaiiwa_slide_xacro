#include "ros/ros.h"
#include "std_msgs/String.h"
#include <iostream>

class PUB {
	private:
		ros::NodeHandle _nh;
		ros::Publisher _parrot_pub;	
	public:
		PUB();
		void publishing(std_msgs::String word);
};

PUB::PUB() {
	_parrot_pub = _nh.advertise<std_msgs::String>("/string",10);
}

void PUB::publishing(std_msgs::String word) {
	_parrot_pub.publish(word);

}

int main (int argc, char **argv) {
	ros::init(argc, argv, "parrot_publisher");
	PUB parrot;
	ros::Rate rate(10);
	std_msgs::String word;
	while(ros::ok()) {
		std::cout << "Say something: ";
		std::cin >> word.data;
		parrot.publishing(word);
		rate.sleep();
	}
	return 0;
}
