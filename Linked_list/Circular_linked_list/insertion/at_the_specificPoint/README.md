# Circular Linked List in C

This project implements a circular linked list in C with three types of insertion functionalities:

1. Insert a node at the end of the list.

## Table of Contents

- [Introduction](#introduction)
- [Data Structure](#data-structure)
- [Functions](#functions)
  -  [Insert at Position](#insert-at-position)

## Introduction

A circular linked list is a variation of a linked list where the last node points back to the first node, creating a circular structure. This implementation allows dynamic insertion of nodes, making it flexible for various use cases.

## Data Structure

The linked list is composed of nodes defined by the following structure:

## Functions 

***Insert at Position***

Inserts a new node at the specific Position of the circular linked list.
```bash
void insertAtPosition(struct Node** head_ref, int new_data, int position);
```