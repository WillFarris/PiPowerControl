# PiPowerControl
Simple script to safely shutdown a Raspberry Pi using GPIO interrupts

## Installation

```
git clone https://github.com/WillFarris/PiPowerControl
cd PiPowerControl
make
sudo make install
```
By default the program will be placed in `/usr/local/bin/`. A future version of this program will automatically create a systemd service to automatically start as a daemon.
