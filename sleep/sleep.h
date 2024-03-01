// Sleep implementation

#include "../common.h"

#include <time.h>
#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>

// Function prototypes
error sleep_impl(int64 milliseconds);
int64 unix_nano_impl();

// Declare an instance of the OSAL_Sleep interface
OSAL_Sleep timer = {
	.sleep = sleep_impl,
};

// Define function to get the system time in nanoseconds
int64 unix_nano_impl()
{
	struct timespec current_time;
	if (clock_gettime(CLOCK_MONOTONIC, &current_time) != 0) {
		perror("clock_gettime");
		return -1;
	}
	int64 nanoseconds = current_time.tv_sec * 1000000000LL + current_time.tv_nsec;
	return nanoseconds;
}

#define DEBUG_TIME

error sleep_impl(int64 milliseconds)
{
	OSAL_unix_nano unix_nano = &unix_nano_impl;
	int64 start_time = unix_nano_impl();
	int64 end_time = start_time + (milliseconds * 1000000LL); // Convert milliseconds to nanoseconds

	while (unix_nano_impl() < end_time) {
		// Calculate the current time in milliseconds
		int64 current_time = (unix_nano_impl() - start_time) / 1000000LL;
#ifdef DEBUG_TIME
		printf("Time elapsed in milliseconds: %lld\n", (long long int)current_time);
#endif
	}

	return 0;
}