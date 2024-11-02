# Real-Time Anomaly Detection in Time Series Data using Rolling Z-Scores

## Description

This C program implements a real-time anomaly detection algorithm for time series data by calculating rolling Z-scores. Each data point's deviation from a rolling mean and standard deviation is assessed, and anomalies are flagged based on a specified threshold.

## Algorithm Overview

1. **Rolling Mean and Standard Deviation**: A sliding window approach is used to compute the rolling mean and standard deviation for each point in the time series.
2. **Z-Score Calculation**: For each data point, a Z-score is computed as the difference between the data point and the rolling mean, divided by the rolling standard deviation.
3. **Anomaly Detection**: If the absolute Z-score exceeds the specified threshold, the data point is flagged as an anomaly.

## Parameters

- **WINDOW_SIZE**: Defines the number of data points in the rolling window.
- **THRESHOLD**: Sets the sensitivity of anomaly detection. Higher values will detect fewer anomalies.

## Usage

To compile and run the program:

```bash
gcc anomaly_detection.c -o anomaly_detection
./anomaly_detection
