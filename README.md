# MPI Hello World
Sample project structure for MPI using catkin.

## Build
The package builds as a regular catkin project, i.e.:
```
catkin build mpi_hello_world_catkin
```

## Running
A script in the folder `shared` provides a simple example. It basically launches `N_PROCESSES` ROS nodes using `mpirun`.
