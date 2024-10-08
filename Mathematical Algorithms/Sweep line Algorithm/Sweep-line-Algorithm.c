// The sweep line algorithm works as follows:

// Sort events: Consider each line segment as generating two events: one at the left endpoint (start) and one at the right endpoint (end). We sort all these events by their x-coordinates. If two events have the same x-coordinate, a start event is processed before an end event.

// Active set: As the sweep line moves from left to right, it maintains an active set of line segments that intersect the current position of the sweep line. This set is usually maintained as a balanced binary search tree (e.g., using std::set in C++ or implementing a balanced tree in C) so that we can efficiently insert, delete, and search segments.

// Handle events: For each event (either a start or end of a segment):

// If it's a start event, we add the segment to the active set and check for intersections with its neighbors.
// If it's an end event, we remove the segment from the active set and check for intersections between the neighbors of the segment we just removed.
// Intersection check: When two segments are consecutive in the active set, we check if they intersect. If they do, we record the intersection point.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Struct to represent a point
typedef struct {
    int x, y;
} Point;

// Struct to represent a line segment
typedef struct {
    Point start, end;
} Segment;

// Event struct (either a start or end of a segment)
typedef struct {
    int x;            // X-coordinate of the event
    int type;         // 0 for start, 1 for end
    Segment *segment; // Pointer to the line segment
} Event;

// Comparator for sorting events by their x-coordinate
int compareEvents(const void *a, const void *b) {
    Event *eventA = (Event *)a;
    Event *eventB = (Event *)b;
    if (eventA->x != eventB->x)
        return eventA->x - eventB->x;
    return eventA->type - eventB->type; // Start event comes before end event
}

// Utility function to check if two points are on opposite sides of a line
bool onOppositeSides(Point a, Point b, Segment s) {
    int cross1 = (s.end.x - s.start.x) * (a.y - s.start.y) - (s.end.y - s.start.y) * (a.x - s.start.x);
    int cross2 = (s.end.x - s.start.x) * (b.y - s.start.y) - (s.end.y - s.start.y) * (b.x - s.start.x);
    return (cross1 * cross2) < 0;
}

// Function to check if two segments intersect
bool doSegmentsIntersect(Segment s1, Segment s2) {
    return onOppositeSides(s1.start, s1.end, s2) && onOppositeSides(s2.start, s2.end, s1);
}

// Function to handle the sweep line algorithm
void sweepLineAlgorithm(Segment segments[], int n) {
    int totalEvents = 2 * n; // Each segment has a start and an end event
    Event events[totalEvents];

    // Create events for all segments (start and end)
    for (int i = 0; i < n; i++) {
        events[2 * i].x = segments[i].start.x;
        events[2 * i].type = 0; // Start event
        events[2 * i].segment = &segments[i];

        events[2 * i + 1].x = segments[i].end.x;
        events[2 * i + 1].type = 1; // End event
        events[2 * i + 1].segment = &segments[i];
    }

    // Sort events by x-coordinate
    qsort(events, totalEvents, sizeof(Event), compareEvents);

    // Active set of segments (we'll use a simple array for now)
    Segment *activeSet[n];
    int activeCount = 0;

    // Process all events
    for (int i = 0; i < totalEvents; i++) {
        Event currentEvent = events[i];

        if (currentEvent.type == 0) { // Start event
            // Add the segment to the active set
            activeSet[activeCount++] = currentEvent.segment;

            // Check for intersections with all other segments in the active set
            for (int j = 0; j < activeCount - 1; j++) {
                if (doSegmentsIntersect(*activeSet[j], *currentEvent.segment)) {
                    printf("Intersection found between segment %d and segment %d\n",
                           j, activeCount - 1);
                }
            }
        } else { // End event
            // Remove the segment from the active set
            for (int j = 0; j < activeCount; j++) {
                if (activeSet[j] == currentEvent.segment) {
                    // Shift remaining segments to fill the gap
                    for (int k = j; k < activeCount - 1; k++) {
                        activeSet[k] = activeSet[k + 1];
                    }
                    activeCount--;
                    break;
                }
            }
        }
    }
}

// Driver code
int main() {
    Segment segments[] = {
        {{1, 1}, {4, 4}},
        {{1, 4}, {4, 1}},
        {{2, 3}, {5, 3}}
    };
    int n = sizeof(segments) / sizeof(segments[0]);

    sweepLineAlgorithm(segments, n);

    return 0;
}
