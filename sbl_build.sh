# sudo apt-get install gcc-arm-none-eabi make
# sudo apt-get install python3-empy
# sudo apt-get install python3-future
# sudo apt-get install python3-intelhex  # necessary for building .hex bootloader
# git submodule update --init --recursive
BOARD=FlywooF745
BOARD=CubeOrangePlus
BOARD=mRoControlZeroH7
BOARD=FlywooF745
BOARD=SkystarsH7HD
BOARD=MatekH743
echo "building for $BOARD"
#./waf configure --board $BOARD
#./waf distclean
./waf copter
cp ./build/$BOARD/bin/arducopter.apj ~/Desktop/
cp ./build/$BOARD/bin/arducopter_with_bl.hex ~/Desktop/
