#ifndef INCLUDE_MPI_HELLO_WORLD_HELLO_WORLD_NODE_H_
#define INCLUDE_MPI_HELLO_WORLD_HELLO_WORLD_NODE_H_

#include <atomic>
#include <memory>
#include <ros/ros.h>
#include <string>
#include <vector>

namespace mpi {

class HelloWorldNode {
public:
  explicit HelloWorldNode(const ros::NodeHandle &nh,
                          const ros::NodeHandle &nh_private);
  bool run();
  const std::atomic<bool> &shouldExit() const noexcept;
  std::string updateAndPrintStatistics();
  void shutdown();

private:
  void callMpiHelloWorld();
  ros::AsyncSpinner spinner_;
  const ros::NodeHandle &node_handle_;
  const ros::NodeHandle &node_handle_private_;
  std::atomic<bool> should_exit_;
};

} // namespace mpi

#endif // INCLUDE_MPI_HELLO_WORLD_HELLO_WORLD_NODE_H_
