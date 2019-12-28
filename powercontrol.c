/* Simple daemon to control soft power down and reboot on button press */
#include <stdlib.h>
#include <stdint.h>
#include <wiringPi.h>

const int POWERPIN = 17;
const int REBOOTPIN = 23;

const int MUTEX_LOCKED = 1;
const int MUTEX_UNLOCKED = 0;

static volatile uint8_t powerThreadMutex = 0;
static volatile uint8_t rebootThreadMutex = 0;

void handle_power_interrupt(void)
{
	if(powerThreadMutex == MUTEX_LOCKED)
		return;

	powerThreadMutex = MUTEX_LOCKED;
	system("poweroff");
	powerThreadMutex = MUTEX_UNLOCKED;
}

void handle_reboot_interrupt(void)
{
	if(rebootThreadMutex == MUTEX_LOCKED)
		return;

	rebootThreadMutex = MUTEX_LOCKED;
	system("reboot");
	rebootThreadMutex = MUTEX_UNLOCKED;
}

int main()
{
	//setup gpio on the pi with BCM pin numberings
	wiringPiSetupGpio();

	//setup the power pin to trigger an interrupt when the button is pressed and released
	pullUpDnControl(POWERPIN,  PUD_UP);
	wiringPiISR(POWERPIN, INT_EDGE_FALLING, &handle_power_interrupt);

	//same for reboot button
	pullUpDnControl(REBOOTPIN, PUD_UP);
	wiringPiISR(REBOOTPIN, INT_EDGE_FALLING, &handle_reboot_interrupt);

	for(;;) {} //loop forever
	return 0;
}
