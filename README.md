# 🍴 philosophers - The Dining Philosophers Problem

# 🌟 Overview

The philo project is an implementation of the classic Dining Philosophers Problem—a synchronization challenge in computer science. The goal is to simulate the lives of several philosophers who must share a finite number of resources (forks) while avoiding conditions like deadlocks and starvation.

This project demonstrates a robust understanding of multithreading, mutex synchronization, and system resource management.

# ✨ Features

    Concurrency Management: Uses POSIX threads (pthreads) to simulate multiple philosophers acting simultaneously.

    Synchronization: Implements mutexes to protect shared resources (the forks) and critical sections (changing state, printing logs).

    Deadlock Prevention: Uses a specific strategy (e.g., asymmetrical locking, resource hierarchy, or 'pick up both' attempt) to prevent the system from reaching a deadlock state.

    Accurate Timekeeping: Tracks time for the simulation, ensuring meals and death checks are timed correctly using functions like gettimeofday.

    State Logging: Outputs clear, time-stamped logs of each philosopher's actions (eating, sleeping, thinking, dying) to the console.

# 🛠️ Installation & Usage

- Prerequisites

The project is built in C and requires the standard POSIX thread library.

- Building the Project

Compile: Run make to compile the executable.

    make

  This will generate the executable file named philo.

- Running the Simulation

The program takes command-line arguments to set the parameters of the simulation.

    ./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]

- Example Execution

To run a simulation with 5 philosophers, where each must eat at least 7 times:

    ./philo 5 800 200 200 7

# 📜 Log Output Format

The output streams actions with precise timing:

[timestamp_in_ms] <philosopher_id> is thinking  
[timestamp_in_ms] <philosopher_id> has taken a fork  
[timestamp_in_ms] <philosopher_id> is eating  
[timestamp_in_ms] <philosopher_id> is sleeping  
[timestamp_in_ms] <philosopher_id> died  
