#include <stdio.h>

int maxArea(int* heights, int size) {
    int left = 0;
    int right = size - 1;
    int max_area = 0;

    while (left < right) {
        // Calculate the area with the current left and right pointers
        int height = heights[left] < heights[right] ? heights[left] : heights[right];
        int width = right - left;
        int area = height * width;

        // Update the maximum area if the current area is larger
        if (area > max_area) {
            max_area = area;
        }

        // Move the pointer with the smaller height inward
        if (heights[left] < heights[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;
}

int main() {
    int heights[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int size = sizeof(heights) / sizeof(heights[0]);
    int result = maxArea(heights, size);

    printf("The maximum area of water that can be contained is: %d\n", result);
    return 0;
}
