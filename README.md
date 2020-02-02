# PiPowerControl
Script to safely shutdown a Raspberry Pi using GPIO interrupts

## Installation

Requires the `wiringPi` library

```
git clone https://github.com/WillFarris/PiPowerControl
cd PiPowerControl
make
sudo make install
sudo systemctl enable powercontrold.service
sudo systemctl start powercontrold.service
```
By default the program will be placed in `/usr/local/bin/powercontrold`. A systemd service is created at `/lib/systemd/system/powercontrold.service`.
