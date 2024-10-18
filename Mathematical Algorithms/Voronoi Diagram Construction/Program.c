#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_POINTS 100
#define MAX_VORONOI_VERTICES 200

typedef struct {
    double x;
    double y;
} Point;

typedef struct {
    Point vertices[MAX_VORONOI_VERTICES];
    int vertex_count;
} VoronoiCell;

Point sites[MAX_POINTS];
VoronoiCell voronoi_cells[MAX_POINTS];
int site_count;

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void compute_voronoi() {
    for (int i = 0; i < site_count; i++) {
        VoronoiCell cell = { .vertex_count = 0 };
        
        // A simple approach: iterate over a grid and find the closest site for each point
        for (int x = 0; x < 100; x++) {
            for (int y = 0; y < 100; y++) {
                Point current_point = { x, y };
                int closest_site = -1;
                double min_dist = INFINITY;

                // Find the closest site
                for (int j = 0; j < site_count; j++) {
                    double dist = distance(current_point, sites[j]);
                    if (dist < min_dist) {
                        min_dist = dist;
                        closest_site = j;
                    }
                }

                // If this point belongs to the current site, add it to the cell
                if (closest_site == i) {
                    cell.vertices[cell.vertex_count++] = current_point;
                }
            }
        }
        
        voronoi_cells[i] = cell;
    }
}

void print_voronoi() {
    for (int i = 0; i < site_count; i++) {
        printf("Voronoi Cell for site (%lf, %lf):\n", sites[i].x, sites[i].y);
        for (int j = 0; j < voronoi_cells[i].vertex_count; j++) {
            printf("  Point: (%lf, %lf)\n", voronoi_cells[i].vertices[j].x, voronoi_cells[i].vertices[j].y);
        }
    }
}

int main() {
    printf("Enter the number of points (max %d): ", MAX_POINTS);
    scanf("%d", &site_count);

    if (site_count > MAX_POINTS) {
        printf("Too many points!\n");
        return 1;
    }

    printf("Enter the points (x y):\n");
    for (int i = 0; i < site_count; i++) {
        scanf("%lf %lf", &sites[i].x, &sites[i].y);
    }

    compute_voronoi();
    print_voronoi();

    return 0;
}
