# Circular Linked List Deletion at Start in C

This project implements a circular linked list in C with functionality to delete a node at the start of the list.

## Table of Contents

- [Introduction](#introduction)
- [Data Structure](#data-structure)
- [Functions](#functions)
  - [Delete at Start](#delete-at-specific-position)

## Introduction

A circular linked list is a variation of a linked list where the last node points back to the first node, creating a circular structure. This implementation allows for dynamic deletion of nodes, specifically at the start of the list.

## Data Structure

The linked list is composed of nodes defined by the following structure:

```c
void deleteAtPosition(struct Node** head_ref, int position);
```