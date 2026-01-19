#!/bin/bash

openocd \
  -f interface/stlink.cfg \
  -f target/stm32h7x.cfg \
  -c "flash bank bank1 stm32h7x 0x08100000 0x100000 0 0 stm32h7x.cpu0" \
  -c "init; program arduplane_with_bl.hex verify reset exit"
