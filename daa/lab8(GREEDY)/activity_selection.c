// 6.2 Write a program to implement the activity-selection problem stated as follows:
// You are given n activities with their start and finish times. Select the maximum number of 
// activities that can be performed by a single person, assuming that a person can only work on a 
// single activity at a time. Example: Consider the following 6 activities ( 0, 1, 2, 3, 4, 5). 
// start[] = {1, 3, 0, 5, 8, 5}; finish[] = {2, 4, 6, 7, 9, 9); 
// The maximum set of activities that can be executed by a single person is (0, 1, 3, 4). 

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start;
    int finish;
} activity;

int compare(const void *a, const void *b) {
    activity *x = (activity *)a;
    activity *y = (activity *)b;
    if (x->finish < y->finish) return -1;
    if (x->finish > y->finish) return 1;
    return 0;
}

void greedy_activity_selector(activity *activities, int n) {
    int i, j, count = 1;

    qsort(activities, n, sizeof(activity), compare);
    printf("Selected activities: ");    
    printf("(%d, %d) ", activities[0].start, activities[0].finish);
    j=0;
    for (i = 1; i < n; i++) {
        if (activities[i].start >= activities[j].finish) {
            printf("(%d, %d) ", activities[i].start, activities[i].finish);
            j = i;
            count++;
        }
    }

    printf("\nThe maximum number of activities that can be executed by a single person is: %d", count);
}

int main() {
    int n, i, j, count = 0;
    activity *activities;
    
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    activities = (activity *)malloc(n * sizeof(activity));
    printf("Enter the start and finish time of each activity: ");
    for (i = 0; i < n; i++) {
        scanf("%d %d", &activities[i].start, &activities[i].finish);
    }

    greedy_activity_selector(activities, n);
    return 0;
}