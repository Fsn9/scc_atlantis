#include "scc.h"

Scc::Scc() : Node("scc")
{
	publisher_ = create_publisher<std_msgs::msg::String>("topic", 10);
}

void Scc::talk()
{
	std_msgs::msg::String msg;
	msg.data = "Hey";
	publisher_->publish(msg);
}
