#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "sensor_msgs/msg/point_cloud2.hpp"
#include "mavros_msgs/msg/state.hpp"

class Scc : public rclcpp::Node
{
	public:
		Scc();
		void talk();
		// Crow
		void crow_pcl_cb(const sensor_msgs::msg::PointCloud2::SharedPtr msg);
		void crow_state_cb(const mavros_msgs::msg::State::SharedPtr msg);
	private:
		// Crow
		rclcpp::Subscription<mavros_msgs::msg::State>::SharedPtr crow_state_sub_;
		rclcpp::Subscription<sensor_msgs::msg::PointCloud2>::SharedPtr crow_pcl_sub_;
		rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
		// Raven

		// Sense
};
