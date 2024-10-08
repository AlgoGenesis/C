Here's a shorter version of the **README.md** file:

---

# Concurrent Queue in C

This project implements a **thread-safe concurrent queue** in C using **POSIX threads (pthreads)**, **mutexes**, and **condition variables**. It supports multiple producer and consumer threads, ensuring safe access to the queue.

## Features

- **Thread-Safe**: Ensures safe concurrent access using mutexes.
- **Producer-Consumer Model**: Uses condition variables to wait when the queue is empty or full.
- **Dynamic Queue**: The queue grows dynamically as elements are added.

## Requirements

- POSIX Threads Library (`pthread`)
- GCC Compiler

## Build and Run

1. **Compile**:
   ```bash
   gcc -o concurrent_queue main.c -lpthread
   ```

2. **Run**:
   ```bash
   ./concurrent_queue
   ```

## How It Works

- **Producer** threads enqueue items to the queue.
- **Consumer** threads dequeue items, waiting if the queue is empty.
- **Mutex** ensures only one thread accesses the queue at a time.
- **Condition variables** allow consumers to wait until the queue has items.

---
