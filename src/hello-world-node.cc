#include "mpi_hello_world/hello-world-node.h"
#include "mpi_hello_world/hello-world.h"

#include <glog/logging.h>

namespace mpi {

HelloWorldNode::HelloWorldNode(
    const ros::NodeHandle& nh, const ros::NodeHandle& nh_private)
    : spinner_(1), node_handle_(nh), node_handle_private_(nh_private) {
  should_exit_.store(false);
}

bool HelloWorldNode::run() {
  LOG(INFO) << "--- Running MPI example ----------";
  spinner_.start();
  callCudaHelloWorld();
  return true;
}

const std::atomic<bool>& HelloWorldNode::shouldExit() const noexcept {
  return should_exit_;
}

std::string HelloWorldNode::updateAndPrintStatistics() {
  return "computing...";
}

void HelloWorldNode::shutdown() {}

void HelloWorldNode::callCudaHelloWorld() {
  std::string result = hello_world_cu();
  LOG(INFO) << "MPI result: " << result;
  should_exit_.store(true);
}

}  // namespace mpi
