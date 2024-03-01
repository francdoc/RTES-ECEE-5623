/* Application code that should be in a specific project's repo.*/

/*
#### Compiling for Linux OS using real-time library (-lrt)
* gcc app.c -o app -lrt

#### Run program
* ./app
*/

#include "sleep.h"

int main()
{
	int64 milliseconds = 5000;
	error err = timer.sleep(milliseconds);
	if (err) {
		printf("Error running sleep\n");
		return 1;
	}
	return 0;
}