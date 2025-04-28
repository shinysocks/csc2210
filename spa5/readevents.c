// readevents.c - code to read and classify the events

#include "event.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>

void read_events(Event all_events[], int max_events, int *event_count) {
    char time[MAX_TIME_LENGTH + 1]; // add 1 for null terminator
    int milliliters;
    assert(MAX_EVENT_NAME < 80); 
    char item[80];
    
    *event_count = 0;
    int fields_read = scanf("%5s %79s %d", time, item, &milliliters);

    // read until we read a partial record (< 3 elements), eof, or max_events
    while ( fields_read == 3 && !feof(stdin) && *event_count < max_events ) {
        strncpy(all_events[*event_count].time, time, MAX_TIME_LENGTH);
        strncpy(all_events[*event_count].name, item, MAX_EVENT_NAME);

        all_events[*event_count].milliliters = milliliters;

        *event_count+=1;

        // read for next time through loop
        fields_read = scanf("%5s %79s %d", time, item, &milliliters);
    }
}

void determine_if_event_is_output(Event *an_event) {
    if (strcmp(an_event->name, "urine") == 0 || strcmp(an_event->name, "bloodloss") == 0 || strcmp(an_event->name, "diarrhea") == 0) {
        an_event->is_output = true;
    } else {
        an_event->is_output = false;
    }
}

void classify_events(Event events[], int event_count) {
    for(int i = 0; i < event_count; ++i) {
        determine_if_event_is_output(&events[i]);
    }
}
