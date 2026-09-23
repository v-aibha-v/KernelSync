# KernelSync

> Building the foundations of concurrent systems from the ground up — exploring process synchronization, mutual exclusion, inter-process communication, and classic Operating System concurrency problems in C++.

## Overview

**KernelSync** is a practical exploration of fundamental Operating System
synchronization and concurrency concepts implemented in C++.

The repository demonstrates how concurrent processes and threads coordinate
access to shared resources, prevent race conditions, communicate with each
other, and handle classic synchronization challenges using established
Operating System mechanisms.

## Core Concepts

- Process Synchronization
- Thread Synchronization
- Mutual Exclusion
- Race Conditions
- Semaphores
- Critical Sections
- Shared Memory
- Message Passing
- Deadlock Prevention
- Concurrent Resource Management

## Synchronization Problems

| Implementation                          | Concept                                           |
| --------------------------------------- | ------------------------------------------------- |
| `semaphore.cpp`                         | Semaphore-based mutual exclusion                  |
| `peterson.cpp`                          | Peterson's mutual exclusion algorithm             |
| `producer_consumer.cpp`                 | Producer-Consumer synchronization                 |
| `read-writer.cpp`                       | Readers-Writers synchronization                   |
| `DINING PHILOSOPHERS.cpp`               | Dining Philosophers problem                       |
| `race cond.cpp`                         | Race condition demonstration                      |
| `message passing.cpp`                   | Inter-process communication using message passing |
| `BOUNDED BUFFER WITH SHARED MEMORY.cpp` | Shared-memory bounded buffer                      |
| `buffer out.cpp`                        | Buffer-based process coordination                 |

## Technology

- **Language:** C++
- **Concurrency:** C++ Threads
- **Synchronization:** POSIX Semaphores
- **Platform:** Linux / POSIX-compatible environments

## How It Works

KernelSync focuses on the mechanisms that allow concurrent execution to remain
controlled and predictable.

```text
Concurrent Processes / Threads
            │
            ▼
    ┌─────────────────┐
    │ Synchronization │
    └────────┬────────┘
             │
     ┌───────┼────────┐
     ▼       ▼        ▼
 Semaphores Mutexes  IPC
     │       │        │
     └───────┼────────┘
             ▼
     Safe Resource Access
```
