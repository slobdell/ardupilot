#!/bin/bash

# this did not work
# openocd -f micoair-h743.cfg -c "program arducopter.elf verify reset exit"
#
# THIS WORKS TO FLASH ARDUPILOT
openocd -f micoair-h743.cfg -c "program arducopter_with_bl.hex verify reset exit"

# start_gdb_server
# sudo openocd -f micoair-h743.cfg

#mygdb:
# gdb-multiarch arducopter.elf
# then do: target extended-remote :3333
# break main
# monitor reset halt
# continue
