# Circular Linked List for Round-Robin Task Scheduling in C

This project implements a circular linked list to manage tasks using a round-robin scheduling algorithm. Each task is represented as a node in the circular linked list, allowing efficient task management.

## Table of Contents

- [Introduction](#introduction)
- [Data Structure](#data-structure)

## Introduction

In round-robin scheduling, tasks are executed in a circular manner, allowing each task to receive a fixed time slice for execution. This implementation allows for dynamic insertion and deletion of tasks.

## Data Structure

The linked list is composed of nodes defined by the following structure:

```c
struct Task {
    int id;                // Task identifier
    struct Task* next;     // Pointer to the next task in the list
};
