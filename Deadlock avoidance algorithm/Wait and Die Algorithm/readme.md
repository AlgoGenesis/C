# Wait-Die Deadlock Avoidance Algorithm in C

This project implements the **Wait-Die Algorithm** in C, a deadlock avoidance technique used primarily in database and transaction management systems. The Wait-Die scheme ensures that deadlocks do not occur by enforcing a priority rule based on transaction age (timestamp), allowing only specific requests while aborting others.

## Table of Contents
- [Introduction](#introduction)
- [Algorithm Overview](#algorithm-overview)
- [Features](#features)
- [Example](#example)
- [Limitations](#limitations)

## Introduction

The Wait-Die Algorithm is a deadlock avoidance algorithm that manages resource allocation based on transaction age. When a transaction requests a resource that is already held by another transaction, the algorithm uses timestamps to determine whether the requesting transaction should wait or be aborted ("die"). This approach prevents deadlocks by avoiding circular waiting conditions.

## Algorithm Overview

The Wait-Die Algorithm works as follows:
- **Age Comparison**: Each transaction is assigned a timestamp when it begins, representing its age.
- **Wait Rule**: If a younger transaction requests a resource held by an older transaction, it waits.
- **Die Rule**: If an older transaction requests a resource held by a younger transaction, the older transaction is aborted (dies) and can retry later.

This scheme avoids deadlock by preventing a cycle in the wait-for graph, thus maintaining system safety.

## Features

- **Deadlock Avoidance**: Prevents deadlock by enforcing a strict priority rule based on transaction age.
- **Simple Priority System**: Uses timestamps to decide which transactions wait and which are aborted.
- **Efficient for Database Systems**: Commonly used in databases and transactional systems to manage locks on resources.

## Example

### Sample Scenario

Assume we have three transactions with timestamps and two resources:

| Transaction | ID | Timestamp |
|-------------|----|-----------|
| T1          | 1  | 10        |
| T2          | 2  | 15        |
| T3          | 3  | 5         |

#### Simulation

1. **Transaction T1 requests Resource R1**: Granted.
2. **Transaction T2 requests Resource R1**: Transaction T2 is younger than T1, so it waits.
3. **Transaction T3 requests Resource R1**: Transaction T3 is older than T1, so T1 is aborted (dies) and releases R1 for T3.

This approach ensures the system remains deadlock-free by allowing older transactions to preempt younger ones if necessary.

## Limitations

- **Transaction-Based**: Suited for transactional systems; not typically used for general-purpose resource allocation.
- **Fixed Priority**: Transaction age remains fixed, so newer transactions may experience more aborts.
- **Non-Preemptive Resources**: The algorithm assumes resources are non-preemptive, meaning a held resource cannot be forcibly taken from a transaction.

This implementation demonstrates a simplified version of the Wait-Die algorithm for educational purposes. For a real-world application, further refinements would be required to handle complex resource and transaction management scenarios.
